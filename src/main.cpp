#include <bits/stdc++.h>
#include "../include/jngen.h"
#include "../include/json.hpp"
using namespace std;
using json = nlohmann::json;
struct object{
	string _id, _class, _category;
	map<string, vector<string>> attr;
};
std::ifstream f("../test/number.json");
json num = json::parse(f);
signed main(){
	vector<object> obj;
	for (json::iterator it = num.begin(); it != num.end(); ++it) {
		object tmp;
		tmp._category = it.key();
		tmp._class = it.value()["class"];
		tmp._id = it.value()["id"];
		for(json::iterator itt = it.value()["attr"].begin(); itt!=it.value()["attr"].end(); ++itt){
			tmp.attr[itt.key()]=itt.value();
		}
		obj.push_back(tmp);
	}
	for(auto x:obj){
		cout<<"object"<<x._id<<'\n';
		cout<<x._category<<' '<<x._class<<'\n';
		for(auto z:x.attr){
			cout<<z.first<<' ';
			for(auto c:z.second) cout<<c<<' ';
		}cout<<'\n';
	}
}

