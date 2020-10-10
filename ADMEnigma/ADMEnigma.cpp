// ADMEnigma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinCoder.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <vector>

using namespace std; 

string validateArguments(int argc, char** argv);
void processArguments(int argc, char** argv);


// Make Object of each compression class
BinCoder binCoder;

 
//// ENUMS
//enum   operationtype { encode, decode } operationType;
//enum   compressiontype { bin, rle, dic, fror, dif }compressionType;

int main(int argc, char** argv)
{
    
    string validString = validateArguments(argc, argv); 
    
    if (validString != "VALID") 
        cout << validString << "\n";    
    else 
        processArguments(argc, argv); 

    // TODO: out message
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
    transform(fileName.begin(), fileName.end(), fileName.begin(), ::toupper);


    //  if (compression != "BIN" && compression != "RLE" && compression != "DIC" && compression !=  "FOR" && compression != "DIF")
    if (compression == "BIN") {
        binCoder.processArguments(operationType, dataType, fileName);
    }
    if (compression == "RLE") {
     //   binCoder.processArguments(operationType, dataType, fileName);
    }
    if (compression == "DIC") {
    //    binCoder.processArguments(operationType, dataType, fileName);
    }
    if (compression == "FOR") {
    //    binCoder.processArguments(operationType, dataType, fileName);
    }
    if (compression == "DIF") {
    //    binCoder.processArguments(operationType, dataType, fileName);
    }
    // std::cout << codeOption << "  " << compression << dataType << fileName << "\n";
}
 
// Returns "valid" if all arguments are succesful, returns the problematic argument if not
string validateArguments(int argc, char** argv)
{ 
    // validate amount of arguments
    if (argc != 5)
        return "Invalid count: # of arguments should be 4, not " +to_string (argc - 1);

    string operationType = argv[1];
    string compression = argv[2];
    string dataType = argv[3];
    string fileName = argv[4];

    // Make uppercase for easier comparison
    transform(operationType.begin(), operationType.end(), operationType.begin(), ::toupper);
    transform(compression.begin(), compression.end(), compression.begin(), ::toupper);
    transform(dataType.begin(), dataType.end(), dataType.begin(), ::toupper);
    transform(fileName.begin(), fileName.end(), fileName.begin(), ::toupper);

    // validate operation type
    if (operationType != "EN" && operationType != "DE")
        return "Invalid operation type: " + operationType;  

    // validate compression
    if (compression != "BIN" && compression != "RLE" && compression != "DIC" && compression !=  "FOR" && compression != "DIF")
        return "Invalid compression: " + compression + ". Please choose BIN, RLE, DIC, FOR, or DIF";

    // validate data type
    if (dataType != "INT8" && dataType != "INT16" && dataType != "INT32" && dataType != "INT64" && dataType != "STRING")
        return "Invalid DATA TYPE: " + dataType + ". Please choose INT8, INT16, INT32, INT64, or STRING";

    // validate filename 
     // TODO: check filename ditzy datzy probably dependent on operation type

    return "VALID";
}


