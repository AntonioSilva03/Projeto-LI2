#ifndef MAX_STACK
#define MAX_STACK 100000 /// Número máximo de posições que a stack pode levar.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 *  Esta struct é utilizada para fazer cast dos elementos em void para todos os tipos (util para algumas conversões).
 *
 */
union void_cast
{
    void *ptr; /// Tipo genérico para guardar qualquer elemento.
    double value; /// Cast do elemento de void para double.
    float valuee; /// Cast do elemento de void para float.
    char cc; /// Cast do elemento de void para char.
    char *arr; /// Cast do elemento de void para string.
    int ii; /// Cast do elemento de void para inteiro.
};

/**
 *  Estrutura que define um novo tipo de variável onde serão indicados os tipos de cada elemento a ser introduzido na stack.
 * 
 */
typedef enum
{
    CHAR, /// Tipo para elementos que são carateres.
    INT, /// Tipo para elementos que são inteiros.
    DBL, /// Tipo para elementos que são doubles.
    STR, /// Tipo para elementos que são strings.
    ARR, /// Tipo para elementos que são arrays.
    BLK /// Tipo para elementos que são blocos.
} TYPE;
/**
 * Definição dos elementos que vão ser adicionados na stack.
 * 
 */
typedef struct
{
    TYPE t; /// Tipo do elemento adicionado.
    void *elem; /// Elemento em formato genérico.
} STACK_ELEM;
/**
 * Definição da stack.
 * 
 */ 
typedef struct
{
    STACK_ELEM *st; /// Array onde vão ser adicionados todos os elementos.
    int sp; /// Inteiro que indica a posição do topo da stack.
} STACK;

/// Referências das funções definidas em stack.c.
STACK *new_stack();
void push(STACK *s, STACK_ELEM elem);
STACK_ELEM pop(STACK *s);
#endif