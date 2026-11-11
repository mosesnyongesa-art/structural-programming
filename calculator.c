#include <stdio.h>
#include <stdlib.h>

int main()
{
 int a;
 int b;
 int answer;
 char op;
 printf("enter first number: ");
 scanf("%d", &a);
 printf("enter operator: ");
 scanf(" %c", &op);
 printf("enter second number: ");
 scanf("%d", &b);

 if (op=='+')
 {
     answer=a+b;
     printf("answer=%d", answer);
 }
 else if (op=='-')
 {
     answer=a-b;
     printf("answer=%d", answer);
 }
  else if (op=='*')
 {
     answer=a*b;
     printf("answer=%d", answer);
 }
  else if (op=='/')
 {
     if (b==0)
     {
         printf("cannot devide by zero");
     }
     else
     {
          answer=a/b;
        printf("answer=%d", answer);
     }
 }
 else
 {
     printf("invalid operator");
 }
 return 0;
}
