// #include <stdio.h>
// int main() {

//    int i = 1;
// while (i <= 10) 
// {printf ("%d\n", i);
// i++;}




//     return 0;
// } // aprendendo a usar o while

// #include <stdio.h>
// int main() {
// int i = 11;
// do {printf ("%d\n", i); i++;} while (i <= 10);



// return 0;
// }  // aprendendo a usar o do while

// #include <stdio.h>
// int main() {
//    for (int i = 1; i <= 10; i++)
//    {
//       printf ("%d\n", i);
//    }    

// return 0;
// }  // aprendendo a usar o for

// loops_demo.c
// gcc -std=c11 -Wall -Wextra -Wpedantic loops_demo.c -o loops_demo

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <errno.h>
// #include <limits.h>
// #include <string.h>

// static void strip_newline(char *s) {
//     s[strcspn(s, "\r\n")] = '\0';
// }

// // Lê um inteiro com validação (usa WHILE)
// static bool read_int(const char *prompt, int *out) {
//     char buf[128];

//     while (1) { // <- while de validação
//         if (prompt) printf("%s", prompt);

//         if (!fgets(buf, sizeof buf, stdin)) return false; // EOF/erro
//         strip_newline(buf);

//         if (buf[0] == '\0') {
//             puts("Entrada vazia. Tente novamente.");
//             continue;
//         }

//         errno = 0;
//         char *end = NULL;
//         long v = strtol(buf, &end, 10);

//         // aceita espaços no final
//         while (end && *end == ' ') end++;

//         if (errno != 0 || end == buf || (end && *end != '\0') || v < INT_MIN || v > INT_MAX) {
//             puts("Número inválido. Digite um inteiro (ex: 0, 5, -2).");
//             continue;
//         }

//         *out = (int)v;
//         return true;
//     }
// }

// static void opcao_tabuada_for(void) {
//     int n;
//     if (!read_int("Digite um inteiro (ex: 7): ", &n)) return;

//     puts("\nTabuada (0 a 10) usando FOR:");
//     for (int i = 0; i <= 10; i++) { // <- for (contagem clara)
//         printf("%d x %d = %d\n", n, i, n * i);
//     }
// }

// static void opcao_fatorial_while(void) {
//     int n;
//     if (!read_int("Digite n (0 a 20): ", &n)) return;

//     if (n < 0 || n > 20) { // 21! estoura unsigned long long
//         puts("Fora do intervalo. Use 0 a 20.");
//         return;
//     }

//     unsigned long long fat = 1ULL;
//     int i = 2;

//     while (i <= n) { // <- while (repete enquanto condição for verdadeira)
//         fat *= (unsigned long long)i;
//         i++;
//     }

//     printf("\n%d! = %llu\n", n, fat);
// }

// int main(void) {
//     int op;

//     do { // <- do-while (menu aparece pelo menos 1 vez)
//         puts("\n=== MENU ===");
//         puts("1 - Tabuada (usa FOR)");
//         puts("2 - Fatorial (usa WHILE)");
//         puts("0 - Sair");
//         if (!read_int("> ", &op)) {
//             puts("\nEOF detectado. Saindo...");
//             break;
//         }

//         switch (op) {
//             case 1: opcao_tabuada_for(); break;
//             case 2: opcao_fatorial_while(); break;
//             case 0: puts("Saindo..."); break;
//             default: puts("Opção inválida."); break;
//         }
//     } while (op != 0);

//     return 0;
// } // aprendendo a usar os 3 tipos de loops

// #include <stdio.h>

// int main(void) {
//     int numero;

//     do {
//         printf("Digite um numero par para sair do programa: ");

//         if (scanf("%d", &numero) != 1) {
//             puts("Entrada invalida. Encerrando.");
//             return 1;
//         }

//         if (numero % 2 == 0) {
//             printf("%d eh par!\n", numero);
//         } else {
//             printf("%d eh impar!\n", numero);
//         }

//     } while (numero % 2 != 0);

//     puts("Voce digitou um numero par, saindo do programa...");
//     return 0;
// } // programa que so sai quando o usuario digita um numero par

// #include <stdio.h>

// int main(void) {
//     int altura = 5;

//     for (int i = 0; i < altura; i++) {           // controla as linhas
//         for (int j = 0; j <= i; j++) {           // imprime (i+1) hashes
//             printf(" #");
//         }
//         printf("\n");
//     }

//     return 0;
// } // aprendendo a fazer uma piramide com loops aninhados

// #include <stdio.h>

// int main(void) {
//     int i = 1;

//     while (i <= 10) {          // loop externo: linhas
//         int j = 1;             // reset do j a cada linha

//         while (j <= 10) {      // loop interno: colunas
//             printf("%d\t", i * j);
//             j++;
//         }

//         printf("\n");          // quebra de linha ao final da linha i
//         i++;
//     }

//     return 0;
// }  // aprendendo a fazer uma tabuada com loops aninhados

// #include <stdio.h>

// int main(void) {
//     for (int i = 1; i <= 10; i++) {          // loop externo (linhas)
//         for (int j = 1; j <= 10; j++) {      // loop interno (colunas)
//             printf("%d\t", i * j);
//         }
//         printf("\n");                        // quebra de linha
//     }
//     return 0;
// }   // aprendendo a fazer uma tabuada com loops aninhados usando for

// #include <stdio.h>
 
// int main() {
//     for (int i = 0, j = 10; i < j; i++, j--) {
//         printf("i = %d, j = %d\n", i, j);
//     }
//     return 0;
// } // aprendendo a usar multiplas variaveis em um for

// #include <stdio.h>
 
// int main() {
//     for (int i = 0; i < 100; i += (i % 2 == 0) ? 1 : 2) {
//         printf("%d ", i);
//     }
//     return 0;
// } // aprendendo a usar expressao condicional em um for

// #include <stdio.h>

// void recursiveLoop(int n) {
//     if (n >= 0) {
//         printf("%d ", n);
//         recursiveLoop(n - 1);
//     }
// }

// int main(void) {
//     int numero = 5;

//     printf("Contagem regressiva: ");
//     recursiveLoop(numero);
//     putchar('\n');

//     return 0;
// }
// aprendendo a fazer um loop usando recursao

