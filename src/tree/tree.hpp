#ifndef GEN_TREE_HPP
#define GEN_TREE_HPP
#include <iostream>
#include <string>

#include "../jngen/jngen.hpp"
namespace MochaGen {
class gen_tree {
    Tree t;
    int vertex_count = 0;
    int weighted_type = 0;
    int edge_count = 0;
    bool is_binary = 0;
    std::pair<int, int> vertex_weights = {0, 1e9 + 7};
    std::pair<int, int> edge_weights = {0, 1e9 + 7};
    std::pair<int, int> weights = {0, 1e9 + 7};

    gen_tree(int _vertex_count) : vertex_count(_vertex_count) {}
    gen_tree& weighted(int type);
    gen_tree& edge_weight(int l, int r);
    gen_tree& vertex_weight(int l, int r);
    gen_tree& binary(bool _binary = true);
    gen_tree& prepare();
};
}  // namespace MochaGen
std::ostream& operator<<(std::ostream& o, MochaGen::gen_tree& g);

#endif
