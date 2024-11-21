#include "bitarray.h"


void BitArray::last_bites_to_zero() {
	if (!arr.empty()) {
		unsigned char offset = 0b11111111;
		offset <<= 8 - size % 8;

		arr.back() &= offset;
	
	}

}

void BitArray::right_offset_by_one() {
	bool last_bit = 0;
	bool new_last_bit;

	for (size_t i = 0; i < arr.size(); i++) {
		new_last_bit = (0b00000001 & arr[i]) != 0;
		arr[i] >>= 1;
		arr[i] |= 0b10000000 * last_bit;

		last_bit = new_last_bit;

	}

	last_bites_to_zero();

}

void BitArray::left_offset_by_one() {
	bool first_bit = 0;
	bool new_first_bit;

	std::reverse(arr.begin(), arr.end());

	for (size_t i = 0; i < arr.size(); i++) {
		new_first_bit = (0b10000000 & arr[i]) != 0;
		arr[i] <<= 1;
		arr[i] |= 0b00000001 * first_bit;

		first_bit = new_first_bit;

	}

	std::reverse(arr.begin(), arr.end());

}

std::string BitArray::get_bin_notation_full() const {
	std::string bin;

	for (auto x : arr) {
		for (size_t i = 0; i < 8; i++) {
			if (x & (0b10000000 >> i)) {
				bin.push_back('1');

			}

			else {
				bin.push_back('0');

			}

		}

	}

	return bin;

}

std::string BitArray::get_bin_notation() const {
	std::string bin;

	for (size_t i = 0; i < size; i++) {
		if (arr[i / 8] & (0b10000000 >> (i % 8))) {
			bin.push_back('1');

		}

		else {
			bin.push_back('0');

		}

	}

	return bin;

}

std::string BitArray::to_string() const {
	std::string str_arr;

	for (auto x : arr) {
		str_arr.push_back((char)x);

	}

	return str_arr;

}

std::size_t BitArray::get_size() {
	return size;

}

void BitArray::swap(BitArray& b) {
	std::vector<unsigned char> v = b.arr;
	b.arr = arr;
	arr = v;
	v.clear();

	std::size_t s = b.size;
	b.size = size;
	size = s;

}

void BitArray::push_back(bool bit) {
	size++;

	unsigned char offset = 0b10000000;

	if (size > arr.size() * 8) {
		arr.push_back((unsigned char)(offset * bit));

		return;

	}

	offset >>= (size % 8) - 1;

	arr.back() |= (offset * bit);

}

void BitArray::pop_back() {
	if (!size) return;

	size--;

	if (size == (arr.size() - 1) * 8) {
		arr.pop_back();

	}

	else {
		last_bites_to_zero();

	}

}


void BitArray::resize(size_t num_bits, bool value = 0) {
	std::size_t dif = num_bits - size;

	if (num_bits > size) {
		for (size_t i = 0; i < dif; i++) {
			push_back(value);

		}

	}

	else {
		dif *= -1;

		for (size_t i = 0; i < dif; i++) {
			pop_back();

		}

	}

	size = num_bits;

}

void BitArray::clear() {
	arr = {};
	size = 0;

}

BitArray& BitArray::operator=(const BitArray& b) {
	arr = b.arr;
	size = b.size;

	return *this;

}

BitArray& BitArray::operator&=(const BitArray& b) {
	if (size != b.size) {
		std::cout << "operator&= error: arrays must have same size";
		exit(EXIT_FAILURE);

	}

	size_t vector_size = arr.size();

	for (size_t i = 0; i < vector_size; i++) {
		arr[i] &= b.arr[i];

	}

	return *this;

}

BitArray& BitArray::operator|=(const BitArray& b) {
	if (size != b.size) {
		std::cout << "operator|= error: arrays must have same size";
		exit(EXIT_FAILURE);

	}

	size_t vector_size = arr.size();

	for (size_t i = 0; i < vector_size; i++) {
		arr[i] |= b.arr[i];

	}

	return *this;

}

BitArray& BitArray::operator^=(const BitArray& b) {
	if (size != b.size) {
		std::cout << "operator^= error: arrays must have same size";
		exit(EXIT_FAILURE);

	}

	size_t vector_size = arr.size();

	for (size_t i = 0; i < vector_size; i++) {
		arr[i] ^= b.arr[i];

	}

	return *this;

}

BitArray& BitArray::operator<<=(size_t n) {
	for (size_t i = 0; i < n; i++) left_offset_by_one();

	return *this;

}

BitArray& BitArray::operator>>=(size_t n) {
	for (size_t i = 0; i < n; i++) right_offset_by_one();

	return *this;

}

BitArray BitArray::operator<<(size_t n) const {
	BitArray new_arr(*this);

	new_arr <<= n;

	return new_arr;

}

BitArray BitArray::operator>>(size_t n) const {
	BitArray new_arr(*this);

	new_arr >>= n;

	return new_arr;

}

BitArray& BitArray::set(size_t n, bool val = 1) {
	if (n >= size or n < 0) {
		exit(EXIT_FAILURE);

	}
	
	if (val) {
		arr[n / 8] |= (0b10000000 >> n % 8);

	}

	else {
		arr[n / 8] &= (0b11111111 - (0b10000000 >> n % 8));

	}

	return *this;

}

BitArray& BitArray::reset(size_t n) {
	if (n >= size or n < 0) {
		exit(EXIT_FAILURE);

	}
	
	return this->set(n, 0);

}

BitArray& BitArray::set() {
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] |= 0b11111111;

	}

	last_bites_to_zero();

	return *this;
}

BitArray& BitArray::reset() {
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] &= 0b00000000;

	}

	return *this;

}

bool BitArray::any() const {
	for (auto x : arr) {
		if (x & 0b11111111) {
			return true;

		}

	}

	return false;

}

bool BitArray::none() const {
	return(!this->any());

}

bool BitArray::operator[](size_t i) const {
	return (bool)((arr[i / 8] & (0b10000000 >> i % 8)) != 0);

}

BitArray BitArray::operator~() const {
	BitArray new_arr(*this);

	for (size_t i = 0; i < arr.size(); i++) {
		new_arr.arr[i] = ~arr[i];

	}

	return new_arr;

}

size_t BitArray::count() const {
	size_t c = 0;

	for (size_t i = 0; i < size; i++) {
		c += (size_t)((arr[i / 8] & (0b10000000 >> i % 8)) != 0);

	}

	return c;

}

bool operator==(const BitArray& a, const BitArray& b) {
	return a.get_bin_notation_full() == b.get_bin_notation_full();

}

bool operator!=(const BitArray& a, const BitArray& b) {
	return !(a == b);

}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
	BitArray new_bit_arry(b1);
	
	new_bit_arry &= b2;
	
	return new_bit_arry;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
	BitArray new_bit_arry(b1);

	new_bit_arry |= b2;

	return new_bit_arry;

}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
	BitArray new_bit_arry(b1);

	new_bit_arry ^= b2;

	return new_bit_arry;


}