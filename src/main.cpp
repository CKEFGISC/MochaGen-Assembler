#include <bits/stdc++.h>
#include "../include/jngen.h"
#include "../include/json.hpp"
using namespace std;
using json = nlohmann::json;


struct object{
	string _id, _class, _category;
	map<string, vector<string>> attr;
	//category: number/array
	//class: integer/float
};

vector<object> obj;

std::ifstream f("../test/number.json");
json num = json::parse(f);
//open file and parse

void ParseJson(){
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

}

void ParseTest(){
	for(auto x:obj){
		cout<<"object"<<x._id<<'\n';
		cout<<x._category<<' '<<x._class<<'\n';
		for(auto z:x.attr){
			cout<<z.first<<' ';
			for(auto c:z.second) cout<<c<<' ';
		}cout<<'\n';
	}
}

void InitializeOutput(){
	cout<<"#include<bits/stdc++.h>\n";
	cout<<"#include<jngen.h>\n";
	cout<<"using namespace std;\n";
}

signed main(){
	ParseJson();
	int cnt=1;
	for(auto x:obj){
		if(x._category=="number"){
			if(x._class=="integer"){
				int l=stoi(x.attr["range"][0]);
				int r=stoi(x.attr["range"][1]);
				if(x.attr["is_prime"][0]=="1"){
					if(x.attr["is_odd"][0]=="1"){
						cout<<"int obj"<< cnt<<"= rndm.randomPrime("<<l<<","<< r<<");\n";
						cout<<"cout<<obj"<<cnt<<";\n";
					}else{
						cout<<"int obj"<<cnt<<"=2;\n";
						cout<<"cout<<obj"<<cnt<<";\n";
					}
				}else{
					cout<<"int obj"<<cnt<<"=rnd.next("<<l<<","<<r<<");\n";
					if(x.attr["is_odd"][0]=="1"){
						cout<<"if(obj"<<cnt<<"%2==0) obj"<<cnt<<"+=1;\n";
					}else if(x.attr["is_odd"][0]=="0"){
						cout<<"if(obj"<<cnt<<"%2==1) obj"<<cnt<<"+=1;\n";
					}
					cout<<"cout<<obj"<<cnt<<";\n";
				}
			}
		}
	}
	cout<<"}";
}

