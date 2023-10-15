#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "guiao1.h"
#include "guiao2.h"
#include "guiao3.h"
#include "guiao4.h"
#include "guiao5.h"
#include "variaveis.h"
#include "overloading.h"

/**
 *   Referência da função handle, dado que o compilador lê o código por ordem e necessitamos que a handle seja definida primeiro.
 *
 */

int handle(STACK *s, char *token, VAR *v, int charcheck);

/**
 * Referência da função que imprime arrays.
 *
 */
void printArrs(STACK_ELEM *arr);

/**
 * Função que lê um imput.
 *
 */
int read(STACK *s, char *token, VAR *v)
{
    if (strcmp(token, "l") == 0)
    {
        char line[BUFSIZ];
        char tokenn[BUFSIZ];
        int charcheck = 0;  /// Variável que verifica se está a ser criada uma string.
        int blockcheck = 0; /// Variável que verifica se está a ser criado um bloco.
        /// Verifica se o imput que leu é valido e coloca-o todo na string "line".
        if (fgets(line, BUFSIZ, stdin) != NULL)
        {
            /// Leitura da string membro a membro.
            while (sscanf(line, "%s%[^\n]", tokenn, line) == 2)
            {
                /// Caso em que o elemento introduz um string.
                if (tokenn[0] == '\"' && tokenn[strlen(tokenn) - 1] != '\"')
                {
                    charcheck = 1;
                    handle(s, tokenn, v, charcheck);
                }
                /// Caso em que o elemento fecha uma string.
                else if (tokenn[strlen(tokenn) - 1] == '\"' && tokenn[0] != '\"')
                {
                    charcheck = 0;
                    handle(s, tokenn, v, 1);
                }
                /// Caso em que o elemento abre e fecha uma string (string com apenas uma palavra).
                else if (tokenn[strlen(tokenn) - 1] == '\"' && tokenn[0] == '\"')
                {
                    handle(s, tokenn, v, 1);
                }
                /// Caso em que o elemento é uma chaveta mas não está a ser criado um bloco.
                else if (blockcheck != 1 && strcmp(tokenn, "}") != 0)
                {
                    handle(s, tokenn, v, charcheck);
                }
            }
            /// Casos em que o elemento é o ultimo da string "line".
            /// Caso em que o elemento fecha uma string.
            if (tokenn[strlen(tokenn) - 1] == '\"' && tokenn[0] != '\"')
            {
                charcheck = 0;
                handle(s, tokenn, v, 1);
            }
            /// Caso em que o elemento abre e fecha uma string (string com apenas uma palavra).
            else if (tokenn[strlen(tokenn) - 1] == '\"' && tokenn[0] == '\"')
            {
                handle(s, tokenn, v, 1);
            }
            /// Caso em que o elemento é uma chaveta mas não está a ser criado um bloco.
            else if (blockcheck != 1 && strcmp(tokenn, "}") != 0)
            {
                handle(s, tokenn, v, charcheck);
            }
        }
        return 1;
    }
    return 0;
}

/**
 * Função que dá print ao elemento no topo da stack.
 *
 */
int topostack(STACK *s, char *token)
{
    if (strcmp(token, "p") == 0)
    {
        STACK_ELEM X = s->st[(s->sp)];
        /// Caso em que o elemento e um inteiro.
        if (X.t == INT)
        {
            printf("%d\n", (int)(size_t)X.elem);
        }
        /// Caso em que o elemento e um caracter.
        if (X.t == CHAR)
        {
            printf("%c\n", (char)(size_t)X.elem);
        }
        /// Caso em que o elemento e um double.
        if (X.t == DBL)
        {
            union void_cast v;
            v.ptr = X.elem;
            printf("%g\n", v.value);
        }
        /// Caso em que o elemento e uma string ou bloco.
        if (X.t == STR || X.t == BLK)
        {
            printf("%s\n", (char *)X.elem);
        }
        /// Caso em que o elemento e um array.
        if (X.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)X.elem;
            printArrs(arr); /// Os arrays precisam de todo um tratamento no print.
            printf("\n");
        }
        return 1;
    }
    return 0;
}
/**
 * Função que vê várias linhas no imput.
 *
 */
int readlines(STACK *s, char *token, VAR *v)
{
    char line[BUFSIZ];
    if (strcmp(token, "t") == 0)
    {
        /// Ciclo que verifica se a linha seguinte é nula ou não.
        while (fgets(line, BUFSIZ, stdin) != NULL)
        {
            handle(s, line, v, 1);
        }
        return 1;
    }
    return 0;
}

