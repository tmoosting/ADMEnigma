#include "RLECoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <chrono> 

using namespace std;
using namespace chrono;


float RLECoder::processArguments(string opType, string dataType, string fileName)
{
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







void RLECoder::encodeInt8(string fileName) { 
	vector<__int8> vectorInt8 = csvReader.readInt8(fileName);
	 
	string outputString;
	int n = vectorInt8.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (vectorInt8[i] == vectorInt8[i + 1]) {
			count++;
			i++;
		}
		//TODO: Skip add if next is not same. Then also in decoder
		outputString += to_string(count);
		outputString += "*";
		outputString += to_string(vectorInt8[i]);
		outputString += "+";
		// TODO : remove trailing +
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".rle";

	ofstream file(newFileName);
	file << outputString;
	file.close(); 
	cout << "Encoded " << fileName << "with data type int8 into run length encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}
void RLECoder::encodeInt16(string fileName)
{
	vector<__int16> vectorInt16 = csvReader.readInt16(fileName); 
	string outputString;
	int n = vectorInt16.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (vectorInt16[i] == vectorInt16[i + 1]) {
			count++;
			i++;
		}
		outputString += to_string(count);
		outputString += "*";
		outputString += to_string(vectorInt16[i]);
		outputString += "+";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".rle";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int16 into run length encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void RLECoder::encodeInt32(string fileName)
{
	vector<__int32> vectorInt32 = csvReader.readInt32(fileName);
	string outputString;
	int n = vectorInt32.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (vectorInt32[i] == vectorInt32[i + 1]) {
			count++;
			i++;
		}
		outputString += to_string(count);
		outputString += "*";
		outputString += to_string(vectorInt32[i]);
		outputString += "+";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".rle";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int32 into run length encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}

void RLECoder::encodeInt64(string fileName)
{
	vector<__int64> vectorInt64 = csvReader.readInt64(fileName);
	string outputString;
	int n = vectorInt64.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (vectorInt64[i] == vectorInt64[i + 1]) {
			count++;
			i++;
		}
		outputString += to_string(count);
		outputString += "*";
		outputString += to_string(vectorInt64[i]);
		outputString += "+";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".rle";

	ofstream file(newFileName);
	file << outputString;
	file.close();
	cout << "Encoded " << fileName << "with data type int64 into run length encoded format. Output file: " << newFileName << " length of output: " << outputString.size();

}


void RLECoder::decodeInt8(string fileName)
{
	vector<__int8> int8Vector; 
	ifstream file(fileName); // the file that is youknow
	string line;// each string up to a +: so is a number, then *, then the content

	while (getline(file, line, '+'))
	{
		//TODO :Add exception 
		string segment;
		stringstream linestream(line);
		vector<string> seglist;

		while (getline(linestream, segment, '*')) {
			seglist.push_back(segment);
		}

		for (size_t i = 0; i < stoi(seglist[0]); i++) {
			int8Vector.push_back(  (__int8)stoi(seglist[1])   );
		} 
	}
	file.close();

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout << (int)int8Vector[i] << "\n";
}
void RLECoder::decodeInt16(string fileName)
{
	vector<__int16> int16Vector;
	ifstream file(fileName);  
	string line; 

	while (getline(file, line, '+'))
	{ 
		string segment;
		stringstream linestream(line);
		vector<string> seglist;

		while (getline(linestream, segment, '*')) {
			seglist.push_back(segment);
		}

		for (size_t i = 0; i < stoi(seglist[0]); i++) {
			int16Vector.push_back((__int16)stoi(seglist[1]));
		}
	}
	file.close();

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout << (int)int16Vector[i] << "\n";
}

void RLECoder::decodeInt32(string fileName)
{
	vector<__int32> int32Vector;
	ifstream file(fileName);
	string line;

	while (getline(file, line, '+'))
	{
		string segment;
		stringstream linestream(line);
		vector<string> seglist;

		while (getline(linestream, segment, '*')) {
			seglist.push_back(segment);
		}

		for (size_t i = 0; i < stoi(seglist[0]); i++) {
			int32Vector.push_back((__int32)stoi(seglist[1]));
		}
	}
	file.close();

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout << (int)int32Vector[i] << "\n";
}

void RLECoder::decodeInt64(string fileName)
{
	vector<__int64> int64Vector;
	ifstream file(fileName);
	string line;

	while (getline(file, line, '+'))
	{
		string segment;
		stringstream linestream(line);
		vector<string> seglist;

		while (getline(linestream, segment, '*')) {
			seglist.push_back(segment);
		}

		for (size_t i = 0; i < stoi(seglist[0]); i++) {
			int64Vector.push_back((__int64)stoi(seglist[1]));
		}
	}
	file.close();

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout << (int)int64Vector[i] << "\n";
}



void RLECoder::encodeString(string fileName) {
	vector<string> vectorString = csvReader.readString(fileName); 

	string outputString;
	int n = vectorString.size();
	if (n <= 1)
		cout << "Why am I trying to encode an empty vector?";

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (vectorString[i] == vectorString[i + 1]) {
			count++;
			i++;
		}
		//TODO: Skip add if next is not same. Then also in decoder
		outputString += to_string(count); 
		outputString += "*";
		outputString += (vectorString[i]);
	    outputString += "+";
	}

	string newFileName = fileName;
	newFileName.erase(newFileName.length() - 4);
	newFileName += ".rle";

	ofstream file(newFileName); 
	file << outputString;
	file.close();

	cout << "Encoded " << fileName << "with data type string into run length encoded format. Output file: " << newFileName << " length of output: "<< outputString.size();
 
	//for (int i = 0; i < 200; i++)	
	//	cout << outputString[i];
	

}



void RLECoder::decodeString(string fileName) {

	vector<string> stringVector; // output vector

	ifstream file(fileName); // the file that is youknow

	string line;// each string up to a +: so is a number, then *, then the content

	while (getline(file, line, '+')) 
	{
		//TODO :Add exception 
		string segment; 
		stringstream linestream(line);
		vector<string> seglist;

		while (getline(linestream, segment, '*')) {
			seglist.push_back(segment);
		}

		for (size_t i = 0; i < stoi(seglist[0]); i++) {
			stringVector.push_back(seglist[1]);
		}
		

	}
	file.close();

	cout << "Decoding file: " << fileName << ", outputting the first 20 values:\n";
	for (int i = 0; i < 20; i++)
		cout <<  stringVector[i] << "\n";
}


 