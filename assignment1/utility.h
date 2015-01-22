#include <stdlib.h>
#include <stdio.h>

#ifdef __unix__
#define CLEAR "clear"
#else
#undef CLEAR
#define CLEAR "cls"
#endif

static const char *const helptext[] = {
  "Please select one of the following functions",
  "",
  "1) Kilograms to Pounds",
  "2) Celsius to Kelvin",
  "3) Teaspoons to Millilitres",
  "4) Multiplication Table",
  "5) Squares Table",
  "X) Exit",
  "",
  "Enter Option:",
  0
};

void menu();
int get_input();
void kg_to_lbs();
void back_to_menu();
void celsius_to_kelvin();
void tsp_to_ml();
void multiplication_table();
void square_table();
