#pragma once


#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;


class BinCoder
{
public:	
	 

	void processArguments(string opType, string dataType, string fileName);

	void encodeInt8(vector<__int8> vectorInt8, string fileName);

	void encodeInt(string dataType, string fileName);

	void decodeInt(string dataType, string fileName);

	void encodeString(string fileName);

	void decodeString(string fileName);

};

