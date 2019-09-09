#ifndef TEXTPROCCESSOR_H
#define TEXTPROCCESSOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TextProccessor
{
public:
  TextProccessor();
  ~TextProccessor();
  vector<vector<int>> readText2Vector (string filename);
};

#endif // TEXTPROCCESSOR_H
