// Notas //

// ESTUDAR //

##########// BINWALK //############!!!
1 - ANINHAMENTO DE REPETICAO
2 - COMANDOS BREAK, CONTINUE, GOTO
3 - BIBLIOTECA string.h

// Tipos da linguegem C // 
char 	letras e símbolos:   'a',  'b', 'H', '^', '*','1','0'
short int 	de -32767 até 32767 (apenas números inteiros)
int numero inteiros
float 	de -3.4 x 1038 até +3.4 x 10+38com até 6 dígitos de precisão
double 	de -1.7 x 10308 até +1.7 x 10+308com até 10 dígitos de precisão

///////////////////////////////////////////////////////////////////////////////

// Esqueleto basico de um programa em C // 
#include <stdio.h>

// Protótipo de função
void minhaFuncao(void);

int main() {
    // Declaração e inicialização de variáveis
    int a = 5;

    // Chamada de função
    minhaFuncao();

    // Operação e saída
    printf("Valor de a: %d\n", a);

    // Retorno do programa
    return 0;
}

// Definição da função
void minhaFuncao(void) {
    printf("Dentro da função minhaFuncao.\n");
}

///////////////////////////////////////////////////////////////////////////////

// Sintaxe do Operador Ternário //

#include <stdio.h>

int main() {
    int a = 5, b = 10;
    int maior;

    maior = (a > b) ? a : b;  // Se a > b, maior recebe a; caso contrário, recebe b

    printf("O maior valor é %d\n", maior);  // Saída: O maior valor é 10

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

1 - Declarando constantes:
    #define VALOR_DE_PI 3.1415   // Não se coloca ponto-e-vírgula após o valor
    #define LARGURA_MAXIMA 50 

2 - Inicializacao de variaveis com valores
    double pi = 3.1415;
    int largura_maxima = 50;

3 - Especificadores de formato (printf())

    Inteiros

    %d ou %i: Inteiro decimal com sinal.
    %u: Inteiro decimal sem sinal.
    %o: Inteiro em octal.
    %x: Inteiro em hexadecimal (minúsculas).
    %X: Inteiro em hexadecimal (maiúsculas).

    Caracteres e Strings

    %c: Caractere.
    %s: String (sequência de caracteres terminada em nulo).

    Ponto Flutuante

    %f: Número de ponto flutuante (float).
    %e ou %E: Notação científica (com 'e' ou 'E').
    %g ou %G: Usa %f ou %e/%E, o que for mais curto.
    %a ou %A: Notação hexadecimal para ponto flutuante.

    Ponteiros

    %p: Endereço de ponteiro.