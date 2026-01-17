#include <stdio.h>

#define ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CARTAS (ESTADOS * CIDADES_POR_ESTADO)

typedef struct {
    char codigo[4];          // Ex: "A01"
    char nome[60];           // Cidade
    long long populacao;     // População
    double area;             // Área km²
    double pib;              // PIB
    int pontos;              // Pontos turísticos

    // Calculadas
    double densidade;        // População / área
    double pib_per_capita;   // PIB / população

    // "Super Poder"
    double super_poder;      // Soma de todas as propriedades (inseridas + calculadas)
} Carta;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void ler_texto(const char *msg, char *dest, int tam) {
    printf("%s", msg);
    if (fgets(dest, tam, stdin) != NULL) {
        for (int i = 0; dest[i]; i++) {
            if (dest[i] == '\n') { dest[i] = '\0'; break; }
        }
    }
}

int codigo_valido(char estado, int cidade) {
    return (estado >= 'A' && estado <= 'H' && cidade >= 1 && cidade <= 4);
}

void gerar_codigo(char estado, int cidade, char codigo[4]) {
    codigo[0] = estado;
    codigo[1] = '0';
    codigo[2] = (char)('0' + cidade);
    codigo[3] = '\0';
}

int indice_carta(char estado, int cidade) {
    int e = estado - 'A';   // 0..7
    int c = cidade - 1;     // 0..3
    return e * CIDADES_POR_ESTADO + c;
}

void calcular(Carta *c) {
    // Evita divisão por zero
    c->densidade = (c->area > 0.0) ? ((double)c->populacao / c->area) : 0.0;
    c->pib_per_capita = (c->populacao > 0) ? (c->pib / (double)c->populacao) : 0.0;

    // Super Poder: soma de tudo (inserido + calculado)
    // Obs: densidade entra como valor bruto mesmo (como você pediu: soma de todas as propriedades)
    c->super_poder =
        (double)c->populacao +
        c->area +
        c->pib +
        (double)c->pontos +
        c->densidade +
        c->pib_per_capita;
}

void cadastrar_carta(Carta *c, char estado, int cidade) {
    gerar_codigo(estado, cidade, c->codigo);

    printf("\n=== Cadastro da carta %s ===\n", c->codigo);

    ler_texto("Nome da cidade: ", c->nome, sizeof(c->nome));

    printf("Populacao: ");
    scanf("%lld", &c->populacao);
    limpar_buffer();

    printf("Area (km^2): ");
    scanf("%lf", &c->area);
    limpar_buffer();

    printf("PIB: ");
    scanf("%lf", &c->pib);
    limpar_buffer();

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontos);
    limpar_buffer();

    calcular(c);
}

void exibir_carta(const Carta *c) {
    printf("\n--- CARTA %s ---\n", c->codigo);
    printf("Cidade: %s\n", c->nome);
    printf("Populacao: %lld\n", c->populacao);
    printf("Area (km^2): %.2f\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Pontos turisticos: %d\n", c->pontos);
    printf("Densidade Populacional: %.2f hab/km^2\n", c->densidade);
    printf("PIB per Capita: %.6f\n", c->pib_per_capita);
    printf("Super Poder (soma): %.2f\n", c->super_poder);
}

void print_resultado(const char *nome_prop, int vencedor) {
    // vencedor: 1 = carta1, 2 = carta2, 0 = empate
    if (vencedor == 1) printf("%s: Carta 1 venceu\n", nome_prop);
    else if (vencedor == 2) printf("%s: Carta 2 venceu\n", nome_prop);
    else printf("%s: Empate\n", nome_prop);
}

int comparar_maior_double(double a, double b) {
    if (a > b) return 1;
    if (a < b) return 2;
    return 0;
}
int comparar_menor_double(double a, double b) {
    if (a < b) return 1;
    if (a > b) return 2;
    return 0;
}
int comparar_maior_ll(long long a, long long b) {
    if (a > b) return 1;
    if (a < b) return 2;
    return 0;
}
int comparar_maior_int(int a, int b) {
    if (a > b) return 1;
    if (a < b) return 2;
    return 0;
}

