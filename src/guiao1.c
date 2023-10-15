#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao1.h"
/**
 *   Função que adiciona dois elementos.
 *
 */
int soma(STACK *s, char *token)
{
    if (strcmp(token, "+") == 0) /// Comparar se o operador que a stack recebe é o operador "+"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if ((X.t == DBL && Y.t == DBL)) /// Caso onde ambos os elementos são doubles
        {
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            float x = xx.value; /// Conversão através do union do valor guardado em xx de void* para float, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            float y = yy.value; /// Conversão através do union do valor guardado em yy de void* para float, , guardando-o em y
            union void_cast z;
            z.value = x + y; /// Soma entre os valores guardados em x e y, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da soma para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if ((X.t == INT && Y.t != X.t) || (X.t == DBL && Y.t != X.t)) ///Caso os dois valores sejam de tipos diferentes
        {
            if (X.t == INT) /// Caso X seja inteiro
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = (double)xx.ii; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem;  /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z; 
                z.value = x + y; /// Soma dos valores guardados em x e y, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da soma para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
            else /// Caso X seja double
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = (double)yy.ii; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = x + y; /// Soma dos valores guardados em x e y, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da soma para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
        }
        else /// Caso os dois valores sejam inteiros
        {
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
            void *z = (void *)(x + y); /// Soma os dois valores, transformando depois o resultado num void* z
            Z.elem = z; /// Coloca o resultado da soma, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função que subtrai dois elementos.
 *
 */
int sub(STACK *s, char *token)
{
    if (strcmp(token, "-") == 0) /// Comparar se o operador que a stack recebe é o operador "-"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if (X.t == DBL && Y.t == DBL) /// Caso onde ambos os elementos são doubles
        { 
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
            union void_cast z;
            z.value = y - x; /// Subtração do valor guardado em y pelo valor guardado em x, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if ((X.t == INT && Y.t != X.t) || (X.t == DBL && Y.t != X.t)) /// Caso os dois valores sejam de tipos diferentes
        {
            if (X.t == INT) /// Caso X seja inteiro
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = (double)xx.ii; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = y - x; /// Subtração do valor guardado em y pelo valor guardado em x, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
                push(s, Z);  /// Envia o resultado final para a Stack
                return 1;
            }
            else
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = (double)yy.ii; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = y - x; /// Subtração do valor guardado em y pelo valor guardado em x, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
        }
        else /// Caso os dois valores sejam inteiros
        { 
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
            void *z = (void *)(y - x); /// Subtrai y por x, transformando depois o resultado num void* z 
            Z.elem = z; /// Coloca o resultado da subtração, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função que multiplica dois elementos.
 *
 */
int prod(STACK *s, char *token)
{
    if (strcmp(token, "*") == 0) /// Comparar se o operador que a stack recebe é o operador "*"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if (X.t == DBL && Y.t == DBL) /// Caso onde ambos os elementos são doubles
        {
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
            union void_cast z;
            z.value = x * y; /// Multiplicação entre os valores guardados em x e y, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da multiplicação para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if ((X.t == INT && Y.t != X.t) || (X.t == DBL && Y.t != X.t)) ///Caso os dois valores sejam de tipos diferentes
        {
            if (X.t == INT) /// Caso X seja inteiro
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = (double)xx.ii; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = x * y; /// Multiplicação entre os valores guardados em x e y, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da multiplicação para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
            else /// Caso X seja double
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = (double)yy.ii; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = x * y; /// Multiplicação entre os valores guardados em x e y, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da multiplicação para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1; 
            }
        }
        else /// Caso os dois valores sejam inteiros
        {
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
            void *z = (void *)(x * y); /// Multiplica x por y, transformando depois o resultado num void* z 
            Z.elem = z; /// Coloca o resultado da multiplicação, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função que divide dois elementos.
 *
 */
int quo(STACK *s, char *token) 
{
    if (strcmp(token, "/") == 0) /// Comparar se o operador que a stack recebe é o operador "/"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if ((X.t == DBL && Y.t == DBL)) /// Caso onde ambos os elementos são doubles
        {
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
            union void_cast z;
            z.value = y / x; /// Divisão do valor guardado em y pelo valor guardado em x, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if ((X.t == INT && Y.t != X.t) || (X.t == DBL && Y.t != X.t)) /// Caso os dois valores sejam de tipos diferentes
        {
            if (X.t == INT) /// Caso X seja inteiro
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = (double)xx.ii; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = y / x; /// Divisão do valor guardado em y pelo valor guardado em x, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
            else
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = (double)yy.ii; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = y / x; /// Divisão do valor guardado em y pelo valor guardado em x, guardando o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
        } 
        else /// Caso os dois valores sejam inteiros
        {
            Z.t = INT; /// Resultado terá de ser inteiro quando são dois inteiros a dividir
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            int x = xx.ii; /// Conversão através do union do valor guardado em xx de void* para inteiro, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            int y = yy.ii; /// Conversão através do union do valor guardado em yy de void* para inteiro, guardando-o em y
            union void_cast z;
            z.ii = (int)y / x; /// Divisão do valor guardado em y pelo valor guardado em x, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da subtração para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função que incrementa (adicionar um ao elemento, quer seja double, inteiro ou char).
 *
 */
int inc(STACK *s, char *token)
{
    if (strcmp(token, ")") == 0) /// Comparar se o operador que a stack recebe é o operador ")"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento em questão
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if (X.t == DBL) /// Caso o elemento seja double
        {
            Z.t = DBL; ///Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast z;
            z.value = x + 1; /// Adiciona o valor 1 ao valor guardado em x, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do incremento para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if (X.t == CHAR) /// Caso o elemento seja char
        {
            Z.t = CHAR; ///Resultado terá de ser char
            union void_cast u;
            u.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em u
            u.cc = (char)u.ii; /// Conversão através do union do valor guardado em u de void* para char, guardando-o novamente em u
            u.cc = u.cc + 1; /// Adiciona 1 ao char em questão, fazendo-o avançar para o próximo caracter na tabela ASCII
            Z.elem = u.ptr; /// Conversão do incremento para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else
        {
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            void *z = (void *)(x + 1); /// Adiciona o valor 1  ao valor guardado em x, transformando depois o resultado num void* z 
            Z.elem = z; /// Coloca o resultado da incrementação, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função que decrementa (subtrai um ao elemento, quer seja double, inteiro ou char).
 *
 */
int dec(STACK *s, char *token)
{
    if (strcmp(token, "(") == 0) /// Comparar se o operador que a stack recebe é o operador "("
    {
        STACK_ELEM X = pop(s); /// Pega no elemento em questão
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if (X.t == DBL) /// Caso o elemento seja double
        {
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast z;
            z.value = x - 1; /// Subtrai o valor 1 ao valor guardado em x, guardando o resultado em z
            Z.elem = z.ptr; /// Conversão do decremento para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if (X.t == CHAR) /// Caso o elemento seja char
        {
            Z.t = CHAR; /// Resultado terá de ser char
            union void_cast u;
            u.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em u
            u.cc = (char)u.ii; /// Conversão através do union do valor guardado em u de void* para char, guardando-o novamente em u
            u.cc = u.cc - 1; /// Subtrai 1 ao char em questão, fazendo-o regredir para o  caracter anterior na tabela ASCII
            Z.elem = u.ptr; /// Conversão do decremento para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else
        {
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            void *z = (void *)(x - 1); /// Subtrai o valor 1  ao valor guardado em x, transformando depois o resultado num void* z 
            Z.elem = z; /// Coloca o resultado da decrementação, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função módulo. Dá o resto da divisão inteira entre dois inteiros.
 *
 */
int mod(STACK *s, char *token)
{
    if (strcmp(token, "%") == 0) /// Comparar se o operador que a stack recebe é o operador "%"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        Z.t = INT; /// Resultado terá de ser sempre inteiro na função módulo
        size_t x = (int)(size_t)X.elem; /// Conversão do valor X para um size_t e depois para inteiro, guardando-o em x
        size_t y = (int)(size_t)Y.elem; /// Conversão do valor Y para um size_t e depois para inteiro, guardando-o em y
        void *z = (void *)(size_t)(y % x); /// Calcula o resto da divisão entre o y e o x, converte o resultado para size_t e depois para void*
        Z.elem = z; /// Coloca o resultado do resto da divisão, o void* z, no Z
        push(s, Z); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}
/**
 *   Função exponencial. Faz-se y elevado a x.
 *
 */
int pot(STACK *s, char *token)
{
    if (strcmp(token, "#") == 0) /// Comparar se o operador que a stack recebe é o operador "#"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        if (X.t == DBL && Y.t == DBL) /// Caso onde ambos os elementos são doubles
        {
            Z.t = DBL; /// Resultado terá de ser double
            union void_cast xx;
            xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
            double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
            union void_cast yy;
            yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
            double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
            union void_cast z;
            z.value = pow(y, x); /// Faz y elevado a x e guarda o resultado em z
            Z.elem = z.ptr; /// Conversão do resultado da exponencialização para void* e coloca em Z o resultado
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
        else if ((X.t == INT && Y.t != X.t) || (X.t == DBL && Y.t != X.t)) ///Caso os dois valores sejam de tipos diferentes
        {
            if (X.t == INT) /// Caso X seja inteiro
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = (double)xx.ii; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = yy.value; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = pow(y, x); /// Faz y elevado a x e guarda o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da exponencialização para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
            else /// Caso X seja double
            {
                Z.t = DBL; /// Resultado terá de ser double
                union void_cast xx;
                xx.ptr = X.elem; /// Pega no valor que vem de X e coloca-o no union para o converter, guardando-o em xx
                double x = xx.value; /// Conversão através do union do valor guardado em xx de void* para double, guardando-o em x
                union void_cast yy;
                yy.ptr = Y.elem; /// Pega no valor que vem de Y e coloca-o no union para o converter, guardando-o em yy
                double y = (double)yy.ii; /// Conversão através do union do valor guardado em yy de void* para double, guardando-o em y
                union void_cast z;
                z.value = pow(y, x);  /// Faz y elevado a x e guarda o resultado em z
                Z.elem = z.ptr; /// Conversão do resultado da exponencialização para void* e coloca em Z o resultado
                push(s, Z); /// Envia o resultado final para a Stack
                return 1;
            }
        }
        else /// Caso os dois valores sejam inteiros
        {
            Z.t = INT; /// Resultado terá de ser inteiro
            size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
            size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
            void *z = (void *)(size_t)(pow((int)y, (int)x)); /// Faz y elevado a x, converte o resultado para size_t e depois para void*
            Z.elem = z; /// Coloca o resultado da exponencialização, o void* z, no Z
            push(s, Z); /// Envia o resultado final para a Stack
            return 1;
        }
    }
    return 0;
}
/**
 *   Função "e" (bitwise). Comparação das suas representações em binário, através do operador lógico &. Ambos têm de ser verdadeiros para dar 1.
 *
 */
int and (STACK * s, char *token)
{
    if (strcmp(token, "&") == 0) /// Comparar se o operador que a stack recebe é o operador "&"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        Z.t = INT; /// Resultado terá de ser inteiro, porque esta função só funciona para inteiros
        size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
        size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
        void *z = (void *)(size_t)((int)x & (int)y); 
        /// A linha acima converte o x e o y para int, faz a função pré-definida &, converte esse resultado para size_t, deppis para void*, guardando o resultado em z
        Z.elem = z; /// Coloca o resultado da última operação, o void* z, no Z
        push(s, Z); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}
/**
 *   Função "ou" (bitwise). Comparação das suas representações em binário, através do operador lógico |. Basta um ser verdadeiro para dar 1.
 *
 */
int ou(STACK *s, char *token)
{
    if (strcmp(token, "|") == 0) /// Comparar se o operador que a stack recebe é o operador "|"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        Z.t = INT; /// Resultado terá de ser inteiro, porque esta função só funciona para inteiros
        size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
        size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
        void *z = (void *)(size_t)((int)x | (int)y);
        /// A linha acima converte o x e o y para int, faz a função pré-definida |, converte esse resultado para size_t, deppis para void*, guardando o resultado em z
        Z.elem = z; /// Coloca o resultado da última operação, o void* z, no Z
        push(s, Z); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}
/**
 *   Função "xor" (bitwise). Comparação das suas representações em binário, num operador lógico em que apenas um pode ser verdadeiro.
 *
 */
int xor (STACK * s, char *token) 
{
    if (strcmp(token, "^") == 0) /// Comparar se o que a stack recebe operador é o operador "^"
    {
        STACK_ELEM X = pop(s); /// Pega no primeiro elemento
        STACK_ELEM Y = pop(s); /// Pega no segundo elemento
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        Z.t = INT; /// Resultado terá de ser inteiro, porque esta função só funciona para inteiros
        size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
        size_t y = (size_t)Y.elem; /// Conversão do valor Y para um size_t, guardando-o em y
        void *z = (void *)(size_t)((int)x ^ (int)y);
        /// A linha acima converte o x e o y para int, faz a função pré-definida ^, converte esse resultado para size_t, deppis para void*, guardando o resultado em z
        Z.elem = z; /// Coloca o resultado da última operação, o void* z, no Z
        push(s, Z); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}
/**
 * Função "not" (bitwise). Inverte os bits na sua representação binária.
 *
 */
int not(STACK * s, char *token)
{
    if (strcmp(token, "~") == 0) /// Comparar se o que a stack recebe operador é o operador "~"
    {
        STACK_ELEM X = pop(s); /// Pega no elemento em questão
        STACK_ELEM Z; /// Local onde vai ficar guardado o resultado final
        Z.t = INT; /// Resultado terá de ser inteiro, porque esta função só funciona para inteiros
        size_t x = (size_t)X.elem; /// Conversão do valor X para um size_t, guardando-o em x
        void *z = (void *)(size_t) ~(int)x;
        /// A linha acima converte o x e o y para int, faz a função pré-definida ~, converte esse resultado para size_t, deppis para void*, guardando o resultado em z
        Z.elem = z; /// Coloca o resultado da última operação, o void* z, no Z
        push(s, Z); /// Envia o resultado final para a Stack
        return 1;
    }
    return 0;
}