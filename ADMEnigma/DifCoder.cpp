#include "DifCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <chrono> 

using namespace std;
using namespace chrono;
 

float DifCoder::processArguments(string opType, string dataType, string fileName, int givenOutputCount)
{
	outputCount = givenOutputCount;
	auto start = high_resolution_clock::now();
	if (opType == "EN") {
		if (dataType == "STRING") {
			//encodeString(fileName); 
		}
		else {
			if (dataType == "INT8")
				encodeInt8(fileName);
			else 	if (dataType == "INT16")
				encodeInt16(fileName);
			else 	if (dataType == "INT32")
				encodeInt32(fileName);
			else 	if (dataType == "INT64")
				encodeInt64(fileName);
		}
	}
	else 	if (opType == "DE") {
		if (dataType == "STRING") {
			//	decodeString(fileName);
		}
		else {
			if (dataType == "INT8")
				decodeInt8(fileName);
			else 	if (dataType == "INT16")
				decodeInt16(fileName);
			else 	if (dataType == "INT32")
				decodeInt32(fileName);
			else 	if (dataType == "INT64")
				decodeInt64(fileName);
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	return duration.count();
}







void DifCoder::encodeInt8(string fileName) {

	vector<__int8> vectorInt = csvReader.readInt8(fileName); 
	string outputString;

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	outputString += to_string(vectorInt[0]);
	outputString += ",";

	for (size_t i = 1; i < vectorInt.size(); i++)
	{
		outputString += to_string(vectorInt[i ] - vectorInt[i - 1]);
		outputString += ","; 
	} 
	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dif";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int8 into differential encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}
void DifCoder::encodeInt16(string fileName)
{
	vector<__int16> vectorInt = csvReader.readInt16(fileName);
	string outputString;

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	outputString += to_string(vectorInt[0]);
	outputString += ",";

	for (size_t i = 1; i < vectorInt.size(); i++)
	{
		outputString += to_string(vectorInt[i] - vectorInt[i - 1]);
		outputString += ",";
	}
	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dif";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int16 into differential encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void DifCoder::encodeInt32(string fileName)
{
	vector<__int32> vectorInt = csvReader.readInt32(fileName);
	string outputString;

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	outputString += to_string(vectorInt[0]);
	outputString += ",";

	for (size_t i = 1; i < vectorInt.size(); i++)
	{
		outputString += to_string(vectorInt[i] - vectorInt[i - 1]);
		outputString += ",";
	}
	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dif";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int32 into differential encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void DifCoder::encodeInt64(string fileName)
{
	vector<__int64> vectorInt = csvReader.readInt64(fileName);
	string outputString;

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	outputString += to_string(vectorInt[0]);
	outputString += ",";

	for (size_t i = 1; i < vectorInt.size(); i++)
	{
		outputString += to_string(vectorInt[i] - vectorInt[i - 1]);
		outputString += ",";
	}
	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dif";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int64 into differential encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}


void DifCoder::decodeInt8(string fileName)
{
	vector<__int8> vectorInt; 
	ifstream file(fileName);
	string line; 

	while (getline(file, line, ','))
		vectorInt.push_back((__int8)stoi(line)); 

	for (size_t i = 1; i < vectorInt.size(); i++) 
		vectorInt[i] = vectorInt[i - 1] + vectorInt[i];  

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)vectorInt[i] << "\n";
}
void DifCoder::decodeInt16(string fileName)
{
	vector<__int16> vectorInt;
	ifstream file(fileName);
	string line;

	while (getline(file, line, ','))
		vectorInt.push_back((__int16)stoi(line));

	for (size_t i = 1; i < vectorInt.size(); i++)
		vectorInt[i] = vectorInt[i - 1] + vectorInt[i];

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)vectorInt[i] << "\n";
}

void DifCoder::decodeInt32(string fileName)
{
	vector<__int32> vectorInt;
	ifstream file(fileName);
	string line;

	while (getline(file, line, ','))
		vectorInt.push_back((__int32)stoi(line));

	for (size_t i = 1; i < vectorInt.size(); i++)
		vectorInt[i] = vectorInt[i - 1] + vectorInt[i];

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)vectorInt[i] << "\n";
}

void DifCoder::decodeInt64(string fileName)
{
	vector<__int64> vectorInt;
	ifstream file(fileName);
	string line;

	while (getline(file, line, ','))
		vectorInt.push_back((__int64)stoi(line));

	for (size_t i = 1; i < vectorInt.size(); i++)
		vectorInt[i] = vectorInt[i - 1] + vectorInt[i];

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)vectorInt[i] << "\n";
}


 