#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "guiao4.h"

/**
 * Função que inverte um array. Utiliza o mesmo esquema da inverteString definida no guiao 5.
 *
 *
 */
STACK_ELEM *inverteArray(STACK_ELEM *arr, int a)
{
    int i;
    STACK_ELEM aux;
    /// Corre a string até metade e troca o elemento da posição i com o elemento da posição i a contar do fim.
    for (i = 0; i < a / 2; i++)
    {
        aux = arr[(a - 1) - i];
        arr[(a - 1) - i] = arr[i];
        arr[i] = aux;
    }
    return arr;
}

/**
 * Função geral que cria todo o tipo de strings.
 *
 */
int createString(STACK *s, char *token)
{
    STACK_ELEM X;
    STACK_ELEM Y;
    char *fin = malloc(10000000); /// String final resultante da junção de todas as substrings recebidas.
    /// Caso em que o token inicia uma string, i.e apenas abre aspas. (Exemplo: "hoje ).
    if (token[0] == '\"' && token[strlen(token) - 1] != '\"') //"gffufuyfuy
    {
        int pointer = 0;
        while ((long unsigned int)pointer < strlen(token))
        {
            fin[pointer] = token[pointer];
            pointer++;
        }
        X.t = STR;
        X.elem = (void *)fin;
        push(s, X);
        return 1;
    }
    /// Caso em que o token termina uma string, i.e apenas fecha aspas. (Exemplo: hoje" ).
    else if (token[strlen(token) - 1] == '\"' && token[0] != '\"') // wowdwjdwidj"
    {
        fin[0] = ' ';
        strcat(fin, token);
        X = pop(s);
        token = (char *)X.elem;
        while (token[0] != '\"')
        {
            strcat(token, fin);
            int pointer = 1;
            fin[0] = ' ';
            while (token[pointer - 1] != '\0')
            {
                fin[pointer] = token[pointer - 1];
                pointer++;
            }
            X = pop(s);
            token = (char *)X.elem;
        }
        strcat(token, fin);
        int pointer2 = 1;
        char *finn = malloc(10000000);
        while (token[pointer2] != '\"')
        {
            finn[pointer2 - 1] = token[pointer2];
            pointer2++;
        }
        Y.t = STR;
        Y.elem = (void *)finn;
        push(s, Y);
        return 1;
    }
    /// Casos especiais. Estes incluem casos em que a string tem apenas uma palavra ou e uma palavra no meio de uma string de varias palavras.
    else
    {
        /// Caso em que a string tem apenas uma palavra. Isto é, ocorrem aspas no inicio e no fim da string recebida. (Exemplo: "ola").
        if (token[0] == '\"' && strlen(token) != 1)
        {
            int pointer = 1;
            while (token[pointer] != '\"')
            {
                fin[pointer - 1] = token[pointer];
                pointer++;
            }
            X.t = STR;
            X.elem = (void *)fin;
            push(s, X);
            return 1;
        }
        /// Caso em que a string e uma palavra no meio da string final. Isto é, não ocorrem aspas nem no inicio nem no fim da string recebida. (Exemplo: ola).
        else if (token[0] != '\"')
        {
            int pointer = 0;
            while (token[pointer] != '\0')
            {
                fin[pointer] = token[pointer];
                pointer++;
            }
            X.t = STR;
            X.elem = (void *)fin;
            push(s, X);
            return 1;
        }
        else
        /// Caso especifico em que a string e introduzida por um espaço. (Exemplo: " ola"). Este caso lida com o espaço inicial da string.
        {
            X.t = STR;
            fin[0] = '\"';
            X.elem = (void *)fin;
            push(s, X);
            return 1;
        }
    }
}
/**
 * Função geral que cria um array.
 *
 */
