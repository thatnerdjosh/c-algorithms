#include<stdbool.h>
#include<stdio.h>

const int SIZE = 5;

int * sortNumbers(int * numbers) {
  bool sorted = false;

  // Create a temp variable for swapping values in an array, defining a default value (is it safe to just do `int temp`?) 
  int temp = 0;

  while (!sorted) {
    bool changed = false;

    // Loop 0 .. SIZE - 1 so we get all the indexes of the array
    for (int i=0; i < SIZE; i++) {

      // Exit condition
      if (i == SIZE - 1) {
        sorted = !changed;
        continue;
      }

      // If nextNum < thisNum, swap
      if (numbers[i + 1] < numbers[i]) {
        temp = numbers[i + 1];
        numbers[i + 1] = numbers[i];
        numbers[i] = temp;
        changed = true;
      }
    }
  }
  return numbers;
}

int main() {
  int unsorted[SIZE] = {1, 5, 4, 2, 3};
  int * sorted = sortNumbers(unsorted);

  // TODO: Add unit tests, because they are fun and convenient 8-)
  for (int i=0; i < SIZE; i++) {
    printf("%d\r\n", sorted[i]);
  }
  return 0;
}
