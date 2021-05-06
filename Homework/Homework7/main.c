/*
 INSTRUCCIONES IMPORTANTES, lee el readme que te deje en el repositorio:)
 */
#include "header.h"

int main()
{
    FILE *flujo;
    int temppin, temptime, flag = 1, pin, option, bucle = 1, user;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128], buffer[32];
    strftime(output, 128, "%d/%m/%y", tlocal);
    struct tm *ts;
    size_t last;
    time_t timestamp = time(NULL);

    //obtiene dia
    ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';
    //obtiene hora
    char hour[128];
    strftime(hour, 128, "%H:%M", tlocal);

    printf("Eres un trabajador o administrador?\n-Presiona 1 si eres un trabajador,\n-Presiona 2 si eres admin\n");
    scanf("%d", &option);
    if (option == 1) //opciones de trabajador
    {
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (checkPines(pin) != 1) //verificar si ese pin existe en el sistema
        {
            printf("ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario como administrador\n");
            printf("Hasta pronto!\n");
            getchar();
            getchar();
            exit(1);
        }
        printf("**  #%d !!, Bienvenido al sistema ** \nQue deseas hacer?\n", pin);
        printf("-Presiona 1 si vas a entrar al jale\n-Presiona 2 si vas a salir del jale\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1: //entrada al jale
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu entrada pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), output, buffer);
            printf("exito");
            fflush(flujo);
            fclose(flujo);
            break;
        case 2: //salida del jale
            flujo = fopen("times.txt", "r+");
            while (flag != 0)
            {
                fscanf(flujo, "%d %d", &temppin, &temptime);
                if (temppin == pin)
                {
                    temptime += verTiempoTrabajado(pin);
                    fseek(flujo, -3, SEEK_CUR);
                    fprintf(flujo, "%d %d", pin, temptime);
                    fflush(flujo);
                    fclose(flujo);
                    flag = 0;
                }
            }
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu salida pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, verTiempoTrabajado(pin));
            printf("\n Has trabajado por %d segundos \nHasta Luego!\n", verTiempoTrabajado(pin));
            fflush(flujo);
            fclose(flujo);
            fprintf(flujo, "%d %d\n", pin, verTiempoTrabajado(pin));
            break;
        }
        getchar();
    }
    else if (option == 2) //opciones de admin
    {
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (pin != 000)
        {
            printf("Tu no eres admin >:| Expulsado\n");
            getchar();
            getchar();
            exit(1);
        }
        else
        {
            while (bucle == 1)
            {
                option = 0;
                printf("\nQue deseas hacer?\n");
                printf("Presiona 1 si quieres ver las asistencias de un usuario\nPresiona 2 si quieres agregar un nuevo trabajador\nPresiona 3 si quiero ver las horas trabajadas de un usuario\nPresiona 4 si quieres salir\n");
                fflush(stdin);
                scanf("%d", &option);
                // acciones
                switch (option)
                {
                case 1: //Reporte de asistencias
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != 1) //verificar si ese pin existe en el sistema
                    {
                        printf("Ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario \n");
                        printf("Hasta pronto!\n");
                        getchar();
                        getchar();
                        exit(1);
                    }
                    verAsistencias(pin);
                    break;
                case 2://creacion de usuario
                    crearRegistro();
                    break;
                case 3://reporte de  horas
                    printf("Escribe el pin del usuario para ver sus horas trabajadas(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != 1) //verificar si ese pin existe en el sistema
                    {
                        printf("Ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario \n");
                        printf("Lo siento pero nos tenemos que despedir, hasta pronto!\n");
                        getchar();
                        getchar();
                        exit(1);
                    }
                    printf("El usuario con el pin: %d,  ha trabajado por %d segundos \n", pin, calcHorasLaboradas(pin));
                    break;
                    case 4:
                        exit(1);
                        break;
                }
                
                
            }
        }
    }
    else
    {
        printf("Lamentamos no poder atenderte pero no escribiste una opcion valida. Presione enter para salir ...");
        getchar();
        getchar();
        exit(1);
    }
    getchar();
}
/*Inician Funciones*/
int crearRegistro(void)
{
    int newpin = 1, pin, flag = 0;
    char horae[30], horas[30], dias[40];
    FILE *fichero;

    fichero = fopen("system.txt", "a");

    if (fichero == NULL)
    {
        printf("Error: No se ha podido crear el fichero system.txt\n");
    }
    else
    {
        while (1)
        {
            if (checkPines(newpin))
            {
                newpin++;
            }
            else
            {
                break;
            }
        }

        fichero = fopen("system.txt", "a");
        printf("El nuevo pin generado automaticamente es : %d\n", newpin);
        printf("Introduce los dias que trabajara, sin espacios (ejemplos: LunesMartes   o   MiercolesJuevesViernes\n");
        fflush(stdin);
        scanf("%s", dias);
        printf("Introduce la hora de entrada del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", horae);
        printf("Introduce la hora de salida del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", horas);
        fprintf(fichero, "c%d e%s s%s d%s\n", newpin, horae, horas, dias);
        printf("exito");
        fflush(fichero);
        fclose(fichero);
        fichero = fopen("times.txt", "a");
        fprintf(fichero, "%d 0 \n", newpin);
        fflush(fichero);
        fclose(fichero);
        printf("\n");
    }
}
int checkPines(int pin)
{
    int pines[9], j = 0;
    int c;
    FILE *fichero;

    fichero = fopen("system.txt", "r");

    if (fichero == NULL)
    {
        printf("Error: No se ha podido crear el fichero system.txt\n");
    }
    else
    {
        while ((c = fgetc(fichero)) != EOF)
        {
            if (c == 'c')
            {
                c = fgetc(fichero);
                pines[j] = c - '0';
                if (pin == pines[j])
                {
                    fflush(fichero);
                    fclose(fichero);
                    return 1;
                }
                j = +1;
            }
        }
    }
    fflush(fichero);
    fclose(fichero);
}
int verAsistencias(int pin)
{
    int c, asistencias = 0;
    FILE *fichero;
    fichero = fopen("log.txt", "r");
    while ((c = fgetc(fichero)) != EOF)
    {
        if (c == 's')
        {
            c = fgetc(fichero) - '0';
            if (c == pin)
            {
                asistencias++;
            }
        }
    }
    fflush(fichero);
    fclose(fichero);
    printf("\nEl usuario %d tiene : %d asistencias\n", pin, asistencias);
}
int verTiempoTrabajado(int pin)
{
    char tiempo1[20], tiempo2[20];
    int t1, t2, tiempo;
    int c, asistencias = 0;
    FILE *fichero;
    fichero = fopen("log.txt", "r");
    while ((c = fgetc(fichero)) != EOF)
    {
        if (c == 'e')
        {
            c = fgetc(fichero) - '0';
            if (c == pin)
            {
                c = fgetc(fichero) - '0';
                fgets(tiempo1, 11, fichero);
                t1 = atoi(tiempo1);
            }
        }
    }
    tiempo = (unsigned long)time(NULL) - t1;
    fflush(fichero);
    fclose(fichero);
    return tiempo;
}
int calcHorasLaboradas(int pin)
{
    int horas, c, pinarch;
    FILE *fichero;
    fichero = fopen("times.txt", "r");
    while (1)
    {
        fscanf(fichero, "%d %d", &pinarch, &horas);
        if (pinarch == pin)
        {
            return horas;
            break;
        }
    }
}
