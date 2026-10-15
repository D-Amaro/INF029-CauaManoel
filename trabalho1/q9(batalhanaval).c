#include <stdio.h>
#include <stdlib.h>

int QTD_NAVIOS = 5;

int TAMANHOS[5] = {4, 3, 1, 1, 1};

#define LINHAS 10
#define COLUNAS 10

void inicializarTabuleiro(char tab[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tab[i][j] = ' '; 
        }
    }
}

void exibirTabuleiro(char tab[LINHAS][COLUNAS], int ocultar) {
    printf("  ");
    for (int j = 0; j < COLUNAS; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUNAS; j++) {
            if (ocultar == 1 && tab[i][j] == 'N') {
                printf("[ ]");
            } else {
                printf("[%c]", tab[i][j]);
            }
        }
        printf("\n");
    }
}

int posicionarNavio(char tab[LINHAS][COLUNAS], int tamanho, int lInicial, int cInicial, char orientacao) {
 
    if (orientacao == 'H' || orientacao == 'h') {
        if (cInicial + tamanho > COLUNAS) return 0; 
    } else {
        if (lInicial + tamanho > LINHAS) return 0; 
    }


    for (int i = 0; i < tamanho; i++) {
        int l = lInicial;
        int c = cInicial;
        if (orientacao == 'H' || orientacao == 'h') c += i;
        else l += i;

        if (tab[l][c] != ' ') return 0; 
    }

 
    for (int i = 0; i < tamanho; i++) {
        int l = lInicial;
        int c = cInicial;
        if (orientacao == 'H' || orientacao == 'h') c += i;
        else l += i;

        tab[l][c] = 'N'; 
    }
    return 1; 
}


int atirar(char tab[LINHAS][COLUNAS], int l, int c) {
    if (l < 0 || l >= LINHAS || c < 0 || c >= COLUNAS) {
        printf("Tiro fora do tabuleiro!\n");
        return 0;
    }

    if (tab[l][c] == 'N') {
        tab[l][c] = 'O'; 
        printf(">>> ACERTOU UM NAVIO! <<<\n");
        return 1;
    } else if (tab[l][c] == ' ') {
        tab[l][c] = 'X'; 
        printf(">>> TIRO NA AGUA! <<<\n");
        return 0;
    } else {
        printf("Você já atirou nesta posição.\n");
        return 0;
    }
}

int verificarVitoria(char tab[LINHAS][COLUNAS]) {
  
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tab[i][j] == 'N') {
                return 0; 
            }
        }
    }
    return 1; 
}


int main() {
    char tabJ1[LINHAS][COLUNAS];
    char tabJ2[LINHAS][COLUNAS];

    inicializarTabuleiro(tabJ1);
    inicializarTabuleiro(tabJ2);

    printf("--- FASE DE POSICIONAMENTO ---\n");
    for (int jogador = 1; jogador <= 2; jogador++) {
        printf("\nJOGADOR %d, posicione seus %d navios!\n", jogador, QTD_NAVIOS);
        char (*tabAtual)[COLUNAS] = (jogador == 1) ? tabJ1 : tabJ2;

        for (int i = 0; i < QTD_NAVIOS; i++) {
            int posicionado = 0;
            while (posicionado == 0) {
                exibirTabuleiro(tabAtual, 0);
                int l, c;
                char ori = 'H';
                
                printf("Navio %d (Tamanho %d). Informe Linha (0-9) e Coluna (0-9): ", i+1, TAMANHOS[i]);
                scanf("%d %d", &l, &c);
                
                if (TAMANHOS[i] > 1) {
                    printf("Orientacao (H para Horizontal, V para Vertical): ");
                    scanf(" %c", &ori);
                }

                if (posicionarNavio(tabAtual, TAMANHOS[i], l, c, ori)) {
                    posicionado = 1;
                    printf("Navio posicionado com sucesso!\n\n");
                } else {
                    printf("Posição inválida ou sobreposta! Tente novamente.\n\n");
                }
            }
        }
       
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
    }

    
    printf("--- FASE DE BATALHA ---\n");
    int turno = 1;
    int jogoAtivo = 1;

    while (jogoAtivo) {
        printf("\n====================================\n");
        printf("TURNO DO JOGADOR %d\n", turno);
        
        char (*tabInimigo)[COLUNAS] = (turno == 1) ? tabJ2 : tabJ1;
        
        printf("Tabuleiro do Inimigo (Seus tiros):\n");
        exibirTabuleiro(tabInimigo, 1); 

        int l, c;
        printf("Informe as coordenadas do tiro - Linha (0-9) e Coluna (0-9): ");
        scanf("%d %d", &l, &c);

        atirar(tabInimigo, l, c); 

        if (verificarVitoria(tabInimigo)) {
            printf("\nPARABENS! O JOGADOR %d VENCEU A BATALHA NAVAL!\n", turno);
            exibirTabuleiro(tabInimigo, 0); 
            jogoAtivo = 0;
        }

    
        turno = (turno == 1) ? 2 : 1; 
    }

    return 0;
}
