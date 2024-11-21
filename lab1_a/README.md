## Lab1_a BitArray
A program with the implementation of a dynamic bit array in c++. The BitArray class was created , it uses vector<unsigned char> to store the array.

## Description of class constructors
* BitArray() — creates array with size 0
* BitArray(size_t num_bits, size_t value = 0) — creates array with size num_bits, they can be specified by the binary notation of value
* BitArray(const BitArray& b) — creates copy of array b

## Description of methods and operators of the BitArray class
* get_bin_notation() — returns the array as a string of '0' and '1'
* get_bin_notation_full() — same as get_bin_notation(), but it also takes into account insignificant zeros
* to_string() — returns the array as a string of unsigned chars
* get_size() — returns array's size
* swap(BitArray& b) — swaps current array with array b
* push_back(bool bit) — adds the specified bit to the end of the array
* pop_back() _ delete bit from the end of the array
* resize(size_t num_bits, bool value = 0) — changes the size of the archive, fills it with the same bits specified by value
* clear() — clears array
* operator=(const BitArray& b), operator&=(const BitArray& b), operator|=(const BitArray& b), operator^=(const BitArray& b) — assignment and bitwise operators, array b must have same size as current array
* operator<<=(size_t n), operator>>=(size_t n) — bitwise left/right shift by n with assigment
* operator<<(size_t n),  operator>>(size_t n) — bitwise left/right shift by n without assigment
* set(size_t n, bool val = 1) — changes the value of the bit at the position n to val
* set() — changes all bits to 1
* reset(size_t n) — changes the value of the bit at the position n to 0
* reset() — changes all bits to 0
* any() — returns 1 if there are at least one 1-bit in the array, otherwise 0
* none() — returns 1 if there are not 1-bit in the array otherwise 0
* operator[](size_t i) — returns value ot the bit at i position
* operator~() — returns array where all the bits are inverted
* count() — returns count of 1-bit
* operator==(const BitArray& a, const BitArray& b) — returns 1 if a == b, otherwise 0
* operator!=(const BitArray& a, const BitArray& b) — returns 0 if a != b, otherwise 0
* operator&(const BitArray& b1, const BitArray& b2), operator|(const BitArray& b1, const BitArray& b2), operator^(const BitArray& b1, const BitArray& b2) — returns a new array that is the result of a bitwise operation between a and b, a must have same size as b
### the main function provides an example of using most of the methods and operators

## Valgrind's memcheck report
```
==10417== Memcheck, a memory error detector
==10417== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10417== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10417== Command: ./a.out
==10417==
==10417==
==10417== HEAP SUMMARY:
==10417==     in use at exit: 0 bytes in 0 blocks
==10417==   total heap usage: 13 allocs, 13 frees, 72,726 bytes allocated
==10417==
==10417== All heap blocks were freed -- no leaks are possible
==10417==
==10417== For lists of detected and suppressed errors, rerun with: -s
==10417== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
