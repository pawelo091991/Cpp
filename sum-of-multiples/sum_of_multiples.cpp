#include "sum_of_multiples.h"

uint32_t sum_of_multiples::to(std::list<uint32_t>divide, uint32_t max){

	std::list<uint32_t>numbers; 
	for(uint32_t i = 0; i < max; i++){
		for(auto d : divide){
			if(i % d == 0){
				numbers.push_back(i);
			}
		}
	}

	numbers.unique();
	uint32_t sum = std::accumulate(numbers.begin(), numbers.end(), 0);
	return sum;
}
