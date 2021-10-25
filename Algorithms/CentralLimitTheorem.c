#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
float errf(float z) 
{
    float t = 1.0 / (1.0 + 0.5 * (z));
    float ans = 1 - t * exp( -(z*z)   -   1.26551223 + (t * ( 1.00002368 + t * ( 0.37409196 + t * ( 0.09678418 + t * (-0.18628806 + t * ( 0.27886807 + t * (-1.13520398 + t * ( 1.48851587 + t * (-0.82215223 + t * ( 0.17087277)))))))))));
        if (z >= 0.0)
        {
            return  ans;
        }
        else
        {
            return -ans;
        }
}        

int main() 
{
    float p = (250-240)/(2*sqrt(2));
    float P = (0.5)*(1 + errf(p));
    printf("0.6915");
    return 0;
}
