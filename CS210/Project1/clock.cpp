#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// Function to get the time input from the user
vector<int> getTime()
{
    vector<int> clockArray(6); // Initialize a vector to store time components
    string time; // String to store the input time
    char formatType; // Variable to store the format type (12-hour or 24-hour)

    // Loop to get the format type from the user
    do
    {
        cout << "Type '1' for 12-Hour Clock Format." << endl;
        cout << "Type '2' for 24-Hour Clock Format." << endl;
        cin >> formatType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
    }
    while (formatType != '1' && formatType != '2'); // Repeat until valid input

    // If 12-hour format is selected
    if (formatType == '1')
    {
        // Loop to get the time in 12-hour format
        do
        {
            cout << "Please use this format for the meridiem distinction \"HH:MM:SS:AM\" or \"HH:MM:SS:PM\"." << endl;
            getline(cin, time);
        }
        while (time.size() != 11 || (time[9] != 'A' && time[9] != 'P') || time[10] != 'M' || time[2] != ':' || time[5] != ':' || time[0] > '2' || time[3] > '6' || time[6] > '6');
    }
    else // If 24-hour format is selected
    {
        // Loop to get the time in 24-hour format
        do
        {
            cout << "Please use this format for the 24-Hour Clock \"HH:MM:SS\":" << endl;
            getline(cin, time);
        }
        while (time.size() != 8 || time[2] != ':' || time[5] != ':' || time[0] > '2' || time[3] > '6' || time[6] > '6');
    }

    // Convert the input time string to integers and store in clockArray
    clockArray[0] = time[0] - '0';
    clockArray[1] = time[1] - '0';
    clockArray[2] = time[3] - '0';
    clockArray[3] = time[4] - '0';
    clockArray[4] = time[6] - '0';
    clockArray[5] = time[7] - '0';

    // If 12-hour format, add AM/PM distinction
    if (formatType == '1')
    {
        clockArray.resize(7); // Resize vector to accommodate AM/PM
        if (time[9] == 'A')
        {
            clockArray[6] = 0; // 0 at index 6 means AM
            clockArray[7] = 0;
        }
        else
        {
            clockArray[6] = 0; // 1 at index 7 means PM
            clockArray[7] = 1;
        }
    }
    else // If 24-hour format
    {
        clockArray.resize(7); // Resize vector to accommodate format type
        clockArray[6] = 1; // 1 at index 6 means 24-hour format
        clockArray[7] = 1;
    }

    return clockArray; // Return the time vector
}

// Function to check if the time is in 24-hour format
bool formatCheck24(vector<int>& timeVec)
{
    if (timeVec[6] == 1 && timeVec[7] == 1)
    {
        return true; // Return true if 24-hour format
    }
    else
    {
        return false; // Return false otherwise
    }
}

// Function to convert time to 12-hour format
void formatTo12(vector<int>& timeVec)
{
    int existingHours = timeVec[0] * 10 + timeVec[1]; // Calculate existing hours
    bool isPM = existingHours >= 12; // Check if it's PM

    if (existingHours == 0) {
        existingHours = 12; // Midnight case
    } else if (existingHours > 12) {
        existingHours -= 12; // Convert to 12-hour format
    }

    timeVec[1] = existingHours % 10;
    timeVec[0] = (existingHours / 10) % 10;

    // Ensure the vector has enough space
    if (timeVec.size() < 8) {
        timeVec.resize(8);
    }

    // Set AM/PM distinction
    if (existingHours == 12 && !isPM) {
        // Noon case
        timeVec[6] = 0;
        timeVec[7] = 1;
    } else if (existingHours == 12 && isPM) {
        // Midnight case
        timeVec[6] = 1;
        timeVec[7] = 1;
    } else {
        timeVec[6] = isPM ? 0 : 0;
        timeVec[7] = isPM ? 1 : 0;
    }
}

// Function to convert time to 24-hour format
void formatTo24(vector<int> &timeVec)
{
  if (timeVec[0] == 2 && timeVec[1] == 4)
  {
    timeVec[0] = 0;
    timeVec[1] = 0;
  }
}

// Function to check if the time is AM
bool meridiemDistinction(vector<int>& timeVec)
{
    cout << timeVec[6] << timeVec[7] << endl;
    if (timeVec[6] == 0 && timeVec[7] == 0)
    {
        return true; // Return true if AM
    }
    else
    {
        return false; // Return false otherwise
    }
}

// Function to output the time in both 12-hour and 24-hour formats
void outputTime(vector<int>& twelveHourClock, vector<int>& twentyFourHourClock, bool anteMeridiem)
{
    // Print the header
    cout << '\n' << endl;
    cout << setfill('*') << setw(26) << "" << setfill(' ') << setw(5) << "" << setfill('*') << setw(26) << "" << endl;
    cout << '*' << setfill(' ') << setw(6) << "" << "12-Hour Clock" << setw(6) << '*' << setw(6) << '*' << setw(6) << "" << "24-Hour Clock" << setw(6) << '*' << endl;

    // Print the time
    cout << '*' << setfill(' ') << setw(6) << ""
         << twelveHourClock[0] << twelveHourClock[1] << ":"
         << twelveHourClock[2] << twelveHourClock[3] << ":"
         << twelveHourClock[4] << twelveHourClock[5] << " "
         << (anteMeridiem ? "AM" : "PM")
         << setw(2) << ' ' << ""
         << setw(6) << '*' << setw(6) << '*' << setw(8) << ""
         << twentyFourHourClock[0] << twentyFourHourClock[1] << ":"
         << twentyFourHourClock[2] << twentyFourHourClock[3] << ":"
         << twentyFourHourClock[4] << twentyFourHourClock[5]
         << setw(9) << setfill(' ') << '*' << endl;

    cout << setfill('*') << setw(26) << "" << setfill(' ') << setw(5) << "" << setfill('*') << setw(26) << "" << endl;
    cout << '\n';
}

