/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#  include <stdio.h>
main ( ){
    float fahr, celsius; 
    int lower, upper, step;lower = 0; 
    upper = 300;
    step = 20; 
    fahr = lower;
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%f\t%f\n", fahr, celsius); 
        fahr = fahr + step;}
        
}
