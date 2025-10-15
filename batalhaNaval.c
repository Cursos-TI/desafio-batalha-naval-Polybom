#include <stdio.h>

#define TAM 10   // tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3  // tamanho fixo de cada navio

int main() {
    int tabuleiro[TAM][TAM];  // matriz do tabuleiro
    int i, j;

    // === 1. Inicializar o tabuleiro com 0 (água) ===
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === 2. Declara os dois navios ===
    // Cada navio tem tamanho 3 e será representado por um vetor unidimensional
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // === 3. Coordenadas iniciais dos navios ===
    // Coordenadas iniciais fixas 
    int linhaHorizontal = 2; // linha inicial do navio horizontal
    int colunaHorizontal = 4; // coluna inicial do navio horizontal

    int linhaVertical = 6; // linha inicial do navio vertical
    int colunaVertical = 1; // coluna inicial do navio vertical

    // === 4. Verificacao se os navios cabem no tabuleiro ===
    // Verifica limites para o navio horizontal
        if (colunaHorizontal + TAM_NAVIO > TAM) {
        printf("Erro: o navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }
    
    // Verificacao dos limites para o navio vertical
    if (linhaVertical + TAM_NAVIO > TAM) {
        printf("Erro: o navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }

    // === 5. Garantir que não há sobreposição ===
    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (linhaVertical + i == linhaHorizontal &&
            (colunaVertical >= colunaHorizontal &&
             colunaVertical < colunaHorizontal + TAM_NAVIO)) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepoem!\n");
        return 1;
    }

    // === 6. Posicionar o navio horizontal no tabuleiro ===
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // === 7. Posicionar o navio vertical no tabuleiro ===
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // === 8. Exibir o tabuleiro ===
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}

