#ifndef GEN_ARRAY_HPP
#define GEN_ARRAY_HPP

#include <iostream>
#include <string>
#include <vector>

using std::ostream, std::endl, std::cout;

namespace MochaGen {

template <typename T>
struct gen_array {
    int length = 0;
    bool prepared = 0;
    T content;
    std::vector<T> content_value;
    bool is_unique = 0;
    bool is_sorted = 0;
    std::string endswith = "\n";

    gen_array(int _length, T _content) : length(_length), content(_content), content_value(_length, _content) {}

    gen_array<T>& end(std::string _endswith);
    gen_array<T>& prepare();
};  // struct gen_array

};  // namespace MochaGen

template <typename T>
ostream& operator<<(ostream& o, MochaGen::gen_array<T>& a);

#endif
