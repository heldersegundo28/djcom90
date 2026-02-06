// #include <stdio.h>

// int main() {
//     char tabuleiro[5][5];
//     int navio[2] = {2, 3}; // posição fixa do navio
//     int linha, coluna;
//     int acertou = 0;

//     // Inicializar tabuleiro
//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             tabuleiro[i][j] = '~';
//         }
//     }

//     // Repetir até acertar
//     while(acertou == 0) {

//         // Mostrar tabuleiro
//         for(int i = 0; i < 5; i++) {
//             for(int j = 0; j < 5; j++) {
//                 printf("%c ", tabuleiro[i][j]);
//             }
//             printf("\n");
//         }

//         // Jogada
//         printf("Digite linha e coluna (0 a 4): ");
//         if (scanf("%d %d", &linha, &coluna) != 2) {
//     printf("Entrada invalida! Digite dois numeros.\n");
//     while (getchar() != '\n'); // limpa buffer
//     continue;
// }


//         // Verificar limites
//         if(linha < 0 || linha >= 5 || coluna < 0 || coluna >= 5) {
//             printf("Posicao invalida!\n");
//             continue;
//         }

//         // Verificar acerto
//         if(linha == navio[0] && coluna == navio[1]) {
//             tabuleiro[linha][coluna] = 'X';
//             printf("🎯 Acertou o navio!\n");
//             acertou = 1;
//         } else {
//             tabuleiro[linha][coluna] = 'O';
//             printf("💦 Agua!\n");
//         }
//     }

//     // Mostrar tabuleiro final
//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             printf("%c ", tabuleiro[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
//}
// Este programa é um jogo simples de batalha naval, onde o jogador tenta acertar a posição de um navio em um tabuleiro 5x5. O navio está fixo na posição (2, 3). O jogador insere as coordenadas para tentar acertar o navio, e o programa indica se foi um acerto ou um erro, atualizando o tabuleiro a cada jogada. O jogo continua até que o navio seja acertado.

// Programa em C que lê 5 notas, armazena em um vetor e em uma matriz,
// calcula a soma e a média, e exibe a matriz e a média.
#include <stdio.h>
int main () {
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

for (int i = 0; i < 2; i++) {       // linhas
    for (int j = 0; j < 3; j++) {   // colunas
        printf("%d ", m[i][j]);
    }
    printf("\n");
}
return 0;
} // aprendendo a usar matrizes em C. Este programa define uma matriz 2x3, preenche com valores de 1 a 6, e depois imprime os valores da matriz no console.