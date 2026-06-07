#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Vector {
	public:
		int size = 0;
		int capacity = 1;
		unique_ptr<int[]> arr = make_unique<int[]>(capacity);

		void push_back(int elem) {
			if (this->size == 0) {
				this->size++;
				this->arr[0] = elem;
				return;
			}

			if (this->size > this->capacity) {
				this->capacity *= 2;
				int* buff_arr = new int[capacity];
				for (int i = 0; i < size; ++i) {
					buff_arr[i] = arr[i]; 
				}
				arr.reset(buff_arr);
			}
			this->arr[size] = elem;
			this->size++;
		}

		void remove() {
			if (this->size == 0) {
				return;
			}

			this->size -= 1;
		}


		bool is_bounds(int index) {
			if (0 > index || index >= this->size) {
				return false;
			}
			return true;
		}

		void replace(int index, int elem) {
			if (is_bounds(index)) {
				arr[index] = elem;
			} else {
				throw runtime_error("index out of bounds");
			}
		}

		int index(int index) {
			if (!is_bounds(index)) {
				throw runtime_error("index out of bounds");
			}
			return arr[index];
		}
};

int main() {
	Vector arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(9);
	for (int i = 0; i < arr.size; ++i) {
		cout << arr.index(i) << '\n';
	}
	arr.remove();
	for (int i = 0; i < arr.size; ++i) {
		cout << arr.index(i) << '\n';
	}

	arr.replace(0, 15);
	cout << arr.index(0) << '\n';
}
