#include "DicCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <map>
#include <utility>      
#include <chrono> 

using namespace std;
using namespace chrono;
 

float DicCoder::processArguments(string opType, string dataType, string fileName, int givenOutputCount)
{
	outputCount = givenOutputCount;
	auto start = high_resolution_clock::now();
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
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	return duration.count();
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
		outputString += to_string(p.first) + ":" + to_string(p.second) + "+"; 
	} 
	// marker for recreating map
	outputString += "*";
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += "+";
	}
	  
	// endmarker for decoding 
	outputString += "*";

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
		outputString += to_string(p.first) + ":" + to_string(p.second) + "+";
	}
	// marker for recreating map
	outputString += "*";
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += "+";
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
		outputString += to_string(p.first) + ":" + to_string(p.second) + "+";
	}
	// marker for recreating map
	outputString += "*";
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += "+";
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
		outputString += to_string(p.first) + ":" + to_string(p.second) + "+";
	}
	// marker for recreating map
	outputString += "*";
	// write rest through dict
	for (size_t i = 0; i < vectorInt.size(); i++)
	{
		outputString += to_string(intMap[vectorInt[i]]);
		outputString += "+";
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
	vector<__int8> intVector;
	ifstream file(fileName); 
	string line; 
	map<__int8, __int8> freshMap;	
	string dictString;  
	string contentString;  
	getline(file, dictString, '*');  

	// divide dictstring into a set of substrings, each with a: in the middle
	vector<string> keyValueStrings = splitIntoSubstrings(dictString, '+');

	// foreach of thsoe substrings, divide intwo two substrings, one before, one after the ':'
	for (size_t i = 0; i < keyValueStrings.size(); i++)
	{
		string keyValueString = keyValueStrings[i];
		int colonPos = keyValueString.find(":");
		string keyString = keyValueString.substr(0, colonPos);
		string valueString = keyValueString.substr(  colonPos+1, keyValueString.length());
		//cout << "keyString: " << keyString;
		//cout << "valueString: " << valueString;
		pair <__int8, __int8> keyval;
		keyval = make_pair((__int8)stoi(valueString), (__int8)stoi(keyString));
		freshMap.insert(keyval);
	}	 
	// Create outputstring using map  
	while (getline(file, contentString, '*')) { 
		// iterate through the large string that is the rest
		string segment;
		stringstream linestream(contentString);
		vector<string> seglist;
		while (getline(linestream, segment, '+')) {
			intVector.push_back(freshMap[(__int8)stoi(segment)]);
		} 
	}
	if (outputCount == 0)
		outputCount = intVector.size();
	file.close();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)intVector[i] << "\n";
}




void DicCoder::decodeInt16(string fileName)
{
	vector<__int16> intVector;
	ifstream file(fileName);
	string line;
	map<__int16, __int16> freshMap;
	string dictString;
	string contentString;
	getline(file, dictString, '*');

	// divide dictstring into a set of substrings, each with a: in the middle
	vector<string> keyValueStrings = splitIntoSubstrings(dictString, '+');

	// foreach of thsoe substrings, divide intwo two substrings, one before, one after the ':'
	for (size_t i = 0; i < keyValueStrings.size(); i++)
	{
		string keyValueString = keyValueStrings[i];
		int colonPos = keyValueString.find(":");
		string keyString = keyValueString.substr(0, colonPos);
		string valueString = keyValueString.substr(colonPos + 1, keyValueString.length()); 
		pair <__int16, __int16> keyval;
		keyval = make_pair((__int16)stoi(valueString), (__int16)stoi(keyString));
		freshMap.insert(keyval);
	}
	// Create outputstring using map 
	while (getline(file, contentString, '*')) {
		// iterate through the large string that is the rest
		string segment;
		stringstream linestream(contentString);
		vector<string> seglist;
		while (getline(linestream, segment, '+')) {
			intVector.push_back(freshMap[(__int16)stoi(segment)]);
		}
	}
	if (outputCount == 0)
		outputCount = intVector.size();
	file.close();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)intVector[i] << "\n";
}

void DicCoder::decodeInt32(string fileName)
{
	vector<__int32> intVector;
	ifstream file(fileName);
	string line;
	map<__int32, __int32> freshMap;
	string dictString;
	string contentString;
	getline(file, dictString, '*');

	// divide dictstring into a set of substrings, each with a: in the middle
	vector<string> keyValueStrings = splitIntoSubstrings(dictString, '+');

	// foreach of thsoe substrings, divide intwo two substrings, one before, one after the ':'
	for (size_t i = 0; i < keyValueStrings.size(); i++)
	{
		string keyValueString = keyValueStrings[i];
		int colonPos = keyValueString.find(":");
		string keyString = keyValueString.substr(0, colonPos);
		string valueString = keyValueString.substr(colonPos + 1, keyValueString.length());
		//cout << "keyString: " << keyString;
		//cout << "valueString: " << valueString;
		pair <__int32, __int32> keyval;
		keyval = make_pair((__int32)stoi(valueString), (__int32)stoi(keyString));
		freshMap.insert(keyval);
	}
	// Create outputstring using map 
	while (getline(file, contentString, '*')) {
		// iterate through the large string that is the rest
		string segment;
		stringstream linestream(contentString);
		vector<string> seglist;
		while (getline(linestream, segment, '+')) {
			intVector.push_back(freshMap[(__int32)stoi(segment)]);
		}
	}
	if (outputCount == 0)
		outputCount = intVector.size();
	file.close();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)intVector[i] << "\n";
}

