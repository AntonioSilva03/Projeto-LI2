#include "stack.h"
#include "variaveis.h"
/// Cria referências das funções utilizadas no guião4.c criando ligação entre a stack.h e o mesmo.
int handle(STACK *s, char *token, VAR *v, int charcheck);
STACK_ELEM *inverteArray(STACK_ELEM *arr, int a);
int createString(STACK *s, char *token);
int createArray(STACK *s, char* token);
int coloca(STACK *s, char* token);
int concatArray(STACK *s, char *token);
int multArray(STACK *s, char *token);
int size(STACK *s, char* token);
int indice(STACK *s, char* token);
int buscainicio(STACK *s, char *token);
int buscafim(STACK *s, char *token);
int tirainicio(STACK *s, char *token);
int tirafin(STACK *s, char *token);
int finder(STACK *s, char *token);
int substring(STACK *s, char *token);
int whitespaces(STACK *s, char *token);



