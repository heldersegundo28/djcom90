// chess_moves.c - valida movimentos básicos de xadrez (sem roque/en passant/promoção/xeque)
// Compilar: gcc -std=c11 -Wall -Wextra -Wpedantic chess_moves.c -o chess_moves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum { COLOR_NONE = 0, WHITE, BLACK } Color;
typedef enum { EMPTY = 0, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } PieceType;

typedef struct {
    PieceType type;
    Color color;
} Piece;

static int abs_i(int x) { return x < 0 ? -x : x; }

static char piece_to_char(Piece p) {
    if (p.type == EMPTY) return '.';
    char c = '?';
    switch (p.type) {
        case PAWN:   c = 'P'; break;
        case KNIGHT: c = 'N'; break;
        case BISHOP: c = 'B'; break;
        case ROOK:   c = 'R'; break;
        case QUEEN:  c = 'Q'; break;
        case KING:   c = 'K'; break;
        default:     c = '?'; break;
    }
    if (p.color == BLACK) c = (char)tolower((unsigned char)c);
    return c;
}

static bool parse_square(const char s[3], int *row, int *col) {
    // s: "a1".."h8"
    if (!s || strlen(s) < 2) return false;
    char file = (char)tolower((unsigned char)s[0]);
    char rank = s[1];
    if (file < 'a' || file > 'h') return false;
    if (rank < '1' || rank > '8') return false;

    *col = file - 'a';
    // linha 0 = rank 8 (topo), linha 7 = rank 1 (base)
    *row = 8 - (rank - '0');
    return true;
}

static void print_board(const Piece board[8][8]) {
    puts("    a b c d e f g h");
    puts("  +-----------------+");
    for (int r = 0; r < 8; r++) {
        int rank = 8 - r;
        printf("%d | ", rank);
        for (int c = 0; c < 8; c++) {
            printf("%c ", piece_to_char(board[r][c]));
        }
        printf("| %d\n", rank);
    }
    puts("  +-----------------+");
    puts("    a b c d e f g h");
}

static void init_board(Piece board[8][8]) {
    // limpa
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            board[r][c] = (Piece){ .type = EMPTY, .color = COLOR_NONE };

    // peças brancas (rank 1 e 2) -> linhas 7 e 6
    board[7][0] = (Piece){ROOK,   WHITE};
    board[7][1] = (Piece){KNIGHT, WHITE};
    board[7][2] = (Piece){BISHOP, WHITE};
    board[7][3] = (Piece){QUEEN,  WHITE};
    board[7][4] = (Piece){KING,   WHITE};
    board[7][5] = (Piece){BISHOP, WHITE};
    board[7][6] = (Piece){KNIGHT, WHITE};
    board[7][7] = (Piece){ROOK,   WHITE};
    for (int c = 0; c < 8; c++) board[6][c] = (Piece){PAWN, WHITE};

    // peças pretas (rank 8 e 7) -> linhas 0 e 1
    board[0][0] = (Piece){ROOK,   BLACK};
    board[0][1] = (Piece){KNIGHT, BLACK};
    board[0][2] = (Piece){BISHOP, BLACK};
    board[0][3] = (Piece){QUEEN,  BLACK};
    board[0][4] = (Piece){KING,   BLACK};
    board[0][5] = (Piece){BISHOP, BLACK};
    board[0][6] = (Piece){KNIGHT, BLACK};
    board[0][7] = (Piece){ROOK,   BLACK};
    for (int c = 0; c < 8; c++) board[1][c] = (Piece){PAWN, BLACK};
}

static bool in_bounds(int r, int c) { return r >= 0 && r < 8 && c >= 0 && c < 8; }

static bool path_clear_straight(const Piece board[8][8], int r1, int c1, int r2, int c2) {
    int dr = (r2 > r1) ? 1 : (r2 < r1 ? -1 : 0);
    int dc = (c2 > c1) ? 1 : (c2 < c1 ? -1 : 0);

    // deve ser linha ou coluna
    if (!((dr == 0 && dc != 0) || (dr != 0 && dc == 0))) return false;

    int r = r1 + dr, c = c1 + dc;
    while (r != r2 || c != c2) {
        if (board[r][c].type != EMPTY) return false;
        r += dr; c += dc;
    }
    return true;
}

static bool path_clear_diagonal(const Piece board[8][8], int r1, int c1, int r2, int c2) {
    int dr = r2 - r1;
    int dc = c2 - c1;
    if (abs_i(dr) != abs_i(dc) || dr == 0) return false;

    int step_r = (dr > 0) ? 1 : -1;
    int step_c = (dc > 0) ? 1 : -1;

    int r = r1 + step_r, c = c1 + step_c;
    while (r != r2 && c != c2) {
        if (board[r][c].type != EMPTY) return false;
        r += step_r; c += step_c;
    }
    return true;
}

