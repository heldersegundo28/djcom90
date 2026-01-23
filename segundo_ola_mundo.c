#include <stdio.h>
int main()
{
    int  num1; int resultado; 
    printf("digite um numero: ");
    scanf("%d", &num1);
    resultado = num1 % 2;
    printf("o resto da divisao de %d por 2 e: %d\n", num1, resultado);
    if (resultado == 0)
    {
        printf("o numero %d e par\n", num1);
    }
    else
    {
        printf("o numero %d e impar\n", num1);
    }
    return 0;
} // estou aprendendo C, no caso hoje esta sendo scanf, if, else, else if, operadores relacionais e logicos.