#pragma once
#include "Number.h"

class C { 
	public:
		int r,c;
		Number* n{nullptr};//{nullptr};
		const Symbol& s;//=Symbol('.');
		C(int _r, int _c) : r{_r}, c{_c}, s{*(new Symbol('.'))} {
			this_id=to_string(_r)+ " " + to_string(_c);
			if(is_debug) cout << "Created " << this_id << endl;

		};  
		C(int _r, int _c, Number* _nc) : r{_r}, c{_c}, n{_nc} , s{*(new Symbol('.'))}
		{
			this_id=to_string(_r)+ " " + to_string(_c) + " " + to_string(n->num) + " " + s.sym +  " [N]";
			n->cells.push_back(this);
			if(is_debug) cout << "Created " << this_id << endl;
		};  
		C(int _r, int _c, const Symbol& sc) :r{_r}, c{_c}, s{sc} { 

			this_id=to_string(_r)+ " " + to_string(_c) + " " + sc.sym + " [S]";
			if(is_debug) {
			cout << "Symbol copy sc@ " << &sc << endl;
			cout << "Symbol copy s@ " << &s << endl;
			cout << "Created " << this_id << endl;
			}
		};  
#if C_cc == MY
		C(const C& other): s{*(new Symbol(other.s.sym))} {
			this->r = other.r;
			this->c = other.c;
			this->n = other.n;
			this->this_id= other.this_id;
			if(is_debug) cout << "Copying " << other.this_id << endl;


		}
#elif C_cc == DEFAULT
C(const C& other)  = default;
#elif C_cc == DELETE
C(const C& other)  = delete;
#elif C_cc == MYOTHER
C(const C& other) { cout << "copy My other" << endl; }
#endif  
		//C(C&& other)
		friend ostream& operator<<(ostream& s, const C& c);
		~C() {

		if(is_debug) cout << "Destroyed " << this_id << " " << ((n) ? to_string(n->num) : "" )<<  endl;
		}
	private: 
		string this_id;

};
ostream& operator<<(ostream& s, const C& c){
	auto n = (c.n) ?  (c.n)->num  : -1;
	s << "["<< n <<" | " ;
	s.put(c.s.sym); s <<" ]"; // << '-' << (c.s.sym) << '-'<< "]" 
	s << "("<<to_string(c.r) <<"," << to_string(c.c) << ")" << endl; 
	return s;
}