static bool valid_pawn_move(const Piece board[8][8],
                           Color color, int r1, int c1, int r2, int c2) {
    int dir = (color == WHITE) ? -1 : 1; // brancas sobem (linha diminui)
    int start_row = (color == WHITE) ? 6 : 1;

    int dr = r2 - r1;
    int dc = c2 - c1;

    Piece dest = board[r2][c2];

    // avanço reto (sem captura)
    if (dc == 0) {
        // 1 passo
        if (dr == dir && dest.type == EMPTY) return true;

        // 2 passos a partir da linha inicial
        if (r1 == start_row && dr == 2 * dir) {
            int mid_r = r1 + dir;
            if (board[mid_r][c1].type == EMPTY && dest.type == EMPTY) return true;
        }
        return false;
    }

    // captura diagonal (1 passo)
    if (abs_i(dc) == 1 && dr == dir) {
        if (dest.type != EMPTY && dest.color != color) return true;
        return false;
    }

    return false;
}

static bool is_valid_move(const Piece board[8][8],
                          int r1, int c1, int r2, int c2,
                          Color turn, const char **reason) {
    if (!in_bounds(r1,c1) || !in_bounds(r2,c2)) {
        if (reason) *reason = "fora do tabuleiro";
        return false;
    }

    Piece from = board[r1][c1];
    Piece to   = board[r2][c2];

    if (from.type == EMPTY) {
        if (reason) *reason = "casa de origem vazia";
        return false;
    }
    if (from.color != turn) {
        if (reason) *reason = "nao eh sua vez / peca do adversario";
        return false;
    }
    if (r1 == r2 && c1 == c2) {
        if (reason) *reason = "origem = destino";
        return false;
    }
    if (to.type != EMPTY && to.color == turn) {
        if (reason) *reason = "destino ocupado por peca sua";
        return false;
    }

    int dr = r2 - r1;
    int dc = c2 - c1;

    switch (from.type) {
        case PAWN: {
            bool ok = valid_pawn_move(board, from.color, r1, c1, r2, c2);
            if (!ok && reason) *reason = "movimento invalido de peao";
            return ok;
        }
        case KNIGHT: {
            int adr = abs_i(dr), adc = abs_i(dc);
            bool ok = (adr == 2 && adc == 1) || (adr == 1 && adc == 2);
            if (!ok && reason) *reason = "movimento invalido de cavalo";
            return ok;
        }
        case BISHOP: {
            bool ok = path_clear_diagonal(board, r1, c1, r2, c2);
            if (!ok && reason) *reason = "bispo precisa andar na diagonal sem bloqueio";
            return ok;
        }
        case ROOK: {
            bool ok = path_clear_straight(board, r1, c1, r2, c2);
            if (!ok && reason) *reason = "torre precisa andar reto sem bloqueio";
            return ok;
        }
        case QUEEN: {
            bool ok = path_clear_straight(board, r1, c1, r2, c2) ||
                      path_clear_diagonal(board, r1, c1, r2, c2);
            if (!ok && reason) *reason = "rainha anda reto ou diagonal sem bloqueio";
            return ok;
        }
        case KING: {
            bool ok = abs_i(dr) <= 1 && abs_i(dc) <= 1;
            if (!ok && reason) *reason = "rei anda 1 casa (roque nao implementado)";
            return ok;
        }
        default:
            if (reason) *reason = "tipo de peca desconhecido";
            return false;
    }
}

static void do_move(Piece board[8][8], int r1, int c1, int r2, int c2) {
    board[r2][c2] = board[r1][c1];
    board[r1][c1] = (Piece){EMPTY, COLOR_NONE};
}

int main(void) {
    Piece board[8][8];
    init_board(board);

    Color turn = WHITE;
    char line[128];

    puts("Xadrez (movimentos basicos). Digite jogadas como: e2 e4");
    puts("Comandos: board | reset | quit");
    print_board(board);

    while (1) {
        printf("\nTurno: %s > ", (turn == WHITE) ? "BRANCAS" : "PRETAS");
        if (!fgets(line, sizeof line, stdin)) break;

        // remove newline
        line[strcspn(line, "\r\n")] = '\0';

        if (strcmp(line, "quit") == 0) break;
        if (strcmp(line, "board") == 0) { print_board(board); continue; }
        if (strcmp(line, "reset") == 0) { init_board(board); turn = WHITE; print_board(board); continue; }
        if (line[0] == '\0') continue;

        char a[8], b[8];
        if (sscanf(line, " %7s %7s", a, b) != 2) {
            puts("Entrada invalida. Use: e2 e4  (ou board/reset/quit)");
            continue;
        }

        int r1,c1,r2,c2;
        if (!parse_square(a, &r1, &c1) || !parse_square(b, &r2, &c2)) {
            puts("Casa invalida. Use algo como a1..h8");
            continue;
        }

        const char *reason = NULL;
        if (!is_valid_move(board, r1,c1,r2,c2, turn, &reason)) {
            printf("ILLEGAL: %s\n", reason ? reason : "movimento invalido");
            continue;
        }

        do_move(board, r1,c1,r2,c2);
        print_board(board);

        turn = (turn == WHITE) ? BLACK : WHITE;
    }

    puts("Fim.");
    return 0;
} // chess_moves.c
