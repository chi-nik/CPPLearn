#include <iostream>
#include <string>
#include <sstream>
#include "../file_reader.h"

class Card{
	private:
		std::string raw_string;
		int id;
		std::vector<int> winning, our_numbers;

	public:
		Card(std::string s): raw_string{s}{
		}
		void parse(){
			std::stringstream ss(raw_string);
			std::string tmp;
			std::vector<string> res;
			int n{};
			bool start_our = false;
			while(std::getline(ss,tmp,' ')){
				if(n++<2 ||  tmp == "") continue;
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
		void toStr(){
			for(auto a: winning){ cout << a << " "; }
			cout << endl;
			for(auto a: our_numbers){ cout << a << " "; }
			cout << endl;
		}
};
int main(){
	std::vector<string> input=file_reader("input.txt");
	Card c(input[0]);
	c.parse();
	c.toStr();
	return 0;
}	
