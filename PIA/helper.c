#include "header.h"
FILE *flujo;
int imprimeLinea()
{
    printf("\n-----------------------------------------------------------------------------------------------------------------\n\n");
}

int consultas(int option)
{
    char busqueda[10]; //orden1 = ascendente orden 2 descendente
    int orden;
    switch (option)
    {
    case '1':
        printf("Opcion 1: categoria\n\n");
        printf("Escribe la categoria que quieres ver(asegurate que exista)\n");
        fflush(stdin);
        scanf("%s", busqueda);
    buscarCategoria(busqueda);
        break;

    case '2':
    orden=1;
        imprimirPorFecha(orden);
        break;
    case '3':
        balanceTotal();
        return 0;
        break;
        case '4':
        printf("Saliendo\n\n");
        return 0;
        break;
    default:
        printf("Opcion No valida\n\n");
        break;
    }
};
int balanceTotal(){
    int date;
    FILE *fichero;
    double montoActivo=0, montoPasivo=0, totalPas=0, totalAct=0;
    char categoriaTemp[15], concepto[10];
    fichero =fopen("Activos.txt", "rb");
    while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &montoActivo, categoriaTemp,concepto, &date);
            totalAct+= montoActivo;
        }
        totalAct-=montoActivo; // correccion de precio ultima linea vacia
        printf("\n Activos : +%lf\n", totalAct);
        fflush(fichero);
        fclose(fichero);
        fichero=fopen("Pasivos.txt", "rb");
    while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &montoPasivo, categoriaTemp,concepto, &date);
            totalPas+=montoPasivo;
        }

        printf("\n Pasivos : -%lf\n", totalPas);
        printf("\n Total : %lf\n", (totalAct-totalPas));
        
        fflush(fichero);
        fclose(fichero);
        return 0;
}

int buscarCategoria(char categoria[]){
    FILE *fichero;
    char categoriaTemp[10], concepto[20];
    double monto;
    int date;
    fichero =fopen("Activos.txt", "rb");
    printf("\n Activos encontrados con la categoria: %s\n", categoria);
    while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &monto, categoriaTemp,concepto, &date);
            if(strcmp(categoria, categoriaTemp) ==0){
               printf("%lf %s %s %d\n", monto, concepto, categoria, date);
            }
        }
        fclose(fichero);
        fichero=fopen("Pasivos.txt", "rb");
        printf("\n Pasivos encontrados con la categoria: %s\n", categoria);
    while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &monto, categoriaTemp,concepto, &date);
            if(strcmp(categoria, categoriaTemp) ==0){
               printf("%lf %s %s %d\n", monto, concepto, categoria, date);
            }
        }
        fclose(fichero);
        return 0;
}

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
    scanf("%s", categoria);
    printf("Esribe el concepto : (el nombre) \n\n");
    fflush(stdin);
    scanf("%s", concepto);
    if (opt == 1)
    {
        flujo = fopen("Pasivos.txt", "a");
    }
    else if (opt == 2)
    {
        flujo = fopen("Activos.txt", "a");
    }
    fprintf(flujo, "\n%.2lf %s %s %lu", monto, categoria, concepto, (unsigned long)time(NULL));
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
    scanf("%s", newPassword);
    fprintf(fichero, "%s", newPassword);
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
    fscanf(fichero, "%s", password);
    printf("Bienvenido : Escribe tu password\n");
    fflush(stdin);
    scanf("%s", temppass);
    fflush(fichero);
    fflush(stdin);
    fclose(fichero);
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
    fflush(stdin);

    scanf("%d", &opt);
    if (opt != 1 && opt != 2)
    {
        printf("No introduciste una opcion valida\n");
        return 0;
    }

    //Abir para leer

    (opt == 1)
        ? (fileptr1 = fopen("Pasivos.txt", "r"))
        : (fileptr1 = fopen("Activos.txt", "r"));

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

    (opt == 1)
        ? (remove("Pasivos.txt"))
        : (remove("Activos.txt"));

    //rename the file replica.c to original name

    (opt == 1)
        ? (rename("replica.c", "Pasivos.txt"))
        : (rename("replica.c", "Activos.txt"));

    printf("\n Despues de ser modificado, ahora los valores son los siguientes: \n");

    (opt == 1)
        ? (fileptr1 = fopen("Pasivos.txt", "r"))
        : (fileptr1 = fopen("Activos.txt", "r"));

    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}
int imprimirPorFecha(int orden)
{
    FILE *fichero;
    char concepto[20], categoria[20];
    double monto;
    struct tm ts;
    char buf[80];
    int fecha, c;
    if (orden == 1){
        printf("    Todas las entradas de dinero en orden: \n");
        fichero = fopen("Activos.txt", "rb");
        while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf %s %s %d", &monto, concepto, categoria, &fecha);
            time_t rawtime = fecha;
            ts = *localtime(&rawtime);
            strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S ", &ts);
            printf("%s %lf %s %s", buf, monto, concepto, categoria);
        }
        fclose(fichero);

        fichero = fopen("Pasivos.txt", "rb");
        printf("\n    Todos los gastos en orden: \n");
        while (!feof(fichero))
        {
            printf("\n");
            fscanf(fichero, "%lf %s %s %d", &monto, concepto, categoria, &fecha);
            time_t rawtime = fecha;
            ts = *localtime(&rawtime);
            strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
            printf("%s %lf %s %s",buf, monto, concepto, categoria);
        }
        fclose(fichero);
        return 0;
    }
}