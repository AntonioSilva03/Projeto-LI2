#include "stack.h"
/// Cria referências das funções utilizadas no guião2.c criando ligação entre a stack.h e o guião2.c

int topo(STACK *s, char *token);
int trocar(STACK *s, char *token);
int rodar(STACK *s, char *token);
int popp(STACK *s, char *token);
int duplicar(STACK *s, char *token);
int toChar(STACK *s, char *token);
int toFloat(STACK *s, char *token);
int toString(STACK *s, char *token);
int toInt(STACK *s, char *token);