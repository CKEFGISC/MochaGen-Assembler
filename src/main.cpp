// This is the sample main file of the project.
// It is used to create a sample executable to test the library.
// You can use this file as a reference to create your own main file.

#include <iostream>
#include <string>

#include "assembler.h"
#include "jngen/jngen.hpp"

using namespace MochaGen;
using std::cout, std::endl;

signed main() {
    gen_graph my_graph = gen_graph(3, 2).bipartite(2, 1).weighted(3).edge_weight(1, 10).vertex_weight(1, 10);
    cout << my_graph << endl;

    gen_geometry my_geometry = gen_geometry(5).xrange(1, 10).yrange(1, 10);  //.general_position();
    cout << my_geometry << endl;
    return 0;
}