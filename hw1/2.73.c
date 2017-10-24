#include <stdio.h>
#include <limits.h>

int saturating_add (int x, int y) {
  int result = x+y;
  //cPO will be 100...00 if pos overflow and 000...00 otherwise
  int checkPositiveOverflow = (~(x&INT_MIN)&~(y&INT_MIN)&(result&INT_MIN));
  //cNO will be 100...00 if pos overflow and 000...00 otherwise
  int checkNegativeOverflow = ((x&INT_MIN)&(y&INT_MIN)&~(result&INT_MIN));
  //now, perform arithmetic shift on both cPO and cNO to get 111...111
  checkPositiveOverflow = checkPositiveOverflow >> ((sizeof(int)<<3)-1);
  checkNegativeOverflow = checkNegativeOverflow >> ((sizeof(int)<<3)-1);
  //return 
  return ((INT_MAX & checkPositiveOverflow) + (INT_MIN & checkNegativeOverflow) + (~checkPositiveOverflow & ~checkNegativeOverflow & result));
}

int main(void) {
  printf("%d", saturating_add(INT_MAX-1, 3));
  return 0;
}
