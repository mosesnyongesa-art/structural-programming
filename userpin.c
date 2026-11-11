#include <stdio.h>
#include <stdlib.h>

int main()
{   int userpin;
    int correctpin=9999;

    printf("please provide your user pin: ");
    scanf("%d", &userpin);
    if(userpin==correctpin){
        printf("access granted");
    }
    else if(userpin<1000){
        printf("pin less than 4 digits");
    }
    else if(userpin>9999){
        printf("pin greater than 5 digits");
    }
    else{
            printf("access denied");

    }
    return 0;
}
