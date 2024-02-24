#include<iostream>
#include<string>
#include<vector>
#include"jngen.h"
#include"array.hpp"
#include"../number/number.hpp"
#include"../graph/graph.hpp"
#include"../string/string.hpp"
#include"../tree/tree.hpp"
#include"../geometry/geometry.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen{
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

}
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
