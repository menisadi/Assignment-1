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
      string name = line.substr(0,index);
      string sLength = line.substr(index+1,line.length()-index);
      // std::cout << sLength << endl;
      int length = atoi(sLength.c_str());
      // std::cout << length << endl;
      roadsName.push_back(name);
      // std::cout << name << endl;
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
  size_t indexStart = 0;
  size_t indexMiddle = 0;
  size_t indexEnd = 0;
  string tmpStr;
  string nameOfRoadForComp;
  
  for(std::vector<string>::iterator it = routes.begin(); it != routes.end(); ++it)
  {
    (*it).append(",");
    //std::cout << *it << endl;
    tmpStr = *it;

    indexStart = 0;
    indexMiddle = tmpStr.find_first_of(',') + 1;
    
    while (indexEnd < tmpStr.length())
    {
      indexEnd = tmpStr.find_first_of(',',indexMiddle) + 1;
      //std::cout << indexStart << " " << indexMiddle << " " << indexEnd  << endl;
      nameOfRoadForComp = tmpStr.substr(indexStart,(indexEnd - indexStart) - 1);
      
      // search nameOfRoadForComp in roadsName and add 1 to the corresponding roadsCount
      bool found = false;
      size_t roadIndex = 0;
      while ((!found) && (roadIndex < roadsName.size())) {
	if (roadsName[roadIndex] == nameOfRoadForComp)
	  found = true;
	//std::cout << roadIndex << endl;
	++roadIndex;
      }	// at the end roadIndex wiil be equal to the corresponding index + 1;
      roadIndex--;
      roadsCount[roadIndex]++;
      std::cout << roadIndex << endl;
      std::cout << roadsCount[roadIndex] << endl;
      
      std::cout << nameOfRoadForComp << endl;
      indexStart = indexMiddle;
      indexMiddle = indexEnd; 
    }
  }

  return 0;
}
