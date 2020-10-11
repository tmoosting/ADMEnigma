#include "CSVReader.h"
#include <string>
#include <fstream>
#include <vector>
#include <utility>  
#include <stdexcept>  
#include <sstream>  


using namespace std;
 

template <typename T>
vector<T> CSVReader::readInt(string fileName) {
    vector<T> returnVector;
    ifstream file(fileName);
    string line;
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        //TODO :Add exception 
        T snazzyInt = (T)stoi(line);
        returnVector.push_back(snazzyInt);
    }
    file.close();
    return returnVector;
}

vector<__int8> CSVReader::readInt8(string fileName) {    
    vector<__int8> returnVector; 
    ifstream file(fileName);
    string line; 
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        //TODO :Add exception 
        __int8 snazzyInt = (__int8)stoi(line);
        returnVector.push_back(snazzyInt); 
    } 
    file.close();
    return returnVector;
}
vector<__int16> CSVReader::readInt16(string fileName) {
    vector<__int16> returnVector;
    ifstream file(fileName);
    string line;
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        //TODO :Add exception 
        __int16 snazzyInt = (__int16)stoi(line);
        returnVector.push_back(snazzyInt);
    }
    file.close();
    return returnVector;
}
vector<__int32> CSVReader::readInt32(string fileName) {
    vector<__int32> returnVector;
    ifstream file(fileName);
    string line;
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        //TODO :Add exception 
        __int32 snazzyInt = (__int32)stoi(line);
        returnVector.push_back(snazzyInt);
    }
    file.close();
    return returnVector;
}
vector<__int64> CSVReader::readInt64(string fileName) {
    vector<__int64> returnVector;
    ifstream file(fileName);
    string line;
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        //TODO :Add exception 
        __int64 snazzyInt = (__int64)stoi(line);
        returnVector.push_back(snazzyInt);
    }
    file.close();
    return returnVector;
}
vector<string> CSVReader::readString(string fileName) {
    ifstream file(fileName);
    vector<string> returnVector; 
    string line; 
    while (getline(file, line, '\n')) // there is input overload classfile
    {
        returnVector.push_back(line); 
    } 
    file.close();
    return returnVector;
}


std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;

    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ',')) {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({ colname, std::vector<int> {} });
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}