#include <stdio.h>
#include <stdlib.h>

int *range(int a) {
  int *d = (int *)malloc(sizeof(int) * a);
  for (int i = 0; i < a; ++i) {
    d[i] = i;
  }
  return d;
}

/**
   Circular shifts an entire array to the right by an
   integer amount in place.

   *NOTE* the swap function can be replaced by any
   swap function of your desire. (And should be inline)

   @param {Array} ary The array to work on
   @param {int} amount The amount of 
   places to shift by
*/
void shift(int *ary, int len, int amt) { //smaller of 2 shift
  int d, s, left, check, k, mx;
  amt = (amt + len) % len;
  if (amt == 0)
    return;
  d = len - amt;
  s = 0;
  while (s < d) {
    left = d - s;
    check = amt > left;
    if (check) {
      amt = left;
    }
    for (k = d, mx = amt + d; k < mx; ++k) {
      //swapping
      ary[s] ^= ary[k];
      ary[k] ^= ary[s];
      ary[s] ^= ary[k];
      ++s;
    }
    if (check) {
      d += amt;
      amt = len - d;
    }
  }
  return;
}

/**
   Logs tests
*/
int main (int argc, char **argv){
  int size = 10;
  if(argc > 1){
    size = atoi(argv[1]);
  }
  for(int i = 0; i < size; ++i){
    int * ary = range(size);
    shift(ary, size, i);
    for(int j = 0; j < size; ++j){
      printf("%i\t", ary[j]);
    }
    printf("\n");
    free(ary);
  }
}

