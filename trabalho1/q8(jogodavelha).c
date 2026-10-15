#include <stdio.h>
#include <ctype.h>

void inicializarTabuleiro(char tabuleiro[3][3]);
void mostrarTabuleiro(char tabuleiro[3][3]);
int jogadaValida(char tabuleiro[3][3], char linha, int coluna);
void fazerJogada(char tabuleiro[3][3], char linha, int coluna, char simbolo);
int verificarVencedor(char tabuleiro[3][3], char simbolo);
int tabuleiroCheio(char tabuleiro[3][3]);

int main()
{
    char tabuleiro[3][3];
    char entrada[10]; 
    int jogador = 1;
    char simbolo;
    int fim = 0;

    inicializarTabuleiro(tabuleiro);

    while(!fim) {
        mostrarTabuleiro(tabuleiro);

        simbolo = (jogador == 1) ? 'X' : '0';

        printf("Jogador %d, informe sua jogada: ", jogador);
        scanf("%s", entrada);

        char linha = toupper(entrada[0]);
        int coluna = entrada[1] - '0'; 
      
        if(jogadaValida(tabuleiro, linha, coluna)) {
            fazerJogada(tabuleiro, linha, coluna, simbolo);

            if(verificarVencedor(tabuleiro, simbolo)) {
                mostrarTabuleiro(tabuleiro);
                printf("Jogador %d venceu!\n", jogador);
                fim = 1;
            }
            else if(tabuleiroCheio(tabuleiro)) {
                mostrarTabuleiro(tabuleiro);
                printf("Nao houve ganhador.\n");
                fim = 1;
            }
            else {
                jogador = (jogador == 1) ? 2 : 1;
            }
        }
        else {
            printf("\n>>> Jogada invalida! Use letras de A a C e numeros de 1 a 3 para posicoes vazias (ex: B2).\n");
        }
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[3][3])
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiro(char tabuleiro[3][3])
{
    printf("\n");
    printf("    1   2   3\n");
    printf("A   %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("   ---+---+---\n");
    printf("B   %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("   ---+---+---\n");
    printf("C   %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int jogadaValida(char tabuleiro[3][3], char linha, int coluna)
{

    if(linha < 'A' || linha > 'C') return 0;
    if(coluna < 1 || coluna > 3) return 0;

    int i = linha - 'A';
    int j = coluna - 1;

    if(tabuleiro[i][j] != ' ') return 0;

    return 1;
}

void fazerJogada(char tabuleiro[3][3], char linha, int coluna, char simbolo)
{
    int i = linha - 'A';
    int j = coluna - 1;
    tabuleiro[i][j] = simbolo;
}

int verificarVencedor(char tabuleiro[3][3], char simbolo)
{
  
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo) return 1;
        if(tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo) return 1;
    }
  
    if(tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo) return 1;
    if(tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo) return 1;

    return 0;
}

int tabuleiroCheio(char tabuleiro[3][3])
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1; 
}
