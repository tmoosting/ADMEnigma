#pragma once

#include "CSVReader.h"  
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;


class BinCoder
{
public:	  
	CSVReader csvReader;
	float processArguments(string opType, string dataType, string fileName);
	void encodeInt8( string fileName);
	void encodeInt16( string fileName);
	void encodeInt32( string fileName);
	void encodeInt64( string fileName);
	void decodeInt8(string fileName);
	void decodeInt16(string fileName);
	void decodeInt32(string fileName);
	void decodeInt64(string fileName); 
	void encodeString(string fileName);
	void decodeString(string fileName);

 
	template<typename T> 
	void encodeInt(string fileName);  
	 // https://riptutorial.com/cplusplus/example/28734/explicit-instantiation 
	// https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
};

