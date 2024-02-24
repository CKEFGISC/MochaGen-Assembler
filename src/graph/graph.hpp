#ifndef GEN_GRAPH_HPP
#define GEN_GRAPH_HPP
#include<iostream>
#include<string>
#include"../jngen/jngen.hpp"
//#include<jngen>
namespace MochaGen{
	struct gen_graph{
        Graph g;
        int edge_count = 0;
        int vertex_count = 0;
        bool vertex_weighted = 0;
        bool edge_weighted = 0;
        int weighted_type=0;
        std::pair<int, int> vertex_weights = {0, 1e9+7};
        std::pair<int, int> edge_weights = {0, 1e9+7};
        bool prepared=0;
        int n1=0, n2=0;
        bool is_acyclic = 0;
        bool is_directed = 0;
        bool is_connected = 0;
        bool is_bipartite = 0;
        bool loops_allowed = 0;
        bool multi_allowed = 0;
        bool is_one_base=0;


		gen_graph(int _vertex_count, int _edge_count);
        gen_graph& weighted(int type);
		gen_graph& edge_weight(int l, int r);
        gen_graph& vertex_weight(int l, int r);
		gen_graph& acyclic();
		gen_graph& directed();
		gen_graph& connected();
		gen_graph& bipartite(int _n1, int _n2);
		gen_graph& allow_loops();
        gen_graph& allow_multi();
        gen_graph& prepare();
        gen_graph& one_base();
	};
}
std::ostream& operator << (std::ostream& o, MochaGen::gen_graph& graph);

#endif
