#pragma once
//#include "C.h"
class C;
class Number {
	public:
		int num{0};
		vector<C*> cells;
		friend ostream& operator<<(ostream& s, const Number& n);
		bool operator==(const Number& rhs){ //, const Number& rhs){
			bool result = num == rhs.num;
			return result;
			//for(auto c : cells) {
			//	result = result && (lhs.c->r == rhs.c->r) && (lhs.c->c == rhs.c->c) ;
			//}
			//return result;

		}
};
#include "C.h"

ostream& operator<<(ostream& s, const Number& n){
	//auto n = (c.n) ?  (c.n)->num  : -1;
	s << "["<< to_string(n.num) <<" @ " ;
	for(auto c : n.cells) {
		s << *c;
	}
	return s;
}