// Function to display the menu
void displayMenu()
{
  cout << setfill(' ') << setw(14) << "" << setfill('*') << setw(26) << "" << endl;
  cout << setfill(' ') << setw(14) << "" << "* " << "1 - Add One Hour" << setfill(' ') << setw(7) << "" << '*' << endl;
  cout << setfill(' ') << setw(14) << "" << "* " << "2 - Add One Minute" << setfill(' ') << setw(5) << "" << '*' << endl;
  cout << setfill(' ') << setw(14) << "" << "* " << "3 - Add One Second" << setfill(' ') << setw(5) << "" << '*' << endl;
  cout << setfill(' ') << setw(14) << "" << "* " << "4 - Exit Program" << setfill(' ') << setw(7) << "" << '*' << endl;
  cout << setfill(' ') << setw(14) << "" << setfill('*') << setw(26) << "" << endl;
  cout << '\n' << endl;
}

// Function to add one hour to the clock
void addOneHour(vector<int> &clockVector)
{
    int hours = clockVector[0] * 10 + clockVector[1];
    hours = (hours + 1) % 24; // Increment hour and handle overflow

    clockVector[1] = hours % 10;
    clockVector[0] = (hours / 10) % 10;

    // Ensure the vector has enough space
    if (clockVector.size() < 8) {
        clockVector.resize(8);
    }

    // Update AM/PM distinction
    if (hours < 12) {
        clockVector[6] = 0;
        clockVector[7] = 0; // AM
    } else if (hours < 24) {
        clockVector[6] = 0;
        clockVector[7] = 1; // PM
    } else {
        clockVector[6] = 1;
        clockVector[7] = 1; // 24-hour format
    }
}

// Function to add one minute to the clock
void addOneMinute(vector<int> &clockVector)
{
    int minutes = clockVector[2] * 10 + clockVector[3];
    minutes = (minutes + 1) % 60; // Increment minute and handle overflow

    clockVector[3] = minutes % 10;
    clockVector[2] = (minutes / 10) % 10;

    // If minutes overflow, increment the hour
    if (minutes == 0) {
        addOneHour(clockVector);
    }
}

// Function to add one second to the clock
void addOneSecond(vector<int> &clockVector)
{
    int seconds = clockVector[4] * 10 + clockVector[5];
    seconds = (seconds + 1) % 60; // Increment second and handle overflow

    clockVector[5] = seconds % 10;
    clockVector[4] = (seconds / 10) % 10;

    // If seconds overflow, increment the minute
    if (seconds == 0)
    {
        addOneMinute(clockVector);
    }
}

// Function to quit the program
void quitProgram(bool &running)
{
  running = false;
}

// Main loop to handle user input and update the clock
void mainLoop(vector<int> &clock1, vector<int> &clock2)
{
  bool running = true;

    while (running)
    {
      int userInput;
      displayMenu();
      cin >> userInput;

      do
      {
        bool AM = false;

        switch (userInput)
        {
          case 1:
          addOneHour(clock1);
          addOneHour(clock2);
          formatTo12(clock1);
          formatTo24(clock2);
          AM = meridiemDistinction(clock1);
          outputTime(clock1, clock2, AM);
          break;

          case 2:
          addOneMinute(clock1);
          addOneMinute(clock2);
          formatTo12(clock1);
          formatTo24(clock2);
          AM = meridiemDistinction(clock1);
          outputTime(clock1, clock2, AM);
          break;

          case 3:
          addOneSecond(clock1);
          addOneSecond(clock2);
          formatTo12(clock1);
          formatTo24(clock2);
          AM = meridiemDistinction(clock1);
          outputTime(clock1, clock2, AM);
          break;

          case 4:
          quitProgram(running);
          break;

          default:
          cout << "Please enter a valid input." << endl;
          displayMenu();
        }
      }
      while (userInput > 4 || userInput < 1);
    }
}

// Main function
int main()
{
    vector<int> timeInts = getTime(); // Get the initial time from the user
    bool format24 = formatCheck24(timeInts); // Check if the format is 24-hour

    vector<int> twelveHourClock;
    vector<int> twentyFourHourClock = timeInts;
    bool AM = meridiemDistinction(timeInts); // Determine if it's AM or PM

    if (format24)
    {
        twelveHourClock = timeInts;
        formatTo12(twelveHourClock); // Convert to 12-hour format if needed
    }
    else
    {
        twelveHourClock = timeInts;
    }

    outputTime(twelveHourClock, twentyFourHourClock, AM); // Output the initial time

    mainLoop(twelveHourClock, twentyFourHourClock); // Enter the main loop

    return 0;
}
