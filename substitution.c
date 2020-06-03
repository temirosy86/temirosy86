#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc!=2)
    {
        printf("missing command line input\n", argv[0]);
        return 1;
    }
     for (int i = 0; i<strlen(argv[1]); i++)
     {
         if (!isalpha (argv[1][i]))
         {
             printf("input error,only text is allowed for the key\n", argv[1]);
             return 1;
         }

     }

     int clen=strlen(argv[1][i]);
     if (clen < 26 || clen > 26)
     {
         printf("Error: input key must contain 26 character letters \n", argv[0]);
         return 1;
     }

     int count = 0;
     int con = 0;
     for (int i= 0; i < clen; i++)
     {
         for (int j = 0; argv[1][j] !='\0'; j++)
         {
             count++;
            if (argv[1][i]==argv[1][j])
            {
                con++; // this memory location wont store values that appear more than once
            }
         }
     }
     if (con!=clen) // if the number of the input which has a 26 character lenght (clen) is not equal to the counter storing values from the loops
     {
         printf("Error: input key must contain unique letters \n", argv[0]);
         return 1;
     }
 string plaintext;
 plaintext = get_string ("enter the plaintext: \n");
 printf("plaintext: %s", plaintext);

char ciphertext = strlen(plaintext);
 for (int k= 0; k < ciphertext; k++)
 {
     if (islower (plaintext(k)))
     {
         ciphertext = (tolower(ciphertext))
         printf("cipher text: %c\n", ciphertext);
     }
     else if (isupper (plaintext(k)))
     {
         ciphertext = (toupper (ciphertext));
         printf("cipher text: %c\n", ciphertext);
     }
 }
 printf("\n");
 return 0;
}