int createArray(STACK *s, char *token)
{
    if (strcmp(token, "]") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y;
        STACK_ELEM Z;
        STACK_ELEM *arr = malloc(10000000); /// Array do tipo STACK_ELEM pois os arrays podem levar elementos de qualquer tipo.
        int pointer = 0;
        int check = 0; /// Variável que gere o ciclo while abaixo.
        /// Ciclo que vai dando pop aos eleentos da stack até encontrar um "[" que vai fechar o array.
        while (check == 0)
        {
            if (X.t == CHAR && (char)(size_t)X.elem == '[')
            {
                check = 1; /// Após encontrar um "[" que fecha o array, interrompe o ciclo atribuindo um valor diferente de zero à variável auxiliar.
            }
            /// Enquanto não encontra um elemento que feche o array, vai tirando elementos da stack e colocando no array.
            else
            {
                arr[pointer] = X;
                pointer++;
                X = pop(s);
            }
        }
        /// Colocação do tamanho final no array, por motivos de facilidade ao dar print da stack, mais tarde.
        Z.t = INT;
        Z.elem = (void *)(size_t)pointer;
        arr[pointer] = Z;
        /// Configuração de uma variavel para enviar o array final para a stack.
        Y.t = ARR;
        Y.elem = (void *)inverteArray(arr, pointer + 1); /// Como os elementos vao estar em ordem contrária devido ao funcionamento da stack, inverte o array antes de enviar.
        push(s, Y);
        return 1;
    }
    return 0;
}
/**
 * Função que coloca todos os elementos de um array ou string na stack.
 *
 */
int coloca(STACK *s, char *token)
{
    if (strcmp(token, "~") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Z;
        STACK_ELEM *arr = (STACK_ELEM *)X.elem;
        /// Caso em que o elemento e um array.
        if (X.t == ARR)
        {
            /// Ciclo que corre todo o array e coloca cada elemento do array numa variavel e envia para a stack.
            for (int i = 1; i <= (int)(size_t)arr[0].elem; i++)
            {
                Z = arr[i];
                push(s, Z);
            }
            return 1;
        }
        /// Caso em que o elemento e uma string.
        else if (X.t == STR)
        {
            char *a = (char *)X.elem;
            /// Ciclo que corre toda a string e coloca cada letra numa variavel e envia para a stack.
            for (long unsigned int i = 0; i < strlen(a); i++)
            {
                Z.t = CHAR;
                Z.elem = (void *)(size_t)a[i];
                push(s, Z);
            }
            return 1;
        }
    }
    return 0;
}
/**
 * Função que junta dois arrays ou strings num so array.
 *
 */
