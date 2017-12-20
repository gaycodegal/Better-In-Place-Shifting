# Better In-Place Shifting

In-place shifting has had the double-reversal method, and GCD method of shifting which both run in O(n). I made something in-between which also runs in O(n). It is based on element swapping. With each swap, at least one element ends up in the correct position.

It is useful for me because it provides instructions as to where to swap elements, and all one has to do is then write element swapping code. This is particularly useful for when elements are of arbitrary size as they are in one of my other projects.
