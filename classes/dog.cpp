#include "dog.h"
#include <iostream>

void Dog::bark(){
	std::cout <<"Woof" << std::endl;
}


int main(){
	Dog woofy;
	woofy.bark();

	return 0;
}
