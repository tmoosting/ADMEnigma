#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream


using namespace std;



class CSVReader
{
public: 
	vector<__int8> readInt8(string fileName);
	vector<__int16> readInt16(string fileName);
	vector<__int32> readInt32(string fileName);
	vector<__int64> readInt64(string fileName);
	vector<string> readString(string fileName);
};

