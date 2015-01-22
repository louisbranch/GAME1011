#include "utility.h"

int main() {
  system(CLEAR);
  puts("WELCOME");
  menu();
  return 0;
}

void menu() {
  int i;
  for (i = 0; helptext[i]; i++) {
    puts(helptext[i]);
  }
  char option;
  scanf(" %c", &option);
  system(CLEAR);

  switch (option) {
    case '1':
      kg_to_lbs();
      break;
    case '2':
      celsius_to_kelvin();
      break;
    case '3':
      tsp_to_ml();
      break;
    case '4':
      multiplication_table();
      break;
    case '5':
      square_table();
      break;
  }
}

void kg_to_lbs() {
  int k = get_input();
  if (k) {
    float p = k * 2.2;
    printf("%d kgs == %.2f pounds\n", k, p);
    back_to_menu();
  }
}

void celsius_to_kelvin() {
  int c = get_input();
  if (c) {
    float k = c + 273.15;
    printf("%d Celsius == %.2f Kelvin\n", c, k);
    back_to_menu();
  }
}

void tsp_to_ml() {
  int t = get_input();
  if (t) {
    float m = t * 4.92;
    printf("%d Teaspoons == %.2f Millilitres\n", t, m);
    back_to_menu();
  }
}

void multiplication_table() {
  int n = get_input();
  int i, j;
  for (i = 1; i <= n; i++) {
    if (i == 1) {
      printf("%6d", i);
    } else if (i < 9) {
      printf("%3d", i);
    } else {
      printf("%4d", i);
    }
  }
  for (i = 1; i <= n; i++) {
    printf("\n%-3d|", i);
    for (j = 1; j <= n; j++) {
      if (j == 1) {
        printf("%2d", i*j);
      } else if (j < 9) {
        printf("%3d", i*j);
      } else {
        printf("%4d", i*j);
      }
    }
  }
  puts("");
  back_to_menu();
}

void square_table() {
  int n = get_input();
  int i, j;
  int dots = 11;
  for (i = 1; i <= n; i++) {
    printf("%d", i);
    if (i > 3 && i < 9) {
      dots = 10;
    } else if (i > 9) {
      dots = 8;
    }
    for (j = 0; j < dots; j++) {
      printf(".");
    }
    printf("%d\n", i*i);
  }
  puts("");
  back_to_menu();
}

int get_input() {
  int input;
  puts("Value:");
  if (scanf(" %d", &input) != 1) {
    input = 0;
  }
  return input;
}

void back_to_menu() {
  char option;
  puts("Do you want to go back to the menu? (y/n)");
  scanf(" %c", &option);
  if (option == 'y' || option == 'Y') {
    system(CLEAR);
    menu();
  }
}
