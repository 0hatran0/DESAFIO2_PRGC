#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4

void inicializarCartas(int cartas[TAM][TAM]) {
    int pares[TAM*TAM] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    int i, j, temp, pos;

    // Embaralha os pares
    srand(time(NULL));
    for (i = TAM*TAM-1; i > 0; i--) {
        pos = rand() % (i+1);
        temp = pares[i];
        pares[i] = pares[pos];
        pares[pos] = temp;
    }

    // Distribui na matriz
    pos = 0;
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            cartas[i][j] = pares[pos++];
}

void mostrarTabuleiro(int cartas[TAM][TAM], int visivel[TAM][TAM]) {
    int i, j;
    printf("   ");
    for (i = 0; i < TAM; i++) printf(" %d ", i);
    printf("\n");

    for (i = 0; i < TAM; i++) {
        printf(" %d ", i);
        for (j = 0; j < TAM; j++) {
            if (visivel[i][j])
                printf("[%d]", cartas[i][j]);
            else
                printf("[ ]");
        }
        printf("\n");
    }
}

int main() {
    int cartas[TAM][TAM], visivel[TAM][TAM] = {0};
    int lin1, col1, lin2, col2, acertos = 0;

    inicializarCartas(cartas);

    while (acertos < 8) {
        mostrarTabuleiro(cartas, visivel);

        printf("\nEscolha a primeira carta (linha e coluna): ");
        scanf("%d %d", &lin1, &col1);
        visivel[lin1][col1] = 1;
        mostrarTabuleiro(cartas, visivel);

        printf("Escolha a segunda carta (linha e coluna): ");
        scanf("%d %d", &lin2, &col2);
        visivel[lin2][col2] = 1;
        mostrarTabuleiro(cartas, visivel);

        if (cartas[lin1][col1] == cartas[lin2][col2]) {
            printf("Acertou!\n");
            acertos++;
        } else {
            printf("Errou! As cartas serão escondidas novamente.\n");
            visivel[lin1][col1] = 0;
            visivel[lin2][col2] = 0;
        }

        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        system("clear || cls");
    }

    printf("Parabéns! Você encontrou todos os pares!\n");
    return 0;
}
