#include "array.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../geometry/geometry.hpp"
#include "../graph/graph.hpp"
#include "../jngen/jngen.hpp"
#include "../number/number.hpp"
#include "../string/string.hpp"
#include "../tree/tree.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen {

template <typename T>
gen_array<T>& gen_array<T>::end(std::string _endswith) {
    endswith = _endswith;
    return *this;
}

template <typename T>
gen_array<T>& gen_array<T>::prepare() {
    prepared = 1;
    for (int i = 0; i < length; i++) {
        content_value[i].prepare();
    }
    return *this;
}

template <typename T>
ostream& operator<<(ostream& o, MochaGen::gen_array<T>& a) {
    if (!a.prepared) a.prepare();
    for (int i = 0; i < a.length; i++) {
        // a.content.prepare();
        o << a.content_value[i];
    }
    cout << a.endswith;
    return o;
}
/*
template<typename T>
gen_array<T>::gen_array(int _length, T _content): length(_length), content(_content), content_value(_length){}
template<typename T>
gen_array<T>& gen_array<T>::prepare(){
    for(int i=0; i<length; i++){
        content_value[i]=content;
        content_value[i].prepare();
    }
}*/

}  // namespace MochaGen
/*
template<typename T>
ostream& operator << (ostream& o, MochaGen::gen_array<T>& a){
    a.prepare();
    for(int i=0; i<a.length; i++){
        //a.content.prepare();
        o << a.content_value[i].len << std::endl;
    }
        return o;
}*/
