#include <iostream>
#include <string>
#include <regex>
#include "file_reader.h"

using namespace std;
struct Draw {
	int r,g,b;

	//Draw(): r{0}, g{0}, b{0} {};
	Draw(string ds) : r{0}, g{0}, b{0}  {
		typedef  pair<int&, regex> map_ir; //pb = {r, regexR};
		//map_ir pb = {r,regexR};
		vector<map_ir> map_si = {
			{r,regex(".* (\\d+) red.*")},
			{g,regex(".* (\\d+) green.*")},
			{b,regex(".* (\\d+) blue.*")},
		};
		smatch sm;
		for( auto i : map_si){
			cout << "stirng: " << ds << endl;
			if (regex_match(ds, sm, i.second)) {
				cout << "found" <<endl;
				i.first=stoi(sm[1]);
			}
		}
	}
	friend ostream& operator<<(ostream& s, Draw d);
	
};
ostream& operator<<(ostream& s, Draw d){
	s << "["  << d.r << ", " << d.g << ", " << d.b << "]";
	return s;
}
struct GameEntry {
	int gameNum;
	vector<Draw> vd;

};

int main(){
	vector<string> data = file_reader("input.txt");
	Draw a(" 209 green, 3 blue, 23 red ;");
	cout << a <<endl;



	return 0;
}

