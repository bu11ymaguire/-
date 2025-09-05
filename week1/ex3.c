#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void factoriaztion(int N) {
  bool can_divide = false;
  int check = 0;
  for (int i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      can_divide = true;
      check = i;
      break;
    }
  }
  if (can_divide) {
    printf("%d * ", check);
    factoriaztion(N / check);
  } else {
    printf("%d", N);
    return;
  }
}

int main() {
  printf("User input number: ");
  int input;
  scanf("%d", &input);

  printf("%d= ", input);
  factoriaztion(input);

  return 0;
}
