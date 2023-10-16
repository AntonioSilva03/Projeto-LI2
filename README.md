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
Strings: "string"
```

```
Bloco: { 2 3 4 + [ 3 4 5 ] _ }
```

- Operações com dois inteiros
```
2 2 +
```
O programa vai guardar os dois valores na stack e a operação vai retirá-los e operá-los (importante salientar que as operações não são guardadas na stack)

- Operações com arrays
```
[ 2 3 4 5 6 ] [ 2 3 4 ] +
[ 2 3 4 5 ] 2 *
Os arrays 
