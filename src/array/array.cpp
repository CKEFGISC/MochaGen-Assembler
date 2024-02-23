#include<iostream>
#include<string>
#include"jngen.h"
#include"array.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen{
    template<typename T>
    struct gen_array{
        gen_array(int _length): length(_length){}
    };

}

template<typename T>
ostream& operator << (ostream& o, MochaGen::gen_array<T>& a){
    o << a << std::endl;
	return o;
}
