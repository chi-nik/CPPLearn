#pragma once
#include <vector>
#include <stack>
class Towers {

public:
	struct rng {
		int from;
		int to;
		bool single;
		bool top;
		/// From bottom piece till top piece (1)
		rng(int f, int t = 1) : from(f), to(t) 
		{ 
			single = f == t; 
			top = f == 1 && single; 
		};

	};
	//enum Pile { A, B, C };
	std::stack<int> A, B, C;
	Towers(int); 
	void mv(char source, char dest, rng);
	std::string toString();
	std::vector<int> asvec(std::stack<int> s);
};
