# AI Coding Guidelines for djcom90

## Project Overview
This is a C programming learning repository with simple console applications. The main project is a Super Trunfo (Top Trumps) card game implementation in `super_trunfo.c`.

## Code Structure and Patterns
- Use Portuguese for comments, variable names, and user-facing strings (e.g., "Populacao", "Cidade", "Digite o nome").
- Define data structures using `typedef struct` (e.g., `Carta` in `super_trunfo.c`).
- Modularize code with functions for input, output, and logic (e.g., `cadastrar_carta`, `mostrar_carta`, `comparar`).
- Handle input buffering: Use `limpar_buffer()` after `scanf` to consume leftover newline characters.
- For string input with spaces: Use `fgets` followed by manual newline removal (see `ler_texto` function).
- Numeric inputs: Use `scanf` with appropriate formats (`%lld` for `long long`, `%lf` for `double`).

## Comparison Logic
- Implement attribute comparison using `(a > b) - (a < b)` for integer-like results (-1, 0, 1) instead of if-else chains (see `comparar` function).

## User Interaction
- Use `do-while` loops for replay functionality, checking for 's' or 'S' input.
- Display results with clear labels and formatting (e.g., "\n--- DADOS DO ALUNO ---\n").

## Build and Run
- Compile with `gcc -o <output> <source>.c` (e.g., `gcc -o super_trunfo super_trunfo.c`).
- Run the executable directly (e.g., `./super_trunfo`).

## Key Files
- `super_trunfo.c`: Exemplifies complete program structure with struct, functions, and main loop.
- `primeiro_ola_mundo.c`: Shows learning progression with commented code versions.