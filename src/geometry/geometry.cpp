#include<iostream>
#include<string>
#include"jngen.h"
#include"geometry.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen{
}
ostream& operator << (ostream& o, MochaGen::gen_geometry& g){
	//if(a._class=="float") o<<a.valf<<std::endl;
	//else o << a.val << std::endl;
    o<<g<<endl;
	return o;
}
