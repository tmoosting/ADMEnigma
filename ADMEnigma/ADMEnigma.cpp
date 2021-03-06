// ADMEnigma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinCoder.h"
#include "RLECoder.h"
#include "DicCoder.h"
#include "FORCoder.h"
#include "DifCoder.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>
#include <chrono>
#include <filesystem>

using namespace std; 
using namespace chrono;  


string validateArguments(int argc, char** argv);
void processArguments(int argc, char** argv);
void writeOperationData(string opType, string compression, string dataType, string fileName, float operationTime);
float getFileSize(string fileName);
bool file_exists(string fileName);
int outputCount = 20;

// Make Object of each compression class
BinCoder binCoder;
RLECoder rleCoder;
DicCoder dicCoder;
FORCoder forCoder;
DifCoder difCoder;
   

int main(int argc, char** argv)
{
    
    string validString = validateArguments(argc, argv); 
    
    if (validString != "VALID") 
        cout << validString << "\n";    
    else 
        processArguments(argc, argv); 
     
} 

void processArguments(int argc, char** argv)
{
     
    string operationType = argv[1];
    string compression = argv[2];
    string dataType = argv[3];
    string fileName = argv[4]; 
    transform(operationType.begin(), operationType.end(), operationType.begin(), ::toupper);
    transform(compression.begin(), compression.end(), compression.begin(), ::toupper);
    transform(dataType.begin(), dataType.end(), dataType.begin(), ::toupper); 

    float operationTime; 
    if (compression == "BIN") {
        operationTime =   binCoder.processArguments(operationType, dataType, fileName, outputCount);
    }
    if (compression == "RLE") {
        operationTime = rleCoder.processArguments(operationType, dataType, fileName, outputCount);
    }
    if (compression == "DIC") {
        operationTime = dicCoder.processArguments(operationType, dataType, fileName, outputCount);
    }
    if (compression == "FOR") {
        operationTime =  forCoder.processArguments(operationType, dataType, fileName, outputCount);
    }
    if (compression == "DIF") {
        operationTime = difCoder.processArguments(operationType, dataType, fileName, outputCount);
    }
    writeOperationData(operationType, compression, dataType, fileName, operationTime);
}


// Returns "valid" if all arguments are succesful, returns the problematic argument if not
string validateArguments(int argc, char** argv)
{  
    string outputCountString;
    // validate amount of arguments
    if (argc == 6) { 
        outputCount = stoi(argv[5]);
    }         
    else if (argc != 5)
        return "Invalid count: # of arguments should be 4 or 5, not " + to_string(argc - 1);

    string operationType = argv[1];
    string compression = argv[2];
    string dataType = argv[3];
    string fileName = argv[4]; 

    // Make uppercase for easier comparison
    transform(operationType.begin(), operationType.end(), operationType.begin(), ::toupper);
    transform(compression.begin(), compression.end(), compression.begin(), ::toupper);
    transform(dataType.begin(), dataType.end(), dataType.begin(), ::toupper); 

    // validate operation type
    if (operationType != "EN" && operationType != "DE")
        return "Invalid operation type: " + operationType;  

    // validate compression
    if (compression != "BIN" && compression != "RLE" && compression != "DIC" && compression !=  "FOR" && compression != "DIF")
        return "Invalid compression: " + compression + ". Please choose BIN, RLE, DIC, FOR, or DIF";

    // validate data type
    if (dataType != "INT8" && dataType != "INT16" && dataType != "INT32" && dataType != "INT64" && dataType != "STRING")
        return "Invalid DATA TYPE: " + dataType + ". Please choose INT8, INT16, INT32, INT64, or STRING";

    if (compression == "BIN" || compression == "FOR" || compression == "DIF")
        if (dataType == "STRING")
            return "Invalid DATA TYPE: " + dataType + " IS NOT VALID FOR Bin, FOR and Dif encoding";
    // validate filename  
     
    if (!file_exists(fileName))
        return "FILE NOT FOUND: " + fileName;
    return "VALID";
}

void writeOperationData(string opType, string compression, string dataType, string fileName, float operationTime) {

    string outputString; 
    outputString += fileName;
    outputString += ",";
    outputString += opType;
    outputString += ",";
    outputString += compression;
    outputString += ",";
    outputString += dataType;
    outputString += ",";

    // filesize
    string sizeCheckFileName = fileName; 
    if (opType == "DE") {
        sizeCheckFileName.erase(sizeCheckFileName.length() - 4);
        sizeCheckFileName += ".";
        sizeCheckFileName += compression;
    } 
    string sizeString = to_string(getFileSize(sizeCheckFileName));
    size_t pos1 = sizeString.find(".");
    if (pos1 != std::string::npos)
        sizeString.erase(pos1, sizeString.length());
    outputString += sizeString;
    outputString += ",";

    // timetaken
    string timeString = to_string(operationTime);
    size_t pos2 = timeString.find(".");
    if (pos2 != std::string::npos)
        timeString.erase(pos2, timeString.length());

    outputString += timeString;
    outputString += "\n";

    std::ofstream outfile;
    outfile.open("OperationData.txt", std::ios_base::app);
    outfile << outputString;
    outfile.close();
}

float getFileSize(string fileName) {
    // TODO fix  

    ifstream testFile(fileName, ios::binary);
    const auto begin = testFile.tellg();
    testFile.seekg(0, ios::end);
    const auto end = testFile.tellg();
    const auto fsize = (end - begin);
    return fsize / 1024;

  

}
 
bool file_exists(string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}


