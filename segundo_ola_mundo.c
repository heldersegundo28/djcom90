#include <stdio.h>
int main()
{
    int  num1;
    int num2;
    printf("digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("digite o segundo numero: ");
    scanf("%d", &num2);
    if (num1 > num2)
    {
        printf("num1 é maior que num2\n");
    }
    else if (num1 < num2) {
        printf("num2 é maior que num1\n");
    } 
    else {
        printf("os numeros sao iguais\n");
    }
    
    return 0;
} // estou aprendendo C, no caso hoje esta sendo scanf, if, else, else if, operadores relacionais e logicos.