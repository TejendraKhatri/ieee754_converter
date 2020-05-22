/**************************************************
*
* File Name: ieee754_converter.c
*
* Developer: Tejendra, Khatri
* Date: Feb 29, 2020 at 11:00 pm
* Updated: Feb 29, 2020 at 11:30 pm
* Compile: gcc ieee754_converter.c -o a.out
*
/**************************************************/

#include <stdio.h>

typedef union
{
  float f ;
  struct
  {
    unsigned int mantissa : 23 ;
    unsigned int exponent : 8 ;
    unsigned int sign : 1 ;
  } ieee ;
} ieee754_float;

//Function to print binary number upto lim bits
void decToBin(int n,int lim)
{
    //array to store binary num
    int binaryNum[32]; 
    int i = 0; 
    while (n > 0) {  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for(int x = 1;x <= (lim-i);x++)
    {
        printf("0");
    }
     for(int j = i-1;j>=0;j--)
    {
        printf("%d",binaryNum[j]);
    }
}

//Print the parts of IEEE 754 representation
void prettyPrinter(ieee754_float tFloat) 
{ 
    //print the sign 0 or 1
	printf("%d | ", tFloat.ieee.sign); 
    //print the exponent part of the float
	decToBin(tFloat.ieee.exponent, 8); 
	printf(" | "); 
    //print the mantissa part of the float
	decToBin(tFloat.ieee.mantissa, 23); 
	printf("\n"); 
}

int main()
{
    //Enter the float value here to see 
    //IEEE floating point representation
    float input;
    printf("Enter the float value: ");
    scanf("%f",&input);
    // printf("%f \n",input);
    //--------------------------------------------
    //Conversion Code
    ieee754_float tFloat;
    tFloat.f = input;
    //Print the structure with pretty printer
    //which then calls a function to
    //convert to binary number
    prettyPrinter(tFloat); 
    // decToBin(245,23);
    return 0;
}
