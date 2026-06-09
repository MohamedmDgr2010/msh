#include <unistd.h>   // for getcwd
#include <limits.h>   // for PATH_MAX
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "env.h"
#include "excute.h"
#include <sys/wait.h>
#include <cstring>
using namespace std;

std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    std::string current;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (c == ' ' || c == '\t') {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        } 
        else if (c == '&' || c == '|' || c == '>' || c == '<') {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }

            // لدعم >> 
            if ((c == '>' || c == '<') && i+1 < line.size() && line[i+1] == c) {
                tokens.push_back(std::string(2, c));
                ++i;
            } else {
                tokens.push_back(std::string(1, c));
            }
        } else {
            current += c;
        }
    }

    if (!current.empty())
        tokens.push_back(current);

    return tokens;
}

vector<string> split(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string word;
    while (iss >> word) tokens.push_back(word);
    return tokens;
}

int main(){
  
  char cwd[PATH_MAX];
  string line,cmd;
  vector<string> tokens;
  vector<string> args;
  
  
  do{
    try{
    
    if(getcwd(cwd,sizeof(cwd))!=nullptr){
      cout<<cwd<<" $ ";
    }
    
    getline(cin,line);
    if(line.empty())continue;
    tokens=tokenize(line);
    for(auto& t:tokens){
      if(t[0]=='$'){
        t.erase(0,1);
        t=env::get(t);
      }
    }
    args=tokens;
    
    cmd=!tokens.empty() ? tokens[0]:"";
    if(cmd.empty())continue;
    cout << "command: " << cmd << endl;
cout << "args: ";
for (const auto& arg : args) {
    cout << arg << " ";
}
cout << endl; // لإنتاج سطر جديد في النهاية

    
    exe::exec(cmd,args);
    
    
  }
    catch(string e){
      cerr<<e<<endl;
    }
  }while(cmd!="exit");
}