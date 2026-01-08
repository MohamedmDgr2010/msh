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


namespace exe{
  using namespace std;
  int exec(string cmd,vector<string> args);
  int command(string cmd,vector<string> args);
  int prog(string prog,vector<char*> args);
}// namespace excuter