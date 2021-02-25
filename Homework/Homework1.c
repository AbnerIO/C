/* NOTES 1
Instructions: Write or copy the text and press ENTER, then make "EOF" (crl+z in cmd or ctrl+D in C compiler), i dont know exactly how to do "EOF" in mac  
I made this program manually 100% by myself using strings, void function, while etc. More notes at the end
*/

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
        if (replacing2underscore == 1) // -------CONFIRMED <strong> or <h1,2,3,4,etc> process--------------
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
            else if (text[i] == '>' && tags == 2)           //significa que ya encontramos ><> ==== '>' '<'/strong'>'  así que para ya de replacing2underscore 
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
        else if (killScript == 1) //----------------CONFIRMED <scripts> process---------------
        {
            if (text[i] == textScript[k])
            {
                k++;
            }
            else
            {
                k = 0;
            }
            if (k == 8)                      //significa que ya encontramos '</script>', así que para ya de killScript. 
            {
                killScript = 0;
                k = 0;
            }
        }
        else if (ignore == 1) // --------------------CONFIRMED IGNORED characters process----------------------
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
            else if (text[i] == 'H' || text[i] == 'S' || text[i] == 's' || text[i] == 'h') // Or it could be an "r" or "s" of    <Script> <strong>   or    <h1,2,3,4,etc>
            {
                possibleBoldOrScript = 1;
            }
        }
        else                    //
            if (text[i] == '<') //  EVALUATE if its the start of a tag ("<")
        {
            ignore = 1;
        }
        else
        {
            putchar(text[i]); //PRINTS characters that dont represent any risk (NO scripts, h1,htmls,img,etc)
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

/* NOTES 2
My program  evaluate character by character ('n' times)
1.-First of all, it search if there is a tag (´<´ es el principal indicador de eso)    **Line 98
            If its true, it create a flag (ignore=1) 
            If its false, print the character
2.-Now with the following characters, if ignore=1,  the program will evaluate if its a 
            <script>: Activate the tag killScript=1
            <h1,2,3,4,5,etc> or <strong>: Activate the flag replacing2underscore=1, because in both of them it will do the same thing. 
            '>': Close the tag ignore, so ignore=0, because that means that the tag in html is closed (<html'>', <img'>', <p'>')
            Else: It wont do anything neither print the character. 
    All of these things are inside the Lines 60-96
3.- I made like ""stop signals"" for each tag
            if replacing2underscore             do something          Line 19-43
            if killScript=1                           do something          Line 44-59

*/
