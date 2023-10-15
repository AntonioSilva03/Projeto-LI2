#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"

/**
 * Função que cria a stack.
 * 
 */
STACK *new_stack()
{
    STACK *new = malloc(sizeof *new); /// Alocação de espaço para a stack.
    new->st = malloc(sizeof *new->st * MAX_STACK); /// Alocação de espaço para cada elemento da stack.
    return new;
}
/**
 * Função que adiciona um elemento à stack.
 * 
 */
void push(STACK *s, STACK_ELEM elem)
{
    s->sp++; /// Move o apontador do topo da stack uma unidade para a frente.
    s->st[s->sp] = elem; /// Adiciona o novo elemento na stack.
}
/**
 * Função que retira um elemento da stack.
 * 
 */
STACK_ELEM pop(STACK *s)
{
    STACK_ELEM ret = s->st[s->sp]; /// Retira o elemento da stack.
    s->sp--; /// Diminui o apontador da stack em uma unidade.
    return ret; /// Devolve o valor retirado.
}