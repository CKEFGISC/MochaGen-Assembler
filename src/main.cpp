#include<iostream>
#include<string>
#include"number/number.hpp"

int main(){
	auto a=MochaGen::gen_number("integer").range(10, 100).parity(1).prepare();
	std::cout<<a;
	return 0;
}

