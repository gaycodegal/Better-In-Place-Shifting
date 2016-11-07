# Better In-Place Shifting

Most people know the circular shift algorithm that uses reverse internally, which reverses the entire array (n/2 swaps) and then reverses two sub arrays ((n-m)/2 + m/2 == n/2 swaps), using n swaps in total. I was examining this algorithm and was determined to make a different algorithm that would function in place, while still only requiring a maximum of n swaps.

Thus, I came up with a new algorithm which uses a maximum of n-1 swaps and a minimum of n/2 swaps (provided of course that the array needs to be shifted at all). On average, in C++ compiled using the -O2 command, I was able to beat the shift-by-reversing version by about 300%, with a maximum of over 500%, and lows of about 200%. There are three cases where my algorithm is either just as fast, or marginally slower than the reversal algorithm due to its constant factors (although other algorithms exist that beat the reversal algorithm in two cases). The first case is when no elements need to move - there is no faster solution than simply not moving them. The second case is when the array needs to be shifted by 1 - and a better algorithm for this case I'm sure is easy for the reader to devise. The final case is when the array is shifted by n - 1 (or conversely shifted to the left by 1), which is basically the same as the second case.

The algorithm is provided in JavaScript and C++. C++ includes the tests I used, JavaScript's tests simply demonstrate functionality.

My algorithm requires basically the same amount of swaps, and has likely worse constant factors internally, but is able to still beat the current algorithm by an average of 300%.
