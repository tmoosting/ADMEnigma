#include "DifCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;
 

void DifCoder::processArguments(string opType, string dataType, string fileName)
{
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

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
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

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
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

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
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

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout << (int)vectorInt[i] << "\n";
}



void DifCoder::encodeString(string fileName) {
	/*vector<string> vectorString = csvReader.readString(fileName);

	string newFileName = fileName;

	newFileName.erase(newFileName.length() - 4);
	newFileName += ".bin";

	ofstream file(newFileName, ios::binary);
	int a = vectorString.size();
	cout << a;
	cout << vectorString[0];
	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
	file.write(reinterpret_cast<const char*>(&vectorString[0]), sizeof(string) * vectorString.size());
 */

}
void DifCoder::decodeString(string fileName) {
	//vector<string> tester;

	//ifstream file(fileName, ios::binary);
	//int a;
	//file.read(reinterpret_cast<char*>(&a), sizeof(a)); 
	//tester.resize(a);
	//file.read(reinterpret_cast<char*>(&tester[0]), sizeof(string) * tester.size());
	// 
	//cout << tester.size();
	//cout << tester[0];
	//cout << tester[1];
	//cout << tester[2];

}

