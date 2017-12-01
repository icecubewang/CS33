#include <stdio.h>
//#include <assert.h>
#include <math.h>

static float u2f(unsigned u) {
  return *(float*) &u;
}

float fpwr8(int x) {
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;

  if (x < (-23-126)/3) {
    /* Too small, Return 0.0 */
    exp = 0;
    frac = 0;
  } else if (x < (-126)/3) {
    /* Denomalized result */
    exp = 0;
    frac = 1 <<  (unsigned) (x - (-126-23));
  } else if (x < 128/3) {
    /* Normalized result. */
    exp = 3 * x + 127;
    frac = 0;
  } else {
    /* Too big. Return +infinity */
    exp = 0xFF;
    frac = 0;
  }

  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}

//int main(int argc, char* argv[]) {
//  printf("%d\n", (fpwr8(0) == powf(8,0)));
//  printf("%d\n", (fpwr8(100) == powf(8,100)));
//  printf("%d\n", (fpwr8(-100) == powf(8,-100)));
//  printf("%d\n", (fpwr8(10000) == powf(8,10000)));
//  printf("%d\n", (fpwr8(-10000) == powf(8,-10000)));
//  return 0;
//}