/**
 * Função que analiza cada elemento e atribui o tipo adequado (e envia para a stack).
 *
 */
int val(STACK *s, char *token)
{
    STACK_ELEM val;
    /// Analiza se o elemento tem ou não um ".", referente às casas decimais de um valor double.
    if (strchr(token, '.') == NULL)
    {
        val.t = INT;
        sscanf(token, "%d", (int *)&val.elem);
    }
    /// Caso tenha:
    else
    {
        val.t = DBL;
        sscanf(token, "%lg", (double *)&val.elem);
    }
    /// Caso em que o elemento é um caracter.
    if (strchr("abcdefghijklmnopqrstuvwxyz[", *token) != NULL)
    {
        val.t = CHAR;
        sscanf(token, "%c", (char *)&val.elem);
    }
    push(s, val); /// Envio final do elemento devidamente processado para a stack.
    return 1;
}

/**
 * Função central que separa todos os tokens recebidos dependendo da sua funcionalidade e contexto.
 *
 */
int handle(STACK *s, char *token, VAR *v, int charcheck)
{
    /// Funções que são chamadas através dos tokens "+*/)(%#&|^~".
    if (strchr("+*/)(%#&|^~", *token) != NULL)
    {
        return plusoverload(s, token) || staroverload(s, token, v) || slashoverload(s, token) || closebracketsoverload(s, token) || openbracketsoverload(s, token) || percentoverload(s, token, v) || hashtagoverload(s, token) || and(s, token) || ou(s, token) || xor(s, token) || tiloverload(s, token, v);
    }
    /// Caso especial que analiza o contexto do token "-", pois este pode ser um operador ou um número negativo.
    else if (strchr("-", *token) != NULL)
    {
        /// Se o token for apenas um "-", então estamos perante um operador.
        if (strcmp(token, "-") == 0)
        {
            return sub(s, token);
        }
        /// Caso em que o "-" refere-se a um número negativo.
        else
        {
            return val(s, token);
        }
    }
    /// Função que é chamada através do token "S/".
    else if (strcmp(token, "S/") == 0)
    {
        return whitespaces(s, token);
    }
    /// Função chamada durante a criação de uma string.
    else if (charcheck == 1)
    {
        return createString(s, token);
    }
    /// Funções que são chamadas através dos tokens "$\\@;_".
    else if (strchr("$\\@;_", *token) != NULL)
    {
        return topo(s, token) || trocar(s, token) || rodar(s, token) || popp(s, token) || duplicar(s, token);
    }
    /// Funções que são chamadas através dos tokens "cfisltp".
    else if (strchr("cfisltp", *token) != NULL)
    {
        return toChar(s, token) || toFloat(s, token) || toString(s, token) || toInt(s, token) || read(s, token, v) || topostack(s, token) || readlines(s, token, v);
    }
    /// Funções que são chamadas através dos tokens "?=><!".
    else if (strchr("?=><!", *token) != NULL)
    {
        return elif (s, token) || equaloverload(s, token) || maioroverload(s, token) || menoroverload(s, token) || nott(s, token);
    }
    /// Funções que são chamadas através dos tokens "e<e>e&e|".
    else if (strchr("e<e>e&e|", *token) != NULL)
    {
        return emaior(s, token) || emenor(s, token) || eand(s, token) || eou(s, token);
    }
    /// Função que é chamada através dos tokens "ABCDEFGHIJKLMNOPQRSTUVWXYZ".
    else if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", *token) != NULL)
    {
        return var_handle(s, token, v);
    }
    /// Função que é chamada através dos tokens ":A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z".
    else if (strchr(":A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z", *token) != NULL)
    {
        return var_new_handle(s, token, v);
    }
    /// Funções que são chamadas através dos tokens ",]".
    else if (strchr(",]", *token) != NULL)
    {
        return commaoverloading(s, token) || createArray(s, token);
    }
    /// Função que é chamada se o token não respeitar nenhum dos casos anteriores.
    else
    {
        return val(s, token);
    }
}
/**
 * Função que imprime especificamente os arrays.
 *
 */
