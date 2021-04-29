/*El programa es sencillo, no considero que requiera instrucciones a parte de las que ya se dan por el terminal*/

#include <stdio.h>
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower

#define MAXIMA_LONGITUD_CADENA 10

typedef struct nodoCadena
{
    char username[MAXIMA_LONGITUD_CADENA];
    char password[MAXIMA_LONGITUD_CADENA];
    // Las ramas
    struct nodoCadena *izquierda;
    struct nodoCadena *derecha;
} usuario;

usuario *nuevoNodo(char username[MAXIMA_LONGITUD_CADENA], char password[MAXIMA_LONGITUD_CADENA])
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(usuario);
    size_t tamanioNodopass = sizeof(usuario);
    usuario *nodo = (usuario *)malloc(tamanioNodo);
    usuario *nodopass = (usuario *)malloc(tamanioNodopass);
    // Asignar el dato e iniciar hojas
    strcpy(nodo->username, username);
    strcpy(nodo->password, password);
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void agregar(usuario *nodo, char *cadena, char *password)
{
    if (strcmp(cadena, nodo->username) > 0)
    {
        if (nodo->derecha == NULL)
        {
            nodo->derecha = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->derecha, cadena, password);
        }
    }
    else
    {
        if (nodo->izquierda == NULL)
        {
            nodo->izquierda = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->izquierda, cadena, password);
        }
    }
}

usuario *buscarUsername(usuario *nodo, char *cadena)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        return nodo;
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return buscarUsername(nodo->derecha, cadena);
    }
    else
    {
        return buscarUsername(nodo->izquierda, cadena);
    }
}
usuario *buscarPassword(usuario *nodo, char *cadena, char *pass)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        if (strcmp(pass, nodo->password) == 0)
        {
            *nodo->username = NULL;
            *nodo->password=NULL;
            return NULL;
        }
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return buscarPassword(nodo->derecha, cadena, pass);
    }
    else
    {
        return buscarPassword(nodo->izquierda, cadena, pass);
    }
}
void ordenar(usuario *nodo) //(raiz)
{
    if (nodo != NULL)
    {
        ordenar(nodo->izquierda);
        printf("%s,", nodo->username);
        ordenar(nodo->derecha);
    }
}


/*agregar(raiz,"name","password")*/
int main(int argc, char const *argv[])
{
    char user[MAXIMA_LONGITUD_CADENA];
    char pass[MAXIMA_LONGITUD_CADENA];
    usuario *raiz = NULL;
    printf("\nBienvenido\n\nPrimero deberas crear al usuario raiz \n");
     printf("Escribe el usuario que deseas agregar:\n");
    fflush(stdin);
    scanf("%s", &user[0]);
    printf("Escribe el password\n");
    fflush(stdin);
    scanf("%s", &pass[0]);
    raiz = nuevoNodo(user,pass);
    int add = 0, eliminacion = 0, ordenamiento = 0;
    char option, s;
    while ((s = getchar()) != EOF)
    {
        
        printf("\n-Presiona a si quieres agregar un usuario\n-Presiona e si quieres eliminar un usuario\n-Presiona o si quieres ver ordenados a los usuarios\n\n");
        fflush(stdin);
        scanf("%c", &option);
        switch (option)
        {
        case 'a':
            add = 1;
            break;
        case 'e':
            eliminacion = 1;
            break;
        case 'o':
            ordenamiento = 1;
            break;
        default:
            printf("!Opcion no valida");
            break;
        }
        if (add != 0 || eliminacion != 0 || ordenamiento != 0)
        {
            if (add == 1)
            {
                char user[MAXIMA_LONGITUD_CADENA];
                char pass[MAXIMA_LONGITUD_CADENA];
                printf("Escribe el usuario que deseas agregar:\n");
                fflush(stdin);
                scanf("%s", &user[0]);
                struct nodoCadena *apuntadorUser = buscarUsername(raiz, user);
                if (apuntadorUser != NULL)
                {
                    printf("\n\t!Lo siento pero '%s' ya existe en el sistema\n", user);
                }
                else
                {
                    printf("Escribe el password que deseas asignarle:\n");
                    fflush(stdin);
                    scanf("%s", &pass[0]);
                    agregar(raiz, user, pass);
                    printf("\n\tEl usuario '%s' se agrego correctamente\n", user);
                }
            }
            else if (eliminacion == 1)
            {
                char user[MAXIMA_LONGITUD_CADENA];
                char pass[MAXIMA_LONGITUD_CADENA];
                printf("Escribe el usuario que deseas eliminar:\n");
                fflush(stdin);
                scanf("%s", &user[0]);
                struct nodoCadena *apuntadorUser = buscarUsername(raiz, user);
                if (apuntadorUser != NULL)
                {
                    printf("Escribe el password del usuario para eliminarlo:\n");
                    fflush(stdin);
                    scanf("%s", &pass[0]);
                    struct nodoCadena *apuntadorPass = buscarPassword(raiz, user, pass);
                    if (apuntadorPass == NULL)
                    {
                        printf("\n\t Se elimino al usuario %s correctamente \n", user);
                    }
                    else
                    {
                        printf("\t!Password incorrecta\n");
                    }
                }
                else
                {
                    printf("\n !El usuario no se encuentra en nuestro sistemas\n");
                }
            }
            else if (ordenamiento == 1)
            {
                ordenar(raiz);
                printf("\nPresiona enter para continuar\n");
                getchar();
            }
        }
        add = 0;
        eliminacion = 0;
        ordenamiento = 0;
    }

}
