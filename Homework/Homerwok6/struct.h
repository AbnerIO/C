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
