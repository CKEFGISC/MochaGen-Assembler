#include<iostream>
#include<string>
#include"../jngen/jngen.hpp"

#include"graph.hpp"
#include"../number/number.hpp"
#include<vector>
using std::ostream, std::endl, std::cout;
namespace MochaGen{
    gen_graph::gen_graph(int _vertex_count, int _edge_count): edge_count(_edge_count), vertex_count(_vertex_count){}

    gen_graph& gen_graph::weighted(int type){
        weighted_type=type;
        return *this;
    }
	gen_graph& gen_graph::edge_weight(int l, int r){
		edge_weights.first=l;
		edge_weights.second=r;
		return *this;
	};
    gen_graph& gen_graph::vertex_weight(int l, int r){
		vertex_weights.first=l;
		vertex_weights.second=r;
		return *this;
	};
	gen_graph& gen_graph::acyclic(){
		is_acyclic = true;
		return *this;
	};
	gen_graph& gen_graph::directed(){
		is_directed = true;
		return *this;

	};
	gen_graph& gen_graph::connected(){
		is_connected = true;
		return *this;

	};
	gen_graph& gen_graph::bipartite(int _n1, int _n2){
		if(_n1+_n2!=vertex_count){
			cout<<"invalid vertex sum, ignoring bipartite";
			return *this;
		}
		is_bipartite=true;
		n1=_n1;
		n2=_n2;
		return *this;

	};
	gen_graph& gen_graph::allow_loops(){
		loops_allowed = true;
		return *this;

	};
	gen_graph& gen_graph::allow_multi(){
		multi_allowed = true;
		return *this;

	};
    gen_graph& gen_graph::one_base(){
        is_one_base=true;
        return *this;
    }
	gen_graph& gen_graph::prepare(){
        if(is_bipartite){
			if(is_acyclic||is_directed||loops_allowed){
				cout<<"unavailable modifier for bipartite graph, ignoring bipartite";
			}else{
				g=Graph::randomBipartite(n1, n2, edge_count).connected(is_connected).allowMulti(multi_allowed);
            	if(weighted_type==1||weighted_type==3){
					std::vector<int> edge_weight_array(edge_count, 1);
					for(int i=0; i<edge_count; i++){
						int tmp=1;
						tmp << gen_number("integer").range(edge_weights.first, edge_weights.second);
						edge_weight_array[i]=tmp;
					}
					g.setEdgeWeights(edge_weight_array);
				}
				if(weighted_type==2||weighted_type==3){
					std::vector<int> vertex_weight_array(vertex_count);
					for(int i=0; i<vertex_count; i++){
						int tmp=0;
						tmp << gen_number("integer").range(vertex_weights.first, vertex_weights.second);
						vertex_weight_array[i]=tmp;
					}
					g.setVertexWeights(vertex_weight_array);
            	}
				return *this;
			}
        }
		if(weighted_type>0){
            g=Graph::random(vertex_count, edge_count).directed(is_directed).acyclic(is_acyclic).connected(is_connected).allowLoops(loops_allowed).allowMulti(multi_allowed);
            if(weighted_type==1||weighted_type==3){
                std::vector<int> edge_weight_array(edge_count, 1);
                for(int i=0; i<edge_count; i++){
                    int tmp=1;
                    tmp << gen_number("integer").range(edge_weights.first, edge_weights.second);
                    edge_weight_array[i]=tmp;
                }
                g.setEdgeWeights(edge_weight_array);
            }
            if(weighted_type==2||weighted_type==3){
                std::vector<int> vertex_weight_array(vertex_count);
                for(int i=0; i<vertex_count; i++){
                    int tmp=0;
                    tmp << gen_number("integer").range(vertex_weights.first, vertex_weights.second);
                    vertex_weight_array[i]=tmp;
                }
                g.setVertexWeights(vertex_weight_array);
            }
		}else{
            g=Graph::random(vertex_count, edge_count).directed(is_directed).acyclic(is_acyclic).connected(is_connected).allowLoops(loops_allowed).allowMulti(multi_allowed);
		}
        prepared=true;
		return *this;
	}
}
ostream& operator << (ostream& o, MochaGen::gen_graph& graph){
    if(!graph.prepared)graph.prepare();
	o<<graph.g<<endl;
	return o;
}
