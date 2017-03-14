/*******************************/
/* Programmer: Nathan Woodward */
/* Program: assignment10pe03.c */
/* Approximate time: 60 mins  */
/*******************************/

/*
  This program calculates the multiplicative
  persistence of a number iteratively
*/

#include <stdio.h>
#include <stdlib.h>

int persistence(int n);
int reduction(int n);

int main(int argc, char* argv[])
{
  int n,i;
  
  printf("Enter integers or ctrl-d(EOF) to exit:\n");
  while((scanf("%d", &n)) != EOF){
    i = persistence(n);
    printf("persistence = %d\n", i);
  }
  return 0;
}

int persistence(int n)
{
  int i;
  i = 0;
  
  while(n > 9){
    n = reduction(n);
    i++;
  }
  
  return i;
}

int reduction(int n)
{
  int product;
  product = 1;

  while(n != 0){
    product *= (n%10);
    n /= 10;
  }
  
  return product;
}


