#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variaveis.h"
/**
 * Função que cria, aloca espaço e atribui valores às variáveis predefinidas.
 * 
 */
VAR *new_var()
{
    VAR *new_var = malloc(sizeof *new_var);                  /// Cria e aloca espaço a um array auxiliar que leva todas as variaveis.
    new_var->varr = malloc(sizeof *new_var->varr * VAR_MAX); /// Aloca espaço a cada elemento do array, para receber todos os elementos de cada variável.
    int pos = 0;
    /// Ciclo que corre todo o array e atribui valores e tipos a cada uma das variáveis predefinidas.
    for (char i = 'A'; i <= 'Z'; i++, pos++)
    {
        if (i == 'A') /// Se o i for A
        {
            new_var->varr[pos].t = INT; /// o tipo do A é inteiro
            new_var->varr[pos].elem = (void *)10; /// Sendo o seu elemento 10, tendo de converte-lo para void*
        }
        if (i == 'B') /// Se o i for B
        {
            new_var->varr[pos].t = INT; /// o tipo do B é inteiro
            new_var->varr[pos].elem = (void *)11; /// Sendo o seu elemento 11, tendo de converte-lo para void*
        }
        if (i == 'C') /// Se o i for C
        {
            new_var->varr[pos].t = INT; /// o tipo do C é inteiro
            new_var->varr[pos].elem = (void *)12; /// Sendo o seu elemento 12, tendo de converte-lo para void*
        }
        if (i == 'D') /// Se o i for D
        {
            new_var->varr[pos].t = INT; /// o tipo do D é inteiro
            new_var->varr[pos].elem = (void *)13; /// Sendo o seu elemento 13, tendo de converte-lo para void*
        }
        if (i == 'E') /// Se o i for E
        {
            new_var->varr[pos].t = INT; /// o tipo do E é inteiro
            new_var->varr[pos].elem = (void *)14; /// Sendo o seu elemento 14, tendo de converte-lo para void*
        }
        if (i == 'F') /// Se o i for F
        {
            new_var->varr[pos].t = INT; /// o tipo do F é inteiro
            new_var->varr[pos].elem = (void *)15; /// Sendo o seu elemento 15, tendo de converte-lo para void*
        }
        if (i == 'N') /// Se o i for N
        {
            new_var->varr[pos].t = CHAR; /// o tipo do N é char
            new_var->varr[pos].elem = (void *)'\n'; /// Sendo o seu elemento '\n', tendo de converte-lo para void*
        }
        if (i == 'S') /// Se o i for S
        {
            new_var->varr[pos].t = CHAR; /// o tipo do S é char
            new_var->varr[pos].elem = (void *)' '; /// Sendo o seu elemento ' ', tendo de converte-lo para void*
        }
        if (i == 'X') /// Se o i for X
        {
            new_var->varr[pos].t = INT; /// o tipo do X é inteiro
            new_var->varr[pos].elem = (void *)0; /// Sendo o seu elemento 0, tendo de converte-lo para void*
        }
        if (i == 'Y') /// Se o i for Y
        {
            new_var->varr[pos].t = INT; /// o tipo do Y é inteiro
            new_var->varr[pos].elem = (void *)1; /// Sendo o seu elemento 1, tendo de converte-lo para void*
        }
        if (i == 'Z') /// Se o i for Z
        {
            new_var->varr[pos].t = INT; /// o tipo do Z é inteiro
            new_var->varr[pos].elem = (void *)2; /// Sendo o seu elemento 2, tendo de converte-lo para void*
        }
    }
    return new_var;
}
/**
 * Função que trata das operações com a variável A e com a troca de elemento da variável A.
 * 
 */