void DicCoder::decodeInt64(string fileName)
{
	vector<__int64> intVector;
	ifstream file(fileName);
	string line;
	map<__int64, __int64> freshMap;
	string dictString;
	string contentString;
	getline(file, dictString, '*');

	// divide dictstring into a set of substrings, each with a: in the middle
	vector<string> keyValueStrings = splitIntoSubstrings(dictString, '+');

	// foreach of thsoe substrings, divide intwo two substrings, one before, one after the ':'
	for (size_t i = 0; i < keyValueStrings.size(); i++)
	{
		string keyValueString = keyValueStrings[i];
		int colonPos = keyValueString.find(":");
		string keyString = keyValueString.substr(0, colonPos);
		string valueString = keyValueString.substr(colonPos + 1, keyValueString.length());
		//cout << "keyString: " << keyString;
		//cout << "valueString: " << valueString;
		pair <__int64, __int64> keyval;
		keyval = make_pair((__int64)stoi(valueString), (__int64)stoi(keyString));
		freshMap.insert(keyval);
	}
	// Create outputstring using map 
	while (getline(file, contentString, '*')) {
		// iterate through the large string that is the rest
		string segment;
		stringstream linestream(contentString);
		vector<string> seglist;
		while (getline(linestream, segment, '+')) {
			intVector.push_back(freshMap[(__int64)stoi(segment)]);
		}
	}

	file.close();
	if (outputCount == 0)
		outputCount = intVector.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << (int)intVector[i] << "\n";
}



void DicCoder::encodeString(string fileName) {
 
		vector<string> vectorStr = csvReader.readString(fileName);
		string outputString;
		map<string, int> strMap;

		// create map keys
		for (size_t i = 0; i < vectorStr.size(); i++)
		{
			pair <string, int> keyval = make_pair(vectorStr[i], strMap.size());

			strMap.insert(keyval);

		}
		// write dict
		for (const auto& p : strMap)
		{
			outputString += (p.first) + ":" + to_string(p.second) + "+";
		}
		// marker for recreating map
		outputString += "*";
		// write rest through dict
		for (size_t i = 0; i < vectorStr.size(); i++)
		{
			outputString += to_string(strMap[vectorStr[i]]);
			outputString += "+";
		}
		// endmarker
		outputString += "*";
		string newFileName = fileName;
		newFileName.erase(newFileName.length() - 4);
		newFileName += ".dic";

		ofstream file(newFileName);
		file << outputString;
		file.close();
		cout << "Encoded " << fileName << "with data type string into dictionary encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

	}


 
void DicCoder::decodeString(string fileName) {
	vector<string> stringVector;
	ifstream file(fileName);
	string line;
	map<int, string> freshMap;
	string dictString;
	string contentString;
	getline(file, dictString, '*');

	// divide dictstring into a set of substrings, each with a: in the middle
	vector<string> keyValueStrings = splitIntoSubstrings(dictString, '+');

	// foreach of thsoe substrings, divide intwo two substrings, one before, one after the ':'
	for (size_t i = 0; i < keyValueStrings.size(); i++)
	{
		string keyValueString = keyValueStrings[i];
		int colonPos = keyValueString.find(":");
		string keyString = keyValueString.substr(0, colonPos);
		string valueString = keyValueString.substr(colonPos + 1, keyValueString.length()); 
		pair <int, string> keyval;
		keyval = make_pair((int)stoi(valueString), keyString);
		freshMap.insert(keyval);
	}
	// Create outputstring using map  
	while (getline(file, contentString, '*')) { 
		// iterate through the large string that is the rest
		string segment;
		stringstream linestream(contentString);
		vector<string> seglist;
		while (getline(linestream, segment, '+')) {
			stringVector.push_back(freshMap[(int)stoi(segment)]);
		}
	}

	file.close();
	if (outputCount == 0)
		outputCount = stringVector.size();
	cout << "Decoding file: " << fileName << ", outputting the first " << outputCount << " values:\n";
	for (int i = 0; i < outputCount; i++)
		cout << stringVector[i] << "\n";

}

 
vector<string> DicCoder::splitIntoSubstrings(string str, char dl)
{
	string word = ""; 
	int num = 0; 
	str = str + dl; 
	int l = str.size(); 
	vector<string> substr_list;
	for (int i = 0; i < l; i++) { 
		if (str[i] != dl)
			word = word + str[i];
		else { 
			if ((int)word.size() != 0)
				substr_list.push_back(word); 
			word = "";
		}
	} 
	return substr_list;
}