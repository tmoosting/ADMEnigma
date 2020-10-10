#include "BinCoder.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;

CSVReader csvReader;

void BinCoder::processArguments(string opType, string dataType, string fileName)
{
	if (opType == "EN") {
		if (dataType == "STRING")
			encodeString(fileName);
		else 
			encodeInt(dataType, fileName);
	}
	else 	if (opType == "DE") {
		if (dataType == "STRING")
			decodeString(fileName);
		else
			decodeInt(dataType, fileName);
	} 
} 
void BinCoder::encodeInt(string dataType, string fileName) {
	//TODO: Clean up Garbage mess here
	vector<__int8> vectorInt8;
	vector<__int16> vectorInt16;
	vector<__int32> vectorInt32;
	vector<__int64> vectorInt64; 

	if (dataType == "INT8") {
		vectorInt8 = csvReader.readInt8(fileName);
		encodeInt8(vectorInt8);
	}
	else 	if (dataType == "INT16") {
		vectorInt16 = csvReader.readInt16(fileName);

	}
	else 	if (dataType == "INT32") {
		vectorInt32 = csvReader.readInt32(fileName);

	}
	else 	if (dataType == "INT64") {
		vectorInt64 = csvReader.readInt64(fileName);

	} 
	//for (int i = 0; i < 5; i++)
	//{
	//	int retuuuurnint = (int)tester[i];
	//	cout << "number" << retuuuurnint;
	//}
}

void BinCoder::decodeInt(string dataType, string fileName) {

}

void BinCoder::encodeString(string fileName) {
	vector<string> vectorString = csvReader.readString(fileName); 
}
void BinCoder::decodeString(string fileName) {
	vector<string> tester = csvReader.readString(fileName); 
}


void BinCoder::encodeInt8(vector<__int8> vectorInt8) {

}

 