#include <stdio.h>
int main()
{
    int c;
    int number = 0, WriteAll = 0;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {         // Check if theres quotes, parethesis or something like that.
        case ']': 
        case '>':
        case '}':
        case ')':
            WriteAll = 0;//When is closed, writeall is OFF
            putchar(c);
            break;
        case '[':
        case '<':
        case '(':
        case '{':
            WriteAll = 1; //When is open, writeall is ON
            putchar(c);
            break;
        case '\'':
            putchar(c);
            WriteAll++;
            break;
        case '\"':
            putchar(c);
            WriteAll++;
            break;
        default:
            if (c != ',' && c != '.' && c != ':' && c != '?' && c != '!' && c != '-' && c != ';' && c != '_' && c != '#' && c != '=' && c != '¿') // evaluate if it isnt an special character
            {
                if (WriteAll == 1)
                {
                    putchar(c);
                }
                else
                {
                    if (WriteAll == 2)
                    {
                        WriteAll = 0;
                    }
                    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
                    {
                        number++;
                    }
                    else
                    {
                        number = 0;
                    }
                    if (number == 1) // theres a number, write X
                    {
                        putchar('X');
                    }
                    if (number == 0)
                    {
                        putchar(c);
                    }
                }
            }
        }
    }
    return 0;
}
