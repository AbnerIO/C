// Made by myself, no copied code, but i used google for concepts and little pieces of info about prime numbers algorithms https://www.conoce3000.com/html/espaniol/Libros/Matematica01/Cap07-03-AlgoritmoDeterminarNumeroPrimo.php#:~:text=El%20algoritmo%20m%C3%A1s%20simple,%20para%20determinar%20si%20un,entonces%20es%20compuesto%20en%20caso%20contrario%20es%20primo.
#include <stdio.h>
#include <math.h>
#define K 15 //How many numbers do you want to print+1 (so, if you want to print 4, write 5)

int Getprimes(int k);
int Coutmaxdigits(int m); //Count the number of "0"s and "1"s of the largest number, because all of them will have the same quantity.
int DecimaltoBinary(int d, int y);
int listOfPrimes[K];
int maxDigits;
int main()
{
    printf("Esta es una lista de los primeros %d numeros primarios en version binaria:\n\n", (K - 1));
    int longest, u, maxDigits, j, a[100];
    int i = 0;
    Getprimes(K);
    while (listOfPrimes[K - 1] > 0) //cuenta cuantos digitos tiene el numero binario más grande
    {
        a[i] = listOfPrimes[K - 1] % 2;
        listOfPrimes[K - 1] /= 2;
        ++i;
    }
    maxDigits = i;
    for (int g = 0; g < K; g++)
    {
        DecimaltoBinary(listOfPrimes[g], maxDigits);
    }
    getchar();
}

int Getprimes(int k)
{
    int i, flag, sqr;
    int j = 0;
    int count = 1;
    int n = 2;

    while (count <= k)
    {
        sqr = sqrt(n);
        flag = 0;
        for (i = 2; i <= sqr; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            listOfPrimes[j] = n;
            count++;
            j++;
        }
        n++;
    }
}

int DecimaltoBinary(int d, int y)
{
    int j, a[100], digits;
    int i = 0;
    while (d > 0)
    {
        a[i] = d % 2;
        d /= 2;
        ++i;
    }
    digits = i;
    for (j = i - 1; j >= 0; --j)
    {
        if (digits < y)
        {
            printf("0");
            digits++;
            j++;
        }
        else
        {
            printf("%d", a[j]);
        }
    }
    printf("\n");
    return 0;
}
