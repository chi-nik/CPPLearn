#pragma once
#include "C.h"
#include "Symbol.h"
#include "Number.h"
#include <set>

class Grid{
	public:
		vector<vector<C>> grid{};
		vector<string> raw_grid;
		Grid(vector<string>&& a) : raw_grid{std::move(a)}  {};
		
		vector<C> GetListSyms() {
			vector<C> res;
			for(auto a:grid){
				for(auto b:a){
					if(b.s.sym != '.') res.push_back(b) ;
				}
			}
			return res;
		}
		vector<Number> GetUniqueNums(vector<C> rng){ //vector<C>
			// get nums
			vector<Number> res;
			std::set<Number*> set_nums;
			for(auto a: rng) {
				if(a.n) set_nums.insert(a.n);
			}
			for(auto a: set_nums) {
				//if(a.n) set_nums.insert(a.n);
				cout << *a;
				res.push_back(*a);
			}
			return res;
		}
		vector<C> GetRegion(C c, int n){
			vector<C> res;
			
			//generate region indexes
			for(int col=c.c-n; (col < (int) grid[0].size()) && (col <= c.c+n) ; col++) {
				//cout << "Col is : " << col << endl;
				if(col < 0) {cout << "continue \n"; continue;}
				for(int row=c.r-n; row < (int) grid.size() && row <= c.r+n; row++) {
					if(row < 0){cout << "continue \n"; continue;} 
					//cout << "Row is : " << col << endl;
					res.push_back(grid[row][col]);
					cout << grid[row][col];


				
				}
			}
			return res;
			//for(int row=c.r-n; row<grid[0].size(); row++
			


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

