<h1 align="center"> Projeto de Laboratórios de Informática II

Calculadora em stack </h1>

## Introdução
Este programa consiste num conjunto de operações de manipulação de números, arrays e strings.

## Descrição
A base deste programa é uma stack onde todos os elementos (números, arrays, strings e blocos) são armazenados. Cada operação atua nos dois primeiros elementos da stack (ou no primeiro caso seja uma operação singular). Estas operações incluem todas as operações básicas com números, manipulação de arrays e strings, e a possibilidade da criação de blocos com várias sub-operações que podem depois ser aplicadas a um outro elemento.

## Compilação
Este programa não possui makefile (poderei adicionar no futuro) pelo que a compilação deve ser feita pelo compilador usando o comando:
```
gcc *.c -lm
```
Saliento que a flag -lm é obrigatória para que o compilador reconheça as funções da biblioteca math.h

## Execução
A execução do programa pode ser feita através do seguinte comando:
```
./a.out
```
O programa entrará em modo de espera. Aqui poderá ser introduzido o input.

## Modo de utilização
Os seguintes são exemplos de como utilizar o programa de maneira correta. Todos os tokens devem ser separados por um espaço

- Como apresentar os tokens
```
Números: 2 3 4 + 5 - /
```

```
Arrays: [ 2 3 4 5 6 ]
```

```
Strings: "string" "teste"
```

```
Bloco: { 2 3 4 + [ 3 4 5 ] _ }
```

- Operações com dois inteiros
```
Input: 2 2 +
O que será guardado na stack: 4
```
O programa vai guardar os dois valores na stack e a operação vai retirá-los e operá-los (importante salientar que as operações não são guardadas na stack)

- Operações com arrays
```
Input: [ 2 3 4 5 6 ] [ 2 3 4 ] +
O que será guardado na stack: [ 2 3 4 5 6 2 3 4 ]

Input: [ 2 3 4 5 ] 2 *
O que será guardado na stack: [ 2 3 4 5 2 3 4 5 ]
```
Os arrays são implementados como substacks logo podem conter todos os tipos de dados dentro. Adicionalmente os valores podem ser definidos com operações.

Exemplo:
```
Input: [ 2 3 4 + 3 ]
Array que será guardado na stack: [ 2 7 3 ]
```

- Operações com strings
```
Input: "string" "teste" +
O que será guardado na stack: "stringteste"
```
As strings podem conter espaços, tudo o que estiver dentro das aspas será guardado na mesma string.
```
"string de teste"
```

- Operações com blocos

Blocos são guardados sem qualquer manipulação isto é, tudo o que estiver dentro do bloco (operações inclusive) serão guardadas na stack.
```
Input: { 2 3 + [ 2 3 4 5 ] + }
O que será guardado na stack: { 2 3 + [ 2 3 4 5 ] + }
```
Estes blocos podem depois ser executados usando o token ```~```. Apenas aí todas as operações serão efetuadas.
```
Input: { 2 3 + [ 2 3 4 5 ] + } ~
O que será guardado na stack: [ 7 2 3 4 5 ]
```
Neste caso, a stack guarda o ```2``` e o ```3```, lê o ```+``` e aplica-o aos dois valores anteriores e guarda o resultado na stack. Depois lê o array e guarda o na stack. Por fim lê o token ```+``` e aplica-o aos dois valores anteriores. Neste caso os valores são ```7``` e ```[ 2 3 4 5 ]``` logo a operação vai juntar os valores na ordem que aparecem resultando no array ```[ 7 2 3 4 5 ]```.

- Variáveis

Este programa possui a funcionalidade de substituir valores por letras de modo a simplificar o input. Estas variáveis são representadas por letras maiusculas de A a Z. Seguem as instruções de como as utilizar:
```
Input: A
O que será guardado na stack: Valor guardado em A

Input: 10 :A
Neste caso, o valor 10 será guardado na variável A

Input: 10 :A 20 :B A B +
Neste caso, o valor 10 e 20 serão guardados nas variáveis A e B e depois os valores serão somados.
```
As variáveis são guardadas durante a execução do programa, sendo depois reiniciadas.

Como o programa lê e faz a triagem do input token a token é possível fazer multiplas operações ao mesmo tempo com vários tipos de estruturas.

## Conclusão
Trabalho realizado por Pedro Silva, António Silva e Diogo Barros.
