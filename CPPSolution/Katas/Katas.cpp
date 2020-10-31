
#include "Katas.h"
#include <limits>
#include <algorithm>

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
std::string cleanString2(std::string s) 
{
	std::string ctrlStr(s);
	std::string resStr;
	auto csIter = ctrlStr.begin();
	//auto resIter = resStr.begin();
	while (csIter != ctrlStr.end()) 
	{ 
		if (*csIter != '#') resStr.push_back(*csIter); 
		else if(!resStr.empty()) resStr.pop_back();  
		csIter++;
	}

	return resStr;

}
std::string cleanString(std::string s) { 
	std::string resStr;
	for (auto sChar: s) 
	{ 
		if (sChar != '#') resStr.push_back(sChar); 
		else if(!resStr.empty()) resStr.pop_back();  
	}

	return resStr;
}
std::string range_extraction(std::vector<int> args) 
{
	std::string res;
	args.push_back(args.back());
	auto begRng = args.begin();

	for (auto it = args.begin(); it != args.end(); ++it)
	{
		// decide if the string is broken
		bool isBreakingString = it - begRng != *it - *begRng;
		if ( isBreakingString )
		{
			auto lastPos = it - 1;
			switch (lastPos+1 - begRng)
			{
			case 1:
				res.append(std::to_string(*begRng) + ",");
				break;
			case 2:
				res.append(std::to_string(*begRng) + "," + std::to_string(*lastPos) + ",");
				break;
			default:
				res.append(std::to_string(*begRng) + "-" + std::to_string(*lastPos) + ",");
				break;
			}
			//reset
			begRng = it;

		}
	}
	res.pop_back(); // remove ,
	return res;
	
}

int dblLinear(int n) {

	static std::vector<int> listOfInt = { 1 };
	static int begPrevBatch = 0;
	static int curBatchNum = 0;
	static int indexMaxCurBatch = 0;
	static int thisBatchMax = 1; 

	// does it need to grow?
	if (n <= indexMaxCurBatch) return listOfInt[n];

	do 
	{
		curBatchNum++;
		thisBatchMax += std::pow(3, curBatchNum);
		int lastAddedBatchMin;
		do
		{
			// grow
			int endPrevBatch = listOfInt.size() - 1;
			lastAddedBatchMin = INT_MAX;

			// add batch untill max batch_cb < min lastaddedBatch 
			while (begPrevBatch <= endPrevBatch) {
				int y2 = (listOfInt[begPrevBatch]) * 2 + 1;
				int y3 = (listOfInt[begPrevBatch]) * 3 + 1;
				lastAddedBatchMin = std::min(lastAddedBatchMin, y3);
				lastAddedBatchMin = std::min(lastAddedBatchMin, y2);
				listOfInt.push_back(y2);
				listOfInt.push_back(y3);
				++begPrevBatch;
			}
			int lastAddedBatchMax = listOfInt.back();   
			std::sort(listOfInt.begin(), listOfInt.end());
			auto it = std::unique(listOfInt.begin(), listOfInt.end());
			listOfInt.resize(std::distance(listOfInt.begin(), it));
			begPrevBatch = std::find(listOfInt.begin(), listOfInt.end(), lastAddedBatchMin) - listOfInt.begin(); 
		} while (thisBatchMax >= lastAddedBatchMin);
		indexMaxCurBatch = std::find(listOfInt.begin(), listOfInt.end(), thisBatchMax) - listOfInt.begin();
	} while (n > indexMaxCurBatch);

	return listOfInt[n];
}
