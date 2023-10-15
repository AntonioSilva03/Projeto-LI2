#ifndef VAR_MAX
#define VAR_MAX 26 /// Define o tamanho máximo do array das variáveis para o número de letras do alfabeto.
#include "stack.h"
/**
 * Estrutura que define uma variável.
 * 
 */
typedef struct
{
    TYPE t; /// Tipo do elemento que está na variável.
    void *elem; /// Elemento em void, porque pode ser qualquer coisa.
} VAR_ELEM;
/**
 * Estrutura que define o array para receber todas as variáveis.
 * 
 */
typedef struct
{
    VAR_ELEM *varr; /// Referência de um array com elementos do tipo VAR_ELEM definidos antes.

} VAR;

VAR *new_var();
int var_new(char *token, void *new);
int var_handle(STACK *s, char *token, VAR *v);
int var_new_handle(STACK *s, char *token, VAR *v);
int var_A(STACK *s, VAR *v, char *token);
int var_B(STACK *s, VAR *v, char *token);
int var_C(STACK *s, VAR *v, char *token);
int var_D(STACK *s, VAR *v, char *token);
int var_E(STACK *s, VAR *v, char *token);
int var_F(STACK *s, VAR *v, char *token);
int var_G(STACK *s, VAR *v, char *token);
int var_H(STACK *s, VAR *v, char *token);
int var_I(STACK *s, VAR *v, char *token);
int var_J(STACK *s, VAR *v, char *token);
int var_K(STACK *s, VAR *v, char *token);
int var_L(STACK *s, VAR *v, char *token);
int var_M(STACK *s, VAR *v, char *token);
int var_N(STACK *s, VAR *v, char *token);
int var_O(STACK *s, VAR *v, char *token);
int var_P(STACK *s, VAR *v, char *token);
int var_Q(STACK *s, VAR *v, char *token);
int var_R(STACK *s, VAR *v, char *token);
int var_S(STACK *s, VAR *v, char *token);
int var_T(STACK *s, VAR *v, char *token);
int var_U(STACK *s, VAR *v, char *token);
int var_V(STACK *s, VAR *v, char *token);
int var_W(STACK *s, VAR *v, char *token);
int var_X(STACK *s, VAR *v, char *token);
int var_Y(STACK *s, VAR *v, char *token);
int var_Z(STACK *s, VAR *v, char *token);
#endif