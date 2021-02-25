/*NOTES: i started doing this "manually", then i tried to introduce strings (that works), functions (that works too) and substrings (i made a mess, so i eliminated them) :p
Instructions: Write or copy the text and press ENTER, then make "EOF" (crl+z in cmd or ctrl+D in C compiler), i dont know exactly how to do "EOF" in mac  */

#include <stdio.h>
#include <stdlib.h>
void GET_WHOLE_TEXT(); //PUTS ALL THE CHARACTERS INSIDE AN ARRAY
int killScript = 0;
int x, k = 0;
char text[2000]; //  Max Number of characters (Modifiable)
char textScript[8] = "/script>";
int main()
{
    int ignore, possibleBoldOrScript, replacing2underscore, finishScriptCounter, tags = 0;
    GET_WHOLE_TEXT();
    for (int i = 0; i < 2000; i++)
    {
        if (replacing2underscore == 1) // -------Confirmed <strong> or <h1,2,3,4,etc> process--------------
        {
            if (text[i] == ' ')
            {
                putchar('_');
            }
            else if (text[i] == '>' && tags == 0)
            {
                tags = 1;
            }
            else if (text[i] == '<' && tags == 1)
            {
                tags = 2;
            }
            else if (text[i] == '>' && tags == 2)
            {
                tags = 0;
                ignore = 0;
                replacing2underscore = 0;
            }
            else if (tags == 1)
            {
                putchar(text[i]);
            }
        }
        else if (killScript == 1) //----------------Confirmed <scripts> process---------------
        {
            if (text[i] == textScript[k])
            {
                k++;
            }
            else
            {
                k = 0;
            }
            if (k == 8)
            {
                killScript = 0;
                k = 0;
            }
        }
        else if (ignore == 1) // --------------------ignored characters process----------------------
        {
            if (possibleBoldOrScript != 0)
            {
                if (text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5') // Maybe, its 1,2,3,4,5 of headers (h1,h2,h3 etc) or a "t" of <sTrong>
                {
                    replacing2underscore = 1;
                    ignore = 0;
                }
                else if (text[i] == 't')
                {
                    possibleBoldOrScript = 2;
                }
                else if (possibleBoldOrScript == 2 && text[i] == 'r')
                {
                    possibleBoldOrScript = 0;
                    replacing2underscore = 1;
                }
                else if (text[i] == 'c') // Maybe, its a c of <sCript>
                {
                    killScript = 1;
                    ignore = 0;
                }
                else
                {
                    possibleBoldOrScript = 0;
                }
            }
            if (text[i] == '>') //Maybe, its the end of a tag (">")
            {
                ignore = 0;
            }
            else if (text[i] == 'H' || text[i] == 'S' || text[i] == 's' || text[i] == 'h') // Or it could be an "r" or "s" of    <Script>    or    <h1,2,3,4,etc>
            {
                possibleBoldOrScript = 1;
            }
        }
        else                    //
            if (text[i] == '<') //  Evaluate if its the start of a tag ("<")
        {
            ignore = 1;
        }
        else
        {
            putchar(text[i]); // Prints characters that dont represent any risk (NO scripts, h1,htmls,img,etc)
        }
    }
    getchar();
}
void GET_WHOLE_TEXT()
{
    extern char text[];
    int i = 0;
    while ((text[i] = getchar()) != EOF)
    {
        i++;
    }
}