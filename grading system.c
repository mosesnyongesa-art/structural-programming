#include <stdio.h>
#include <stdlib.h>

int main()
{
   char grade;
   char A;
   char B;
   char C;
   char D;
   char E;
   printf("please enter your grade: ");
   scanf(" %c", &grade);
   switch(grade){
   case 'A':
    printf("excellent");
    break;
   case 'B':
    printf("good");
    break;
   case 'C':
    printf("average");
    break;
   case 'D':
    printf("pass");
    break;
   case 'E':
    printf("fail");
    break;
   default:
    printf("invalid grade");
   }
   return 0;
}
