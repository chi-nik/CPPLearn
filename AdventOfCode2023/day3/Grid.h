#pragma once
#include "C.h"
#include "Symbol.h"

class Grid{
	public:
		vector<vector<C>> grid{};
		vector<string> raw_grid;
		Grid(vector<string>&& a) : raw_grid{std::move(a)}  {};
		
		vector<C> GetRegion(C c, int n){



		}
		
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

