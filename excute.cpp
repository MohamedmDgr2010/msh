#include "excute.h"
using namespace std;

map<string,function<int(vector<string>)>> commands;

bool is_cmd(string cmd){
  return std::find(commands.begin(),commands.end(),cmd)!=commands.end();
}
int exe::command(string cmd,vector<string> args){
  
    if(cmd=="cd")return 1;
    if(cmd=="ls")return 1;
    if(cmd=="cp")return 1;
    if(cmd=="mv")return 1;
    if(cmd== "touch")return 1;
    if(cmd== "export")return 1;
     if(cmd=="mkdir")return 1;
      if(cmd== "rm")return 1;
    if(cmd=="cat")return 1;
    
    
     return -1c;
  
  
}
int exe::prog(string prog,vector<char*> args){
  pid_t pid=fork();
  if(pid==0){
    execvp(const_cast<char*>(prog.c_str()),args.data());
  }else{
    waitpid(pid,NULL,0);
  }
  return 0;
}
int exe::exec(string cmd,vector<string> args){
  if(is_cmd(cmd))return command(cmd,args);
  vector<char*> arg;
  for(auto a:args)arg.push_back(const_cast<char*>(a.c_str()));
  arg.push_back(nullptr);
  return prog(cmd,arg);
  return -1;
}