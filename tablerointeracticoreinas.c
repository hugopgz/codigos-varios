#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

// Estructura para almacenar la coordenada de la reina
typedef struct {
    int row;
    int col;
} Queen;

// Función para imprimir el tablero
void printBoard(char board[SIZE][SIZE]) {
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Función para inicializar el tablero
void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Función para marcar las posiciones afectadas por la reina
void markBoard(char board[SIZE][SIZE], Queen q) {
    for (int i = 0; i < SIZE; i++) {
        board[q.row][i] = 'X';  // Marcar fila
        board[i][q.col] = 'X';  // Marcar columna
        if (q.row + i < SIZE && q.col + i < SIZE) {
            board[q.row + i][q.col + i] = 'X';  // Marcar diagonal principal
        }
        if (q.row - i >= 0 && q.col - i >= 0) {
            board[q.row - i][q.col - i] = 'X';  // Marcar diagonal principal
        }
        if (q.row + i < SIZE && q.col - i >= 0) {
            board[q.row + i][q.col - i] = 'X';  // Marcar diagonal secundaria
        }
        if (q.row - i >= 0 && q.col + i < SIZE) {
            board[q.row - i][q.col + i] = 'X';  // Marcar diagonal secundaria
        }
    }
    board[q.row][q.col] = 'Q';  // Colocar la reina
}

// Función para el camino 1 (aún por implementar)
void camino1() {
    printf("Aun por implementar\n");
}

void comprobacion(int queenCount, int restantes){
    if (queenCount == 8) {
        printf("Enorabuena, has superado el desafio satisfactoriamente\n");
        break;
    }
    if (restantes > 0 && queenCount < 8) {
        printf("Error, reinas aun por colocar pero tablero lleno, desea volver atras?");
    }
}

int main() {
    int opcion;
    char board[SIZE][SIZE];
    Queen queens[SIZE]; //lista de reinas en el tablero
    int queenCount = 0; //cantidad de reinas en el tablero
    int filasLibres = 8; //numero de reinas en el tablero para llegar a un resultado correcto

    printf("Selecciona un camino:\n");
    printf("1. Camino 1\n");
    printf("2. Resolver el problema de las 8 reinas\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        camino1();
        return 0;
    }

    initBoard(board);
    printBoard(board);

    while (1) {
        char fila[1];
        int row = -1, col = -1;
        printf("Ingrese la fila para colocar la reina o 'r' para reiniciar, 'b' para borrar, 'q' para salir: ");
        scanf("%s", fila);

        if (strcmp(fila, "r") == 0) {
            initBoard(board);
            queenCount = 0;
            printf("El tablero ha sido reiniciado.\n");
            printBoard(board);
            continue;
        }

        if (strcmp(fila, "b") == 0) {
            if (queenCount > 0) {
                queenCount--;
                initBoard(board);
                for (int i = 0; i < queenCount; i++) {
                    markBoard(board, queens[i]);
                }
                printf("Último movimiento eliminado.\n");
                printBoard(board);
            } else {
                printf("No hay movimientos anteriores para borrar.\n");
            }
            continue;
        }

        if (strcmp(fila, "q") == 0) {
            printf("Saliendo del programa.\n");
            break;
        }

        row = atoi(&fila[0]);
        printf("Ingrese la columna donde colocar la reina: ");
        scanf("%d", &col);

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            Queen q = {row, col};
            queens[queenCount++] = q;

            //initBoard(board);
            for (int i = 0; i < queenCount; i++) {
                markBoard(board, queens[i]);
            }
            printBoard(board);
        } else {
            printf("Coordenada no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
