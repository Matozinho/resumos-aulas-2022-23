% Verifica se um elemento faz parte da lista
membro(D, [D|_]) :- !.
membro(D, [_|Cauda]) :-
membro(D, Cauda).

% Concatenação de duas listas
concate([], Lista, Lista) :- !.
concate([E|Lista1], Lista2, [E|Lista3]) :-
concate(Lista1, Lista2, Lista3).

% Insere elemento no início da lista
listIni(C, [], [C]) :- !.
listIni(C, Lista, [C|Lista]) :- !.

% Inserir elemento no final da lista
listFim(E, [], [E]) :- !.
listFim(E, Lista1, Lista2) :-
listIni(E, [], ListAux),
concate(Lista1, ListAux, Lista2).

% Encontrar o menor elemento da lista
min([G], G) :- !.
min([Cabeca|Cauda], Cabeca) :-
	min(Cauda, G), (Cabeca @=< G).
min([Cabeca|Cauda], G) :-
	min(Cauda, G), (Cabeca @> G).

% Encontra o maior elemento da lista
max([G], G) :- !.
max([Cabeca|Cauda], Cabeca) :-
max(Cauda, G), (Cabeca @> G).
max([Cabeca|Cauda], G) :-
max(Cauda, G), (Cabeca @=< G).

% Retorna o comprimento da lista
tam([], 0) :- !.
tam([_|Cauda], N) :-
tam(Cauda, N1),
N is N1 + 1.

% Inverte a lista
inverte([], []) :- !.
inverte([Cabeca|Cauda], Lista) :-
inverte(Cauda, LAux),
concate(LAux, [Cabeca], Lista).

% Remove um elemento ad lista
remove(_, [], []) :- !.
remove(X, [X|Cauda], Cauda) :- !.
remove(X, [Cabeca|Cauda], Lista) :-
remove(X, Cauda, LAux),
listIni(Cabeca, LAux, Lista).

% Remove todas as ocorrências de um elemento da lista
removeTodas(_, [], []) :- !.
removeTodas(X, [X|Cauda], L) :-
removeTodas(X, Cauda, L).
removeTodas(X, [X1|Cauda], [X1|Cauda1]) :-
X \== X1,
removeTodas(X, Cauda, Cauda1).

% Recebendo uma lista de numeros, retorna a soma de todos os componentes
sum_list([], 0). % Base case: the sum of an empty list is 0.
sum_list([Head|Tail], Sum) :-
    sum_list(Tail, TailSum), % Recursive call to sum the tail of the list.
    Sum is Head + TailSum. % Add the head of the list to the sum of the tail.

% Get the last element of the list
last_element([X], X) :- !.
last_element([_|Tail], X) :-
    last_element(Tail, X).

% at([Head | Tail], idx, Element) {
% 	if(idx == 1) return Head;
% 	else return at(Tail, idx-1, Element)
% }
at([], _, []) :- !.
at([Head|_], 1, Head) :- !.
at([_|Tail], Idx, Element) :-
  NewIdx is Idx - 1,
  at(Tail, NewIdx, Element).