void comparar_cartas(const Carta *c1, const Carta *c2) {
    printf("\n=== COMPARACAO ===\n");
    printf("Carta 1: %s - %s\n", c1->codigo, c1->nome);
    printf("Carta 2: %s - %s\n\n", c2->codigo, c2->nome);

    // Regras:
    // - Densidade: menor vence
    // - Outras: maior vence
    print_resultado("Populacao", comparar_maior_ll(c1->populacao, c2->populacao));
    print_resultado("Area", comparar_maior_double(c1->area, c2->area));
    print_resultado("PIB", comparar_maior_double(c1->pib, c2->pib));
    print_resultado("Pontos turisticos", comparar_maior_int(c1->pontos, c2->pontos));
    print_resultado("Densidade Populacional (MENOR vence)", comparar_menor_double(c1->densidade, c2->densidade));
    print_resultado("PIB per Capita", comparar_maior_double(c1->pib_per_capita, c2->pib_per_capita));
    print_resultado("Super Poder (soma)", comparar_maior_double(c1->super_poder, c2->super_poder));
}

int main() {
    Carta cartas[TOTAL_CARTAS];
    int cadastrada[TOTAL_CARTAS] = {0};

    int opcao;
    char estado;
    int cidade;

    do {
        printf("\n=== SUPER TRUNFO (CIDADES) ===\n");
        printf("1 - Cadastrar carta (A-H e 1-4)\n");
        printf("2 - Exibir uma carta\n");
        printf("3 - Exibir todas as cartas cadastradas\n");
        printf("4 - Comparar duas cartas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        if (opcao == 1) {
            printf("\nEstado (A a H): ");
            scanf(" %c", &estado);
            limpar_buffer();

            printf("Cidade (1 a 4): ");
            scanf("%d", &cidade);
            limpar_buffer();

            if (!codigo_valido(estado, cidade)) {
                printf("Codigo invalido. Use estado A-H e cidade 1-4.\n");
                continue;
            }

            int idx = indice_carta(estado, cidade);

            if (cadastrada[idx]) {
                printf("Carta %c0%d ja cadastrada. Sobrescrever? (s/n): ", estado, cidade);
                char resp;
                scanf(" %c", &resp);
                limpar_buffer();
                if (!(resp == 's' || resp == 'S')) continue;
            }

            cadastrar_carta(&cartas[idx], estado, cidade);
            cadastrada[idx] = 1;
            printf("Carta cadastrada com sucesso.\n");

        } else if (opcao == 2) {
            printf("\nEstado (A a H): ");
            scanf(" %c", &estado);
            limpar_buffer();

            printf("Cidade (1 a 4): ");
            scanf("%d", &cidade);
            limpar_buffer();

            if (!codigo_valido(estado, cidade)) {
                printf("Codigo invalido.\n");
                continue;
            }

            int idx = indice_carta(estado, cidade);
            if (!cadastrada[idx]) {
                printf("Carta %c0%d nao cadastrada.\n", estado, cidade);
            } else {
                exibir_carta(&cartas[idx]);
            }

        } else if (opcao == 3) {
            int achei = 0;
            for (int i = 0; i < TOTAL_CARTAS; i++) {
                if (cadastrada[i]) {
                    exibir_carta(&cartas[i]);
                    achei = 1;
                }
            }
            if (!achei) printf("\nNenhuma carta cadastrada ainda.\n");

        } else if (opcao == 4) {
            char e1, e2;
            int ci1, ci2;

            printf("\n--- Escolha a CARTA 1 ---\n");
            printf("Estado (A a H): ");
            scanf(" %c", &e1);
            limpar_buffer();
            printf("Cidade (1 a 4): ");
            scanf("%d", &ci1);
            limpar_buffer();

            printf("\n--- Escolha a CARTA 2 ---\n");
            printf("Estado (A a H): ");
            scanf(" %c", &e2);
            limpar_buffer();
            printf("Cidade (1 a 4): ");
            scanf("%d", &ci2);
            limpar_buffer();

            if (!codigo_valido(e1, ci1) || !codigo_valido(e2, ci2)) {
                printf("Codigo(s) invalido(s).\n");
                continue;
            }

            int idx1 = indice_carta(e1, ci1);
            int idx2 = indice_carta(e2, ci2);

            if (!cadastrada[idx1]) {
                printf("Carta 1 (%c0%d) nao cadastrada.\n", e1, ci1);
                continue;
            }
            if (!cadastrada[idx2]) {
                printf("Carta 2 (%c0%d) nao cadastrada.\n", e2, ci2);
                continue;
            }

            // Mostra as duas e compara
            exibir_carta(&cartas[idx1]);
            exibir_carta(&cartas[idx2]);
            comparar_cartas(&cartas[idx1], &cartas[idx2]);

        } else if (opcao == 0) {
            printf("\nEncerrando...\n");
        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
