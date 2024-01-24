#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "../file_reader.h"

using namespace std;
// 'my' 'default'
#define MY 0
#define MYOTHER 1
#define DEFAULT 2
#define DELETE 3
#define C_cc  MY

# define EMPTY(...)
# define DEFER(...) __VA_ARGS__ EMPTY()
# define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()
# define EXPAND(...) __VA_ARGS__

//#define _EXPCB(A, ...)  << " " << #A << A  _EXPC(__VA_ARGS__)
//#define _EXPC(A, ...)  << " " << #A << A  _EXPCB(__VA_ARGS__)
//#define DLOG(msg, ...) cout << msg _EXPC(__VA_ARGS__) << endl; 

//#define _EXPC(A, ...)  << " " << #A << A  _EXPCB(__VA_ARGS__)
//#define DLOG_id() DLOG 
//#define DLOG(msg, ...) cout << msg DEFER(DLOG_id)()(__VA_ARGS__) << endl; 
bool is_debug = false;
class C;
class Symbol {
	//Symbol
	public:
		char sym{'.'};
	//	static Symbol Empty;
		Symbol(char c): sym{c}{
		//	DLOG("[Created] Symbol ", c, this)
			sym=c;
		}
	
};
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
class C { 
	public:
		int r,c;
		Number* n{nullptr};
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

ostream& operator<<(ostream& s, const Number& n){
	//auto n = (c.n) ?  (c.n)->num  : -1;
	s << "["<< to_string(n.num) <<" @ " ;
	for(auto c : n.cells) {
		s << *c;
	}
	return s;
}
ostream& operator<<(ostream& s, const C& c){
	auto n = (c.n) ?  (c.n)->num  : -1;
	s << "["<< n <<" | " ;
	s.put(c.s.sym); s <<" ]"; // << '-' << (c.s.sym) << '-'<< "]" 
	s << "("<<to_string(c.r) <<"," << to_string(c.c) << ")" << endl; 
	return s;
}
class Grid{
	public:
		vector<vector<C>> grid{};
		vector<string> raw_grid;
		Grid(vector<string>&& a) : raw_grid{std::move(a)}  {};
		
		void Gridify(){
			int rw = 0;
			for(auto a:raw_grid) {
				auto& gy = GridifyRow(a, rw++);
				grid.push_back(gy);
			}

			cout << "Got to here" << endl;
			for(auto a: grid) {
				for(auto b: a) {
					// cout << b << endl;
				}
			}
		}

		vector<C>& GridifyRow(string line, int row){
			Number* cn{nullptr};
			string cns;
			int col=0;
			vector<C> &res = *(new vector<C>{});
			res.reserve(150); 
			for(auto c : line) {
				//digit
				//cout << "Line char: " << c <<endl;
				if(isdigit(c))
				{
					if(cns.empty()) {
						cn =new Number;
					}
					cns.push_back(c);
					auto lc = new C(row, col++, cn);
					res.push_back(*lc);

				}
				//dot
				else if (c == '.')
				{
					if(!cns.empty()){
						cn->num=stoi(cns);
						cout << "CNS clear " << cns << " | "
							<< "cn->num" << cn->num << endl;
						cns.clear();
						cn = nullptr;
					}
					res.push_back(*(new C(row, col++)));
					// reset digit
				}
				else 
				{ 
					if(!cns.empty()){
						cn->num=stoi(cns);
						cns.clear();
						cn = nullptr;
					}

					//auto tv = C(row, col++,   );
					//cout << "From tv on  148 " << tv << endl;
					res.push_back(*(new C(row, col++,  *(new Symbol(c))  )));
				}
			}
			return res;

		}

};

int main(){
//vector<string> input =  file_reader("input.txt");
Grid g(file_reader("input.txt"));
g.Gridify();
cout << *g.grid[9][16].n << endl;
//Symbol s1('v');
//cout << s1.sym << "@ " << &s1 << endl;;
//C a(2,3, std::move(s1));
//cout << a << endl;


}

