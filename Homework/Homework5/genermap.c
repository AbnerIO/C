int campo_cubierta[10][10],campo_final[10][10];
#define DIMENSIONES 10 // 10x10
void generarMatriz(int campo_backgroud[DIMENSIONES][DIMENSIONES], int *filas, int *columnas)
{
    for (int fila = 0; fila <= *filas; fila++)
    {
        for (int columna = 0; columna <= *columnas; columna++)
        {
                campo_backgroud[fila][columna] = 'X'; 
                campo_cubierta[fila][columna] = campo_backgroud[fila][columna];
                campo_final[fila][columna] = campo_backgroud[fila][columna];
        }
    }
}