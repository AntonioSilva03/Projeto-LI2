#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao2.h"

/**
 * Função que pega num elemento e coloca-o no topo da stack
 *
 */
int topo(STACK *s, char *token)
{
    if (strcmp(token, "$") == 0) /// Comparar se o operador que a stack recebe é o operador "$"
    {
        STACK_ELEM A = pop(s); /// Pega no elemento que vai ser o endereço do elemento a colocar no topo da stack
        int arg = (int)(size_t)A.elem; /// Converte esse elemento para size_t e depois para inteiro
        STACK_ELEM subb = s->st[(s->sp) - arg]; /// Procura o elemento em questão e depois pega nele sem retirá-lo da stack, ou seja, sem lhe dar pop
        push(s, subb); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}

/**
 * Função que troca a posição entre os dois  elementos no topo da Stack
 * 
 */
int trocar(STACK *s, char *token)
{
    if (strcmp(token, "\\") == 0) /// Comparar se o operador que a stack recebe é o operador "\"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        push(s, X); /// Envia o primeiro elemento lido para a Stack
        push(s, Y); /// Envia o segundo elemento lido para a Stack, trocando-lhes assim a posição
        return 1;
    }
    return 0;
}

/**
 * Função que roda os três elementos no topo da Stack
 * 
 */
int rodar(STACK *s, char *token)
{
    if (strcmp(token, "@") == 0) /// Comparar se o operador que a stack recebe é o operador "@"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento lido
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento lido
        STACK_ELEM Z = pop(s); /// Pega no terceiro elemento lido
        push(s, Y); /// Envia o segundo elemento lido para a Stack
        push(s, X); /// Envia o primeiro elemento lido para a Stack
        push(s, Z); /// Envia o terceiro elemento lido para a Stack
        return 1;
    }
    return 0;
}

/**
 * Função que retira o primeiro elemento lida da stack
 * 
 */
int popp(STACK *s, char *token)
{
    if (strcmp(token, ";") == 0) /// Comparar se o operador que a stack recebe é o operador ";"
    {
        pop(s); /// Pega no primeiro elemento lido retirando-o da stack
        return 1;
    }
    return 0;
}

/**
 * Função que duplica um elemento
 * 
 */
int duplicar(STACK *s, char *token)
{
    if (strcmp(token, "_") == 0) /// Comparar se o operador que a stack recebe é o operador "_"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento
        push(s, X); /// Envia o elemento 
        push(s, X); /// Envia o elemento novamente duplicando-o
        return 1;
    }
    return 0;
}

/**
 * Função que converte um elemento para char
 * 
 */
int toChar(STACK *s, char *token)
{
    if (strcmp(token, "c") == 0) /// Comparar se o operador que a stack recebe é o operador "c"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento
        X.t = CHAR; /// Resultado terá de ser char
        push(s, X); /// Envia o resultado convertendo-o pelo caminho
        return 1;
    }
    return 0;
}

/**
 * Função que converte um elemento para double
 * 
 */
int toFloat(STACK *s, char *token)
{
    if (strcmp(token, "f") == 0) /// Comparar se o operador que a stack recebe é o operador "f"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento
        union void_cast u;
        u.ptr = X.elem;  /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em u
        if (X.t == DBL) /// Se o X for double
        {
            push(s, X); /// Envia o resultado para a Stack
            return 1;
        }
        else
        {
            X.t = DBL; /// Resultado terá de ser Double
            u.value = (double)u.ii; /// Converte o resultado guardado em u para double
            X.elem = u.ptr; /// Guarda em X o valor que estava em u
            push(s, X); /// Envia o resultado para a Stack
            return 1;
        }
    }
    return 0;
}

/**
 * Função que converte um elemento para uma string
 * 
 */
int toString(STACK *s, char *token) 
{
    if (strcmp(token, "s") == 0) /// Comparar se o operador que a stack recebe é o operador "s"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento
        X.t = STR; /// O resultado terá de ser string
        push(s, X); /// Envia o resultado convertendo-o pelo caminho
        return 1;
    }
    return 0;
}

/**
 * Função que converte um elemento para inteiro
 * 
 */
int toInt(STACK *s, char *token)
{
    if (strcmp(token, "i") == 0) /// Comparar se o operador que a stack recebe é o operador "i"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento
        union void_cast u;
        u.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em u
        if (X.t == INT) /// Se o X for inteiro
        {
            X.t = INT; /// Resultado terá de ser inteiro
            push(s, X); /// Envia o resultado
            return 1;
        }
        else if (X.t == DBL) /// Se o X for double
        {
            X.t = INT; /// Resultado terá de ser inteiro
            u.ii = (int)(size_t)u.value; /// Converte o elemento em u para size_t e depois para inteiro
            X.elem = u.ptr; /// Guarda em X o valor que estava em u
            push(s, X); /// Envia o resultado
            return 1;
        }
        else /// Se o X for char
        {
            X.t = INT; /// Resultado terá de ser inteiro
            X.elem = (void *)(size_t)(int)(char)(size_t)X.elem; /// Converte o elemento em X para size_t, depois para char, depois para inteiro, depois para size_t e o fim para void*
            push(s, X); /// Envia o resultado
            return 1;
        }
    }
    return 0;
}