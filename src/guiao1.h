#include "stack.h"
/// Cria referências das funções utilizadas no guião1.c criando ligação entre a stack.h e o guião1.c

int soma(STACK *s, char *token);
int sub(STACK *s, char *token);
int prod(STACK *s, char *token);
int quo(STACK *s, char *token);
int inc(STACK *s, char *token);
int dec(STACK *s, char *token);
int mod(STACK *s, char *token);
int pot(STACK *s, char *token);
int and (STACK * s, char *token);
int ou (STACK * s, char *token);
int xor (STACK * s, char *token);
int not (STACK * s, char *token);