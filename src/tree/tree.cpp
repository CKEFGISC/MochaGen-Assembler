#include<iostream>
#include<string>
#include"jngen.h"
#include"tree.hpp"
#include"../src/number/number.hpp"

using std::ostream, std::endl, std::cout;
namespace MochaGen{
    gen_tree& gen_tree::weighted(int type){
        weighted_type=type;
        return *this;
    }
	gen_tree& gen_tree::edge_weight(int l, int r){
		edge_weights.first=l;
		edge_weights.second=r;
		return *this;
	};
    gen_tree& gen_tree::vertex_weight(int l, int r){
		vertex_weights.first=l;
		vertex_weights.second=r;
		return *this;
	};
    gen_tree& gen_tree::binary(){
        is_binary = true;
        return *this;

    };
    gen_tree& gen_tree::prepare(){
        if(weighted_type>0){
            t=Tree::random(vertex_count);
            if(weighted_type==1||weighted_type==3){
                std::vector<int> edge_weight_array(edge_count);
                for(int i=0; i<edge_count; i++){
                    int tmp;
                    tmp << gen_number("integer").range(edge_weights.first, edge_weights.second);
                    edge_weight_array[i]=tmp;
                }
                t.setEdgeWeights(edge_weight_array);
            }
            if(weighted_type==2||weighted_type==3){
                std::vector<int> vertex_weight_array(vertex_count);
                for(int i=0; i<vertex_count; i++){
                    int tmp;
                    tmp << gen_number("integer").range(vertex_weights.first, vertex_weights.second);
                    vertex_weight_array[i]=tmp;
                }
                t.setVertexWeights(vertex_weight_array);
            }
		}else{
            t=Tree::random(vertex_count);
		}
    }
}
ostream& operator << (ostream& o, MochaGen::gen_tree& t){
	//if(a._class=="float") o<<a.valf<<std::endl;
	//else o << a.val << std::endl;
    o<<t<<endl;
	return o;
}
