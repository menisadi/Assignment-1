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
  /*size_t indexStart = 0;
  size_t indexMiddle = 0;
  size_t indexEnd = 0;
  string tmpStr;*/
  for(std::vector<string>::iterator it = routes.begin(); it != routes.end(); ++it)
  {
    (*it).append("","");
    std::cout << *it << endl;
/*    tmpStr = *it;

    indexStart = 0;
    indexMiddle = tmpStr.find_first_of(',');
    while (indexEnd != string::npos)
    {
      indexEnd = tmpStr.find_first_of(',',indexMiddle+1);
      string nameOfRoadForComp = tmpStr.substr(indexStart,indexEnd);
      //for // search
      std::cout << nameOfRoadForComp << endl;
      //index0 = indexMiddle+4;
      indexStart=indexMiddle;
      indexMiddle=indexEnd; 
    } */
  }

  return 0;
}
