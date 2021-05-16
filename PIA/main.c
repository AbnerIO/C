#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int validarPassword();
int imprimeLinea(void);
int imprimeFichero(void);
int cambiarPassword(void);
int consultas();
int ingresarConcepto(void);
int eliminar(void);

FILE *flujo;
int main()
{
    int opt, bucle = 1;
   
    time_t tiempo = time(0); //Genera timestamp --> "%lu", (unsigned long)time(NULL)

    bucle = validarPassword();
    while (bucle == 1)
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
            printf("\nOPCION 3: CONSULTAS\n\nIntroduce la opcion que desees:\n1     Ver gastos por fecha\n2     Ver gastos por categoria\n3     Salir\n");
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

int imprimeLinea()
{
    printf("\n-----------------------------------------------------------------------------------------------------------------\n\n");
}

int consultas(int option)
{
    char busqueda[10];
    switch (option)
    {
    case '1':
        printf("Opcion 1: categoria\n\n");
        break;

    case '2':
        printf("Opcion 2: fecha\n\n");
        break;

    case '3':
        printf("Opcion 3\n\n");
        break;
    default:
        printf("Opcion No valida\n\n");
        break;
    }
};

int ingresarConcepto(void)
{
    double monto;
    char categoria[15], concepto[15];
    int opt, file = 1; // file 1 pasivo, 2 activo
    printf("Si es un pasivo presiona 1, si es un activo presiona 2\n\n");
    fflush(stdin);
    scanf("%d", &opt);

    if (opt != 1 && opt != 2)
    {
        printf("No es una opcion valida\n");
        return 0;
    }

    printf("Escribe el monto:\n\n");
    fflush(stdin);
    scanf("%lf", &monto);
    printf("Esribe una categoria: (Sugerencias: juegos, salud, comida, universidad, etc) \n\n");
    fflush(stdin);
    scanf("%s", &categoria);
    printf("Esribe el concepto : (Sugerencias: juegos, salud, comida, universidad, etc) \n\n");
    fflush(stdin);
    scanf("%s", &concepto);
    if (opt == 1)
    {
        flujo = fopen("Pasivos.txt", "a");
    }
    else if (opt == 2)
    {
        flujo = fopen("Activos.txt", "a");
    }
    fprintf(flujo, "%.2lf %s %s %lu\n", monto, categoria, concepto, (unsigned long)time(NULL));
    printf("Se ha registrado correctamente\nmonto: %.2lf  , categoria: %s , concepto: %s, tiempo : %lu\n ", monto, categoria, concepto, (unsigned long)time(NULL));
    fflush(flujo);
    fclose(flujo);
}

int imprimeFichero(void)
{
    FILE *fichero;
    char c;

    printf("    Todas las entradas de dinero: \n");
    fichero = fopen("Activos.txt", "rb");
    while (!feof(fichero))
    {
        c = getc(fichero);
        printf("%c", c);
    }
    fclose(fichero);

    fichero = fopen("Pasivos.txt", "rb");
    printf("    Todos los gastos: \n");
    while (!feof(fichero))
    {
        c = getc(fichero);
        printf("%c", c);
    }
    fclose(fichero);
    return 0;
}
int cambiarPassword(void)
{
    char newPassword[10];

    FILE *fichero;
    fichero = fopen("pass.txt", "w");

    printf("Introduce tu nueva password (maximo 10 caracteres):\n");
    fflush(stdin);
    scanf("%s", &newPassword);
    fprintf(fichero, "%s", &newPassword);
    printf("Se ha modificado tu password con exito. Ahora es : %s", newPassword);
    fflush(flujo);
    fclose(flujo);
}
int validarPassword()
{
    char ret, temppass[10], password[10];

    FILE *fichero;
    fichero = fopen("pass.txt", "rb");
    fflush(stdin);
    fscanf(fichero, "%s", &password);
    printf("Bienvenido : Escribe tu password\n");
    fflush(stdin);
    scanf("%s", temppass);
    fflush(flujo);
    fclose(flujo);
    if (!(ret = strncmp(password, temppass, 10)))
    {
        return 1;
    }
    else
        return 0;
}

int eliminar(void)
{
    FILE *fileptr1, *fileptr2;

    char ch;
    int delete_line, temp = 1, opt;

    printf("Deseas eliminar un pasivo? Presiona 1\nDeseas eliminar un activo? presiona 2\n");
    fflush(stdin),

        scanf("%d", &opt);
    if (opt != 1 && opt != 2)
    {
        printf("No introduciste una opcion valida\n");
        return 0;
    }

    //Abir para leer

    (opt==1) 
    ? (fileptr1 = fopen("Pasivos.txt", "r")) 
    :  (fileptr1 = fopen("Activos.txt", "r")); 
    
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Ingresa el numero de linea de gasto que deseas eliminar (el orden es de arriba hacia bajo: gasto 1=presiona 1, gasto 2=presiona 2)");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
        {
            temp++;
        }
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    
    (opt==1) 
    ? (remove("Pasivos.txt")) 
    :  (remove("Activos.txt")); 
    
    //rename the file replica.c to original name

    (opt==1) 
    ? (rename("replica.c", "Pasivos.txt")) 
    :  (rename("replica.c", "Activos.txt")); 
    
    printf("\n Despues de ser modificado, ahora los valores son los siguientes: \n");

    (opt==1) 
    ? (fileptr1 = fopen("Pasivos.txt", "r")) 
    :  (fileptr1 = fopen("Activos.txt", "r")); 
   
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}