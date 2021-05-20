#include "header.h"
FILE *doc;
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
    while (!feof(fichero) && fichero !=NULL)
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &monto, categoriaTemp,concepto, &date);
            if(strcmp(categoria, categoriaTemp) ==0){
               printf("%lf %s %s %d\n", monto, concepto, categoria, date);
            }
        }
        fflush(fichero);
        fclose(fichero);
        fichero=fopen("Pasivos.txt", "rb");
        printf("\n Pasivos encontrados con la categoria: %s\n", categoria);
    while (!feof(fichero) &&fichero !=NULL)
        {
            printf("\n");
            fscanf(fichero, "%lf  %s %s %d", &monto, categoriaTemp,concepto, &date);
            if(strcmp(categoria, categoriaTemp) ==0){
               printf("%lf %s %s %d\n", monto, concepto, categoria, date);
            }
        }
        fflush(fichero);
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
        doc = fopen("Pasivos.txt", "a");
    }
    else if (opt == 2)
    {
        doc = fopen("Activos.txt", "a");
    }
    fprintf(doc, "\n%.2lf %s %s %lu", monto, categoria, concepto, (unsigned long)time(NULL));
    printf("Se ha registrado correctamente\nmonto: %.2lf  , categoria: %s , concepto: %s, tiempo : %lu\n ", monto, categoria, concepto, (unsigned long)time(NULL));
    fflush(doc);
    fclose(doc);
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
    fflush(fichero);
    fclose(fichero);

    fichero = fopen("Pasivos.txt", "rb");
    printf("    \nTodos los gastos: \n");
    while (!feof(fichero))
    {
        c = getc(fichero);
        printf("%c", c);
    }
    fflush(fichero);
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
    fflush(doc);
    fclose(doc);
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
    FILE *primera, *segunda;

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

    (opt == 1)
        ? (primera = fopen("Pasivos.txt", "r"))
        : (primera = fopen("Activos.txt", "r"));

    ch = getc(primera);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(primera);
    }

    rewind(primera); // se regresa
    printf(" \n Ingresa el numero de linea de gasto que deseas eliminar (el orden es de arriba hacia bajo: gasto 1=presiona 1, gasto 2=presiona 2)");
    scanf("%d", &delete_line);

    segunda = fopen("replica.c", "w"); // aqui se hace a migracion al replica.c
    ch = getc(primera); 
    while (ch != EOF)
    {
        ch = getc(primera);
        if (ch == '\n')
        {
            temp++;
        }
        if (temp != delete_line)
        {

            putc(ch, segunda); // se copia todo a replica.c
        }
    }
    fclose(primera);
    fclose(segunda);

    (opt == 1)
        ? (remove("Pasivos.txt"))
        : (remove("Activos.txt"));


    (opt == 1)
        ? (rename("replica.c", "Pasivos.txt")) // se renombra replica y ahora parece que nada ha pasado
        : (rename("replica.c", "Activos.txt"));

    printf("\n Despues de ser modificado, ahora los valores son los siguientes: \n");

    (opt == 1)
        ? (primera = fopen("Pasivos.txt", "r"))
        : (primera = fopen("Activos.txt", "r"));

    ch = getc(primera);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(primera);
    }
    fclose(primera);
    return 0;
}
int imprimirPorFecha(int orden)
{
    FILE *fichero;
    char concepto[20], categoria[20];
    double monto;
    struct tm ts; // para pasar de timestamp a formato dia mes año 
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