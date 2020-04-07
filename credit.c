#include <stdio.h>
#include <cs50.h>


int main(void)
{
  
    long number, cardchec, cardvali;
    
    // here the card number is requested from the user
    do
    {
        printf("Please enter your credit card number \n");
        number = get_long("card number: ");
    }
    while (number < 0); // loop for requesting number greater than zero 
    
    // declaration of the data type of variables to store the computation for checksum validation  
    int nad, mul, sumad, sumprod;
    sumad = 0;
    sumprod = 0;
// assigning variable "cardchec" to number entered by the user for checksum validation    
    cardchec = number;
// assigning second variable "cardvali" to the number entered by the user for card type and card number lenght validation 
    cardvali = number; 
    
    // computation of checksum validation
    while (cardchec > 0)
    {
        // summing digits not multipied by 2
// here the last digit on cardchec is identified gotten by %10 and stored in variable nad, every digit identified are added and stored temporarily in variable sumad, the last digit identified is thereby removed from cardchec to have a new shorter number and then stored in new cardchec,the shorter number is then divided by 10 in order to eliminate the number in between the previous last number and the intending new last number, this process is to ensure we are choosing digits to be added consecutively but ommiting one digit at intervals. This process continues as long as the while condition is satisfied. 
        nad = cardchec % 10;
        sumad += nad; 
        cardchec -= nad;
        cardchec /= 10;
    
        // summing digit multiplied by two
           
        mul = cardchec % 10;
        
        if ((mul * 2) > 9) // products of digits greater than 9 are treated as individual digits
        {
            int n = mul * 2;
            sumprod += ((n % 10) + 1); 
           
        }
        else
        {
            sumprod += (mul * 2);
        }    
        cardchec -= mul;
        cardchec /= 10;
        
    }
    
    // validation of the card number if it passes the checksum, next is the identificaton of the card type and card length 
    if ((sumad + sumprod) % 10 == 0)
    {

        bool Amex = (cardvali >= 340000000000000 && cardvali < 350000000000000) || 
                    (cardvali >= 370000000000000 && cardvali < 380000000000000);
          
        bool Mcard = (cardvali >= 5100000000000000 && cardvali < 5600000000000000);
         
        bool Visa = (cardvali >= 4000000000000 && cardvali < 5000000000000) || 
                    (cardvali >= 4000000000000000 && cardvali < 5000000000000000);

        if (Amex)
        {
            printf("card check successful! Valid American Express card!\n");
        }
        else if (Mcard) 
        {    
            printf("card check successful! Valid MasterCard\n");
        }
        else if (Visa)
        {      
            printf("card check successful! Valid Visa card\n");
        }
        else
        {
            printf("oops!!! card check passed but card type not identified\n");
        }
    }
    else
    {
        printf("oops!!! INVALID CARD!\n");

        printf("enter a valid card number\n");
    }
    
}

