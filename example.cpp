#include <iostream>
#include <random>
using std::cout;
using std::cin;

#include "dynarray.hpp"

int main() {
	size_t n;
	cout << "How many numbers to generate? ";
	cin >> n;

	std::default_random_engine r_eng;
	DynArray<std::default_random_engine::result_type> arr;
	for (auto i = 0; i < n; i++)
	{
		arr << r_eng();
	}
	cout << '\n';

	cout << "Size: " << arr.size() << '\n';
	cout << "Capacity: " << arr.capacity() << '\n';
	cout << "Elements: [";
	bool first = true;
	for (auto elem : arr)
	{
		if (!first) {
			cout << ", ";
		}
		else {
			first = false;
		}
		cout << elem;
	}
	cout << "]\n";

	return 0;
}