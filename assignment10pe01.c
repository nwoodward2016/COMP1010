/*******************************/
/* Programmer: Nathan Woodward */
/* Program: assignment10pe01.c */
/* Approximate time: 90 mins   */
/*******************************/

/*
  This program iteratively calculates
  the nth term of the fibonacci sequence
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char* argv[])
{
  int input, n, result;
  input = 1;
    
  while(input != 2){
    printf("1- Calculate Fibonacci\n2- Exit\n(Enter 1 or 2)\n\n");
    scanf("%d", &input);

    switch(input){
    case 1:
      n=1;
      do{
	if(n<1){
	  printf("n should be a positive integer (n>=1). Retry.\n");
	}
	printf("Enter n: ");
	scanf("%d", &n);
      }while(n<1);
      result = fibonacci(n);
      printf("fibonacci(%d) = %d\n\n", n, result);
      break;
    case 2:
      printf("Thank you!\n");
      break;
    default:
      printf("Invalid choice. Retry\n\n");
      break;
    }
  }

  return 0;
}

int fibonacci(int n)
{
  int before,temp,result,i;
  before = -1;
  result = 1;

  for(i=0;i<=n;++i){
    temp=result+before;
    before=result;
    result=temp;
  }
  
  return result;
}

