#  include <stdio.h>

main ( ){
    float fahr, celsius; 
    int lower, upper, step;
    lower = 0; 
    upper = 300;
    step = 20; 
    celsius = lower;
    printf("Celcius-Farenheit table with and interval of 0 to %d and differences of %d in each case \n", upper, step);
    while(celsius <= upper) {
        fahr = (celsius * 9/5) + 32;
        printf("%3.2f\t%6.1f\n", celsius, fahr); 
        celsius = celsius + step;}
        getch();

}