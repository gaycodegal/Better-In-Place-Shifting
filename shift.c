#include <stdio.h>
#include <stdlib.h>

int *range(int a) {
  int *d = (int *)malloc(sizeof(int) * a);
  for (int i = 0; i < a; ++i) {
    d[i] = i;
  }
  return d;
}

/*
any generic swapping function
@param x {Array} The array
@param a {int} A position within the array to swap
@param b {int} A position within the array to swap
*/
int swap(int *array, int a, int b) {
    int t = array[a];
    array[a] = array[b];
    array[b] = t;
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
    amt = amt % len;
    if (amt == 0)
      return;
    int d = len - amt;
    int s = 0;

    while (s < d) {
        int left = d - s;
        int check = amt > left;
        if (check) {
            amt = left;
        }
        for (int k = 0; k < amt; ++k) {
            swap(ary, s, k + d);
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
      printf("%i ", ary[j]);
    }
    printf("\n");
    free(ary);
  }
}

