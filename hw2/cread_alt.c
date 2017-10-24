#include <stdio.h>

int cread_alt(int *xp) {
  int ret = 0;
  return *(xp ? xp : &ret);
}
