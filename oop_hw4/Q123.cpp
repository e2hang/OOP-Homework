#include <iostream>
using std::string;
using std::cout;
using std::cin;

class thief{
	private: 
		string name;
		double money;
		bool caught; 
	public:
		thief(){
			name = "";
			money = -1;
			caught = false;
		} 
		thief(string n,double m,bool c){
			name = n;
			money = m;
			caught = c;
		}
		thief& steal(walker x){
			money = x.money_print();
			x.zero();
			return this;
		}
}; 

class walker{
	private:
		string name;
		double money;
		bool stolen;
	public:
		walker(){
			name = "";
			money = -1;
			stolen = false;
		} 
		walker(string n,double m,bool c){
			name = n;
			money = m;
			stolen = c;
		}
		double money_print(){
			return money;
		}
		walker& zero(){
			money = 0;
			stolen = true;
			return this;
		}
};

class police{
	
}; 
