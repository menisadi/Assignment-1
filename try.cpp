// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  // read rouds to vector
  string line; 
  ifstream myfile ("Roads.conf");
  vector<string> roads;
  vector<int> roadsCout;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      roads.push_back(line); 
      roadsCout.push_back(0); // initialize count for specipic rouad
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 

  //read routs to vector
  myfile ("Routs.conf");
  vector<string> roats;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      roats.push_back(line); 
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  
  // for each route search for rouds in it, and add 1 to count 
  for(std::vector<string>::iterator it = roats.begin(); it != roads.end(); ++it)
  {
    int index = *it.find_first_of(',');
    string tmp = roads.substr(index+1,roats.lenght());
    index = tmp.find_first_of(',');
    string roadName = tmp.substr(index+1,roats.lenght());
  }
      
  return 0;
}