#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao3.h"

/**
 * Função que se o último elemento obtido for 0 dá return ao primeiro lido senão dá ao segundo
 *
 */
int elif (STACK *s, char *token)
{
    if (strcmp(token, "?") == 0) /// Comparar se o operador que a stack recebe é o operador "?"
    {
        STACK_ELEM Z = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM X = pop(s); /// Pega no terceiro elemento
        if (X.t == INT)        /// Se o X for inteiro
        {
            if ((int)(size_t)X.elem >= 1) /// Depois de converter X para size_t e depois para int, vê se X é maior ou igual a 1
            {
                push(s, Y); /// Se for envia para a stack o segundo elemento lido
                return 1;
            }
            else
            {
                push(s, Z); /// Senão envia para a stack o primeiro elemento lido
                return 1;
            }
        }
        if (X.t == DBL) /// Se o X for double
        {
            if ((double)(size_t)X.elem >= 1) /// Depois de converter X para size_t e depois para double, vê se X é maior ou igual a 1
            {
                push(s, Y); /// Se for envia para a stack o segundo elemento lido
                return 1;
            }
            else
            {
                push(s, Z); /// Senão envia para a stack o primeiro elemento lido
                return 1;
            }
        }
        if (X.t == CHAR) /// Se o X for char
        {
            if ((char)(size_t)X.elem >= 1) /// Depois de converter X para size_t e depois para char, vê se X é maior ou igual a 1
            {
                push(s, Y); /// Se for envia para a stack o segundo elemento lido
                return 1;
            }
            else
            {
                push(s, Z); /// Senão envia para a stack o primeiro elemento lido
                return 1;
            }
        }
        if (X.t == STR) /// Se o X for uma string
        {
            char *a = (char *)X.elem; /// Guarda em *a a string
            if (strlen(a) == 0)       /// Se a string for vazia
            {
                push(s, Z); /// Envia para a stack o primeiro elemento lido
                return 1;
            }
            else
            {
                push(s, Y); /// Senão envia para a stack o segundo elemento lido
                return 1;
            }
        }
        if (X.t == ARR) /// Se o X for um array
        {
            STACK_ELEM *arr = (STACK_ELEM *)X.elem; /// Guarda em *arr o array
            if ((int)(size_t)arr[0].elem == 0)      /// Se o primeiro elemento do array for zero
            {
                push(s, Z); /// Envia para a stack o primeiro elemento lido
                return 1;
            }
            else
            {
                push(s, Y); /// Senão envia para a stack o segundo elemento lido
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Função que compara dois elementos e vê se são iguais e devolve 1 se forem e 0 se não forem
 *
 */
int equal(STACK *s, char *token)
{
    if (strcmp(token, "=") == 0) /// Comparar se o operador que a stack recebe é o operador "="
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z;          /// Local onde vai ficar guardado o resultado
        Z.t = INT;             /// Visto que o resultado é sempre 0 ou 1, o tipo dele tem de ser inteiro
        union void_cast u;
        u.ptr = X.elem; /// Guarda em u o elemento de X
        union void_cast v;
        v.ptr = Y.elem; /// Guarda em v o elemento de Y
        if (X.t == INT) /// Se o X for um inteiro
        {
            if (Y.t == DBL) /// Se o Y for um double
            {
                if ((double)u.ii == v.value) /// Converte u para double e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se o Y for um char
            {
                if (u.ii == (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else /// Se o Y for um inteiro
            {
                if (u.ii == v.ii) /// Como são do mesmo tipo, simplesmente compara-os
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        if (X.t == DBL) /// Se o X for um double
        {
            if (Y.t == INT) /// Se o Y for um inteiro
            {
                if (u.value == (double)v.ii) /// Converte v para double e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se o Y for um char
            {
                if (u.value == (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else /// Se o Y for um double
            {
                if (u.value == v.value) /// Como são do mesmo tipo, simplesmente compara-os
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        if (X.t == CHAR) /// Se o X for um char
        {
            if (Y.t == INT) /// Se o Y for um inteiro
            {
                if ((int)u.cc == v.ii) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se o Y for um double
            {
                if ((int)u.cc == v.value) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se o Y for um char
            {
                if ((int)u.cc == (int)v.cc) /// Converte ambos para inteiros e compara-os
                {
                    Z.elem = (void *)(size_t)1; /// Se eles forem iguais, converte 1 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se não forem iguais, converte 0 para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        if ((X.t == STR && Y.t == STR)) /// Se X e Y forem strings
        {
            char *a = (char *)X.elem;   /// Guarda em *a a string
            char *b = (char *)Y.elem;   /// Guarda em *b a string
            if (strlen(a) != strlen(b)) /// Se o tamanho delas for diferente
            {
                Z.elem = (void *)(size_t)0; /// É impossível serem iguais logo converte 0 para size_t e depois para void*
                push(s, Z);                 /// E envia o resultado para a stack
                return 1;
            }
            for (long unsigned int i = 0; i < strlen(a); i++) /// Vai correr todos os elementos das strings
            {
                if (a[i] != b[i]) /// Se encontrar um elemento entre as strings que seja diferente
                {
                    Z.elem = (void *)(size_t)0; /// Converte 0 para size_t e depois para void*
                    push(s, Z);                 /// E envia o resultado para a stack
                    return 1;
                }
            }
            Z.elem = (void *)(size_t)1; /// Se chegar aqui significa que as strings são iguais logo converte 1 para size_t e depois para void*
            push(s, Z);                 /// E envia o resultado para a stack
            return 1;
        }
        if (X.t == ARR && Y.t == ARR) /// Se X e Y forem arrays
        {
            STACK_ELEM *arr1 = (STACK_ELEM *)X.elem;                    /// Guarda em *arr1 o array
            STACK_ELEM *arr2 = (STACK_ELEM *)Y.elem;                    /// Guarda em *arr2 o array
            if ((int)(size_t)arr1[0].elem != (int)(size_t)arr2[0].elem) /// Se o tamanho dos arrays for diferente
            {
                Z.elem = (void *)(size_t)0; /// É impossível serem iguais logo converte 0 para size_t e depois para void*
                push(s, Z);                 /// E envia o resultado para a stack
                return 1;
            }
            else
            {
                for (int i = 1; i <= (int)(size_t)arr1[0].elem; i++) /// Vai correr todos os elementos dos arrays
                {
                    if (arr1[i].t != arr2[i].t || arr1[i].elem != arr2[i].elem) /// Se encontrar um elemento entre as strings que seja diferente, quer o elemento ou o tipo
                    {
                        Z.elem = (void *)(size_t)0; /// Converte 0 para size_t e depois para void*
                        push(s, Z);                 /// E envia o resultado para a stack
                        return 1;
                    }
                }
                Z.elem = (void *)(size_t)1; /// Se chegar aqui significa que os arrays são iguais logo converte 1 para size_t e depois para void*
                push(s, Z);                 /// Envia o resultado para a stack
                return 1;
            }
        }

        if ((X.t == ARR || X.t == STR) && Y.t != X.t) /// Se X for array ou string e Y não for do mesmo tipo
        {
            Z.elem = (void *)(size_t)0; /// Como não são iguais, converte 0 para size_t e depois para void*
            push(s, Z);                 /// Envia o resultado para a stack
            return 1;
        }
    }
    return 0;
}

/**
 * Função que compara dois elementos e que se o segundo elemento lido for maior que o primeiro devolve 1 senão devolve 0
 *
 */
int maior(STACK *s, char *token)
{
    if (strcmp(token, ">") == 0) /// Comparar se o operador que a stack recebe é o operador ">"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z;          /// Local onde vai ficar guardado o resultado
        Z.t = INT;             /// Visto que o resultado é sempre 0 ou 1, o tipo dele tem de ser inteiro
        union void_cast u;
        u.ptr = X.elem; /// Guarda em u o elemento de X
        union void_cast v;
        v.ptr = Y.elem;               /// Guarda em v o elemento de Y
        if (X.t == INT && Y.t != X.t) /// Se X for inteiro e o Y não for do mesmo tipo
        {
            if (Y.t == DBL) /// Se Y for double
            {
                if ((double)u.ii < v.value) /// Converte u para double e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (u.ii < (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        if (X.t == DBL && Y.t != X.t) /// Se X for double e o Y não for do mesmo tipo
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (u.value < (double)v.ii) /// Converte v para double e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (u.value < (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        if (X.t == CHAR && Y.t != X.t) /// Se X for char e o Y não for do mesmo tipo
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if ((int)u.cc < v.ii) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if ((int)u.cc < v.value) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        else if ((X.t == INT && Y.t == X.t) || (X.t == DBL && Y.t == X.t) || (X.t == CHAR && Y.t == X.t)) /// Se X e Y forem do mesmo tipo
        {
            if (X.t == CHAR) /// Se X for char
            {
                if ((int)u.cc < (int)v.cc) /// Converte u e v para inteiros e compara-os
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else if (X.t == INT) /// Se X for inteiro
            {
                if (u.ii < v.ii) /// Simplesmente compara u e v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else if (X.t == DBL) /// Se X for double
            {
                if (u.value < v.value) /// SImplesmente compara u e v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é maior que u(primeiro elemento) devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é maior que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        /// NÃO DOCUMENTEI
        else if ((X.t == ARR || X.t == STR) && (Y.t == ARR || Y.t == STR))
        {
            char *a = (char *)X.elem;
            char *b = (char *)Y.elem;
            if (strlen(b) > strlen(a))
            {
                Z.elem = (void *)(size_t)1;
                push(s, Z);
                return 1;
            }
            else if (strlen(b) < strlen(a))
            {
                Z.elem = (void *)(size_t)0;
                push(s, Z);
                return 1;
            }
            else
            {
                if (X.t == Y.t)
                {
                    for (long unsigned int i = 0; i < strlen(a); i++)
                    {
                        if (a[i] > b[i])
                        {
                            Z.elem = (void *)(size_t)0;
                            push(s, Z);
                            return 1;
                        }
                        else if (a[i] < b[i])
                        {
                            Z.elem = (void *)(size_t)1;
                            push(s, Z);
                            return 1;
                        }
                    }
                }
                Z.elem = (void *)(size_t)0;
                push(s, Z);
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Função que compara dois elementos e que se o segundo elemento lido for menor que o primeiro devolve 1 senão devolve 0
 *
 */
int menor(STACK *s, char *token)
{
    if (strcmp(token, "<") == 0) /// Comparar se o operador que a stack recebe é o operador "<"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z;          /// Local onde vai ficar guardado o resultado
        Z.t = INT;             /// Visto que o resultado é sempre 0 ou 1, o tipo dele tem de ser inteiro
        union void_cast u;
        u.ptr = X.elem; /// Guarda em u o elemento de X
        union void_cast v;
        v.ptr = Y.elem;               /// Guarda em v o elemento de Y
        if (X.t == INT && Y.t != X.t) /// Se X for inteiro e o Y não for do mesmo tipo
        {
            if (Y.t == DBL) /// Se Y for double
            {
                if ((double)u.ii > v.value) /// Converte u para double e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (u.ii > (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        else if (X.t == DBL && Y.t != X.t) /// Se X for double e o Y não for do mesmo tipo
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (u.value > (double)v.ii) /// Converte v para double e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (u.value > (int)v.cc) /// Converte v para inteiro e compara-o a u
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        else if (X.t == CHAR && Y.t != X.t) /// Se X for char e o Y não for do mesmo tipo
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if ((int)u.cc > v.ii) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if ((int)u.cc > v.value) /// Converte u para inteiro e compara-o a v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        else if ((X.t == INT && Y.t == X.t) || (X.t == DBL && Y.t == X.t) || (X.t == CHAR && Y.t == X.t)) /// Se X e Y forem do mesmo tipo
        {
            if (X.t == CHAR) /// Se X for char
            {
                if ((int)u.cc > (int)v.cc) /// Converte u e v para inteiros e compara-os
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else if (X.t == INT) /// Se X for inteiro
            {
                if (u.ii > v.ii) /// Simplesmente compara u e v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
            else if (X.t == DBL) /// Se X for double
            {
                if (u.value > v.value) /// SImplesmente compara u e v
                {
                    Z.elem = (void *)(size_t)1; /// Como v(segundo elemento) é menor que u(primeiro elemento), devolve 1, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
                else
                {
                    Z.elem = (void *)(size_t)0; /// Se v não é menor que u, devolve 0, depois de o converter para size_t e depois para void*
                    push(s, Z);                 /// Envia o resultado para a stack
                    return 1;
                }
            }
        }
        /// NÃO DOCUMENTEI
        else if ((X.t == ARR || X.t == STR) && (Y.t == ARR || Y.t == STR))
        {
            char *a = (char *)X.elem;
            char *b = (char *)Y.elem;
            if (strlen(b) < strlen(a))
            {
                Z.elem = (void *)(size_t)1;
                push(s, Z);
                return 1;
            }
            else if (strlen(b) > strlen(a))
            {
                Z.elem = (void *)(size_t)0;
                push(s, Z);
                return 1;
            }
            else
            {
                if (X.t == Y.t)
                {
                    for (long unsigned int i = 0; i < strlen(a); i++)
                    {
                        if (a[i] < b[i])
                        {
                            Z.elem = (void *)(size_t)0;
                            push(s, Z);
                            return 1;
                        }
                        else if (a[i] > b[i])
                        {
                            Z.elem = (void *)(size_t)1;
                            push(s, Z);
                            return 1;
                        }
                    }
                }
                Z.elem = (void *)(size_t)0;
                push(s, Z);
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Função que pega num elemento se ele for 0 devolve 1 senão devolve sempre 0
 *
 */
int nott(STACK *s, char *token)
{
    if (strcmp(token, "!") == 0) /// Comparar se o operador que a stack recebe é o operador "!"
    {
        STACK_ELEM X = pop(s); /// Pega num elemento
        STACK_ELEM Y;          /// Local onde vai ficar guardado o resultado
        Y.t = INT;             /// Visto que o resultado é sempre 0 ou 1, o tipo dele tem de ser inteiro
        if (X.t == INT)        /// Se X for inteiro
        {
            if ((int)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para int e se este for igual a 0
            {
                Y.elem = (void *)(size_t)1; /// A resposta terá de ser 1, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
            else
            {
                Y.elem = (void *)(size_t)0; /// Senão a resposta é 0, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
        }
        if (X.t == DBL) /// Se X for double
        {
            if ((double)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para double e se este for igual a 0
            {
                Y.elem = (void *)(size_t)1; /// A resposta terá de ser 1, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
            else
            {
                Y.elem = (void *)(size_t)0; /// Senão a resposta é 0, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
        }
        if (X.t == CHAR) /// Se X for char
        {
            if ((int)(char)(size_t)X.elem == 0) /// Converte o elemento de X para size_t, depois para char e no fim para inteiro e se este for igual a 0
            {
                Y.elem = (void *)(size_t)1; /// A resposta terá de ser 1, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
            else
            {
                Y.elem = (void *)(size_t)0; /// Senão a resposta é 0, convertendo assim esse valor para size_t e depois para void*
                push(s, Y);                 /// Envia o resultado para a stack
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Função que ao contrário da menor em vez de devolver 0 ou 1, devolve o menor elemento dos dois elementos
 *
 */
int emenor(STACK *s, char *token)
{
    if (strcmp(token, "e<") == 0) /// Comparar se o operador que a stack recebe é o operador "e<"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        union void_cast x;
        union void_cast y;
        x.ptr = X.elem; /// Guarda em x o elemento de X
        y.ptr = Y.elem; /// Guarda em y o elemento de Y
        if (X.t == INT) /// Se X for inteiro
        {
            if (Y.t == DBL) /// Se Y for double
            {
                if ((double)x.ii < y.value) /// Converte x para double e compara-o com y
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.ii < (int)y.cc) /// Converte y para inteiro e compara-o com x
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (x.ii < y.ii) /// Compara x e y
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        if (X.t == DBL) /// Se X for double
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (x.value < (double)y.ii) /// Converte y para double e compara-os
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.value < (int)y.cc) /// Converte y para inteiro e compara-os
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if (x.value < y.value) /// Compara x com y
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        if (X.t == CHAR) /// Se X for char
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if ((int)x.cc < y.ii) /// Converte x para inteiro e compara-os
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if ((int)x.cc < y.value) /// Converte x para inteiro e compara-os
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.cc < y.cc) /// Compara x e y
                {
                    push(s, X); /// Se x é menor que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        /// NÃO DOCUMENTEI
        else if ((X.t == ARR || X.t == STR) && (Y.t == ARR || Y.t == STR))
        {
            char *a = (char *)X.elem;
            char *b = (char *)Y.elem;
            if (strlen(b) < strlen(a))
            {
                push(s, Y);
                return 1;
            }
            else if (strlen(b) > strlen(a))
            {
                push(s, X);
                return 1;
            }
            else
            {
                if (X.t == Y.t)
                {
                    for (long unsigned int i = 0; i < strlen(a); i++)
                    {
                        if (a[i] < b[i])
                        {
                            push(s, X);
                            return 1;
                        }
                        else if (a[i] > b[i])
                        {
                            push(s, Y);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/**
 * Função que ao contrário da maior em vez de devolver 0 ou 1, devolve o maior elemento dos dois elementos
 *
 */
int emaior(STACK *s, char *token)
{
    if (strcmp(token, "e>") == 0) /// Comparar se o operador que a stack recebe é o operador "e>"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        union void_cast x;
        union void_cast y;
        x.ptr = X.elem; /// Guarda em x o elemento de X
        y.ptr = Y.elem; /// Guarda em y o elemento de Y
        if (X.t == INT) /// Se X for inteiro
        {
            if (Y.t == DBL) /// Se Y for double
            {
                if ((double)x.ii > y.value) /// Converte x para double e compara com y
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.ii > (int)y.cc) /// Converte y para inteiro e compara-os
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (x.ii > y.ii) /// Compara x e y
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        if (X.t == DBL) /// Se X for double
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if (x.value > (double)y.ii) /// Converte y para double e compara-os
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.value > (int)y.cc) /// Converte y para inteiro e compara-os
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if (x.value > y.value) /// Compara x e y
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        if (X.t == CHAR) /// Se X for char
        {
            if (Y.t == INT) /// Se Y for inteiro
            {
                if ((int)x.cc > y.ii) /// Converte x para inteiro e compara-os
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == DBL) /// Se Y for double
            {
                if ((int)x.cc > y.value) /// Converte x para inteiro e compara-os
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
            if (Y.t == CHAR) /// Se Y for char
            {
                if (x.cc > y.cc) /// Compara x e y
                {
                    push(s, X); /// Se x é maior que y, então o valor a ser enviado para a stack é o X
                    return 1;
                }
                else
                {
                    push(s, Y); /// Senão é o Y
                    return 1;
                }
            }
        }
        /// NÃO DOCUMENTEI
        else if ((X.t == ARR || X.t == STR) && (Y.t == ARR || Y.t == STR))
        {
            char *a = (char *)X.elem;
            char *b = (char *)Y.elem;
            if (strlen(b) > strlen(a))
            {
                push(s, Y);
                return 1;
            }
            else if (strlen(b) < strlen(a))
            {
                push(s, X);
                return 1;
            }
            else
            {
                if (X.t == Y.t)
                {
                    for (long unsigned int i = 0; i < strlen(a); i++)
                    {
                        if (a[i] > b[i])
                        {
                            push(s, X);
                            return 1;
                        }
                        else if (a[i] < b[i])
                        {
                            push(s, Y);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/**
 * Função que pega em dois elementos e que se o segundo elemento lido for 0 devolve o segundo elemento, senão devolve o primeiro elemento lido
 *
 */
int eand(STACK *s, char *token)
{
    if (strcmp(token, "e&") == 0) /// Comparar se o operador que a stack recebe é o operador "e&"
    {
        STACK_ELEM Y = pop(s); /// Pega no primeiro elemento
        STACK_ELEM X = pop(s); /// Pega no segundo elemento
        if (X.t == INT)        /// Se X for inteiro
        {
            if ((int)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para int e se este for igual a 0
            {
                push(s, X); /// O resultado terá de ser X, neste caso 0, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, Y); /// Caso contrário, o resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
        }
        if (X.t == CHAR) /// Se X for char
        {
            if ((int)(char)(size_t)X.elem == 0) /// Converte o elemento de X para size_t, depois para char e depois para int e se este for igual a 0
            {
                push(s, X); /// O resultado terá de ser X, neste caso 0, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, Y); /// Caso contrário, o resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
        }
        if (X.t == DBL) /// Se X for double
        {
            if ((double)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para double e se este for igual a 0
            {
                push(s, X); /// O resultado terá de ser X, neste caso 0, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, Y); /// Caso contrário, o resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
        }
        if (X.t == ARR || X.t == STR) /// Se X for array ou string
        {
            char *a = (char *)X.elem; /// Guarda em *a o array/string
            if (strlen(a) == 0)       /// Se o array/string for vazio
            {
                push(s, X); /// O resultado terá de ser X, neste caso 0, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, Y); /// Caso contrário, o resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Função que pega em dois elementos e que se o segundo elemento lido for 0 o primeiro elemento, senão devolve o segundo elemento lido
 *
 */
int eou(STACK *s, char *token)
{
    if (strcmp(token, "e|") == 0) /// Comparar se o operador que a stack recebe é o operador "e|"
    {
        STACK_ELEM Y = pop(s); /// Pega no primeiro elemento
        STACK_ELEM X = pop(s); /// Pega no segundo elemento
        if (X.t == INT)        /// Se X for inteiro
        {
            if ((int)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para int e se este for igual a 0
            {
                push(s, Y); /// O resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, X); /// Senão tem de mandar o X para a stack
                return 1;
            }
        }
        if (X.t == CHAR) /// Se X for char
        {
            if ((int)(char)(size_t)X.elem == 0) /// Converte o elemento de X para size_t, depois para char e depois para int e se este for igual a 0
            {
                push(s, Y); /// O resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, X); /// Senão tem de mandar o X para a stack
                return 1;
            }
        }
        if (X.t == DBL) /// Se X for double
        {
            if ((double)(size_t)X.elem == 0) /// Converte o elemento de X para size_t e depois para double e se este for igual a 0
            {
                push(s, Y); /// O resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, X); /// Senão tem de mandar o X para a stack
                return 1;
            }
        }
        if (X.t == ARR || X.t == STR) /// Se X for array/string
        {
            char *a = (char *)X.elem; /// Guarda em *a o array/string
            if (strlen(a) == 0)       /// Se o array/string for vazio
            {
                push(s, Y); /// O resultado terá de ser Y, sendo este enviado para a stack
                return 1;
            }
            else
            {
                push(s, X); /// Senão tem de mandar o X para a stack
                return 1;
            }
        }
    }
    return 0;
}