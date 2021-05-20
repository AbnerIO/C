#include "header.h"
#include "helper.c"

int main()
{
    time_t tiempo = time(0); 
    int opt, bucle = 1;


    bucle = validarPassword();
    while (bucle == 1) //interfaz
    {
        printf("Introduce la opcion que desees:\n1     Deseo ver todos los gastos\n2     Quiero ingresar algo\n3     Quiero hacer una consulta\n4     Quiero eliminar un gasto\n5     Quiero cambiar mi password\n6     Quiero salir\n");
        fflush(stdin);
        opt = getchar();

        switch (opt)
        {
        case '1':
            printf("Opcion 1\n\n");
            imprimeLinea();
            imprimeFichero();
            imprimeLinea();
            break;

        case '2':
            printf("Opcion 2\n\n");
            imprimeLinea();
            ingresarConcepto();
            imprimeLinea();
            break;

        case '3':
            imprimeLinea();
            printf("\nOPCION 3: CONSULTAS\n\nIntroduce la opcion que desees:\n1     Ver gastos por categoria\n2     Ver por fecha\n3     Quiero ver el balance total\n4     Salir\n");
            fflush(stdin);
            opt = getchar();
            consultas(opt);
            imprimeLinea();
            break;

        case '4':
            printf("Opcion 4\n\n");
            imprimeLinea();
            eliminar();
            imprimeLinea();
            break;

        case '5':
            printf("Opcion 5\n\n"); 
            imprimeLinea();
            cambiarPassword();
            imprimeLinea();
            break;

        case '6':
            printf("Opcion 6\n\n");
            printf("Hasta pronto!\n\n");
            exit(1);
            getchar();
            imprimeLinea();
            break;

        default:
            printf("\nNo selecionaste una opcion valida, te dare otra oportunidad\n");
            imprimeLinea();
            break;
        }
    }
}
