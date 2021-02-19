#include <stdio.h>
/* copia la entrada a la salida; 2a. versión */
main( ) {
    int c;
    if (c = getchar( ) != EOF)
    {
        putchar(c);  // We wont get the character that we wrote 
    }
    
    getch();
}