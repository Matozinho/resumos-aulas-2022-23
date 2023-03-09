## Lógica de predicados

- muitas limitações mas facilita o raciciocínio por ser simples

- Compromisso ontológico
  - Lógica proposicional: Existem fatos válidos ou não válidos no mundo
  - Lógica de predicados: Pressupõe que o mundo é um conjunto de objetos e relações entre eles, que são válidas ou inválidas

### **Termos**
  - Descrevem ou nomeiam entidades ou objetos
  - Variáveis: são termos que podem ser substituídos por outros termos
  - Constantes: são termos que não podem ser substituídos por outros termos -> Colombo descobriu a América
  - Funções: Igual função normal -> recebe um valor e retorna um valor a partir de um calculo específico

### **Predicados**

- Menor unidade que pode ser representada dentro de um sistema
- Constituem nomes de propriedades e relações
- Ex: z é senador. "senador" é um predicado o qual, quando avaliado resulta em um valor-verdade
- Pode se escrever: senador(z)
- Pergunta-se -> fulano pode ser senador?
- **Aridade de predicados:** Número de termos que o predicado tem:
  - chove -> aridade 0
  - senador(x) -> aridade 1
  - pai(x, Alberto) -> aridade 2
- **Instanciação:** é o processo de avaliação de um predicado que consiste em substituir variáveis por constantes para a obtenção de enunciados

### **Quantificadores**

- São 2
  - Universal
  - Existencial

**Ex:**
- Calabar foi enforcado -> enforcado(Calabar)
- Getúlio foi presidente -> presidente(Getúlio)
  - não da pra fazer pois o predicado não trabalha com variação de tempo
  - Getúlio é presidente? Sim
  - Não considera que ele não **é**, mas sim **foi** presidente
  - Todo Traidor é enforcado -> ∀ x enforcado(x) → traidor(x)
  - Todos os índios eram selvagens -> ∀ x indio(x) → selvagem(x)
  - Tiradentes não era índio -> ¬indio(Tiradentes)
  - Tiradentes foi considerado traidor -> traidor(Tiradentes)

- A representação com predicados ocasionou a perda de informação (passado, presente ou futuro) -> pensa em presente quando se fala de predicados
- As declarações não são facilmente trabalháveis
- A matemárica trabalha com expressões lógicas através da resolução, mas elas deve estar em form de cláusulas

**Cláusula** -> A cláusula deve estar na FNC (Forma Normal Conjuntiva)\
Algoritmo de 7 passos

### **Vantages**

- Ferramental exaustivamente testado.
- Natural para quem entende
- Flexibilidade no que se refere aos campos de aplicação
  - Provar teorema, sistema especialista, diagnóstico, etc...
- Precisão e modularidade
  - Consegue ter predicados que representam algo e pode-se incluir ou remover predicados de forma fácil
- PROLOG -> representa muito bem a lógica de predicados. Linguagem declarativa -> diz **o que** e não **como** fazer.

### **Desvantagens**

- A lógica separa a representação e o processamento tornando difícil inserir aspectos heurísticos.