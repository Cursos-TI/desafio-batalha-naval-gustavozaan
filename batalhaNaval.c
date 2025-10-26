#include <stdio.h>

int main(){

    //--- Definições principais ---
    int tamanho = 10;
    int tamanhoNavio = 3;
    int tabuleiro[10][10];

    //--- Inicio do tabuleiro ---
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //--- Navios ---
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    

    //--- Cordenadas dos navios ---
    int linhaH = 8;
    int colunaH = 2;
    int linhaV = 3;
    int colunaV = 1;

     //--- Posiciona o navio horizontal ---
    if (colunaH + tamanhoNavio <= tamanho) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    //--- Posiciona o navio vertical ---
    if (linhaV + tamanhoNavio <= tamanho) {
        for (int i = 0; i < tamanhoNavio; i++) {
            
            // Evita sobreposição 
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            } else {
                printf("Erro: sobreposição detectada!\n");
                return 1;
            }
        }
    }


    //--- Tabuleiro ---
    printf("\n --- TABULEIRO --- \n");
    printf("   ");
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", 'A' + j);
        }
        printf("\n");

        for (int i = 0; i < tamanho; i++) {
            printf("%2d ", i); 
            for (int j = 0; j < tamanho; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    return 0;
}