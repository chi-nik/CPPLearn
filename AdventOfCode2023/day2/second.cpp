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

	bool isBusted(int l_r, int l_g, int l_b){
		return (r > l_r) || (g > l_g) || (b > l_b) ;
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
	GameEntry(string gs){
		// extract gameid
		smatch sm;
		regex_match(gs,sm, regex("Game (\\d+):.*"));
		gameNum=stoi(sm[1]);
		gs.erase(gs.begin(), gs.begin()+gs.find(':')+1);
		while(gs.find(';') != string::npos){
			string substr= gs.substr(0, gs.find(';')+1);
			gs.erase(gs.begin(), gs.begin()+gs.find(';')+1);
			vd.push_back(Draw(substr));
		}
		vd.push_back(Draw(gs));
		cout << gs << endl; 
	
	}
	bool isGameBusted(){
		for(auto i: vd){
			if ( i.isBusted(12,13,14)) return true;
		}
		return false;
	}
	int getPower() {
		int r_max, g_max, b_max;
		r_max = vd[0].r;
		g_max = vd[0].g;
		b_max = vd[0].b;
		for ( auto i : vd) {
			r_max = (i.r > r_max) ? i.r : r_max;
			g_max = (i.g > g_max) ? i.g : g_max;
			b_max = (i.b > b_max) ? i.b : b_max;
		}

		return r_max*b_max*g_max;
	}
	friend ostream& operator<<(ostream& s, GameEntry ge);
	

};

ostream& operator<<(ostream& s, GameEntry ge)
{
	s << "G: " << ge.gameNum << endl;
	for( auto i: ge.vd){
		s << i << endl;
	}
	return s;
}
int main(){
	vector<string> data = file_reader("input.txt");
	cout << data[0] ;
	int result_gameid_sum=0;
	int result_gamepower_sum=0;
	for(auto d : data){
		GameEntry ge(d);
		if(ge.isGameBusted()) {
			cout << "BUSTEDGAME";
		}
		else{
			result_gameid_sum += ge.gameNum;
		}
		result_gamepower_sum += ge.getPower();

		cout << ge;

	}
	cout << result_gameid_sum << endl;
	cout << result_gamepower_sum << endl;



	return 0;
}

