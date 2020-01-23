
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"

void writeLED(string filename, string value){
   fstream fs;
   string path(LED3_PATH);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

int main()
{
	cout << "Starting the makeLED program" << endl;
    cout << "The current LED Path is: " << LED3_PATH << endl;
    cout << "Turning the LED on" << endl;
       
    writeLED("/brightness", "1");
  
   cout << "Finished the makeLED Program" << endl;
   return 0;
}
