
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

int main() {
   stringstream ss;
   string userInput;
   int value;

   // Failed conversion throws ios_base::failure
   ss.exceptions(ios::failbit);

   getline(cin, userInput);

   while (userInput != "end") {
      try {
         ss.str("");
         ss.clear();
         ss << userInput;
         ss >> value;

         // Division by zero throws runtime_error
         if (value == 0) {
            throw runtime_error("z");
         }

         cout << 60 / value << endl;
      }
      catch (ios_base::failure& excpt) {
         cout << "t" << endl;
      }
      catch (runtime_error& excpt) {
         cout << excpt.what() << endl;
      }
      getline(cin, userInput);
      ss.clear();
   }
   cout << "OK" << endl;

   return 0;
}
