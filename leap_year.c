#include<stdio.h>
#include<stdbool.h>

bool is_leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 != 0) {
      return true;
    } else {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}

int main() {
  int input1;
  printf("Enter a date: ");
  scanf("%4i", &input1);
  printf("Input value is: %i\n", input1);
  bool leap = is_leap_year(input1);
  if (leap) {
    printf("The year %i is a leap year.\n", input1);
  } else {
    printf("The year %i is NOT a leap year.\n", input1);
  }
}