int concatArray(STACK *s, char *token)
{
    if (strcmp(token, "+") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        /// Caso em que os dois elementos são arrays.
        if (X.t == ARR && Y.t == ARR)
        {
            STACK_ELEM *arr1 = (STACK_ELEM *)X.elem;
            STACK_ELEM *arr2 = (STACK_ELEM *)Y.elem;
            int sizearr2 = (int)(size_t)arr2[0].elem;
            arr2[0].t = INT;
            arr2[0].elem = (void *)(size_t)(((int)(size_t)arr1[0].elem) + sizearr2);
            int pointer = 1;
            for (int i = sizearr2 + 1; i <= (int)(size_t)arr2[0].elem; i++, pointer++)
            {
                arr2[i] = arr1[pointer];
            }
            Z.t = ARR;
            Z.elem = (void *)arr2;
            push(s, Z);
            return 1;
        }
        /// Caso em que se junta um elemento a um array (nesta ordem).
        else if (X.t == ARR && (Y.t == INT || Y.t == CHAR))
        {
            STACK_ELEM *arr1 = (STACK_ELEM *)X.elem;
            STACK_ELEM *fin = malloc(1000000);
            STACK_ELEM elemadd;
            elemadd.t = Y.t;
            elemadd.elem = Y.elem;
            fin[0].elem = (void *)(size_t)((int)(size_t)arr1[0].elem + 1);
            fin[1] = elemadd;
            for (int i = 2; i <= (int)(size_t)arr1[0].elem + 1; i++)
            {
                fin[i] = arr1[i - 1];
            }
            Z.elem = (void *)fin;
            Z.t = ARR;
            push(s, Z);
            return 1;
        }
        /// Caso em que se junta um array a um elemento (por esta ordem).
        else if (Y.t == ARR && (X.t == INT || X.t == CHAR))
        {
            STACK_ELEM *arr1 = (STACK_ELEM *)Y.elem;
            STACK_ELEM *fin = malloc(1000000);
            STACK_ELEM elemadd;
            elemadd.t = X.t;
            elemadd.elem = X.elem;
            fin[0].elem = (void *)(size_t)((int)(size_t)arr1[0].elem + 1);
            int i;
            for (i = 1; i <= (int)(size_t)arr1[0].elem; i++)
            {
                fin[i] = arr1[i];
            }
            fin[i] = elemadd;
            Z.elem = (void *)fin;
            Z.t = ARR;
            push(s, Z);
            return 1;
        }
        /// Caso em que se juntam duas strings.
        else if (X.t == STR && Y.t == STR)
        {
            char *str1 = (char *)X.elem;
            char *str2 = (char *)Y.elem;
            char *fin = malloc(1000000);
            strcat(str2, str1);
            strcpy(fin, str2);
            Z.elem = (void *)fin;
            Z.t = STR;
            push(s, Z);
            return 1;
        }
        /// Caso em que se junta uma string a um elemento (por esta ordem).
        else if (Y.t == STR && (X.t == INT || X.t == CHAR))
        {
            char a = (char)(size_t)X.elem;
            char *str1 = (char *)Y.elem;
            str1[strlen(str1)] = a;
            Z.elem = (void *)str1;
            Z.t = STR;
            push(s, Z);
            return 1;
        }
        /// Caso em que se junta um elemento a uma string (por esta ordem).
        else if ((Y.t == INT || Y.t == CHAR) && X.t == STR)
        {
            char *a = malloc(1000000);
            a[0] = (char)(size_t)Y.elem;
            char *str1 = (char *)X.elem;
            strcat(a, str1);
            Z.elem = (void *)a;
            Z.t = STR;
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que replica o array n vezes.
 *
 */
int multArray(STACK *s, char *token)
{
    if (strcmp(token, "*") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        /// Caso em que o elemento a multiplicar e um array.
        if (Y.t == ARR && X.t == INT)
        {
            int arg = (int)(size_t)X.elem;
            STACK_ELEM *arr = (STACK_ELEM *)Y.elem;
            int size = (int)(size_t)arr[0].elem;
            int acc = 1;
            STACK_ELEM *arrr = malloc(10000000);
            arrr[0].elem = (void *)(size_t)(arg * size);
            for (int j = 1; j <= arg; j++)
            {
                for (int i = 1; i <= size; i++)
                {
                    arrr[acc].elem = arr[i].elem;
                    arrr[acc].t = arr[i].t;
                    acc++;
                }
            }
            Z.t = ARR;
            Z.elem = (void *)arrr;
            push(s, Z);
            return 1;
        }
        /// Caso em que o elemento a multiplicar e uma string.
        else if (Y.t == STR && X.t == INT)
        {
            char *at = (char *)Y.elem;
            char *fin = malloc(1000000);
            int arg = (int)(size_t)X.elem;
            while (arg > 0)
            {
                arg--;
                strcat(fin, at);
            }
            Z.t = STR;
            Z.elem = (void *)fin;
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que acha o tamanho de um array ou string.
 * Esta função pode também criar arrays se o que receber for um tamanho (inteiro).
 *
 */
int size(STACK *s, char *token)
{
    if (strcmp(token, ",") == 0)
    {
        STACK_ELEM X = pop(s);
        /// Caso em que o elemento é uma string.
        if (X.t == STR)
        {
            char *arr = (char *)X.elem;
            int counter = 0;
            int pointer = strlen(arr);
            while (pointer != 0)
            {
                counter++;
                pointer--;
            }
            X.t = INT;
            X.elem = (void *)(size_t)counter;
            push(s, X);
            return 1;
        }
        /// Caso em que o elemento é um array.
        else if (X.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)X.elem;
            int size = (int)(size_t)arr[0].elem;
            X.t = INT;
            X.elem = (void *)(size_t)size;
            push(s, X);
            return 1;
        }
        /// Caso em que o elemento é um inteiro. A função cria um array do tamanho (inteiro) recebido, onde os elementos estão por ordem crescente, começando no zero.
        else if (X.t == INT)
        {
            X.t = ARR;
            STACK_ELEM *arr = malloc(1000000);
            int a = (int)(size_t)X.elem;
            arr[0].t = INT;
            arr[0].elem = (void *)(size_t)a;
            for (int i = 1; i <= a; i++)
            {
                arr[i].elem = (void *)(size_t)(i - 1);
                arr[i].t = INT;
            }
            X.elem = (void *)arr;
            push(s, X);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que procura um elemento por indice num array ou string.
 *
 */
int indice(STACK *s, char *token)
{
    if (strcmp(token, "=") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        int arg1 = (int)(size_t)X.elem;
        /// Caso em que o elemento e uma string.
        if (Y.t == STR)
        {
            char *a = (char *)Y.elem;
            if (arg1 > strlen(a)) /// Caso em que o índice pedido excede o comprimento da string.
            {
                Z.elem = (void *)0;
                Z.t = INT;
                push(s, Z);
                return 1;
            }
            char b = a[arg1];
            Z.elem = (void *)(size_t)b;
            Z.t = CHAR;
            push(s, Z);
            return 1;
        }
        /// Caso em que o elemento e um array.
        else
        {
            STACK_ELEM *arr = (STACK_ELEM *)Y.elem;
            Z.t = arr[arg1 + 1].t;
            Z.elem = arr[arg1 + 1].elem;
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que procura os n primeiros termos do array ou string.
 *
 */
int buscainicio(STACK *s, char *token)
{
    if (strcmp(token, "<") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        int arg = (int)(size_t)X.elem;
        /// Caso em que o elemento a ser analizado e um array.
        if (Y.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)Y.elem;
            STACK_ELEM *arrr = malloc(1000000);
            arrr[0] = X;
            for (int i = 1; i <= arg; i++)
            {
                arrr[i] = arr[i];
            }
            Z.elem = (void *)arrr;
            Z.t = ARR;
            push(s, Z);
            return 1;
        }
        /// Caso em que o elemento a ser analizado e uma string.
        else
        {
            char *a = (char *)Y.elem;
            char *fin = malloc(1000000);
            for (int i = 0; i < arg; i++)
            {
                fin[i] = a[i];
            }
            Z.elem = (void *)fin;
            Z.t = STR;
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que procura os últimos n termos do array ou string.
 *
 */
int buscafim(STACK *s, char *token)
{
    if (strcmp(token, ">") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        int arg = (int)(size_t)X.elem;
        /// Caso em que o elemento a ser analizado e um array.
        if (Y.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)Y.elem;
            STACK_ELEM *arrr = malloc(1000000);
            arrr[0] = X;
            int pointer = 1;
            for (int i = ((int)(size_t)arr[0].elem) - (arg - 1); i <= (int)(size_t)arr[0].elem; i++, pointer++)
            {
                arrr[pointer] = arr[i];
            }
            Z.elem = (void *)arrr;
            Z.t = ARR;
            push(s, Z);
            return 1;
        }
        /// Caso em que o elemento a ser analizado e uma string.
        else
        {
            char *a = (char *)Y.elem;
            char *fin = malloc(1000000);
            int pointer = 0;
            for (long unsigned int i = strlen(a) - arg; i < strlen(a); i++, pointer++)
            {
                fin[pointer] = a[i];
            }
            Z.elem = (void *)fin;
            Z.t = STR;
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que tira o primeiro elemento de um array ou string e coloca na stack depois deste.
 *
 */
int tirainicio(STACK *s, char *token)
{
    if (strcmp(token, "(") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Z;
        /// Caso em que o elemento é um array.
        if (X.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)X.elem;
            STACK_ELEM *arrr = malloc(1000000);
            arrr[0].t = INT;
            arrr[0].elem = (void *)(size_t)(((int)(size_t)arr[0].elem) - 1);
            X = arr[1];
            for (int i = 2; i <= (int)(size_t)arrr[0].elem + 1; i++)
            {
                arrr[i - 1] = arr[i];
            }
            Z.t = ARR;
            Z.elem = (void *)arrr;
            push(s, Z);
            push(s, X);
            return 1;
        }
        /// Caso em que o elemento é uma string.
        else
        {
            char *a = (char *)X.elem;
            char *fin = malloc(1000000);
            for (long unsigned int i = 1; i < strlen(a); i++)
            {
                fin[i - 1] = a[i];
            }
            X.elem = (void *)fin;
            push(s, X);
            Z.t = CHAR;
            Z.elem = (void *)(size_t)(char)(size_t)a[0];
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que tira o ultimo elemento de um array ou string e coloca na stack depois deste.
 *
 */
int tirafin(STACK *s, char *token)
{
    if (strcmp(token, ")") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Z;
        /// Caso em que o elemento é um array.
        if (X.t == ARR)
        {
            STACK_ELEM *arr = (STACK_ELEM *)X.elem;
            STACK_ELEM *arrr = malloc(1000000);
            arrr[0].t = INT;
            arrr[0].elem = (void *)(size_t)(((int)(size_t)arr[0].elem) - 1);
            X = arr[(int)(size_t)arr[0].elem];
            for (int i = 1; i <= (int)(size_t)arrr[0].elem; i++)
            {
                arrr[i] = arr[i];
            }
            Z.t = ARR;
            Z.elem = (void *)arrr;
            push(s, Z);
            push(s, X);
            return 1;
        }
        /// Caso em que o elemento e uma string.
        else
        {
            char *a = (char *)X.elem;
            char *fin = malloc(1000000);
            for (long unsigned int i = 0; i < strlen(a) - 1; i++)
            {
                fin[i] = a[i];
            }
            X.t = STR;
            X.elem = (void *)fin;
            push(s, X);
            Z.t = CHAR;
            Z.elem = (void *)(size_t)(char)(size_t)a[strlen(a) - 1];
            push(s, Z);
            return 1;
        }
    }
    return 0;
}
/**
 * Função que acha o indice da primeira ocorrência da substring na string principal.
 *
 */
int finder(STACK *s, char *token)
{
    if (strcmp(token, "#") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        char *a = (char *)X.elem;
        char *b = (char *)Y.elem;
        int indice = -1;
        /// Ciclo que corre a string principal.
        for (unsigned long int i = 0; i < strlen(b); i++)
        {
            if (b[i] == a[0]) /// Procura pela primeira ocorrẽncia do primeiro elemento da substring na string principal.
            {
                indice = i; /// Se encontrar guarda o indice.
                /// Este ciclo corre a substring toda para verificar se o resto da string coincide.
                for (unsigned long int v = 1; v < strlen(a); v++)
                {
                    if (b[i + v] != a[v]) /// Se um dos elementos da substring não for compativel com a string principal, atribui -1 ao indice.
                    {
                        indice = -1;
                    }
                }
                /// If necessário para garantir que a função encontra a primeira ocorrência e não outras que possam dar resultados errados.
                if (indice != -1)
                {
                    Z.t = INT;
                    Z.elem = (void *)(size_t)indice;
                    push(s, Z);
                    return 1;
                }
            }
        }
        Z.t = INT;
        Z.elem = (void *)(size_t)indice;
        push(s, Z);
        return 1;
    }
    return 0;
}
/**
 * Função que divide uma string onde ocorre a substring pedida.
 *
 */
int substring(STACK *s, char *token)
{
    if (strcmp(token, "/") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        char *sub = (char *)X.elem;
        if (strcmp(sub, "\0") == 0)
        {
            push(s, Y);
            return 1;
        }
        char *string = (char *)Y.elem;
        STACK_ELEM *arr = malloc(1000000);
        int indice = 1;
        char *nova = strtok(string, sub);
        while (nova != NULL)
        {
            STACK_ELEM aux;
            aux.elem = (void *)nova;
            aux.t = STR;
            arr[indice] = aux;
            indice++;
            nova = strtok(NULL, sub);
        }
        arr[0].elem = (void *)(size_t)indice;
        arr[0].t = INT;
        Z.elem = (void *)arr;
        Z.t = ARR;
        push(s, Z);
        return 1;
    }
    return 0;
}
int substringy(STACK *s, char *token)
{
    if (strcmp(token, "/") == 0)
    {
        STACK_ELEM X = pop(s);
        STACK_ELEM Y = pop(s);
        STACK_ELEM Z;
        STACK_ELEM *arr = malloc(1000000);
        char *sub = (char *)X.elem;
        char *a = (char *)Y.elem;
        char *novas = malloc(100000);
        int pointer = 0;
        int check = 0; /// Variavel auxiliar para criar um caso de paragem para o ciclo while
        int indice = 1;
        /// Ciclo que corre toda a string principal à procura da substring.
        for (unsigned long int i = 0; i < strlen(a); i++)
        {
            if (a[i] == sub[0]) /// Procura pela primeira ocorrẽncia do primeiro elemento da substring n string principal.
            {
                check = 1;
                unsigned long int j = 1;
                /// Ciclo que corre a substring e verifica se coincide.
                while (check == 1 && j < strlen(sub))
                {
                    if (a[i + j] == sub[j]) /// Verifica cada elemento da substring
                    {
                        check = 1;
                    }
                    /// Se algum elemento não coincidir, pára o ciclo.
                    else
                    {
                        check = 0;
                    }
                    j++;
                }
                if (check == 0)
                {
                    novas[pointer] = a[i];
                    pointer++;
                }
                else
                {
                    i = i + strlen(sub) - 1;
                    Z.elem = (void *)novas; /// Coloca a substring criada numa posição do array.
                    Z.t = STR;
                    arr[indice] = Z;
                    memset(novas, 0, 100000);
                    pointer = 0;
                    indice++;
                }
            }
            else
            {
                novas[pointer] = a[i];
                pointer++;
            }
        }
        Z.t = STR;
        Z.elem = (void *)novas;
        arr[indice] = Z;
        arr[0].t = INT;
        arr[0].elem = (void *)(size_t)indice;
        Z.t = ARR;
        Z.elem = (void *)arr;
        push(s, Z);
        return 1;
    }
    return 0;
}
/**
 * Função que separa uma string pelos espaços e coloca cada substring num array.
 *
 */
int whitespaces(STACK *s, char *token)
{
    if (strcmp(token, "S/") == 0)
    {
        STACK_ELEM ST = pop(s);
        char *str = (char *)ST.elem;
        int pos = 1;
        char *word = malloc(100000);
        int j = 0;
        STACK_ELEM *arr = malloc(100000);
        // Ciclo que corre a string principal
        for (unsigned long int i = 0; i < strlen(str); i++)
        {
            /// Procura por espaços em branco
            if (str[i] == ' ' || i == strlen(str))
            {
                ST.t = STR;
                ST.elem = (void *)word;
                arr[pos] = ST;         /// Ao encontrar um espaço em branco, coloca a substring na próxima posição do array.
                memset(word, 0, 1000); /// Reseta a string auxiliar para receber a próxima substring.
                pos++;
                j = 0;
            }
            /// Enquanto não encontra um espaço em branco. Vai colocando a substring numa string separada.
            else
            {
                word[j] = str[i];
                j++;
            }
        }
        ST.t = INT;
        ST.elem = (void *)(size_t)(pos);
        arr[0] = ST;
        ST.t = ARR;
        ST.elem = (void *)arr;
        push(s, ST);
        return 1;
    }
    return 0;
}