void printArrs(STACK_ELEM *arr)
{
    int arg = (int)(size_t)arr[0].elem; /// Variável onde é guardado o tamanho do array.
    /// Ciclo que corre todo o array.
    for (int i = 1; i <= arg; i++)
    {
        /// Caso em que o elemento e um inteiro.
        if (arr[i].t == INT)
        {
            printf("%d", (int)(size_t)arr[i].elem);
        }
        /// Caso em que o elemento e um caracter.
        if (arr[i].t == CHAR)
        {
            printf("%c", (char)(size_t)arr[i].elem);
        }
        /// Caso em que o elemento e um double.
        if (arr[i].t == DBL)
        {
            union void_cast v;
            v.ptr = arr[i].elem;
            printf("%g", v.value);
        }
        /// Caso em que o elemento e uma string.
        if (arr[i].t == STR)
        {
            printf("%s", (char *)arr[i].elem);
        }
        /// Caso em que o elemento e um array.
        if (arr[i].t == ARR)
        {
            printArrs(arr[i].elem);
        }
    }
}
/**
 * Função principal do programa. Lê o input inicial e faz o print final da stack.
 * @param[in] input
 * @param[out] conteudo_final_da_stack
 */
int main()
{
    STACK *s = new_stack();
    VAR *v = new_var();
    char line[BUFSIZ];
    char token[BUFSIZ];
    int charcheck = 0;           /// Variável que verifica se está a ser criada uma string.
    int blockcheck = 0;          /// Variável que verifica se está a ser criado um bloco.
    char *bloco = malloc(10000); /// String para receber o bloco.
    int pointer = 0;
    /// Verifica se a linha lida não é nula e coloca-a toda na string "line".
    if (fgets(line, BUFSIZ, stdin))
    {
        /// Leitura de toda a string termo a termo.
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
        {
            /// Caso em que um bloco começa a ser criado.
            if (strcmp(token, "{") == 0)
            {
                blockcheck = 1;
            }
            /// Caso em que um bloco é finalizado.
            else if (strcmp(token, "}") == 0)
            {
                sprintf(&bloco[pointer], "%s", token);
                pointer = 0;
                createblock(s, bloco);
                blockcheck = 0;
            }
            /// Caso aplicado durante a criação de um bloco.
            if (blockcheck == 1)
            {
                sprintf(&bloco[pointer], "%s", token);
                pointer++;
                bloco[pointer] = ' ';
                pointer++;
            }
            /// Caso em que uma string começa a ser criada.
            if (token[0] == '\"' && token[strlen(token) - 1] != '\"')
            {
                charcheck = 1;
                handle(s, token, v, charcheck);
            }
            /// Caso em que uma string é finalizada.
            else if (token[strlen(token) - 1] == '\"' && token[0] != '\"')
            {
                charcheck = 0;
                handle(s, token, v, 1);
            }
            /// Caso em que uma string e começada e finalizada (string de uma só palavra).
            else if (token[strlen(token) - 1] == '\"' && token[0] == '\"')
            {
                handle(s, token, v, 1);
            }
            /// Quando o token é uma chaveta mas não está a ser criado um bloco.
            else if (blockcheck != 1 && strcmp(token, "}") != 0)
            {
                handle(s, token, v, charcheck);
            }
        }
        /// Casos definidos anteriormente para a situação em que o elemento é o último da string "line".
        if (strcmp(token, "}") == 0)
        {
            sprintf(&bloco[pointer], "%s", token);
            // bloco[pointer] = token;
            pointer = 0;
            createblock(s, bloco);
            blockcheck = 0;
        }
        if (token[strlen(token) - 1] == '\"' && token[0] != '\"')
        {
            charcheck = 0;
            handle(s, token, v, 1);
        }
        else if (token[strlen(token) - 1] == '\"' && token[0] == '\"')
        {
            handle(s, token, v, 1);
        }
        else if (blockcheck != 1 && strcmp(token, "}") != 0)
        {
            handle(s, token, v, charcheck);
        }
    }
    /// Ciclo que corre toda a stack.
    for (int i = 1; i <= s->sp; i++)
    {
        /// Caso em que o elemento e um inteiro.
        if (s->st[i].t == INT)
        {
            printf("%d", (int)(size_t)s->st[i].elem);
        }
        /// Caso em que o elemento e um caracter.
        if (s->st[i].t == CHAR)
        {
            printf("%c", (char)(size_t)s->st[i].elem);
        }
        /// Caso em que o elemento e um double.
        if (s->st[i].t == DBL)
        {
            union void_cast v;
            v.ptr = s->st[i].elem;
            printf("%g", v.value);
        }
        /// Caso em que o elemento e uma string ou bloco.
        if (s->st[i].t == STR || s->st[i].t == BLK)
        {
            printf("%s", (char *)s->st[i].elem);
        }
        /// Caso em que o elemento e um array.
        if (s->st[i].t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)s->st[i].elem;
            printArrs(arr);
        }
    }
    printf("\n");
    return 0;
}