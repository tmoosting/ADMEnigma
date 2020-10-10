#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream


using namespace std;

class CSVWriter
{
public:
	void writeInt8(vector<__int8> givenVector, string fileName);
	void writeInt16(vector<__int16> givenVector, string fileName);
	void writeInt32(vector<__int32> givenVector, string fileName);
	void writeInt64(vector<__int64> givenVector, string fileName);
	void writeString(vector<string> givenVector, string fileName);
};

