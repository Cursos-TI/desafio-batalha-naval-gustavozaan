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
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};

    

    //--- Cordenadas dos navios ---
    int linhaH = 6; // HORIZONTAL
    int colunaH = 8; // HORIZONTAL

    int linhaV = 5; // VERTICAL
    int colunaV = 1; // VERTICAL

    int linhaD1 = 1; // DIAGONAL (\)
    int colunaD1 = 1; // DIAGONAL (\)

    int linhaD2 = 2; // VERTICAL (/)
    int colunaD2 = 7; // VERTICAL (/)

    //--- Verificação de sobreposição ---
    #define livre(l, c) (tabuleiro [l][c] == 0)

     //--- Posiciona o navio1 horizontal ---
    if (colunaH + tamanhoNavio <= tamanho) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (livre(linhaH, colunaH + i))
            {
               tabuleiro[linhaH][colunaH + i] = navio1[i];
            } else {
                printf("Erro: sobreposição detectada!\n");
                return 1;
            }
            
        }
    }

    //--- Posiciona o navio2 vertical ---
    if (linhaV + tamanhoNavio <= tamanho) {
        for (int i = 0; i < tamanhoNavio; i++) { 
            if (livre(linhaV, colunaV + i))
            {
               tabuleiro[linhaV][colunaV + i] = navio2[i];
            } else {
                printf("Erro: sobreposição detectada!\n");
                return 1;
            }
        }
    }

    //--- Posiciona o navio3 diagonal (\) ---
    if (linhaD1 + tamanhoNavio <= tamanho && colunaD1 + tamanhoNavio <= tamanho){
        for (int i = 0; i < tamanhoNavio; i++)
        {
            if (livre(linhaD1 + i, colunaD1 + i))
            {
                tabuleiro [linhaD1 + i][colunaD1 + i] =  navio3[i];
            }
            
        }
        
    }

    //--- Posiciona o navio4 diagonal (/) ---
    if (linhaD2 + tamanhoNavio <= tamanho && colunaD2 + tamanhoNavio <= tamanho){
        for (int i = 0; i < tamanhoNavio; i++)
        {
            if (livre(linhaD2 + i, colunaD2 + i))
            {
                tabuleiro [linhaD2 + i][colunaD2 + i] =  navio4[i];
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