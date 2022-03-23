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
  // string is 10 char for the string plus the null terminator
  char input1[11];
  printf("Enter a date: ");
  // scan reads 10 characters for the date
  scanf("%s", input1);
  printf("Input value is: %s\n", input1);
  // break string input into components
  int day = 0;
  int month = 0;
  int year = 0;
  /* interesting note on the math used below:
  In order to convert a string into an integer value manually without using atoi(),
  we must use a trick based on how C handles character arithmetic. If you add or subtract 
  a character to/from another character, both chars are cast to ASCII integer values and 
  the arithmetic is applied. If we get some character like '5' (ASCII value 53) we can 
  subtract '0' (ASCII value of 48) from it to produce an integer value of 5. We can repeat 
  this process while multiplying by 10 each iteration to sequentially reproduce large numbers 
  from a string value. This is a pain, but shows how atoi() is implemented. Super cool.
  */
  // day value is found at input1[3] and input1[4]
  int position = 3;
  for (int i = 0; i < 2; i++) {
    day = day * 10 + (input1[position] - '0');
    position++;
  }
  // month value is found at input1[0] and input1[1]
  position = 0;
  for (int j = 0; j < 2; j++) {
    month = month * 10 + (input1[position] - '0');
    position++;
  }
  // year value is found at input1[6] through input1[9]
  position = 6;
  for (int k = 0; k < 4; k++) {
    year = year * 10 + (input1[position] - '0');
    position++;
  }
  printf("Day: %i \nMonth: %i \nYear: %i\n", day, month, year);
  bool leap = is_leap_year(year);
  if (leap) {
    printf("The year %i is a leap year.\n", year);
  } else {
    printf("The year %i is NOT a leap year.\n", year);
  }
}