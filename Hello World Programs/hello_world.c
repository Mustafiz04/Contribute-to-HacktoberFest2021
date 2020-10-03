#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("***Enter option of your choice***\n\n");
    printf("Press 1 for Hello World\n");
    printf("Press 2 for Hello Hactoberfest\n");
    scanf("%d",&n);
    switch(n){
    case 1:
        printf("Hello World\n");
        printf("I'm new to open source\n");
        break;

    case 2:
        printf("Hello Hacktoberfest\n");
        printf("Let's Contribute to Open Source");
        break;

    default:
        printf("Enter valid response");
    }
}
