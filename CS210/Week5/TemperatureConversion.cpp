#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Reads city names and temperatures from a file
void ReadFile(const std::string &filename, std::vector<string> &cities, std::vector<int> &temps);
// Writes city names and temperatures to a file
void WriteFile(const std::string &filename, std::vector<string> &cities, std::vector<int> &temps);
// Converts Fahrenheit temperatures to Celsius
std::vector<int> ConvertTemps(const std::vector<int> &temps);

int main()
{
    // Vectors to store city names and corresponding temperatures
    std::vector<string> cityNames;
    std::vector<int> temperatures;

    // Reading city names and temperatures from a file (Fahrenheit)
    ReadFile("/Users/fiv/Documents/SHNU/CS210/Week5/FahrenheitTemperature.txt", cityNames, temperatures);

    // Converting temperatures from Fahrenheit to Celsius
    std::vector<int> CelciusTemps = ConvertTemps(temperatures);

    // Writing city names and converted Celsius temperatures to another file
    WriteFile("/Users/fiv/Documents/SHNU/CS210/Week5/CelciusTemperature.txt", cityNames, CelciusTemps);

    return 0;
}

// Function to read data from a file
// The function opens the file, reads city names and their corresponding temperatures, and stores them in vectors
void ReadFile(const std::string &filename, std::vector<string> &cities, std::vector<int> &temps)
{
    ifstream file; // Input file stream
    string city;   // Temporary variable to store city names
    int temp;      // Temporary variable to store temperatures

    file.open(filename); // Opens the file with the given filename

    // Checks if the file opened successfully
    if (!file.is_open())
    {
        std::cout << "Could not open target file." << endl; // Error message if the file couldn't open
        return;
    }

    // Reads the file until the end of the file or until a failure occurs
    while (!file.fail() && !file.eof())
    {
        // Reads the city and temperature from the file
        file >> city >> temp;
        cities.push_back(city);   // Adds the city to the cities vector
        temps.push_back(temp);    // Adds the temperature to the temps vector
    }

    // Checks if the loop exited because of an input failure before reaching EOF
    if (!file.eof())
    {
        std::cout << "Input failure before reaching end of file." << endl; // Error message for input failure
    }

    std::cout << "Reading file complete." << endl; // Confirmation message

    file.close(); // Closes the file
}

// Function to write data to a file
// It writes the city names and their corresponding temperatures to a file
void WriteFile(const std::string &filename, std::vector<string> &cities, std::vector<int> &temps)
{
    ofstream file; // Output file stream
    file.open(filename); // Opens the file with the given filename for writing

    // Checks if the file was successfully opened for writing
    if (!file.is_open())
    {
        std::cout << "Could not create file" << endl; // Error message if the file couldn't open for writing
        return;
    }

    // Loops through the cities and temperatures and writes them to the file
    for (size_t i = 0; i < cities.size(); ++i)
    {
        file << cities[i] << " " << temps[i] << endl; // Writes the city and temperature in each line
    }

    std::cout << "Writing file complete." << endl; // Confirmation message

    file.close(); // Closes the file
}

// Function to convert Fahrenheit temperatures to Celsius
// It takes a vector of Fahrenheit temperatures and returns a vector of Celsius temperatures
std::vector<int> ConvertTemps(const std::vector<int> &temps)
{
    size_t i; // Loop variable
    std::vector<int> newTemps; // Vector to store converted temperatures

    // Loops through each Fahrenheit temperature, converts it to Celsius, and adds it to newTemps
    for (i = 0; i < temps.size(); ++i)
    {
        int convertedTemp = static_cast<int>((temps[i] - 32) * (5.0 / 9.0)); // Fahrenheit to Celsius conversion formula
        newTemps.push_back(convertedTemp); // Adds the converted temperature to the vector
    }

    return newTemps; // Returns the vector of converted temperatures
}
