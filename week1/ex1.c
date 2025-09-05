#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
  srand(time(0));
  int num;
  num = rand() % 100 + 1;
  int guess = 6;
  bool correct = false;

  int input;
  printf("Choose 1~100 number. \n");
  printf("User Input: ");
  scanf("%d", &input);
  guess--;

  if (input == num)
    correct = true;
  else
  {
    while (guess>0) 
    {
      printf(" \n");
      if (input < num) {
        printf("Up \n");
        printf("%d chances left! \n",guess);
        printf("Choose 1~100 number. \n");
        printf("User Input: ");
        scanf("%d", &input);
      } else if (input > num) {
        printf("Down \n");
        printf("%d chances left! \n",guess);
        printf("Choose 1~100 number. \n");
        printf("User Input: ");
        scanf("%d", &input);
      }
      if (input == num) {
        correct = true;
        break;
      }
      guess--;
    }
  }
  printf(" \n");
  if (correct) {
    printf("Correct \n");
    printf("You win");
  } else {
    if (input < num)
      printf("Up\n");
    else if (input > num)
      printf("Down\n");
    printf("%d chances left!\n", guess);
    printf("You Lose");
  }

  return 0;
}
