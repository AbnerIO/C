#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int imprimeLinea(void);
int consultas();

int main()
{

    int opt, bucle = 1;
    char password[] = {"Hola"}, temppas[10], ret;

    time_t tiempo = time(0); //Genera timestamp --> "%lu", (unsigned long)time(NULL)

    printf("Bienvenido : Escribe tu password\n");
    fflush(stdin),
    scanf("%s", temppas);
    imprimeLinea();

    while (bucle == 1)
    {

        if (!(ret = strncmp(password, temppas, 10)))//Validacion contraseña if(!)son iguales
        { 
            printf("Introduce la opcion que desees:\n1     Deseo ver todos los gastos\n2     Quiero ingresar algo\n3     Quiero hacer una consulta\n4     Quiero eliminar un gasto\n5     Quiero cambiar mi password\n6     Quiero salir\n");
            fflush(stdin);
            opt = getchar();

            switch (opt)
            {
            case '1':
                printf("Opcion 1\n\n");
                imprimeLinea();
                break;

            case '2':
                printf("Opcion 2\n\n");
                imprimeLinea();
                break;

            case '3':
                imprimeLinea();
                printf("\nOPCION 3: CONSULTAS\n\nIntroduce la opcion que desees:\n1     Ver todos los activos\n2     Ver todos los pasivos\n3     Ver gastos por fecha\n4     Ver gastos por categoria\n5     Salir\n");
                fflush(stdin);
                opt = getchar();
                consultas(opt);
                imprimeLinea();
                break;

            case '4':
                printf("Opcion 4\n\n");
                imprimeLinea();
                break;

            case '5':
                printf("Opcion 5\n\n");
                imprimeLinea();
                break;

            case '6':
                printf("Opcion 6\n\n");
                imprimeLinea();
                break;

            default:
                printf("\nNo selecionaste una opcion valida, te dare otra oportunidad\n");
                imprimeLinea();
                break;
            }
        }
    }
}

int imprimeLinea()
{
    printf("\n-----------------------------------------------------------------------------------------------------------------\n\n");
}

int consultas(int option)
{
    switch (option)
    {
    case '1':
                printf("Opcion 1\n\n");
                imprimeLinea();
                break;

            case '2':
                printf("Opcion 2\n\n");
                imprimeLinea();
                break;

            case '3':
                printf("Opcion 3\n\n");
                imprimeLinea();
                break;

            case '4':
                printf("Opcion 4\n\n");
                imprimeLinea();
                break;

            case '5':
                printf("Opcion 5\n\n");
                imprimeLinea();
                break;
    
    default:
     printf("Opcion No valida\n\n");
        break;
    }
}