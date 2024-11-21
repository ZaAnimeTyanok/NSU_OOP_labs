#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>
#include <algorithm>
#include <vector>


class BitArray {
private:
	std::vector<unsigned char> arr;
	std::size_t size;

	void last_bites_to_zero();
	
	void right_offset_by_one();
	
	void left_offset_by_one();

public:
	BitArray() {
		arr = {};
		size = 0;

	}

	explicit BitArray(size_t num_bits, size_t value = 0) {
		size = (std::size_t)num_bits;

		size_t local_value = value;

		std::size_t n = num_bits / 8 + (num_bits % 8 != 0);

		if (value) {
			local_value <<= (8 - num_bits % 8) * (num_bits % 8 != 0);

			for (size_t i = 0; i < n; i++) {
				arr.push_back((unsigned char)(0b11111111 & local_value));
				local_value >>= 8;

			}

			std::reverse(arr.begin(), arr.end());

		}

		else {
			for (size_t i = 0; i < n; i++) {
				arr.push_back((unsigned char)0);

			}

		}

	}

	BitArray(const BitArray& b) {
		arr = b.arr;
		size = b.size;

	}

	~BitArray() {
		arr.clear();

	}


	std::string get_bin_notation_full()  const;

	std::string get_bin_notation() const;

	std::string to_string() const;
	
	std::size_t get_size();
	
	void swap(BitArray& b);

	void push_back(bool bit);

	void pop_back();

	void resize(size_t num_bits, bool value = 0);

	void clear();

	BitArray& operator=(const BitArray& b);

	BitArray& operator&=(const BitArray& b);

	BitArray& operator|=(const BitArray& b);

	BitArray& operator^=(const BitArray& b);

	BitArray& operator<<=(size_t n);
	
	BitArray& operator>>=(size_t n);

	BitArray operator<<(size_t n) const;

	BitArray operator>>(size_t n) const;

	BitArray& set(size_t n, bool val = 1);

	BitArray& reset(size_t n);
	
	BitArray& set();

	BitArray& reset();

	bool any() const;

	bool none() const;

	bool operator[](size_t i) const;

	BitArray operator~() const;

	size_t count() const;

};

bool operator==(const BitArray& a, const BitArray& b);

bool operator!=(const BitArray& a, const BitArray& b);

BitArray operator&(const BitArray& b1, const BitArray& b2);

BitArray operator|(const BitArray& b1, const BitArray& b2);

BitArray operator^(const BitArray& b1, const BitArray& b2);

#endif