int var_A(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "A") == 0) /// Comparar se o operador que a stack recebe é o operador "A"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o A
        {
            if (i == 'A') /// Quando encontra o A
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de A
                return 1;
            }
        }
    }
    if (strcmp(token, ":A") == 0) /// Comparar se o operador que a stack recebe é o operador ":A"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o A
        {
            if (i == 'A') /// Quando encontra o A
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no A passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do A passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de A
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável B e com a troca de elemento da variável B.
 * 
 */
int var_B(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "B") == 0) /// Comparar se o operador que a stack recebe é o operador "B"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++)  /// Função que procura o B
        {
            if (i == 'B') /// Quando encontra o B
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de B
                return 1;
            }
        }
    }
    if (strcmp(token, ":B") == 0) /// Comparar se o operador que a stack recebe é o operador ":B"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o B
        {
            if (i == 'B') /// Quando encontra o B
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no B passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do B passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de B
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável C e com a troca de elemento da variável C.
 * 
 */
int var_C(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "C") == 0) /// Comparar se o operador que a stack recebe é o operador "C" 
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o C
        {
            if (i == 'C') /// Quando encontra o A
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de C
                return 1;
            }
        }
    }
    if (strcmp(token, ":C") == 0) /// Comparar se o operador que a stack recebe é o operador ":C"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++)
        {
            if (i == 'C') /// Quando encontra o C
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no C passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do C passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de C
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável D e com a troca de elemento da variável D.
 * 
 */
int var_D(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "D") == 0) /// Comparar se o operador que a stack recebe é o operador "D"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o D
        {
            if (i == 'D') /// Quando encontra o D
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de D
                return 1;
            }
        }
    }
    if (strcmp(token, ":D") == 0) /// Comparar se o operador que a stack recebe é o operador ":D"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++)
        {
            if (i == 'D') /// Quando encontra o D
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no D passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do D passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de D
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável E e com a troca de elemento da variável E.
 * 
 */
int var_E(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "E") == 0) /// Comparar se o operador que a stack recebe é o operador "E"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o E
        {
            if (i == 'E') /// Quando encontra o E
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de E
                return 1;
            }
        }
    }
    if (strcmp(token, ":E") == 0) /// Comparar se o operador que a stack recebe é o operador ":E"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o E
        {
            if (i == 'E') /// Quando encontra o E
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no E passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do E passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de E
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável F e com a troca de elemento da variável F.
 * 
 */
int var_F(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "F") == 0) /// Comparar se o operador que a stack recebe é o operador "F"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o F
        {
            if (i == 'F') /// Quando encontra o F
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de F
                return 1;
            }
        }
    }
    if (strcmp(token, ":F") == 0) /// Comparar se o operador que a stack recebe é o operador ":F"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o F
        {
            if (i == 'F') /// Quando encontra o F
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no A passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do F passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de F
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável G e com a troca de elemento da variável G.
 * 
 */
int var_G(STACK *s, VAR *v, char *token)
{ 
    if (strcmp(token, "G") == 0) /// Comparar se o operador que a stack recebe é o operador "G"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o G
        {
            if (i == 'G') /// Quando encontra o G
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t;  /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de G
                return 1;
            }
        }
    }
    if (strcmp(token, ":G") == 0) /// Comparar se o operador que a stack recebe é o operador ":G"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o G
        {
            if (i == 'G') /// Quando encontra o G
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no G passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do G passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de G
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável H e com a troca de elemento da variável H.
 * 
 */
int var_H(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "H") == 0) /// Comparar se o operador que a stack recebe é o operador "H"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o H
        {
            if (i == 'H') /// Quando encontra o H
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de H
                return 1;
            }
        }
    }
    if (strcmp(token, ":H") == 0) /// Comparar se o operador que a stack recebe é o operador ":H"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o H
        {
            if (i == 'H') /// Quando encontra o A
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no H passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do H passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de H
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável I e com a troca de elemento da variável I.
 * 
 */
int var_I(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "I") == 0) /// Comparar se o operador que a stack recebe é o operador "I"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o I
        {
            if (i == 'I') /// Quando encontra o I
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de I
                return 1;
            }
        }
    }
    if (strcmp(token, ":I") == 0) /// Comparar se o operador que a stack recebe é o operador ":I"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o I
        {
            if (i == 'I') /// Quando encontra o I
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no I passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do A passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de I
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável J e com a troca de elemento da variável J.
 * 
 */
int var_J(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "J") == 0) /// Comparar se o operador que a stack recebe é o operador "J"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o J
        {
            if (i == 'J') /// Quando encontra o J
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de J
                return 1;
            }
        }
    }
    if (strcmp(token, ":J") == 0) /// Comparar se o operador que a stack recebe é o operador ":J"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o J
        {
            if (i == 'J') /// Quando encontra o J
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no J passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do J passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de j
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável K e com a troca de elemento da variável K.
 * 
 */
int var_K(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "K") == 0) /// Comparar se o operador que a stack recebe é o operador "K"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o K
        {
            if (i == 'K') /// Quando encontra o K
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de K
                return 1;
            }
        }
    }
    if (strcmp(token, ":K") == 0) /// Comparar se o operador que a stack recebe é o operador ":K"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o K
        {
            if (i == 'K') /// Quando encontra o K
            { 
                v->varr[pos].elem = Z.elem; /// O valor guardado no K passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do K passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de K
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável L e com a troca de elemento da variável L.
 * 
 */
int var_L(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "L") == 0) /// Comparar se o operador que a stack recebe é o operador "L"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o L
        {
            if (i == 'L') /// Quando encontra o L
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de L
                return 1;
            }
        }
    }
    if (strcmp(token, ":L") == 0) /// Comparar se o operador que a stack recebe é o operador ":L"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o L
        {
            if (i == 'L') /// Quando encontra o L
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no L passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do L passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de L
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável M e com a troca de elemento da variável M.
 * 
 */
int var_M(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "M") == 0) /// Comparar se o operador que a stack recebe é o operador "M"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o M
        {
            if (i == 'M') /// Quando encontra o M
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de M
                return 1;
            }
        }
    }
    if (strcmp(token, ":M") == 0) /// Comparar se o operador que a stack recebe é o operador ":M"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o M
        {
            if (i == 'M') /// Quando encontra o M
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no M passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do M passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de M
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável N e com a troca de elemento da variável N.
 * 
 */
int var_N(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "N") == 0) /// Comparar se o operador que a stack recebe é o operador "N"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o N
        {
            if (i == 'N') /// Quando encontra o N
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de N
                return 1;
            }
        }
    }
    if (strcmp(token, ":N") == 0) /// Comparar se o operador que a stack recebe é o operador ":N"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o N
        {
            if (i == 'N') /// Quando encontra o N
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no N passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do N passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de N
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável O e com a troca de elemento da variável O.
 * 
 */
int var_O(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "O") == 0) /// Comparar se o operador que a stack recebe é o operador "O"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o O
        { 
            if (i == 'O') /// Quando encontra o O
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de O
                return 1;
            }
        }
    }
    if (strcmp(token, ":O") == 0) /// Comparar se o operador que a stack recebe é o operador ":O"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o O
        {
            if (i == 'O') /// Quando encontra o A
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no O passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do O passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de O
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável P e com a troca de elemento da variável P.
 * 
 */
int var_P(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "P") == 0) /// Comparar se o operador que a stack recebe é o operador "P"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o P
        {
            if (i == 'P') /// Quando encontra o P
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de P
                return 1;
            }
        }
    }
    if (strcmp(token, ":P") == 0) /// Comparar se o operador que a stack recebe é o operador ":P"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o P
        {
            if (i == 'P') /// Quando encontra o P
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no P passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do P passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de P
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável Q e com a troca de elemento da variável Q.
 * 
 */
int var_Q(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "Q") == 0) /// Comparar se o operador que a stack recebe é o operador "Q"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Q
        {
            if (i == 'Q') /// Quando encontra o Q
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de Q
                return 1;
            }
        }
    }
    if (strcmp(token, ":Q") == 0) /// Comparar se o operador que a stack recebe é o operador ":Q"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Q
        {
            if (i == 'Q') /// Quando encontra o Q
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no Q passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do Q passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de Q
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável R e com a troca de elemento da variável R.
 * 
 */
int var_R(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "R") == 0) /// Comparar se o operador que a stack recebe é o operador "R"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o R
        {
            if (i == 'R') /// Quando encontra o R
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de R
                return 1;
            }
        }
    }
    if (strcmp(token, ":R") == 0) /// Comparar se o operador que a stack recebe é o operador ":R"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o R
        {
            if (i == 'R') /// Quando encontra o R
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no R passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do R passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de R
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável S e com a troca de elemento da variável S.
 * 
 */
int var_S(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "S") == 0) /// Comparar se o operador que a stack recebe é o operador "S"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o S
        {
            if (i == 'S') /// Quando encontra o S
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de S
                return 1;
            }
        }
    }
    if (strcmp(token, ":S") == 0) /// Comparar se o operador que a stack recebe é o operador ":S"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o S
        {
            if (i == 'S') /// Quando encontra o S
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no S passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do S passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de S
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável T e com a troca de elemento da variável T.
 * 
 */
int var_T(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "T") == 0) /// Comparar se o operador que a stack recebe é o operador "T"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o T
        {
            if (i == 'T') /// Quando encontra o T
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de T
                return 1;
            }
        }
    } 
    if (strcmp(token, ":T") == 0) /// Comparar se o operador que a stack recebe é o operador ":T"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o T
        {
            if (i == 'T') /// Quando encontra o T
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no T passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do T passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de T
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável U e com a troca de elemento da variável U.
 * 
 */
int var_U(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "U") == 0) /// Comparar se o operador que a stack recebe é o operador "U"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o U
        {
            if (i == 'U') /// Quando encontra o U
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de U
                return 1;
            }
        }
    }
    if (strcmp(token, ":U") == 0) /// Comparar se o operador que a stack recebe é o operador ":U"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o U
        {
            if (i == 'U') /// Quando encontra o U
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no U passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do U passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de U
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável V e com a troca de elemento da variável V.
 * 
 */
int var_V(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "V") == 0) /// Comparar se o operador que a stack recebe é o operador "V"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o V
        {
            if (i == 'V') /// Quando encontra o V
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de V
                return 1;
            }
        }
    }
    if (strcmp(token, ":V") == 0) /// Comparar se o operador que a stack recebe é o operador ":V"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o V
        {
            if (i == 'V') /// Quando encontra o V
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no V passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do V passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de V
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável W e com a troca de elemento da variável W.
 * 
 */
int var_W(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "W") == 0) /// Comparar se o operador que a stack recebe é o operador "W"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o W
        {
            if (i == 'W') /// Quando encontra o W
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de W
                return 1;
            }
        }
    }
    if (strcmp(token, ":W") == 0) /// Comparar se o operador que a stack recebe é o operador ":W"
    { 
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o W
        {
            if (i == 'W') /// Quando encontra o W
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no W passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do W passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor;
                push(s, X); /// Envia para a stack o novo valor de W
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável X e com a troca de elemento da variável X.
 * 
 */
int var_X(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "X") == 0) /// Comparar se o operador que a stack recebe é o operador "X"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o X
        {
            if (i == 'X') /// Quando encontra o X
            { 
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X);  /// Envia para a stack o valor de X
                return 1;
            }
        }
    }
    if (strcmp(token, ":X") == 0) /// Comparar se o operador que a stack recebe é o operador ":X"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o X
        {
            if (i == 'X') /// Quando encontra o A
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no X passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do X passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de X
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável Y e com a troca de elemento da variável Y.
 * 
 */
int var_Y(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "Y") == 0) /// Comparar se o operador que a stack recebe é o operador "Y"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Y
        {
            if (i == 'Y') /// Quando encontra o Y
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de Y
                return 1;
            }
        }
    }
    if (strcmp(token, ":Y") == 0) /// Comparar se o operador que a stack recebe é o operador ":Y"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Y
        {
            if (i == 'Y') /// Quando encontra o Y
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no Y passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do Y passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de Y
                return 1;
            }
        }
    }
    return 0;
}
/**
 * Função que trata das operações com a variável Z e com a troca de elemento da variável Z.
 * 
 */
