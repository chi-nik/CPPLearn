
#include "Katas.h"
#include <limits>

std::string reverseIT(std::string str) {
	std::string reversed;
	decltype(str.size()) revIter = str.size() - 1;
	for (auto b : str) reversed += str[revIter--];
	return reversed;
}

std::string spinWords(const std::string &str)
{
	std::vector<std::string> vec;
	// split into substring 
	std::string es;
	for (auto c : str)
	{
		if (c != ' ')
			es += c;
		else
		{
			vec.push_back(es);
			vec.push_back(" ");
			es = "";
		}
	}
	vec.push_back(es);
	vec.push_back(" ");

	if (vec.size() > 1) vec.pop_back();
	// reverse 
	for (auto &a : vec)
	{
		if (a.size() >= 5)
		{
			a = reverseIT(a);
		}
	}

	std::string resultStr;
	for (auto a : vec) resultStr += a;
	return resultStr;

}
std::string highAndLow(const std::string &strT)
{
	// tokenize string
	std::vector<int> listNum;
	std::string str(strT+" ");
	int max = std::numeric_limits<int>::min();
	int min = std::numeric_limits<int>::max();
	do{
		//substring 
		int cu = std::stoi(str.substr(0, str.find(' ')));
		if (cu > max) max = cu;
		if (cu < min) min = cu;
		str.erase(0, str.find(' ')+1); 
	} while (str.find(' ') != std::string::npos);

	// convert to int

	std::string res = std::to_string(max) + ' ' + std::to_string(min);
	return res;
}

std::string DNAStrand(const std::string& dna) {
	std::string str(dna);
	for (auto &e : str) {
		switch (e) {
		case 'G':
			e = 'C';
			break; 
		case 'C':
			e = 'G';
			break;
		case 'T':
			e = 'A';
			break;
		case 'A':
			e = 'T';
			break;
		} 
	}
	return str; 
}

