#include "../lib/bitarray/bitarray.h"
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	BitArray bitarray1(17, 122123);
	BitArray bitarray2(16, 56783);

	BitArray bitarray3(9, 0b101011000);
	BitArray bitarray4(9, 0b110011010);

	BitArray bitarray5 = ~bitarray3;
	
	BitArray bitarray6 = bitarray3 & bitarray4;
	BitArray bitarray7 = bitarray3 | bitarray4;
	bitarray3 ^= bitarray6;

	bitarray4.push_back(1);
	bitarray2.pop_back();

	bool i = bitarray4[4];

	bitarray3.reset();

	bitarray4.reset(4);

	bitarray3.clear();
	
	bool is_any = bitarray3.any();

	bool is_none= bitarray3.none();
	

	return 0;

}