int var_Z(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, "Z") == 0) /// Comparar se o operador que a stack recebe é o operador "Z"
    {
        int pos = 0;
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Z
        { 
            if (i == 'Z') /// Quando encontra o Z
            {
                X.elem = v->varr[pos].elem; /// O elemento do resultado tem de ser igual ao elemento da variável
                X.t = v->varr[pos].t; /// O tipo do resultado tem de ser igual ao tipo da variável
                push(s, X); /// Envia para a stack o valor de Z
                return 1;
            }
        }
    }
    if (strcmp(token, ":Z") == 0) /// Comparar se o operador que a stack recebe é o operador ":Z"
    {
        int pos = 0;
        STACK_ELEM Z = pop(s); /// Pega num elemento 
        STACK_ELEM X; /// Local onde vai ficar guardado o resultado da variável
        for (char i = 'A'; i <= 'Z'; i++, pos++) /// Função que procura o Z
        {
            if (i == 'Z') /// Quando encontra o A
            {
                v->varr[pos].elem = Z.elem; /// O valor guardado no Z passa a ser o elemento de Z
                v->varr[pos].t = Z.t; /// O tipo do Z passa a ser o tipo de Z
                X.elem = v->varr[pos].elem; /// Coloca em X o novo valor
                X.t = v->varr[pos].t; /// O tipo de X tem de ser igual ao do valor
                push(s, X); /// Envia para a stack o novo valor de Z
                return 1; 
            }
        }
    }
    return 0;
}
/**
 * Função que distribui cada token de nome de variável pela sua respetiva função.
 * 
 */
