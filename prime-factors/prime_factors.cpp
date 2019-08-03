#include "prime_factors.h"

const std::vector<int> prime_factors::of(unsigned int number){
	std::vector<int> div;
	unsigned int divisor = 2;
	unsigned int temp;
	while(divisor < number){
		temp = number % divisor;
		if(temp == 0){
			number = number / divisor;
			div.push_back(divisor);
		}
		else
			divisor++;
	}
	//div.unique();
	return div;
}
