#include <cs50.h>
#include <stdio.h>

int main(void)
{

    printf("hello, choose the height you want from 1 to 8 \n"); 
    int n;
   do
   {
       n = get_int("height: ");
   }

   while (n < 0 || n > 8);

   for (int i = 0; i < n; i++) //for loop for each row 

   {
       for (int j = 0; j < 2 * n + 2; j++)

       {
           if (i + j < n - 1 || j == n || j== n + 1) // conditional statement to print space

           printf(" ");

           else if(i + j >= n - 1 && j - i <= n + 2)// conditional statement to print hashes

           printf("#");

       }

       printf("\n");// command to ensure the hashes move to the next line 

   }

}
