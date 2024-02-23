#ifndef GEN_STRING_HPP
#define GEN_STRING_HPP
#include<iostream>
#include<string>

namespace MochaGen{
	struct gen_string{
        std::string s;
        int len=0;
        bool is_palindrome=false;
        bool has_pattern=0;
        std::string pattern="";
		gen_string(int _len): len(_len){}

		gen_string& palindrome();
        gen_string& set_pattern(std::string _pattern);
        gen_string& prepare();

	};
};
std::ostream& operator << (std::ostream& o, MochaGen::gen_string& mocha_string);

#endif
