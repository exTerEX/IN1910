#include <iostream>
#include <vector>

class ArrayList
{
  public:
	ArrayList(void) { size = 0; capacity = 1; gfac = 2; data = new int[gfac]; }

	~ArrayList(void) { delete[] data; }

	ArrayList(std::vector<int> list) {
		size = 0; capacity = 1000; data = new int[20];

		for (int idx: list) {
        	append(idx);
    	}
	}

	int &operator[](int index) {
		if (0 <= index && index < size) {
			return data[index];
		} else {
            throw std::range_error("IndexError: Index out of range");
		}
	}

	void append(int value) {
		if (size < capacity)
		{
			data[size] = value; size += 1;
		} else {
			resize(); append(value);
		}
	}

	void print(void) {
		std::cout << "[";
		for (int index = 0; index < size; index++){
			if (index != size - 1) {
				std::cout << data[index] << ", ";
			} else {
				std::cout << data[index];
			}
		}
		std::cout << "]" << std::endl;
	}

	int length(void) { return size; }

	void insert(int value, int index) {
		if (size + 1 < capacity) {			
			for (int i = size; i >= index; i--){
				data[i + 1] = data[i];
			}
			data[index] = value;
			size++;
		} else {
			resize(); insert(value, index);
		}
	}

	void remove(int index) {
		for (int i = index; i <= size; i++) {
			data[i] = data[i + 1];
		}

		size--;

		if ((size / capacity) < 0.75) { shrink_to_fit(); }
	}

	int pop() {
		int current = data[size - 1];
		data[size] = 0;
		
		size--;

		if ((size / capacity) < 0.75) { shrink_to_fit(); }

		return current;
	}

	int pop(int index) {
		int current = data[index];

		for (int i = index; i <= size; i++) {
			data[i] = data[i + 1];
		}

		size--;
		if ((size / capacity) < 0.75) { shrink_to_fit(); }

		return current;
	}
	
	void shrink_to_fit() {
		int newCapacity;
		for (int i = 0; i < 64; i++) {
			newCapacity = 2^i;
			if(newCapacity > size) { break; }
		}
		capacity = newCapacity;
	}

  protected:
  private:
	int *data;
	int size;
	int capacity;
	int gfac;

	void resize() {
		capacity *= gfac;
		int *tmp = new int[capacity];
		for (int i=0; i<size; i++) {
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
	}
};