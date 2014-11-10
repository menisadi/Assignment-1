// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main (void) {
  // read rouds to vector
  string line;
  ifstream myfile ("Roads.conf");
  vector<string> roadsName;
  vector<int> roadsLength;
  vector<int> roadsCount;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      int index = line.find_first_of(',');
      index = line.find_first_of(',',index + 1);
      string name = line.substr(0,index - 1);
      int length = atoi(line.substr(index+1,line.length()).c_str());
      roadsName.push_back(name);
      roadsLength.push_back(length);
      roadsCount.push_back(0); // initialize count for specipic rouad
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  //read routs to vector
  ifstream myfile2 ("Routes.conf");
  vector<string> routes;
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
    routes.push_back(line);
    }
    myfile2.close();
  }
  else cout << "Unable to open file";

  // for each route search for rouds in it, and add 1 to count
  unsigned int index0 = 0;
  unsigned int index1 = 0;
  unsigned int index2 = 0;
  string tmpStr;
  for(std::vector<string>::iterator it = routes.begin(); it != routes.end(); ++it)
  {
    //std::cout << *it << endl;
    tmpStr = *it;

    index0 = 0;
    index1 = tmpStr.find_first_of(',');
    while (index2 != string::npos)  //someting go worng in this "if"
    {
      index2 = tmpStr.find_first_of(',',index1+1);
      string nameOfRoadForComp = tmpStr.substr(index0,index2);
      //for // search
      std::cout << nameOfRoadForComp << endl;
      index0 = index1+4;
      index1=index2;
    }
  }

  return 0;
}