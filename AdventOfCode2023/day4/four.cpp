#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <deque>
#include "../file_reader.h"

class Card{
	private:
		std::string raw_string;
		int id;
		std::vector<int> winning, our_numbers, our_wins;

	public:
		int points{0};
		Card(std::string s): raw_string{s}{
		}
		void getWonCards(std::deque<int>& v){
			vector<int> result; 
			// skim to get the number
			int nc{0};
			if(v.begin() != v.end()){
				nc=v.front();
				v.pop_front();
				v.push_back(0);
				cout << "Popped: " << nc << std::endl;
			}
			cout << "Added Cards: "  << endl;
			for(unsigned i=0; i < points; i++) {
				
				v.at(i)+=(nc)+1;
				cout << v.at(i) << ' ';
			}
			cout << std::endl << "V: ";
			for(auto i=v.cbegin(); i != v.cend(); i++){
				cout << *i << ' ';
			}
			cout << endl;
		}
		void parse(){
			std::stringstream ss(raw_string.erase(0,10));
			std::string tmp;
			std::vector<string> res;
			int n{};
			bool start_our = false;
			while(std::getline(ss,tmp,' ')){
				if(tmp == "") continue;
				if(tmp == "|") { start_our = true; continue;}
				if(start_our){
					our_numbers.push_back(stoi(tmp));
				}
				else{
					winning.push_back(stoi(tmp));
				}
				
			//cut till :
			//split on '|'
			//split on ' ' 
			}
		}
		void computeWinner(){
			//std::vector<int> intersect;
			std::set<int> tmp(winning.cbegin(),winning.cend());
			for(auto num:our_numbers){
				//auto it=tmp.insert(num);
				// already exists?
				//if(!it.second) intersect.push_back(*it.first);

				auto it=tmp.find(num);
				
				if(it!=tmp.end()) our_wins.push_back(*it);

			}
			//if(our_wins.size() > 0) points = (int)(1 << ((int)our_wins.size()-1)) ;
			points =our_wins.size() ;

		}
		void toStr(){
			for(auto a: winning){ cout << a << " "; }
			cout << endl;
			for(auto a: our_numbers){ cout << a << " "; }
			cout << endl;
			for(auto a: our_wins){ cout << a << " "; }
			cout << "[" << points << "]"<< endl;
		}
};
int main(){
	std::vector<string> input=file_reader("input.txt");
	std::vector<Card> result;
	int total_points{0};
	for(auto a:input){
	Card c(a);
	c.parse();
	c.computeWinner();
	result.push_back(c);
	}
	std::deque<int> wonc( 12 );
	for(auto a:result){
		a.toStr();
		total_points+=(wonc.front()+1);
		a.getWonCards(wonc);

	}
	cout << "Points: " << total_points << std::endl;
	return 0;
}	
