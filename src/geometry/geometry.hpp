#ifndef GEN_GEOMETRY_HPP
#define GEN_GEOMETRY_HPP
#include<iostream>
#include<string>

namespace MochaGen{
	class gen_geometry{

        int point_count=0;

		gen_geometry(int _point_count): point_count(_point_count){}

		gen_geometry& weight(int l, int r);
		gen_geometry& acyclic();
		gen_geometry& directed();
		gen_geometry& connected();
		gen_geometry& bipartite();
		gen_geometry& allow_loops();
        gen_geometry& allow_multi();
        gen_geometry& prepare();
	};
}
	std::ostream& operator << (std::ostream& o, MochaGen::gen_geometry& g);

#endif
