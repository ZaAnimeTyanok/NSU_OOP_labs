#include <iostream>

template<typename T> class Container {
public:
	class Iterator {
	public:
		Iterator(T* ptr) {
			ptr_ = ptr;

		}

		T& operator*() {
			return *ptr_;

		}

		T* operator->() {
			return ptr_;

		}

		Iterator& operator++() {
			++ptr_;

			return *this;
			
		}

		Iterator& operator+=(size_t n) {
			ptr_ += n;

			return *this;

		}

		Iterator& operator--() {
			--ptr_;

			return *this;

		}

		Iterator& operator-=(size_t n) {
			ptr_ -= n;

			return *this;

		}

		bool operator==(const Iterator& other) const {
			return ptr_ == other.ptr_;
		
		}

		bool operator!=(const Iterator& other) const {
			return ptr_ != other.ptr_;
		
		}

		Iterator& operator=(const Iterator& other) {
			ptr_ = other.ptr_;
			return *this;

		}


	private:
		T* ptr_;

	};

	Container() : arr_(nullptr), size_(0), capacity_(0){}

	Container(size_t size) : arr_(nullptr), size_(0), capacity_(0) {
		if (size < 0) {
			exit(EXIT_FAILURE);

		}

		if (size) {
			size_ = size;
			capacity_ = size;
			arr_ = new T[size];
		
		}

	}

	Container(std::initializer_list<T> init) : arr_(new T[init.size()]), size_(init.size()), capacity_(init.size()) {
		size_t i = 0;

		for (const auto& value : init) {
			arr_[i++] = value;
		
		}
		
	}
	
	Container& operator=(std::initializer_list<T> init) {
		delete[] arr_;
		
		size_ = init.size();
		capacity_ = init.size();
		arr_ = new T[init.size()];

		size_t i = 0;
		
		for (const auto& value : init) {
			arr_[i++] = value;

		}

		return *this;

	}

	~Container() {
		delete[] arr_;

	}

	size_t size() {
		return size_;

	}

	void push_back(T object) {
		size_++;
		
		if (size_ > capacity_) {
			capacity_ *= 2;
			
			T* new_arr = new T[capacity_];

			for (size_t i = 0; i < size_ - 1; i++) {
				new_arr[i] = arr_[i];

			}

			new_arr[size_ - 1] = object;

			delete[] arr_;

			arr_ = new_arr;

			return;
		}

		arr_[size_ - 1] = object;
	}

	void pop_back() {
		if (!size_) {
			return;
		}
		
		size_--;

		
		if (size_ < capacity_ / 2) {
			capacity_ /= 2;

			T* new_arr = new T[capacity_];

			for (size_t i = 0; i < size_; i++) {
				new_arr[i] = arr_[i];

			}

			delete[] arr_;

			arr_ = new_arr;

		}

	}

	bool empty() {
		return size_ == 0;
	
	}

	T& operator[](size_t i) {
		return arr_[i];
	
	}

	Iterator begin() {
		return Iterator(arr_);

	}

	Iterator end() {
		return Iterator(arr_ + size_);

	}


private:
	T* arr_;
	size_t size_;
	size_t capacity_;

};


int main() {
	Container<int> x;
	x = { 1, 2, 3, 4, 5 };
	
	Container<int> y({6, 7, 8});

	Container<int> z(10);

	for (Container<int>::Iterator i = x.begin(); i != x.end(); ++i) {
		std::cout << *i << std::endl;

	}


	return 0;
}
