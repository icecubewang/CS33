//Homework_2 Feilan Wang 104796844

#include <stdio.h>

int cread_alt(int *xp) {
  int ret = 0;
  return *(xp ? xp : &ret);
}
