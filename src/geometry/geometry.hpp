#ifndef GEN_GEOMETRY_HPP
#define GEN_GEOMETRY_HPP
#include <iostream>
#include <string>

#include "../jngen/jngen.hpp"

namespace MochaGen {
struct gen_geometry {
    TArray<Point> T;
    int point_count = 0;
    bool is_convex_polygon = 0;
    bool in_general_position = 0;
    int xmin = 0, xmax = 1e4;
    int ymin = 0, ymax = 1e4;
    bool prepared = 0;
    gen_geometry(int _point_count) : point_count(_point_count) {}
    gen_geometry& xrange(int _xmin, int _xmax);
    gen_geometry& yrange(int _ymin, int _ymax);
    gen_geometry& convex_polygon(bool _convex_polygon );
    gen_geometry& general_position(bool _general_position );
    gen_geometry& prepare();
};
}  // namespace MochaGen
std::ostream& operator<<(std::ostream& o, MochaGen::gen_geometry& g);

#endif
