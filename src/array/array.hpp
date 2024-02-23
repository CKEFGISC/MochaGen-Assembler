#ifndef GEN_ARRAY_HPP
#define GEN_ARRAY_HPP

#include<iostream>
#include<string>
#include<vector>

namespace MochaGen{
    template<typename T>
	struct gen_array{
		int length=0;
        T element;
        bool is_unique=0;
        bool is_sorted=0;
        gen_array(int _length);
		gen_array& intrange(int l, int r);
        gen_array& floatrange(float l, float r);
		gen_array& prepare();
	};
};

template<typename T>
std::ostream& operator << (std::ostream& o, MochaGen::gen_array<T>& a);

#endif
