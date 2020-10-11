#include "DicCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <map>
#include <utility>      

using namespace std;
 

void DicCoder::processArguments(string opType, string dataType, string fileName)
{
	if (opType == "EN") {
		if (dataType == "STRING") {
			encodeString(fileName); 
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
			 decodeString(fileName);
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







void DicCoder::encodeInt8(string fileName) {
	vector<__int8> vectorInt = csvReader.readInt8(fileName);  
	string outputString;
	map<__int8, __int8> intMap;

	// create map keys
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		  pair <__int8, __int8> keyval = make_pair(vectorInt[i], intMap.size());

		  intMap.insert(keyval);
		 
	} 
	 // write dict  
	for (const auto& p : intMap)
	{
		outputString += to_string(p.first) + ":" + to_string(p.second) + ","; 
	} 
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += ",";
	}
	  
	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dic";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int8 into dictionary encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}
void DicCoder::encodeInt16(string fileName)
{
	vector<__int16> vectorInt = csvReader.readInt16(fileName);
	string outputString;
	map<__int16, __int16> intMap;

	// create map keys
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		pair <__int16, __int16> keyval = make_pair(vectorInt[i], intMap.size());

		intMap.insert(keyval);

	}
	// write dict  
	for (const auto& p : intMap)
	{
		outputString += to_string(p.first) + ":" + to_string(p.second) + ",";
	}
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dic";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int16into dictionary encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void DicCoder::encodeInt32(string fileName)
{
	vector<__int32> vectorInt = csvReader.readInt32(fileName);
	string outputString;
	map<__int32, __int32> intMap;

	// create map keys
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		pair <__int32, __int32> keyval = make_pair(vectorInt[i], intMap.size());

		intMap.insert(keyval);

	}
	// write dict  
	for (const auto& p : intMap)
	{
		outputString += to_string(p.first) + ":" + to_string(p.second) + ",";
	}
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dic";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int32 into dictionary encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void DicCoder::encodeInt64(string fileName)
{
	vector<__int64> vectorInt = csvReader.readInt64(fileName);
	string outputString;
	map<__int64, __int64> intMap;

	// create map keys
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		pair <__int64, __int64> keyval = make_pair(vectorInt[i], intMap.size());

		intMap.insert(keyval);

	}
	// write dict  
	for (const auto& p : intMap)
	{
		outputString += to_string(p.first) + ":" + to_string(p.second) + ",";
	}
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += ",";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".dic";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int64 into dictionary encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}


void DicCoder::decodeInt8(string fileName)
{
	vector<__int8> int8Vector;
	ifstream file(fileName, ios::binary);
	int a;
	file.read(reinterpret_cast<char*>(&a), sizeof(a));
	int8Vector.resize(a);
	file.read(reinterpret_cast<char*>(&int8Vector[0]), sizeof(__int8) * int8Vector.size());

	cout << "Decoding file: " << fileName << ", outputting the first 10 values:\n";
	for (int i = 0; i < 10; i++)
		cout << (int)int8Vector[i] << "\n";
}
void DicCoder::decodeInt16(string fileName)
{
	vector<__int16> int16Vector;
	ifstream file(fileName, ios::binary);
	int a;
	file.read(reinterpret_cast<char*>(&a), sizeof(a));
	int16Vector.resize(a);
	file.read(reinterpret_cast<char*>(&int16Vector[0]), sizeof(__int16) * int16Vector.size());

	cout << "Decoding file: " << fileName << ", outputting the first 10 values:\n";
	for (int i = 0; i < 10; i++)
		cout << (int)int16Vector[i] << "\n";
}

void DicCoder::decodeInt32(string fileName)
{
	vector<__int32> int32Vector;
	ifstream file(fileName, ios::binary);
	int a;
	file.read(reinterpret_cast<char*>(&a), sizeof(a));
	int32Vector.resize(a);
	file.read(reinterpret_cast<char*>(&int32Vector[0]), sizeof(__int32) * int32Vector.size());

	cout << "Decoding file: " << fileName << ", outputting the first 10 values:\n";
	for (int i = 0; i < 10; i++)
		cout << (int)int32Vector[i] << "\n";
}

void DicCoder::decodeInt64(string fileName)
{
	vector<__int64> int64Vector;
	ifstream file(fileName, ios::binary);
	int a;
	file.read(reinterpret_cast<char*>(&a), sizeof(a));
	int64Vector.resize(a);
	file.read(reinterpret_cast<char*>(&int64Vector[0]), sizeof(__int64) * int64Vector.size());

	cout << "Decoding file: " << fileName << ", outputting the first 10 values:\n";
	for (int i = 0; i < 10; i++)
		cout << (int)int64Vector[i] << "\n";
}



void DicCoder::encodeString(string fileName) {
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
void DicCoder::decodeString(string fileName) {
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