int var_handle(STACK *s, char *token, VAR *v)
{
    if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", *token) != NULL)
    {
        return var_A(s, v, token) || var_B(s, v, token) || var_C(s, v, token) || var_D(s, v, token) || var_E(s, v, token) || var_F(s, v, token) || var_G(s, v, token) || var_H(s, v, token) || var_I(s, v, token) ||
               var_J(s, v, token) || var_K(s, v, token) || var_L(s, v, token) || var_M(s, v, token) || var_N(s, v, token) || var_O(s, v, token) || var_P(s, v, token) || var_Q(s, v, token) || var_R(s, v, token) ||
               var_S(s, v, token) || var_T(s, v, token) || var_U(s, v, token) || var_V(s, v, token) || var_W(s, v, token) || var_X(s, v, token) || var_Y(s, v, token) || var_Z(s, v, token);
    }
    return 0;
}
/**
 * Função que distribui cada token de troca de variável pela sua respetiva função.
 * 
 */
int var_new_handle(STACK *s, char *token, VAR *v)
{
    if (strchr(":A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z", *token) != NULL)
    {
        return var_A(s, v, token) || var_B(s, v, token) || var_C(s, v, token) || var_D(s, v, token) || var_E(s, v, token) || var_F(s, v, token) || var_G(s, v, token) || var_H(s, v, token) || var_I(s, v, token) ||
               var_J(s, v, token) || var_K(s, v, token) || var_L(s, v, token) || var_M(s, v, token) || var_N(s, v, token) || var_O(s, v, token) || var_P(s, v, token) || var_Q(s, v, token) || var_R(s, v, token) ||
               var_S(s, v, token) || var_T(s, v, token) || var_U(s, v, token) || var_V(s, v, token) || var_W(s, v, token) || var_X(s, v, token) || var_Y(s, v, token) || var_Z(s, v, token);
    }
    return 0;
}
