#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMITE_INFERIOR_DE_MINAS 10
#define LIMITE_SUPERIOR_DE_MINAS 20
#define DIMENSIONES 10 // 10x10
#define LIMPIA_BUFFER fflush(stdin) //Este es una funcion que obtuve de la segunda referencia que utilicé, limpia el buffer.

void generadorDeCampo(void);
void imprimirCampo(void);
void intento(void);
void imprimirMinasDelCampo(void);
int campo_backgroud[10][10],x, y,M, N,total_mines = 0,mines = 0;
