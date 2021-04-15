#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
/*Main Program*/
int main()
{
    double az[26] = {};
    double op2;
    int pr, type, letter = 100, asign = 0, found_value = 0, new_number = 0, forzada = 0;
    char s[MAXOP];
    printf("Para asignar una variable escribe algo asi:  a=9 . \n-Para forzar la asignacion de una variable escribe algo asi: a:=8\n-Las operaciones se hacen asi :   1 2 + , esto es igual a 1+2\n\n !!!!!! IMPORTANTE: RESPETA EL ESPACIADO ('12+' NO es lo mismo que '1 2 +')\n");
    while ((type = getop(s)) != EOF)
        switch (tolower(type))
        { /*Se evaluan todas las posibles opciones, una para cada letra ya que aplicamos tolower (no importa si escribio mayuscula o minuscula*/
        case 'a':
            push(az[0]);
            letter = 0;
            break;
        case 'b':
            push(az[1]);
            letter = 1;
            break;
        case 'c':
            push(az[2]);
            letter = 2;
            break;
        case 'd':
            push(az[3]);
            letter = 3;
            break;
        case 'e':
            push(az[4]);
            letter = 4;
            break;
        case 'f':
            push(az[5]);
            letter = 5;
            break;
        case 'g':
            push(az[6]);
            letter = 6;
            break;
        case 'h':
            push(az[7]);
            letter = 7;
            break;
        case 'i':
            push(az[8]);
            letter = 8;
            break;
        case 'j':
            push(az[9]);
            letter = 9;
            break;
        case 'k':
            push(az[10]);
            letter = 10;
            break;
        case 'l':
            push(az[11]);
            letter = 11;
            break;
        case 'm':
            push(az[12]);
            letter = 12;
            break;
        case 'n':
            push(az[13]);
            letter = 13;
            break;
        case 'o':
            push(az[14]);
            letter = 14;
            break;
        case 'p':
            push(az[15]);
            letter = 15;
            break;
        case 'q':
            push(az[16]);
            letter = 16;
            break;
        case 'r':
            push(az[17]);
            letter = 17;
            break;
        case 's':
            push(az[18]);
            letter = 18;
            break;
        case 't':
            push(az[19]);
            letter = 19;
            break;
        case 'u':
            push(az[20]);
            letter = 20;
            break;
        case 'v':
            push(az[21]);
            letter = 21;
            break;
        case 'w':
            push(az[22]);
            letter = 22;
            break;
        case 'x':
            push(az[23]);
            letter = 23;
            break;
        case 'y':
            push(az[24]);
            letter = 24;
            break;
        case 'z':
            push(az[25]);
            letter = 25;
            break;
        case '=':
            asign = 1;
            break;
        case ':':
            forzada=1; /*Indica que el usuario va a forzar una asignacion de variable, anotamos eso para que en el futuro no nos pregunte nada*/
            break;
        case NUMBER:
            if (asign == 0)
            {
                push(atof(s));
            }
            if (asign == 1)
            {
                new_number = atof(s);
                found_value = 1;
            }
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':;
            if (letter != 100 && asign == 1 && found_value == 1)
            { /*Empieza el proceso de asiganciónd e variables, preguntando si es forzado, si es nuevo o si se sobreescribira la variable*/
                for (int i = 0; i < 26; i++)
                {
                    if (letter == i)
                    {
                        if (az[i] != 0 && forzada ==0)
                        {
                            printf("Parece que ya habias asigando valor\n -Typea 1 si quieres sobreescribir la variable:) \n-Si NO quieres sobreescribir la variable, escribe culquier otro caracter :(\n");
                            if ((pr = getchar()) != '1')
                            {
                                pop();
                                printf("Cancelaste la opcion, ignore el numero de abajo , despues puede continuar \n");
                            }
                            else
                            {
                                pop();
                                printf("Se reasigno correctamente a: %d, ignore el numero de abajo\n", new_number);
                                az[i] = new_number;
                            }
                            forzada=0;
                        }
                        else
                        {
                            az[i] = new_number;
                            forzada=0;
                        }
                    }
                }
            }
            else
                printf("\t%.8g\n", pop());
            letter = 100; 
            asign = 0;
            found_value = 0;
            new_number = 0;
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
}
