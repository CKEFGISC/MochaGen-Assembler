#ifndef GEN_ARRAY_HPP
#define GEN_ARRAY_HPP

#include<iostream>
#include<string>
#include<vector>
#include"../jngen/jngen.hpp"
#include"array.hpp"
#include"../number/number.hpp"
#include"../graph/graph.hpp"
#include"../string/string.hpp"
#include"../tree/tree.hpp"
#include"../geometry/geometry.hpp"
using std::ostream, std::endl, std::cout;

namespace MochaGen{
    template<typename T>
	struct gen_array{
		int length=0;
        bool prepared=0;
        T content;
        std::vector<T> content_value;
        bool is_unique=0;
        bool is_sorted=0;
        std::string endswith="\n";

        /*
        gen_array(int _length, T _content);
		gen_array& prepare();
        */
        gen_array(int _length, T _content): length(_length), content(_content), content_value(_length, _content){
            //content_value.reserve(_length);
            //for(int i=0; i<length; i++) content_value.push_back(content);
        }

        gen_array<T>& end(std::string _endswith){
            endswith=_endswith;
            return *this;
        }
        gen_array<T>& prepare(){
            prepared=1;
            for(int i=0; i<length; i++){
                content_value[i].prepare();
            }
            return *this;
        }
	};
};
/*
template<typename T>
std::ostream& operator << (std::ostream& o, MochaGen::gen_array<T>& a);
*/
template<typename T>
ostream& operator << (ostream& o, MochaGen::gen_array<T>& a){
    if(!a.prepared)a.prepare();
    for(int i=0; i<a.length; i++){
        //a.content.prepare();
        o << a.content_value[i];
    }
    cout<<a.endswith;
	return o;
}
#endif
