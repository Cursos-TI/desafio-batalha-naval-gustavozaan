#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro (10x10)
#define HAB 5   // Tamanho das matrizes de habilidade (5x5)

//--- Função para exibir o tabuleiro---
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // Mostra 0, 3 ou 5
        }
        printf("\n");
    }
}

//--- Função para criar habilidade em forma de cone---
void criarCone(int cone[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // O cone se expande à medida que desce
            if (j >= HAB/2 - i && j <= HAB/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

//--- Função para criar habilidade em forma de cruz---
void criarCruz(int cruz[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // Linha central e coluna central formam a cruz
            if (i == HAB/2 || j == HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

//--- Função para criar habilidade em forma de octaedro ---
void criarOctaedro(int oct[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int di, dj;
            if (i >= centro)
                di = i - centro;
            else
                di = centro - i;
            if (j >= centro)
                dj = j - centro;
            else
                dj = centro - j;
            if (di + dj <= centro)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB][HAB], int origemX, int origemY) {
    int metade = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX - metade + i;
                int y = origemY - metade + j;

                // Garante que a habilidade não saia do tabuleiro
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0) 
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Posiciona alguns navios manualmente (3)
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Cria as três habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem no tabuleiro
    int origemConeX = 1, origemConeY = 7;
    int origemCruzX = 3, origemCruzY = 2;
    int origemOctX = 5, origemOctY = 5;

    // Aplica habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeX, origemConeY);
    aplicarHabilidade(tabuleiro, cruz, origemCruzX, origemCruzY);
    aplicarHabilidade(tabuleiro, octaedro, origemOctX, origemOctY);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
