#include "FORCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <chrono> 

using namespace std;
using namespace chrono;
 

float FORCoder::processArguments(string opType, string dataType, string fileName, int givenOutputCount)
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




void FORCoder::encodeInt8(string fileName) {
	vector<__int8> medianVector = csvReader.readInt8(fileName);
	int m = medianVector.size() / 2;
	nth_element(medianVector.begin(), medianVector.begin() + m, medianVector.end());
	__int8 median = medianVector[m]; 
	vector<__int8> vectorInt = csvReader.readInt8(fileName); 

	string outputString; 
	outputString += to_string(median); 
	outputString += ","; 

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (auto& element : vectorInt) {
		element -= median;
		outputString += to_string(element);
		outputString += ",";
	} 

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".for";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int8 into frame of reference encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}
void FORCoder::encodeInt16(string fileName)
{
	vector<__int16> medianVector = csvReader.readInt16(fileName);
	int m = medianVector.size() / 2;
	nth_element(medianVector.begin(), medianVector.begin() + m, medianVector.end());
	__int16 median = medianVector[m];
	vector<__int16> vectorInt = csvReader.readInt16(fileName);

	string outputString;
	outputString += to_string(median);
	outputString += ",";

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (auto& element : vectorInt) {
		element -= median;
		outputString += to_string(element);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".for";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int16 into frame of reference encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void FORCoder::encodeInt32(string fileName)
{
	vector<__int32> medianVector = csvReader.readInt32(fileName);
	int m = medianVector.size() / 2;
	nth_element(medianVector.begin(), medianVector.begin() + m, medianVector.end());
	__int32 median = medianVector[m];
	vector<__int32> vectorInt = csvReader.readInt32(fileName);

	string outputString;
	outputString += to_string(median);
	outputString += ",";

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (auto& element : vectorInt) {
		element -= median;
		outputString += to_string(element);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".for";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int32 into frame of reference encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void FORCoder::encodeInt64(string fileName)
{
	vector<__int64> medianVector = csvReader.readInt64(fileName);
	int m = medianVector.size() / 2;
	nth_element(medianVector.begin(), medianVector.begin() + m, medianVector.end());
	__int64 median = medianVector[m];
	vector<__int64> vectorInt = csvReader.readInt64(fileName);

	string outputString;
	outputString += to_string(median);
	outputString += ",";

	int n = vectorInt.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (auto& element : vectorInt) {
		element -= median;
		outputString += to_string(element);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".for";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int64 into frame of reference encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}


void FORCoder::decodeInt8(string fileName)
{
	vector<__int8> vectorInt;
	ifstream file(fileName);  
	string line;  
	__int8 median;

	while (getline(file, line, ','))	
		vectorInt.push_back((__int8)stoi(line)); 

	median = vectorInt[0];
 

	for (auto& element : vectorInt)
		element += median;
	
	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 1; i < outputCount+1; i++)
		cout << (int)vectorInt[i] << "\n";
}
void FORCoder::decodeInt16(string fileName)
{
	vector<__int16> vectorInt;
	ifstream file(fileName);
	string line;
	__int16 median;

	while (getline(file, line, ','))
		vectorInt.push_back((__int16)stoi(line));

	median = vectorInt[0];

 

	for (auto& element : vectorInt)
		element += median;

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 1; i < outputCount+1; i++)
		cout << (int)vectorInt[i] << "\n";
}

void FORCoder::decodeInt32(string fileName)
{
	vector<__int32> vectorInt;
	ifstream file(fileName);
	string line;
	__int32 median;

	while (getline(file, line, ','))
		vectorInt.push_back((__int32)stoi(line));

	median = vectorInt[0];

 

	for (auto& element : vectorInt)
		element += median;

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 1; i < outputCount+1; i++)
		cout << (int)vectorInt[i] << "\n";
}

void FORCoder::decodeInt64(string fileName)
{
	vector<__int64> vectorInt;
	ifstream file(fileName);
	string line;
	__int64 median;

	while (getline(file, line, ','))
		vectorInt.push_back((__int64)stoi(line));

	median = vectorInt[0];

 

	for (auto& element : vectorInt)
		element += median;

	file.close();
	if (outputCount == 0)
		outputCount = vectorInt.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 1; i < outputCount+1; i++)
		cout << (int)vectorInt[i] << "\n";
}

 
