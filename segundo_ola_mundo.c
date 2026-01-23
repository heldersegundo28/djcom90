// #include <stdio.h>
// int main()
// {
//     int  num1; int resultado; 
//     printf("digite um numero: ");
//     scanf("%d", &num1);
//     resultado = num1 % 2;
//     printf("o resto da divisao de %d por 2 e: %d\n", num1, resultado);
//     if (resultado == 0)
//     {
//         printf("o numero %d e par\n", num1);
//     }
//     else
//     {
//         printf("o numero %d e impar\n", num1);
//     }
//     return 0;
// } // estou aprendendo C, no caso hoje esta sendo scanf, if, else, else if, operadores relacionais e logicos.

// #include <stdio.h>
// int main()
// {

//  int x;
//     printf("Digite um numero inteiro: ");
//     if (scanf("%d", &x) != 1) return 0;

//     if (x >= 10 && x <= 20) {
//         printf("dentro\n");
//     } else {
//         printf("fora\n");
//     }




//     return 0;
// } // aprendendo operadores logicos E (&&) e OU (||)

// #include <stdio.h>
// int main()
// {
//  int a = 1;
//  int b = 2;
// if (a == 2 && b == 2)
//  {
//     printf("verdadeiro\n");
// } 
// else 
// { printf("falso\n");}



// return 0;
// } // aprendendo operadores logicos E (&&) e OU (||)

// #include <stdio.h>

// int main() {
//   int idade;

//   printf("Digite a sua idade: \n");
//   scanf("%d", &idade);

//   if (idade < 12) {
//     printf("Você é uma criança\n");
//   } else if (idade >= 12 && idade < 18) {
//     printf("Você é um adolescente\n");
//   } else if (idade >= 18 && idade < 60) {
//     printf("Você é um adulto\n");
//   } else {
//     printf("Você é um idoso\n");
//   }
//   int nota;

//   printf("Digite a sua nota: \n");
//   scanf("%d", &nota);

//   if (nota >= 90) {
//     printf("Sua nota é A\n");
//   } else if (nota >= 80) {
//     printf("Sua nota é B\n");
//   } else if (nota >= 70) {
//     printf("Sua nota é C\n");
//   } else if (nota >= 60) {
//     printf("Sua nota é D\n");
//   } else {
//     printf("Sua nota é F\n");
//   }

//   return 0;
// } // aprendendo estrutura condicional composta if, else if e else.

// #include <stdio.h>

// int main() {
//   int idade;
//   float renda;

//   printf("Digite a sua idade: ");
//   scanf("%d", &idade);
//   printf("Digite a sua renda mensal: \n");
//   scanf("%f", &renda);

//   if (idade < 18 || idade > 60) {
//     if (renda < 2000.0) {
//       printf("Você está qualificado para o desconto especial\n");
//     } else {
//       printf("Você não está qualificado para o desconto devido à renda\n");
//     }
//   } else {
//     printf("Você não está qualificado para o desconto devido à idade\n");
//   }

//   return 0;
// } // aprendendo operadores logicos E (&&) e OU (||) com estrutura condicional composta if, else if e else.

// #include <stdio.h>

// int main(void) {
//     char op;
//     int a, b;

//     if (scanf(" %c %d %d", &op, &a, &b) != 3) return 0;

//     switch (op) {
//         case '+':
//             printf("%d\n", a + b);
//             break;
//         case '-':
//             printf("%d\n", a - b);
//             break;
//         case '*':
//             printf("%d\n", a * b);
//             break;
//         case '/':
//             if (b == 0) {
//                 printf("erro\n");
//             } else {
//                 printf("%d\n", a / b);
//             }
//             break;
//         default:
//             printf("op_invalida\n");
//             break;
//     }

//     return 0;
// } // aprendendo estrutura condicional switch case break e default.

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// static void limpar_linha(void) {
//     int ch;
//     while ((ch = getchar()) != '\n' && ch != EOF) {}
// }

// int main(void) {
//     int opcao;

//     srand((unsigned)time(NULL)); // semente uma vez

//     while (1) {
//         printf("\nMenu Principal\n");
//         printf("1. Iniciar Jogo\n");
//         printf("2. Ver Regras\n");
//         printf("3. Sair\n");
//         printf("Escolha uma opcao: ");

//         if (scanf("%d", &opcao) != 1) {
//             limpar_linha();
//             printf("Entrada invalida. Digite um numero.\n");
//             continue;
//         }

//         switch (opcao) {
//             case 1: {
//                 int numeroSecreto = rand() % 10 + 1;
//                 int palpite = 0;
//                 int tentativas = 0;

//                 printf("Adivinhe o numero (entre 1 e 10).\n");

//                 while (1) {
//                     printf("Seu palpite: ");
//                     if (scanf("%d", &palpite) != 1) {
//                         limpar_linha();
//                         printf("Entrada invalida. Tente novamente.\n");
//                         continue;
//                     }

//                     tentativas++;

//                     if (palpite < 1 || palpite > 10) {
//                         printf("Fora do intervalo! Digite de 1 a 10.\n");
//                         continue;
//                     }

//                     if (palpite == numeroSecreto) {
//                         printf("Parabens! Voce acertou em %d tentativa(s)!\n", tentativas);
//                         break;
//                     } else if (palpite < numeroSecreto) {
//                         printf("Maior!\n");
//                     } else {
//                         printf("Menor!\n");
//                     }
//                 }
//                 break;
//             }

//             case 2:
//                 printf("Regras do Jogo:\n");
//                 printf("1. Escolha uma opcao no menu.\n");
//                 printf("2. Em 'Iniciar Jogo', tente adivinhar o numero secreto (1 a 10).\n");
//                 printf("3. O jogo da dicas: 'Maior' ou 'Menor'.\n");
//                 printf("4. Para sair, escolha a opcao 3.\n");
//                 break;

//             case 3:
//                 printf("Saindo...\n");
//                 return 0;

//             default:
//                 printf("Opcao invalida. Tente novamente.\n");
//                 break;
//         }
//     }
// } // aprendendo estrutura condicional switch case break e default com um jogo de adivinhação.

