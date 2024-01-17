#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "../file_reader.h"

using namespace std;

class Symbol {
	//Symbol
	public:
		char sym;
	//	static Symbol Empty;
		Symbol(char c) {
			sym =c;
		}
	
};
class Number {
	public:
		int num{0};
};
class C { 
	public:
		int r,c;
		Number* n;
		const Symbol& s=Symbol('.');
		C(int r, int c) : r{r}, c{c} {};  
		C(int r, int c, Number* nc) : r{r}, c{c}, n{nc} {};  
		C(int r, int c, Symbol sc) :r{r}, c{c} { };  
		friend ostream& operator<<(ostream& s, C c);
};

ostream& operator<<(ostream& s, C c){
	s << "["<<(c.n)->num <<" | " << c.s.sym << "]" 
		<< "("<<c.r <<"," << c.c << ")" << endl; 
	return s;
}
class Grid{
	public:
		vector<vector<C>> grid;
		vector<string> rawGrid;
		Grid(vector<string>&& a) : rawGrid{std::move(a)}  {};
		
		void printRaw(){
			int rw = 0;
			for(auto a:rawGrid) {
				//cout << a << endl;
				grid.push_back(gridify(a, rw++));
			}
			cout << "Got to here" << endl;
			for(auto a:grid) {
			for(auto b: a ) {
				cout << b << endl;
			}
				
			}
		}
		vector<C> gridify(string line, int row){
			Number* cn;
			string cns;
			int col=0;
			vector<C> res;
			for(auto c : line){
				//digit
				if(isdigit(c))
				{
					if(cns.empty()) {
						cn =new Number;
					}
					cns.push_back(c);
					res.push_back(C(row, col++, cn));

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
					res.push_back(C(row, col++));
					// reset digit
				}
				else 
				{ 
					if(!cns.empty()){
						cn->num=stoi(cns);
						cns.clear();
						cn = nullptr;
					}
					res.push_back(C(row, col++, Symbol(c)));
				}
			}
			return res;

		}

};

int main(){
//vector<string> input =  file_reader("input.txt");
Grid g(file_reader("input.txt"));
g.printRaw();



}

