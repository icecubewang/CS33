#include <stdio.h>
#include <limits.h>
#define INT_ADD_OVERFLOW_P(a, b)\

int saturating_add (int x, int y) {
  if (__builtin_add_overflow_p(x, y,(int)0)){
    if (x > 0)
      return INT_MAX;
    else 
      return INT_MIN;
  }
  else return x+y;
}

int main(void) {
  printf("%d", saturating_add(INT_MAX, 3));
  return 0;
}
