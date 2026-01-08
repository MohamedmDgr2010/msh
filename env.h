#pragma once
#include <unistd.h>   // for getcwd
#include <limits.h>   // for PATH_MAX
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sys/wait.h>
#include <cstring>
#include <sstream>

using namespace std;

namespace env{
  extern map<string,string> LocalEnv;
  int exportVar(string var,string val);
  int unexport(string var);
  // local
  int set(string var,string val);
  string get(string var);
}// namespace env