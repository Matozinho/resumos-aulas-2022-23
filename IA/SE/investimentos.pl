% Regras para definir o tipo de investimento
investimento('Investir 100% na poupança.') :-
  quantia(pequena).

investimento('Investir 50% na poupança, 50% em Tesouro Direto.') :- 
    perfil_pessoal(conservador), 
    perfil_profissional(conservador).

investimento('Investir 60% na poupança, 30% em Tesouro Direto, 10% em ações.') :- 
    perfil_pessoal(conservador), 
    perfil_profissional(agressivo).

investimento('Investir 20% na poupança, 40% em Tesouro Direto, 40% em ações.') :- 
    perfil_pessoal(agressivo), 
    perfil_profissional(conservador).

investimento('Investir 100% em ações.') :- 
    perfil_pessoal(agressivo), 
    perfil_profissional(agressivo).

% Regras para definir perfil pessoal conservador
perfil_pessoal(conservador) :- 
    idade(avancada), 
    emprego(nao_estavel).

perfil_pessoal(conservador) :-
    idade(jovem),
    emprego(nao_estavel),
    n_filhos(A),
    A > 0.

perfil_pessoal(conservador) :-
    idade(avancada),
    emprego(estavel),
    n_filhos(A),
    A > 0.

% Regras para definir perfil pessoal agressivo
perfil_pessoal(agressivo) :-
    idade(jovem),
    emprego(nao_estavel),
    n_filhos(A),
    A = 0.

perfil_pessoal(agressivo) :-
    idade(jovem),
    emprego(estavel),
    n_filhos(A),
    A = 0.

perfil_pessoal(agressivo) :-
    idade(avancada),
    emprego(estavel),
    n_filhos(A),
    A = 0.

% Caso default (todas as regras de perfil pessoal falharam)
perfil_pessoal(conservador) :- perfil_pessoal(agressivo), !, fail; true.

% Regras para definir perfil profissional conservador
perfil_profissional(conservador) :-
    total_rendimentos(A),
    total_despesas(B),
    A =< B.

perfil_profissional(conservador) :-
    total_rendimentos(A),
    total_despesas(B),
    A > B,
    A < 2*B,
    n_filhos(C),
    C > 0.

% Regras para definir perfil profissional agressivo
perfil_profissional(agressivo) :-
    total_rendimentos(A),
    total_despesas(B),
    A > B,
    A < 2*B,
    n_filhos(C),
    C = 0.

perfil_profissional(agressivo) :-
    total_rendimentos(A),
    total_despesas(B),
    A > 2*B.

% Caso default (todas as regras de perfil profissional falharam)
perfil_profissional(conservador) :- perfil_profissional(agressivo), !, fail; true.

% Regras de quantia investida
quantia(pequena) :- valor_quantia(A), A =< 1000.
quantia(alta) :- valor_quantia(A), A > 1000.

% Regras de idade
idade(jovem) :- valor_idade(A), A =< 40.
idade(avancada) :- valor_idade(A), A > 40.

% Regras de emprego estável e instável
emprego(nao_estavel) :- 
    tempo_de_servico(A), A < 3.

emprego(nao_estavel) :- 
    tempo_de_servico(A), A < 5, A >= 3,
    capital_empresa(baixo).

emprego(estavel) :-
    tempo_de_servico(A), A >= 5.

emprego(estavel) :-
    tempo_de_servico(A), A < 5, A >= 3,
    capital_empresa(alto).

% Regras de tempo de servico
tempo_de_servico(A) :- 
    pergunte(tempo_de_servico, A, 'Qual o seu tempo de serviço?').

% Regras do capital da empresa -> para definir se o emprego é estável ou instável
capital_empresa(baixo) :- pergunte(capital_empresa, A, 'Qual o capital da empresa em que você trabalha?'), A < 50000.
capital_empresa(alto) :- pergunte(capital_empresa, A, 'Qual o capital da empresa em que você trabalha?'), A >= 50000.

% Regras de número de filhos
n_filhos(A) :- pergunte(n_filhos, A, 'Número de filhos?').

% Regras de valor da quantia
valor_quantia(A) :- pergunte(valor_quantia, A, 'Qual a quantia que deseja investir?').

% Regras de valor da idade
valor_idade(A) :- pergunte(valor_idade, A, 'Qual a sua idade?').

% Regras de total de rendimentos
total_rendimentos(A) :- pergunte(total_rendimentos, A, 'Qual o seu total de rendimentos?').

% Regras de total de despesas
total_despesas(A) :- pergunte(total_despesas, A, 'Qual o seu total de despesas?').

pergunte(Atributo, Valor, Texto) :-
    fato(Atributo, Valor), !.
pergunte(Atributo, Valor, Texto) :-
    fato(Atributo, Valor), !, fail.
pergunte(A, V, Texto) :-
    nl, write(Texto), nl, write('> '),
    read(V), nl,
    asserta(fato(A, V)).

main :- nl, write('Sistema Especialista em Consultoria de Investimentos'), nl,
  retractall(fato(_,_)),
  % limpa a memória de trabalho
  investimento(A),
  write('O aconselhamento é: '), 
  write(A), nl,
  % Finish the program
  halt.
  
:- dynamic fato/2.
:- initialization(main).