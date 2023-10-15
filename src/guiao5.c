#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao5.h"
#include "variaveis.h"

/**
 * Função que inverte uma string.
 *
 */
char *inverteString(char *arr, int a)
{
    int i;
    char aux;
    /// Este ciclo 'for' corre a string até metade e troca o elemento da posição i com o elemento da posição i a contar do fim.
    for (i = 0; i < a / 2; i++)
    {
        aux = arr[(a - 1) - i];
        arr[(a - 1) - i] = arr[i];
        arr[i] = aux;
    }
    return arr;
}
/**
 * Função que prepara o bloco criado na main para ser enviado para a stack.+
 *
 */
int createblock(STACK *s, char *bloco)
{
    STACK_ELEM X;
    /// Criação da variável do tipo bloco para ser enviado para a stack.
    X.t = BLK;
    X.elem = (void *)bloco;
    push(s, X);
    return 1;
}
/**
 * Função que executa um bloco.
 *
 */
int execbloco(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "~") == 0)
    {
        STACK_ELEM X = pop(s);
        char *bloco = (char *)X.elem;
        char token[BUFSIZ];
        /// Ciclo que corre o bloco convertido para string. Como, por causa do imput, os tokens estão separados por espaços em branco, o ciclo avança de 2 em 2.
        for (unsigned long int i = 2; i < strlen(bloco) - 2; i += 2)
        {
            sscanf(&bloco[i], "%s", token); /// Coloca cada token individualmente numa string.
            handle(s, token, v, 0);         /// Injeta todos os tokens na handle pela ordem que aparecem no bloco.
        }
        return 1;
    }
    return 0;
}
/**
 * Função que executa um bloco a cada elemento de um array ou string.
 *
 */
int arraybloco(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "%") == 0)
    {
        STACK_ELEM bloco = pop(s);
        char *blocoo = (char *)bloco.elem;
        char tokenn[BUFSIZ];
        STACK_ELEM arr = pop(s);
        /// Caso em que o elemento que vai ser operado e um array.
        if (arr.t == ARR)
        {
            STACK_ELEM *arrr = (STACK_ELEM *)arr.elem;
            handle(s, "[", v, 0); /// Envia um parêntises para delimitar o array final na stack.
            /// Ciclo que corre todo o array a ser operado.
            for (int i = 1; i <= (int)(size_t)arrr[0].elem; i++)
            {
                push(s, arrr[i]); /// Envia cada elemento do array para a stack.
                /// Ciclo que, para cada elemento do array, envia o bloco inteiro para ser aplicado a esse elemento.
                for (unsigned long int j = 2; j < strlen(blocoo) - 2; j += 2)
                {
                    sscanf(&blocoo[j], "%s", tokenn); /// Coloca cada token individualmente numa string.
                    handle(s, tokenn, v, 0);          /// Injeta todos os tokens na handle pela ordem que aparecem no bloco.
                }
            }
            handle(s, "]", v, 0); /// Envia um parêntises para a stack para juntar todos os elementos num só array, com o auxílio do outro parêntises enviado anteriormente.
            return 1;
        }
        /// Caso em que o elemento que vai ser operado e uma string.
        else if (arr.t == STR)
        {
            STACK_ELEM X;
            X.t = CHAR;
            char *arrr = (char *)arr.elem;
            /// Ciclo que corre todos os elementos da string a ser operada.
            for (unsigned long int i = 0; i < strlen(arrr); i++)
            {
                sscanf(&arrr[i], "%c", (char *)&X.elem); /// Envia individualmente cada carater da string para a stack.
                push(s, X);
                /// Ciclo que, para cada elemento do array, envia o bloco inteiro para ser aplicado a esse elemento.
                for (unsigned long int j = 2; j < strlen(blocoo) - 2; j += 2)
                {
                    sscanf(&blocoo[j], "%s", tokenn); /// Coloca cada token individualmente numa string.
                    handle(s, tokenn, v, 1);          /// Injeta todos os tokens na handle pela ordem que aparecem no bloco.
                }
            }
            char *fin = malloc(1000);
            unsigned long int pointer = 0;
            /// Ciclo que junta todos os caracteres operados numa única string.
            while (pointer < strlen(arrr))
            {
                X = pop(s);
                sprintf(&fin[pointer], "%c", (char)(size_t)X.elem);
                pointer++;
            }
            X.elem = (void *)inverteString(fin, pointer); /// Devido à maneira como a stack funciona, é necessário inverter a string.
            X.t = STR;
            push(s, X); /// Envio da string final para a stack.
            return 1;
        }
    }
    return 0;
}
/**
 * Função que dá fold a um array usando um bloco. Isto é, aplica uma determinada operação consecutivamente a todos os elementos do array.
 *
 */
int foldr(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "*") == 0)
    {
        STACK_ELEM BLOCO = pop(s);
        char *bloco = (char *)BLOCO.elem;
        STACK_ELEM X = pop(s);
        STACK_ELEM *arr = (STACK_ELEM *)X.elem;
        char token[BUFSIZ];
        /// Ciclo que corre todo o array e envia cada elemento para a stack.
        for (int i = 1; i <= (int)(size_t)arr[0].elem; i++)
        {
            push(s, arr[i]); /// Envio de cada elemento do array para a stack.
        }
        /// Ciclo que volta a correr todo o array menos uma vez.
        for (int p = 1; p < (int)(size_t)arr[0].elem; p++)
        {
            /// Ciclo que, para cada elemento do array, envia o bloco inteiro para ser aplicado a esse elemento.
            for (unsigned long int t = 2; t <= strlen(bloco) - 2; t += 2)
            {
                sscanf(&bloco[t], "%s", token); /// Coloca cada token individualmente numa string.
                handle(s, token, v, 0);         /// Injeta todos os tokens na handle pela ordem que aparecem no bloco.
            }
        }
        return 1;
    }
    return 0;
}
/**
 * Função que filtra um array usando um bloco. Isto é, filtra todos os elementos que são compatíveis depois da aplicação das operações do bloco.
 *
 */
int filter(STACK *s, char *token)
{
    if (strcmp(token, ",") == 0)
    {
        STACK_ELEM *orig = (STACK_ELEM *)s->st[(s->sp) - 1].elem;
        arraybloco(s, "%", NULL); /// Executa o bloco ao array usando a função definida para esse fim.
        STACK_ELEM X = pop(s);
        STACK_ELEM *str = (STACK_ELEM *)X.elem;
        STACK_ELEM *fin = malloc(100000);
        int pos = 1;
        /// Ciclo que corre todo o array após ser operado.
        for (int i = 1; i <= (int)(size_t)orig[0].elem; i++)
        {
            /// Caso em que o valor do array após as operações é verdadeiro.
            if ((int)(size_t)str[i].elem == 1)
            {
                fin[pos] = orig[i]; /// Coloca num array novo o elemento do array antigo que passou nas operações.
                pos++;
            }
        }
        fin[0].t = INT;
        fin[0].elem = (void *)(size_t)(pos - 1); /// Atribui o tamanho final do array à posição zero do array.
        X.t = ARR;
        X.elem = (void *)fin;
        push(s, X); /// Envia o array final para a stack.
        return 1;
    }
    return 0;
}
