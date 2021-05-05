/*Write a program that provides access to a database with the persistent storage implemented through one or more locally stored plain-text files, 
capable of managing records of the time of entry and exit of employees
 and producing reports of attendance and hours worked. 
 The employees are registered with unique PINs, which they type in upon arrival and whenever they leave the workplace. 
 The system knows which days of the week each employee works
 and at what time of the day the person is supposed to come to work. 
 System functionality includes, 
 besides the data capture, 
 the generation of reports of attendence, 
 punctuality, 
 and hours worked, 
 and of course the administrative interface for registering new employees, 
 who are automatically assigned a PIN by the system.
 INSTRUCCIONES IMPORTANTES, lee el readme
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_CHARS 20
int calcHorasLaboradas(int pin);
int crearRegistro(void);
int checkPines(int pin);
int verAsistencias(int pin);
int verTiempoTrabajado(int pin);
int main()
{
    FILE *flujo;
    int temppin, temptime, flag = 1;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output, 128, "%d/%m/%y", tlocal);
    int pin, option, bucle = 1, user;
    char buffer[32];
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

    printf("Eres usuario o administrador? (presiona 1 si eres usuario, 2 si eres admin)\n");
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
        printf("**  #%d !!, Bienvenido al sistema ** \nQue deseas hacer? ( introduce el numero con la opcion que requieras) \n", pin);
        printf("1.- Voy a entrar al jale\n2.- Voy a salir del jale\n");
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
        case 2: //salida del sale
            flujo = fopen("times.txt", "r+");
            while (flag != 0)
            {
                fscanf(flujo, "%d %d", &temppin, &temptime);
                if (temppin == pin)
                {
                    printf("se cuplio");
                    temptime += verTiempoTrabajado(pin);
                    fputchar('c');
                    fseek(flujo, -3, SEEK_CUR);
                    fprintf(flujo, "%d %d", pin, temptime);
                    printf("\n\n validador pin=%d temptime=%d\n\n", pin, temptime);
                    fflush(flujo);
                    fclose(flujo);
                    flag = 0;
                }
            }
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu salida pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, verTiempoTrabajado(pin));
            printf("\n Has trabajado por %d segundos \n", verTiempoTrabajado(pin));
            printf("exito");
            fflush(flujo);
            fclose(flujo);

            /* Cerramos "fichero1.txt". */
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
                printf("\nQue deseas hacer? ( introduce el numero con la opcion que requieras) \n");
                printf("1.- Quiero ver las asistencias de un usuario\n2.- Quiero agregar un nuevo trabajador\n3.-Quiero ver las horas trabajadas de un usuario\n");
                fflush(stdin);
                scanf("%d", &option);
                // acciones
                switch (option)
                {
                case 1:
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    verAsistencias(pin);
                    break;
                case 2:
                    crearRegistro();
                    break;
                    case 3:
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    printf("El usuario con el pin: %d,  ha trabajado por %d segundos \n", pin ,calcHorasLaboradas(pin));
                    break;
                }

                printf("Si deseas hacer otro movimiento ingresa cualquier caracter, si deseas salir introduce '1'\n");
                fflush(stdin);
                scanf("%d", &option);
                if (option == 1)
                {
                    printf("Adios!!\n"),
                        getchar();
                    getchar();
                    exit(1);
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
           }else {
               break;
           }
        }
        
        fichero = fopen("system.txt", "a");
        printf("El nuevo pin generado automaticamente es : %d\n", newpin);
        printf("Introduce los dias que trabajara, sin espacios (ejemplos: LunesMartes   o   MiercolesJuevesViernes\n");
        fflush(stdin);
        scanf("%s", &dias);
        printf("Introduce la hora de entrada del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", &horae);
        printf("Introduce la hora de salida del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", &horas);
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
    printf("\n El usuario %d tiene : %d asistencias\n", pin, asistencias);
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
    int horas,c,pinarch ;
    FILE * fichero;
    fichero = fopen("times.txt", "r");
    while (1)
    {
        fscanf(fichero, "%d %d", &pinarch, &horas);
        if(pinarch==pin)
        {
            return horas;
            break;
        }
        
        }
}