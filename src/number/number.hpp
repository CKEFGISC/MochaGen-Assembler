#ifndef GEN_NUMBER_HPP
#define GEN_NUMBER_HPP
#include <iostream>
#include <string>

namespace MochaGen {
// template <typename T>
struct gen_number {
    std::string _class;
    int val = 0;
    float valf = 1;
    std::pair<int, int> _range = {1, 1e9 + 7};
    std::pair<float, float> _rangef = {1, 1e6};
    int _parity = -1;
    int _prime = -1;
    bool prepared = 0;
    std::string endswith = "\n";

    gen_number(std::string __class) : _class(__class) {}

    gen_number& range(int l, int r);
    gen_number& rangef(int l, int r);

    gen_number& end(std::string _endswith);

    gen_number& is_odd(bool _is_odd);
    gen_number& is_even(bool _is_even);
    //		gen_number& parity(int par);

    gen_number& prime(bool __prime);
    gen_number& prepare();
};
};  // namespace MochaGen

int& operator<<(int& i, MochaGen::gen_number& a);
std::ostream& operator<<(std::ostream& o, MochaGen::gen_number& a);

#endif
