#include "BinCoder.h"
#include "CSVReader.h" 
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <chrono> 

using namespace std;
using namespace chrono;
 
  
//float BinCoder::processArguments(string opType, string dataType, string fileName)
//{
//	if (opType == "EN") {
//		if (dataType == "STRING") {
//			//encodeString(fileName); 
//		}
//		else {
//			if (dataType == "INT8")
//				encodeInt<__int8>(fileName);
//			else 	if (dataType == "INT16")
//				encodeInt<__int16>(fileName);
//			else 	if (dataType == "INT32")
//				encodeInt<__int32>(fileName);
//			else 	if (dataType == "INT64")
//				encodeInt<__int64>(fileName);
//		}
//	}
//	else 	if (opType == "DE") {
//		if (dataType == "STRING") {
//			//	decodeString(fileName);
//		}
//		else {
//			if (dataType == "INT8")
//				decodeInt8(fileName);
//			else 	if (dataType == "INT16")
//				decodeInt16(fileName);
//			else 	if (dataType == "INT32")
//				decodeInt32(fileName);
//			else 	if (dataType == "INT64")
//				decodeInt64(fileName);
//		}
//	}
//	return 0;
//}

float BinCoder::processArguments(string opType, string dataType, string fileName)
{
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
	auto duration = duration_cast<microseconds>(stop - start); 
	return duration.count();
}

 
 
//template <typename T>
//void BinCoder::encodeInt(string fileName) {
//	vector<T> vectorInt = csvReader.readInt<T>(fileName);
//	string binFileName = fileName;
//	binFileName.erase(binFileName.length() - 4);
//	binFileName += ".bin";
//
//	ofstream file(binFileName, ios::binary);
//	int a = vectorInt.size();
//	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
//	file.write(reinterpret_cast<const char*>(&vectorInt[0]), sizeof(__int8) * vectorInt.size());
//
//	cout << "Encoded " << fileName << "with data type ..  into uncompressed binary format. Output file: " << binFileName;
//	//cout << "Encoded " << fileName << "with data type " << to_string(T) <<" into uncompressed binary format. Output file: " << binFileName;
//}


void BinCoder::encodeInt8(  string fileName) {
	vector<__int8> vectorInt8 = csvReader.readInt8(fileName); 
	string binFileName = fileName; 
	binFileName.erase(binFileName.length() - 4);
	binFileName += ".bin";

	ofstream file(binFileName, ios::binary);
	int a = vectorInt8.size(); 
	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
	file.write(reinterpret_cast<const char*>(&vectorInt8[0]), sizeof(__int8) * vectorInt8.size());

	cout << "Encoded " << fileName << "with data type int8 into uncompressed binary format. Output file: " << binFileName; 
}
void BinCoder::encodeInt16(string fileName)
{
	vector<__int16> vectorInt16 = csvReader.readInt16(fileName);
	string binFileName = fileName;
	binFileName.erase(binFileName.length() - 4);
	binFileName += ".bin";

	ofstream file(binFileName, ios::binary);
	int a = vectorInt16.size();
	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
	file.write(reinterpret_cast<const char*>(&vectorInt16[0]), sizeof(__int16) * vectorInt16.size());

	cout << "Encoded " << fileName << "with data type int16 into uncompressed binary format. Output file: " << binFileName;
}

void BinCoder::encodeInt32(string fileName)
{
	vector<__int32> vectorInt32 = csvReader.readInt32(fileName);
	string binFileName = fileName;
	binFileName.erase(binFileName.length() - 4);
	binFileName += ".bin";

	ofstream file(binFileName, ios::binary);
	int a = vectorInt32.size();
	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
	file.write(reinterpret_cast<const char*>(&vectorInt32[0]), sizeof(__int32) * vectorInt32.size());

	cout << "Encoded " << fileName << "with data type int32 into uncompressed binary format. Output file: " << binFileName;
}

void BinCoder::encodeInt64(string fileName)
{
	vector<__int64> vectorInt64 = csvReader.readInt64(fileName);
	string binFileName = fileName;
	binFileName.erase(binFileName.length() - 4);
	binFileName += ".bin";

	ofstream file(binFileName, ios::binary);
	int a = vectorInt64.size();
	file.write(reinterpret_cast<const char*>(&a), sizeof(a));
	file.write(reinterpret_cast<const char*>(&vectorInt64[0]), sizeof(__int64) * vectorInt64.size());

	cout << "Encoded " << fileName << "with data type int64 into uncompressed binary format. Output file: " << binFileName;
}

 
void BinCoder::decodeInt8(string fileName)
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
void BinCoder::decodeInt16(string fileName)
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

void BinCoder::decodeInt32(string fileName)
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

void BinCoder::decodeInt64(string fileName)
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



void BinCoder::encodeString(string fileName) {
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
void BinCoder::decodeString(string fileName) {
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

 