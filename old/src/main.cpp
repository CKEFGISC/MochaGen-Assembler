#include <bits/stdc++.h>
#include "../include/jngen.h"
#include "../include/json.hpp"
using namespace std;
using json = nlohmann::json;



struct object{
	string _id, _class, _category;
	map<string, json> attr;
	//category: number/array
	//class: integer/float
};

vector<object> obj;

void ParseJson(json num){
	for (json::iterator it = num.begin(); it != num.end(); ++it) {
		object tmp;
		tmp._category = it.value()["category"];
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

void ProcessNumber(object x){
	if(x._class=="integer"){
		string l=x.attr["range"]["left"], r=x.attr["range"]["right"];
		if(x.attr["prime"]["is_prime"]=="1"){
			if(x.attr["parity"]["is_odd"]=="1"){
				cout<<"int obj"<< x._id<<"= rndm.randomPrime("<<l<<","<< r<<");\n";
				cout<<"cout<<obj"<<x._id<<";\n";
			}else{
				cout<<"int obj"<<x._id<<"=2;\n";
				cout<<"cout<<obj"<<x._id<<";\n";
			}
		}else{
			cout<<"int obj"<<x._id<<"=rnd.next("<<l<<","<<r<<");\n";
			if(x.attr["parity"]["is_odd"]=="1"){
				cout<<"if(obj"<<x._id<<"%2==0) obj"<<x._id<<"+=1;\n";
			}else if(x.attr["parity"]["is_odd"]=="0"){
				cout<<"if(obj"<<x._id<<"%2==1) obj"<<x._id<<"+=1;\n";
			}
			cout<<"cout<<obj"<<x._id<<";\n";
		}
	}else if(x._class=="float"){
		cout<<"double obj"<<x._id<<"=rnd.nextf()*("<<x.attr["range"]["right"]<<"-"<<x.attr["range"]["left"]<<")+"<<x.attr["range"]["left"]<<";\n";
		cout<<"cout<<obj"<<x._id<<";\n";
	}
}



signed main(){
	std::ifstream f("../test/number.json");
	json num = json::parse(f);
	//open file and parse
	ParseJson(num);
	
	for(auto x:obj){
		if(x._category=="number"){
			ProcessNumber(x);
		}
		cout<<"cout<<\'\\n\';";
	}
	cout<<"}";
}

