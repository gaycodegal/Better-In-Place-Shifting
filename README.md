# Better In-Place Shifting

Most people know the circular shift algorithm that uses reverse internally, which reverses the entire array (n/2 swaps) and then reverses two sub arrays ((n-m)/2 + m/2 == n/2 swaps), using n swaps in total. I was examining this algorithm and was determined to make a different algorithm that would function in place, while still only requiring a maximum of n swaps.

Thus, I came up with a new algorithm which uses a maximum of n-1 swaps and a minimum of n/2 swaps (provided of course that the array needs to be shifted at all). 
