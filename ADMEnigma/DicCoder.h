#pragma once
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;


class DicCoder
{
public:
	CSVReader csvReader;
	float processArguments(string opType, string dataType, string fileName);
	void encodeInt8(string fileName);
	void encodeInt16(string fileName);
	void encodeInt32(string fileName);
	void encodeInt64(string fileName);
	void decodeInt8(string fileName);
	vector<string> splitIntoSubstrings(string str, char dl);
	void decodeInt16(string fileName);
	void decodeInt32(string fileName);
	void decodeInt64(string fileName);
	void encodeString(string fileName);
	void decodeString(string fileName);
 
};

