#include "stack.h"
#include "variaveis.h"
/// Cria referências das funções utilizadas no overloading.c.

int staroverload(STACK *s, char *token, VAR *v);
int plusoverload(STACK *s, char *token);
int equaloverload(STACK *s, char *token);
int tiloverload(STACK *s, char *token, VAR *v);
int menoroverload(STACK *s, char *token);
int maioroverload(STACK *s, char *token);
int openbracketsoverload(STACK *s, char *token);
int closebracketsoverload(STACK *s, char *token);
int hashtagoverload(STACK *s, char *token);
int slashoverload(STACK *s, char *token);
int percentoverload(STACK *s, char *token, VAR *v);
int commaoverloading(STACK *s, char *token);