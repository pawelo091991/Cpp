#include "circular_buffer.h"

namespace circular_buffer {
	template<typename T>
	circular_buffer<T>::circular_buffer(int n) {
		buffer.resize(n);
	}

	template<typename T>
	T circular_buffer<T>::read() {

		if (empty == true)
			throw std::domain_error("Buffer is empty");


		if (buffer[end % buffer.size()] == NULL)
			throw std::domain_error("nothing to read");
		int return_index = end++ % buffer.size();

		T return_value = buffer[return_index];
		buffer[return_index] = NULL;

		return return_value;
	}

	template<typename T>
	void circular_buffer<T>::write(T n) {
		int index = cur++ % buffer.size();

		if (buffer[index] == NULL) {	//allow to write condition
			empty = false;				//buffer no longer empty
			buffer[index] = n;			//write to buffer
		}
		else
			throw std::domain_error("Place is occupied"); //There is something already!
	}

	template<typename T>
	void circular_buffer<T>::clear() {
		for (int i = 0; i < buffer.size(); i++)
			buffer[i] = NULL;
			empty = true;
	}

	template<typename T>
	void circular_buffer<T>::overwrite(T n) {
		if (cur % 3 == end % 3)
			end++;

		int index = cur++ % buffer.size();
		buffer[index] = n;
	}
}  // namespace circular_buffer
