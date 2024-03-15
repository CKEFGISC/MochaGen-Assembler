#ifndef GEN_STRING_HPP
#define GEN_STRING_HPP
#include <iostream>
#include <string>

namespace MochaGen {
class gen_string {
   public:
    std::string s;
    int len = 0;
    bool is_palindrome = false;
    std::string endswith = "\n";
    bool has_pattern = 0;
    std::string pattern_str = "";
    gen_string(int _len) : len(_len) {}

    gen_string& palindrome(bool is_palindrome);
    gen_string& end(std::string _endswith);

    gen_string& pattern(std::string _pattern);
    gen_string& prepare();
};
};  // namespace MochaGen
std::ostream& operator<<(std::ostream& o, MochaGen::gen_string& mocha_string);

#endif
