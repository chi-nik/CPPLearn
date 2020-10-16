// Katas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

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

}// spinWords

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
