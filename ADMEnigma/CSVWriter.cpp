#include "CSVWriter.h"
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

using namespace std;

void CSVWriter::writeInt8(vector<__int8> givenVector, string fileName)
{ 

// Create an output filestream object
    std::ofstream myFile(fileName);
     

    // Send data to the stream
    for (int i = 0; i < givenVector.size(); ++i)
    {
        myFile << givenVector.at(i) << "\n";
    }

    // Close the file
    myFile.close();
}

void CSVWriter::writeInt16(vector<__int16> givenVector, string fileName)
{
 
}

void CSVWriter::writeInt32(vector<__int32> givenVector, string fileName)
{
	 
}

void CSVWriter::writeInt64(vector<__int64> givenVector, string fileName)
{
	 
}

void CSVWriter::writeString(vector<string> givenVector, string fileName)
{
	 
}
