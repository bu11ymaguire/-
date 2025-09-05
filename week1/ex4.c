#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));

  int answer[4];
  int A = rand() % 9 + 1;
  answer[0] = A;

  int B = rand() % 10;
  if (A == B) {
    while (A == B) {
      B = rand() % 10;
    }
  }
  answer[1] = B;

  int C = rand() % 10;
  if (A == C || B == C) {
    while (A == C || B == C) {
      C = rand() % 10;
    }
  }
  answer[2] = C;

  int D = rand() % 10;
  if (A == D || B == D || C == D) {
    while (A == D || B == D || C == D) {
      D = rand() % 10;
    }
  }
  answer[3] = D;

  int trying = 1;
  while (trying <= 4) {
    printf("Try %d: ", trying);
    int input;
    scanf("%d", &input);

    int game[4];

    game[0] = input / 1000;
    input %= 1000;
    game[1] = input / 100;
    input %= 100;
    game[2] = input / 10;
    game[3] = input % 10;

    if (game[0] == game[1] || game[0] == game[2] || game[0] == game[3] ||
        game[1] == game[2] || game[1] == game[3] || game[2] == game[3]) {
      printf("The digits must be all different \n");
      trying++;
      continue;
    }
    int strike = 0;
    int ball = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (answer[i] == game[j]) {
          if (i == j)
            strike++;
          else
            ball++;
          break;
        }
      }
    }
    printf("bull: %d cow: %d\n", strike, ball);
    if (strike == 4) {
      printf("You Win! \n");
      break;
    }
    trying++;
  }
  return 0;
}
