/*Utilicé las siguientes referencias para hacer este proyecto solo con  <time.h> <stdlib.h> y  <stdio.h>
1.-Para generar numeros aleatorios http://www.chuidiang.org/clinux/funciones/rand.php#:~:text=En%20C%2C%20para%20obtener%20n%C3%BAmeros%20aleatorios%2C%20tenemos%20la,%28un%20n%C3%BAmero%20enorme%2C%20como%20de%202%20mil%20millones%29.
2.-Para la lectura de caracteres y numeros sin problemas, y evitando problemas con el buffer: http://www.carlospes.com/curso_de_lenguaje_c/01_11_la_funcion_fflush.php

NOTA:Si lo corres en c compiler, probablemente las columna 9 salga un poco de la pantalla, en otros compiladores esto no pasa (testeado en VS code)
Aun así si lo quieres correr en c compiler si jala, es solo ese detalle de la pantalla. 

Primero te va a perdir x,  le das enter, despues de ya a pedir y, le das enter. 
es de 10 x 10, pero recuerda que incia del cero por lo que su rango es de 0-9
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "values.h"

int main()
{
    printf("Bienvenido\n\nINSTRUCCIONES: Se generara un campo de 10x10 (recuerda que inicia el cero por lo que va del 0-9)\nPrimero se ingresara el valor de x:, despues el de y: EJEMPLO: x:1(pulsas enter) y:2(pulsas enter)\nLas minas te van a aparecer cuando pierdas o ganes.\n\n Muchas suerte!\n\n\n\n");
    total_mines = rand () % (LIMITE_SUPERIOR_DE_MINAS-LIMITE_INFERIOR_DE_MINAS+1) + (LIMITE_INFERIOR_DE_MINAS);  // K MINAS pseudorandomly
    generadorDeCampo();
    intento();
    return 0;
}

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
void generadorDeCampo(void) //Se genera el campo
{
    int i = 10, j = 10;
    srand(time(NULL)); //Alimenta a rand con tiempo del usuario, este algortimo lo obtuve de la primera referencia
    generarMatriz(campo_backgroud, &i, &j);
    mines = 0;
    while (mines < total_mines) //Generar minas de modo aleatorio, ejecutada hasta que el numero de minas puestas alcance a las minas totales
    {
        i = rand() % (DIMENSIONES);
        j = rand() % (DIMENSIONES);
        if (campo_backgroud[i][j] != '*') //No pongas una mina donde ya la hay
        {
            campo_backgroud[i][j] = '*';
            campo_final[i][j] = campo_backgroud[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;
    while (j < DIMENSIONES) 
    {
        while (i < DIMENSIONES) //Asigna los numeros al ver cuantas minas tiene al rededor
        {
            if (campo_backgroud[i][j] != '*')
            {
                campo_backgroud[i][j] = 0;
            }
            if ((campo_backgroud[i - 1][j - 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i - 1][j] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i][j - 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i - 1][j + 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i + 1][j - 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i + 1][j] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i][j + 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            if ((campo_backgroud[i + 1][j + 1] == '*') && (campo_backgroud[i][j] != '*'))
            {
                campo_backgroud[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}
void imprimirCampo(void) // Imprime el campo por atrás
{
    int i = 0, j = 0, z = 0;
    while (z < DIMENSIONES) // Imprime el campo a lo largo del eje x
    {
        if (z == 0)
        {
            printf("\t");
        }
        printf("%d\t", z);
        z++;
    }
    printf("\n\n");

    while (j < DIMENSIONES) // Imprime los caracteres representarivos (por ejemplo, los espacios en blanco)
    {
        printf("%d\t", j);
        while (i < DIMENSIONES)
        {
            if (campo_cubierta[i][j] == 'X')
            {
                printf("%c\t", campo_cubierta[i][j]);
            }
            else if (campo_backgroud[i][j] == 0) // Si el valor contiene 0 significa que no hay mina, significa que lo cambiaremos por ' '
            {
                campo_cubierta[i][j] = ' ';
                printf("%c\t", campo_cubierta[i][j]);
            }
            else
            {
                printf("%d\t", campo_cubierta[i][j]);
            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void intento(void)
{
    int q = 0, i = 0, j = 0, match = 0;
    imprimirCampo();
    while (j < DIMENSIONES) // 
    {
        while (i < DIMENSIONES)
        {
            if (campo_backgroud[i][j] == campo_cubierta[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if (match == ((DIMENSIONES*DIMENSIONES) - total_mines)) // Si el numero de matches = las posiciones libres de minas, significa que limpiaste el campo, o que ganaste
    {
        printf("\n\n\n\tGanaste la partida\n\n\n");
        getchar();
        exit(1);
    }
    printf("\nx:");// Leemos los datos introduciodos y se los asignamos a x y a y
    scanf("%d", &x ); 
    LIMPIA_BUFFER;
    printf("\ny:");
    scanf("%d", &y ); 
    LIMPIA_BUFFER;
    if ((x >= DIMENSIONES) || (x < 0) || (y < 0) || (y >= DIMENSIONES))
    {
        printf("\nEl valor debe estar dentro del plano cartesiano\n");
        intento();
    }
    if (campo_backgroud[x][y] == '*') //Si seleccionaste una mina, explotará .perdiste
    {
        imprimirMinasDelCampo(); 
        printf("\n\t\tPerdiste, acabas de chocar con una mina (%d,%d)\n\t\t", x, y);
        getchar();
        exit(1);
    }
    if (campo_cubierta[x][y] != 'X')//Cubierta
    {
        printf("\nel valor ya se habia introducido antes\n");
        intento();
    }

    else // Verifica los alrededores, se me complicó hacer una funcion recursiva
    {
        campo_cubierta[x][y] = campo_backgroud[x][y];
        if (campo_backgroud[x][y] == 0)
        {
            if (campo_backgroud[x - 1][y - 1] != '*')
            {
                campo_cubierta[x - 1][y] = campo_backgroud[x - 1][y];
            }
            if (campo_backgroud[x - 1][y] != '*')
            {
                campo_cubierta[x - 1][y] = campo_backgroud[x - 1][y];
            }
            if (campo_backgroud[x][y - 1] != '*')
            {
                campo_cubierta[x][y - 1] = campo_backgroud[x][y - 1];
            }
            if (campo_backgroud[x - 1][y + 1] != '*')
            {
                campo_cubierta[x - 1][y + 1] = campo_backgroud[x - 1][y + 1];
            }
            if (campo_backgroud[x + 1][y - 1] != '*')
            {
                campo_cubierta[x + 1][y - 1] = campo_backgroud[x + 1][y - 1];
            }
            if (campo_backgroud[x + 1][y] != '*')
            {
                campo_cubierta[x + 1][y] = campo_backgroud[x + 1][y];
            }
            if (campo_backgroud[x][y + 1] != '*')
            {
                campo_cubierta[x][y + 1] = campo_backgroud[x][y + 1];
            }
            if (campo_backgroud[x + 1][y + 1] != '*')
            {
                campo_cubierta[x + 1][y + 1] = campo_backgroud[x + 1][y + 1];
            }
        }
        intento();
    }
}
void imprimirMinasDelCampo(void) // Es hacer trampa, imprime las minas del campo
{
    int i = 0, j = 0, z = 0;
    while (z < DIMENSIONES)
    {
        if (z == 0)
        {
            printf("\t");
        }
        printf("%d\t", z);
        z++;
    }
    printf("\n\n");

    while (j < DIMENSIONES)
    {
        printf("%d\t", j);
        while (i < DIMENSIONES)
        {
            printf("%c\t", campo_final[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

