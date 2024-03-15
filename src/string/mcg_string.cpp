#include <iostream>
#include <string>

#include "../jngen/jngen.hpp"
#include "mcg_string.hpp"

using std::ostream, std::endl, std::cout;

namespace MochaGen {

gen_string& gen_string::palindrome(bool _is_palindrome = false) {
    is_palindrome = _is_palindrome;
    return *this;
}

gen_string& gen_string::set_pattern(std::string _pattern) {
    if (_pattern.size() == 0) {
        has_pattern = false;
        return *this;
    }
    has_pattern = true;
    pattern = _pattern;
    return *this;
}
gen_string& gen_string::end(std::string _endswith) {
    endswith = _endswith;
    return *this;
}
gen_string& gen_string::prepare() {
    if (is_palindrome) {
        std::string half_string;
        int half_len = (len + 1) / 2;
        if (has_pattern) {
            half_string = rnds.random(half_len, pattern);
        } else {
            half_string = rnds.random(half_len);
        }
        s = half_string;
        if (len % 2) s.erase(s.end() - 1);
        reverse(half_string.begin(), half_string.end());
        s += half_string;
        return *this;
    } else {
        if (has_pattern) {
            s = rnds.random(len, pattern);
        } else {
            s = rnds.random(len);
        }
    }
    return *this;
}
};  // namespace MochaGen
ostream& operator<<(ostream& o, MochaGen::gen_string& mocha_string) {
    mocha_string.prepare();
    o << mocha_string.s << mocha_string.endswith;
    return o;
}
