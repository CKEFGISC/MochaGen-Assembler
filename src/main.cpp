#include<iostream>
#include<string>
#include"number/number.hpp"
#include"graph/graph.hpp"
#include"array/array.hpp"
#include"string/string.hpp"
#include"tree/tree.hpp"
#include"geometry/geometry.hpp"
//#include"jngen.h"
//#include"string/string.hpp"
//#include"tree/tree.hpp"

using namespace MochaGen;
int main(){
	//gen_graph a=gen_graph(3,3);
	//std::cout<<a;
    gen_graph g=gen_graph(5, 3).weighted(3).edge_weight(1, 10).vertex_weight(1,  10);
    gen_number a=gen_number("integer");
    //g.prepare();
    std::cout<<g;
    std::cout<<a;
	return 0;
}