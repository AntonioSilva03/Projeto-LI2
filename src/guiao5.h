#include "stack.h"
#include "variaveis.h"
/// Cria referências das funções utilizadas no guião5.c criando ligação entre a stack.h e o mesmo.
char *inverteString(char *arr, int a);
int handle(STACK *s, char *token, VAR *v, int charcheck);
int createblock(STACK *s, char *token);
int execbloco(STACK *s, char* token, VAR *v);
int arraybloco(STACK *s, char* token, VAR *v);
int foldr(STACK *s, char* token, VAR *v);
int filter(STACK *s, char *token);