// Prime numbers are natural numbers greater than 1 and has no positive divisor
// other than 1 and itself

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int range)
{
  int i=0;
  bool result = true;

  for (i = 2;  i < range; i++) // instead of range, try square root of range
  {
    if((range%i) == 0)
    {
      printf("Not a prime number\n");
      result = false;
      break;
    }
  }
  return result;
}

int main()
{
   int range = 0;
retry:
   printf("Enter a number:\n" );
   scanf("%d", &range);

   if(range == 1){
     printf("Please enter greater than 1\n");
     goto retry;
   }
   if (is_prime(range) == true) {
     printf("%d is a prime number\n", range);
   }
   return 0;
}
