#ifndef GEN_ARRAY_HPP
#define GEN_ARRAY_HPP
#include<iostream>
#include<string>

namespace MochaGen{
	struct gen_array{
		std::string _class;
		int val=0;
		float valf=1;
		std::pair<int, int> _range={1, 1e9+7};
		std::pair<float, float> _rangef={1, 1e6};
		int _parity=-1;
		int _prime=-1;
		gen_array(std::string __class): _class(__class){}

		gen_array& range(int l, int r);
		gen_array& parity(int par);
		gen_array& prime(int __prime);
		gen_array& prepare();
	};
}
	std::ostream& operator << (std::ostream& o, MochaGen::gen_array& a);

#endif
