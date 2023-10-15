#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao1.h"
#include "guiao2.h"
#include "guiao3.h"
#include "guiao4.h"
#include "guiao5.h"
#include "variaveis.h"
#include "overloading.h"
/**
 * Função que analiza o contexto em que o operador "*" está a ser utilizado.
 * 
 */
int staroverload(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "*") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que pelo menos um dos elementos é array ou string e o segundo elemento não e um bloco, a função aplicada e a de multiplicação de arrays.
        if (((X.t == ARR || X.t == STR) || (Y.t == ARR || Y.t == STR)) && X.t != BLK)
        {
            return multArray(s, token);
        }
        /// Caso em que o segundo elemento e um bloco, a função aplicada e a de fold a um array usando um bloco.
        else if (X.t == BLK)
        {
            return foldr(s, token, v);
        }
        /// Qualquer outro caso, especialmente envolvendo números simples, a função aplicada e a do produto.
        else
        {
            return prod(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "+" está a ser utilizado.
 * 
 */
int plusoverload(STACK *s, char *token)
{
    if (strcmp(token, "+") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que pelo menos um dos elementos e array ou string.
        if ((X.t == ARR || X.t == STR) || (Y.t == ARR || Y.t == STR))
        {
            return concatArray(s, token);
        }
        /// Qualquer outro caso, efetua a soma dos elementos.
        else
        {
            return soma(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "=" está a ser utilizado.
 * 
 */
int equaloverload(STACK *s, char *token)
{
    if (strcmp(token, "=") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que um e um só dos elementos e array ou string.
        if (((X.t == ARR || X.t == STR) && (Y.t != ARR && Y.t != STR)) || ((Y.t == ARR || Y.t == STR) && (X.t != ARR && X.t != STR)))
        {
            return indice(s, token);
        }
        /// Qualquer outro caso, envia para a função lógica.
        else
        {
            return equal(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "~" está a ser utilizado.
 * 
 */
int tiloverload(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "~") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        /// Caso em que o elemento é um array ou string, a função aplicada e a de colocar todos os elementos do array ou string na stack.
        if (X.t == ARR || X.t == STR)
        {
            return coloca(s, token);
        }
        /// Se o elemento for um bloco, é aplicada a função que executa o bloco.
        else if (X.t == BLK)
        {
            return execbloco(s, token, v);
        }
        /// Em qualquer outro caso, a função aplicada e a função lógica "not".
        else
        {
            return not(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "<" está a ser utilizado.
 * 
 */
int menoroverload(STACK *s, char *token)
{
    if (strcmp(token, "<") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que o segundo elemento e um inteiro, a função a ser aplicada e a que busca os primeiros n termos de um array ou string.
        if ((X.t == INT) && (Y.t == ARR || Y.t == STR))
        {
            return buscainicio(s, token);
        }
        /// Qualquer outro caso, a função a ser aplicada e a de comparação (menor).
        else
        {
            return menor(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador ">" está a ser utilizado.
 * 
 */
int maioroverload(STACK *s, char *token)
{
    if (strcmp(token, ">") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que o segundo elemento e um inteiro, a função a ser aplicada e a que busca os ultimos n termos de um array ou string.
        if ((X.t == INT) && (Y.t == ARR || Y.t == STR))
        {
            return buscafim(s, token);
        }
        /// Qualquer outro caso, a função a ser aplicada e a de comparação (maior).
        else
        {
            return maior(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "(" está a ser utilizado.
 * 
 */
int openbracketsoverload(STACK *s, char *token)
{
    if (strcmp(token, "(") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        /// Caso o elemento seja um array ou string, a função a ser aplcada e a que retira o primeiro elemento do array ou string.
        if (X.t == ARR || X.t == STR)
        {
            return tirainicio(s, token);
        }
        /// Caso contrário a função a ser aplicada e a função que decrementa um valor ao elemento.
        else
        {
            return dec(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador ")" está a ser utilizado.
 * 
 */
int closebracketsoverload(STACK *s, char *token)
{
    if (strcmp(token, ")") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        /// Caso o elemento seja um array ou string, a função a ser aplcada e a que retira o ultimo elemento do array ou string.
        if (X.t == ARR || X.t == STR)
        {
            return tirafin(s, token);
        }
        /// Caso contrário a função a ser aplicada e a função que incrementa um valor ao elemento.
        else
        {
            return inc(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "#" está a ser utilizado.
 * 
 */
int hashtagoverload(STACK *s, char *token)
{
    if (strcmp(token, "#") == 0) 
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso os dois elementos sejam strings, a função a ser aplicada e a finder, sendo a primeira string a principal e a segunda a substring.
        if (X.t == STR && Y.t == STR)
        {
            return finder(s, token);
        }
        /// Em qualquer outro caso a função a ser aplicada e a função potência.
        else
        {
            return pot(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "/" está a ser utilizado.
 * 
 */
int slashoverload(STACK *s, char *token)
{
    if (strcmp(token, "/") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        STACK_ELEM Y = s->st[(s->sp) - 1];
        /// Caso em que os dois elementos são strings, a função a ser aplicada e a substring.
        if (X.t == STR && Y.t == STR)
        {
            return substring(s, token);
        }
        /// Qualquer outro caso, a função aplicada e a quociente.
        else
        {
            return quo(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "%" está a ser utilizado.
 * 
 */
int percentoverload(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "%") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        /// Caso em que o elemento e um bloco, a função aplicada e a que executa um bloco a um array.
        if (X.t == BLK)
        {
            return arraybloco(s, token, v);
        }
        /// Em qualquer outro caso a função aplicada e a mod.
        else
        {
            return mod(s, token);
        }
    }
    return 0;
}
/**
 * Função que analiza o contexto em que o operador "," está a ser utilizado.
 * 
 */
int commaoverloading(STACK *s, char *token)
{
    if (strcmp(token, ",") == 0)
    {
        STACK_ELEM X = s->st[s->sp];
        /// Caso o elemento seja um bloco, a função a ser aplicada e a filter que filtra um array usando um bloco.
        if (X.t == BLK)
        {
            return filter(s, token);
        }
        /// Em qualquer outro caso a função aplicada e a size.
        else
        {
            return size(s, token);
        }
    }
    return 0;
}