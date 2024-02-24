#include<iostream>
#include<string>
#include"number/number.hpp"
#include"graph/graph.hpp"
#include"array/array.hpp"
#include"string/string.hpp"
#include"tree/tree.hpp"
#include"geometry/geometry.hpp"

using namespace MochaGen;
int main(){
    gen_graph g=gen_graph(3, 2).bipartite(2, 1).weighted(3).edge_weight(1, 10).vertex_weight(1,  10);
    cout<<g;
	return 0;
}