#include<iostream>
#include<string>
#include"../jngen/jngen.hpp"
#include"geometry.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen{
    gen_geometry& gen_geometry::xrange(int _xmin, int _xmax){
        xmin=_xmin;xmax=_xmax;
        return *this;
    }
    gen_geometry& gen_geometry::yrange(int _ymin, int _ymax){
        ymin=_ymin;ymax=_ymax;
        return *this;
    }
    gen_geometry& gen_geometry::convex_polygon(){
        is_convex_polygon=true;
        return *this;
    }
    gen_geometry& gen_geometry::general_position(){
        in_general_position=true;
        return *this;
    }

    gen_geometry& gen_geometry::prepare(){
        prepared=true;
        if(in_general_position){
            T.resize(point_count);
            auto DT=rndg.pointsInGeneralPosition(point_count, xmin, ymin, xmax, ymax);
            for(int i=0; i<point_count; i++){
                T[i]=DT[i];
            }
        }else if(is_convex_polygon){
            T.resize(point_count);
            auto DT=rndg.convexPolygon(point_count,  xmin, ymin, xmax, ymax);
            for(int i=0; i<point_count; i++){
                T[i]=DT[i];
            }
        }else{
            T.resize(point_count);
            for(int i=0; i<point_count; i++){
                T[i]=rndg.point(  xmin, ymin, xmax, ymax);
            }
        }
        return *this;
    }


}
ostream& operator << (ostream& o, MochaGen::gen_geometry& g){
	//if(a._class=="float") o<<a.valf<<std::endl;
	//else o << a.val << std::endl;
    if(!g.prepared) g.prepare();
    o<<g.T<<endl;
	return o;
}
