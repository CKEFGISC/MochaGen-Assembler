#include<iostream>
#include<string>
#include"../jngen/jngen.hpp"
//#include<jngen>

#include"number.hpp"
using std::ostream, std::endl, std::cout;
namespace MochaGen{
	
		gen_number& gen_number::range(int l, int r){
			if(_class=="float") cout<<"ERROR USE .range() INSTEAD";
			else _range.first=l, _range.second=r;
			return *this;
		}

		gen_number& gen_number::rangef(int l, int r){
			if(_class=="float") _rangef.first=l, _rangef.second=r;
			else cout<<"ERROR USE .range() INSTEAD";
			return *this;
		}

		gen_number& gen_number::is_odd(){
      _parity+=2;
    }
		gen_number& gen_number::is_even(){
      _parity+=1;
    }
		gen_number&  gen_number::prime(int __prime){
			if(_class=="float") cout<<"ERROR, NO PRIME FOR FLOAT\n";
			else _prime=__prime;
			return *this;
		}

	    gen_number& gen_number::end(std::string _endswith){
    	    endswith=_endswith;
			return *this;
	    }

		gen_number&  gen_number::prepare(){
            if(prepared) return *this;
			if(_class=="float"){
				valf=rnd.nextf()*(_rangef.second-_rangef.first)+_rangef.first;
			}else{
        if(_parity==2) _parity=-1;
				if(_prime==1){
					if(_parity==1||_parity==0){
						val=rndm.randomPrime(fmax(2, _range.first), _range.second);
					}else{
						if(2>=_range.first&&2<=_range.second){
							val=2;
						}else{
							cout<<"ERROR, NO PRIME THAT SATISFIES THE CONDITION\n";
						}
					}
				}else if(_prime==0){
					if(_parity==0){
						if(_range.first==2&&_range.second==2){
							cout<<"ERROR, NO SATISFYING NUMBER\n";
							return *this;
						}else{
							if((_range.first==_range.second)&&(_range.first%2==1)) {
								cout<<"ERROR, NO SATISFYING NUMBER\n";
								return *this;
							}
							val=rnd.next(_range.first, _range.second);
							if(val%2==1) val++;
							if(val>_range.second) val-=2;
						}
					}else if(_parity==1){
							do{
								val=rnd.next(_range.first, _range.second);
							}while(!(isPrime(val)&&(val%2!=0)));
					}else if(_parity==-1){
						do{
							val=rnd.next(_range.first, _range.second);
						}while(!(isPrime(val)));
					}	
				}else if(_prime==-1){
					if(_parity==1){
						if((_range.first==_range.second)&&(_range.first%2==0)){
							cout<<"ERROR, NO SATISFYING NUMBER\n";
							return *this;
						}
						val=rnd.next(_range.first, _range.second);
						if(val%2==0) val++;
						if(val>_range.second) val-=2;
					}else if(_parity==0){
						if((_range.first==_range.second)&&(_range.first%2==1)) {
							std::cout<<"ERROR, NO SATISFYING NUMBER\n";
							return *this;
						}
						val=rnd.next(_range.first, _range.second);
						if(val%2==1) val++;
						if(val>_range.second) val-=2;
					}else if(_parity==-1){
						val=rnd.next(_range.first, _range.second);
					}
				}
			}
			return *this;
		}
}

int& operator << (int& i, MochaGen::gen_number& a){
    if(!a.prepared) a.prepare();
    
    if(a._class=="float") cout<<"Assigned float to int";
    else i = a.val;
    
	return i;
}
ostream& operator << (ostream& o, MochaGen::gen_number& a){
    if(!a.prepared) a.prepare();
	if(a._class=="float") o<<a.valf<<a.endswith;
	else o << a.val << a.endswith;
	return o;
}
