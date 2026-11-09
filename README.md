# Fundamentos de programação em C

Repositório de estudos da formação em Análise e Desenvolvimento de Sistemas. Reúne anotações da evolução do aprendizado e programas de terminal.

## Programas executáveis

| Arquivo | Conteúdo |
| --- | --- |
| `super_trunfo.c` | Cadastro de até 32 cartas de cidades, consulta e comparação de atributos |
| `chess.c` | Simulação de movimentos básicos de xadrez por turnos |
| `quarto_ola_mundo.c` | Exibição de uma matriz 2×3 |

Os arquivos `primeiro_ola_mundo.c`, `segundo_ola_mundo.c` e `terceiro_ola_mundo.c` preservam exemplos comentados de entrada/saída, condições e repetição. Eles não possuem um programa ativo para executar diretamente.

## Compilar e executar

Instale um compilador C compatível com C11, como GCC. No Windows, utilize um ambiente com GCC disponível no PATH.

~~~bash
git clone https://github.com/heldersegundo28/djcom90.git
cd djcom90
gcc -std=c11 -Wall -Wextra super_trunfo.c -o super_trunfo
gcc -std=c11 -Wall -Wextra chess.c -o chess
gcc -std=c11 -Wall -Wextra quarto_ola_mundo.c -o quarto_ola_mundo
~~~

No Linux/macOS, execute `./super_trunfo`. No PowerShell, execute `.\super_trunfo.exe`. O mesmo padrão vale para os outros programas.

### Super Trunfo

Use o menu numérico para cadastrar, exibir ou comparar cartas. Os códigos usam estados A–H e cidades 1–4. Na comparação, a menor densidade vence; nos demais atributos, vence o maior valor.

O programa mantém os dados somente em memória e ainda requer validação mais completa para entradas inválidas.

### Xadrez

Digite movimentos como `e2 e4`. Os comandos `board`, `reset` e `quit` exibem o tabuleiro, reiniciam a posição e encerram o programa.

A implementação valida movimentos básicos e bloqueios. Não implementa xeque, xeque-mate, roque, en passant ou promoção; portanto, é um simulador didático, sem todas as regras de uma partida oficial.

## Organização e verificação

Os códigos-fonte são preservados como registro do aprendizado. Executáveis devem ser gerados localmente e estão no `.gitignore`.

O GitHub Actions compila os três programas ativos e verifica a saída da matriz e os comandos básicos do simulador de xadrez.

