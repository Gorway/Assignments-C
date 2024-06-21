#include <stdio.h>

int main()
{

    int input = 0;
    int bit_index = 0;
    
    printf("Enter number: ");
    scanf("%d", &input);
    
    printf("Enter bit index to check is it one or zero. ( Between 1-32 ): ");
    scanf("%d", &bit_index);

    int mask = 1;
    mask <<= bit_index;
  
    if(input & mask)
   {
      printf("Bit in index %d is one!\n", bit_index);
   
   } else {

      printf("Bit in index %d is zero!\n", bit_index);
   }

}
