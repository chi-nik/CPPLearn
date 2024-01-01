#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<string> file_reader(string filename) {
	string line;
	vector<string> res;
	ifstream fn(filename, ios::out);
	while(getline(fn,line)){
		res.push_back(line);
	}
	fn.close();
	return res;
}
