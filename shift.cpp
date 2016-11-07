#include <iostream>
#include <ctime>

//do forgive me, I'm using cout and didn't
//feel like writing std:: (my algorithm doesn't use
//std inside it, it's just for the tests).
using namespace std; 

/**
makes an array similar to calling
list(range(length)) in Python.
*/
int * makeArray(const int length){
  int * array = new int[length];
  for(int i = 0; i < length; ++i){
    array[i] = i;
  }
  return array;
}

/**
prints an array.
*/
void printArray(double * array, const int length){
  if(length > 0)
    cout << array[0];
  for(int i = 1; i < length; ++i){
    cout << "," << array[i];
  }
  cout << endl;
  cout << endl;
}

/**
prints an array divided by another array.
*/
void printArray2(double * array, double * array2, const int length){
  if(length > 0)
    cout << array[0]/array2[0];
  for(int i = 1; i < length; ++i){
    cout << "\t" << array[i]/array2[i];
  }
  cout << endl;
  cout << endl;
}

/*
Reverses an array in the range of [from,to]
*/
inline void reverse(int * from, int * to){
  while(from < to){
    *from ^= *to;
    *to ^= *from;
    *from ^= *to;
    ++from;
    --to;
  }
}

/**
This will circular shift an array of integer pointers in some range
an amount to the right. You can modify this code to shift any data type.

Efficiency is O(n), but you will always do 2n swaps using this algorithm.

@param array A pointer to the start of the array to be shifted
@param length The length of the array to be shifted.
@param amount The number of places to shift the array by.
*/
void circular_shift_by_reverse(int * array, const int length, int amount){
  amount %= length;
  if (amount == 0)
    return;
  int * end = array + length - 1;
  int * mid = array + amount - 1;
  reverse(array, end); // n/2
  reverse(array, mid); // amount/2
  reverse(mid + 1, end); // (n-amount)/2
}

/**
This will circular shift an array of integer pointers in some range
an amount to the right. You can modify this code to shift any data type.
See the JavaScript implementation if you don't like pointers.

Efficiency is still O(n), but it will often end earlier, and will make
at most n-1 swaps, and as a minimum n/2 swaps provided that any swaps
need be made at all.

This algorithm is meant for in-place efficiency. For shifting into
a new array of the same size as the old one, there is a simpler algorithm
that achieves the same efficiency as this algorithm does for in-place swaps

@param start A pointer to the start of the range to be shifted.
@param end A pointer to the end of the range to be shifted.
@param amt The number of places to shift the array by.
*/
void circular_shift_steph(int * start, int * end, int amt) { //smaller of 2 shift
  int len = end - start;
  amt %= len;
  if (amt == 0)
    return;
    
  int * d = start + len - amt;
  int * s = start;
  bool check;
  int left;
  while (s < d) {
    left = d - s;
    check = amt > left;
    if (check) {
      amt = left;
    }
    for (int * k = d, *f = amt + d; k < f; ++k, ++s) {
            
      // v Execute your swapping code here v
      *s ^= *k;
      *k ^= *s;
      *s ^= *k;
      // ^ Execute your swapping code here ^
            
    }
    if (check) {
      d += amt;
      amt = start + len - d;
    }
  }
}

/**
Runs some tests to show the comparison of my algorithm to the standard
in place shift by reversal algorithm.
*/
int main(int argc, char ** argv){
  clock_t begin;
  clock_t end;
  double elapsed_secs;
    
  int times = 100, temp;
  int data_length = 10000;
  int shift_amount = data_length/2;
  int runs = 1000;
  int i = 0;
  double * runsRev = new double[runs];
  double * runsTwo = new double[runs];
  double avg = 0;
    
  while(i < runs){
    double temporary;
    shift_amount = (i)*data_length/runs;
    int * data = makeArray(data_length);
    //printArray(data, data_length);
    temp = times;
    begin = clock();
    while(temp--)
      circular_shift_by_reverse(data, data_length, shift_amount);
    end = clock();
	
    temporary = elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << "elapsed for reverse: " << elapsed_secs << endl;
    runsRev[i] = elapsed_secs;
    //printArray(data, data_length);
    delete [] data;

    data = makeArray(data_length);

    temp = times;
    begin = clock();
    while(temp--)
      circular_shift_steph(data, data + data_length, shift_amount);
    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << "elapsed for steph: " << elapsed_secs << endl;
    runsTwo[i] = elapsed_secs;
    //cout << temporary/elapsed_secs << endl;
    avg += temporary/elapsed_secs;
    //cout << avg << endl;
    //printArray(data, data_length);
    delete [] data;
    i++;
  }
  cout << "their times: " << endl;
  printArray(runsRev, runs);
  cout << "my times: " << endl;
  printArray(runsTwo, runs);
  cout << "how many times faster is mine (higher is better): " << endl;
  printArray2(runsRev, runsTwo, runs);

  cout << "If you used the -O2 compile flag, for anything greater than 1 and less than n-1 mine is better by an average of: " << (avg/runs) << endl;
    
  delete [] runsRev;
  delete [] runsTwo;
}
