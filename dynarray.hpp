#pragma once

#ifdef DEBUG
#define TMP_DEBUG_12345 DEBUG
#undef DEBUG
#include <iostream>
using std::cerr;
#define DEBUG (cerr << "[DynArray " << this << "] ")
#endif

template <class T>
class DynArray {
private:
	T* _buffer;
	size_t _length;
	size_t _capacity;

public:
	explicit DynArray(size_t capacity = 64)
		: _buffer(new T[capacity])
		, _length(0) 
		, _capacity(capacity) {
			#ifdef DEBUG
			DEBUG << "New array with capacity " << capacity << '\n';
			#endif
		}

	~DynArray() {
		#ifdef DEBUG
		DEBUG << "Destroyed" << '\n';
		#endif
		delete[] _buffer;
	}

	size_t size() const {
		return _length;
	}

	size_t length() const {
		return _length;
	}

	operator bool() const {
		return length() > 0;
	}

	size_t capacity() const {
		return _capacity;
	}

	void push_back(T element) {
		if (_length + 1 > _capacity) {
			#ifdef DEBUG
			DEBUG << "Push attempt when length and capacity are " << _capacity << ", reallocating" << '\n';
			#endif
			T *new_buffer = new T[_capacity * 2];
			for (size_t i = 0; i < _capacity; ++i) {
				new_buffer[i] = _buffer[i];
			}
			delete[] _buffer;
			_buffer = new_buffer;
			_capacity *= 2;
		}
		_buffer[_length++] = element;
	}

	DynArray<T>& operator<<(T element) {
		push_back(element);
		return *this;
	}

	void pop_back() {
		_length--;
	}

	T& operator[](size_t index) {
		return _buffer[index];
	}

	const T& operator[](size_t index) const {
		return _buffer[index];
	}

	// Iterator bullshit
	class iterator {
	private:
		DynArray<T>* _arr;
		size_t _index;
	public:
		// Default constructible
		iterator() : _arr(nullptr), _index(-1) {}
		iterator(DynArray<T> &arr, size_t index = 0) : _arr(&arr), _index(index) {}
		// Copy constructible
		iterator(const iterator &it) : _arr(it._arr), _index(it._index) {}

		// Copy assignable
		iterator& operator=(const iterator& it) {
			_arr = it._arr;
			_index = it._index;
		}

		// Comparable
		bool operator==(const iterator& it) const {
			return _arr == it._arr && _index == it._index;
		}

		bool operator!=(const iterator& it) const {
			return !(*this == it);
		}

		// Dereferencable
		T& operator*() {
			return (*_arr)[_index];
		}
		const T& operator*() const {
			return (*_arr)[_index];
		}

		T* operator->() {
			return &((*_arr)[_index]);
		}
		const T* operator->() const {
			return &((*_arr)[_index]);
		}

		// Can be incremented
		iterator& operator++() {
			_index++;
			return *this;
		}

		iterator operator++(int) {
			auto copy = *this;
			++*this;
			return copy;
		}
	};

	iterator begin() {
		return iterator(*this);
	}
	const iterator begin() const {
		return iterator(*this);
	}

	iterator end() {
		return iterator(*this, size());
	}
	const iterator end() const {
		return iterator(*this, size());
	}
};

#ifdef TMP_DEBUG_12345
#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG TMP_DEBUG_12345
#undef TMP_DEBUG_12345
#endif
