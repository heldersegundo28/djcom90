#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    long long populacao;
    double area;
    double pib;
    int pontos;
} Carta;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ler_texto(const char *msg, char *dest, int tam) {
    printf("%s", msg);
    fgets(dest, tam, stdin);
    for (int i = 0; dest[i]; i++) {
        if (dest[i] == '\n') {
            dest[i] = '\0';
            break;
        }
    }
}

void cadastrar_carta(Carta *c) {
    ler_texto("Estado (ex: SP): ", c->estado, sizeof(c->estado));
    ler_texto("Codigo da carta: ", c->codigo, sizeof(c->codigo));
    ler_texto("Cidade: ", c->cidade, sizeof(c->cidade));

    printf("Populacao: ");
    scanf("%lld", &c->populacao);

    printf("Area (km²): ");
    scanf("%lf", &c->area);

    printf("PIB: ");
    scanf("%lf", &c->pib);

    printf("Pontos turisticos: ");
    scanf("%d", &c->pontos);

    limpar_buffer();
}

void mostrar_carta(Carta c) {
    printf("\n%s - %s (%s)\n", c.estado, c.cidade, c.codigo);
    printf("Populacao: %lld\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos turisticos: %d\n", c.pontos);
}

int comparar(Carta a, Carta b, int op) {
    if (op == 1) return (a.populacao > b.populacao) - (a.populacao < b.populacao);
    if (op == 2) return (a.area > b.area) - (a.area < b.area);
    if (op == 3) return (a.pib > b.pib) - (a.pib < b.pib);
    if (op == 4) return (a.pontos > b.pontos) - (a.pontos < b.pontos);
    return 0;
}

int main() {
    Carta c1, c2;
    int opcao, resultado;
    char continuar;

    do {
        printf("\n=== SUPER TRUNFO – CIDADES ===\n");

        printf("\nCadastro da CARTA 1\n");
        cadastrar_carta(&c1);

        printf("\nCadastro da CARTA 2\n");
        cadastrar_carta(&c2);

        printf("\nEscolha o atributo:\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos turisticos\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        mostrar_carta(c1);
        mostrar_carta(c2);

        resultado = comparar(c1, c2, opcao);

        printf("\nRESULTADO: ");
        if (resultado > 0)
            printf("Carta 1 venceu!\n");
        else if (resultado < 0)
            printf("Carta 2 venceu!\n");
        else
            printf("Empate!\n");

        printf("\nJogar novamente? (s/n): ");
        scanf(" %c", &continuar);
        limpar_buffer();

    } while (continuar == 's' || continuar == 'S');

    printf("\nPrograma encerrado.\n");
    return 0;
}
