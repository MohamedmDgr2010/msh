#include "excute.h"
using namespace std;

map<string,function<int(vector<string>)>> commands;

bool is_cmd(string cmd){
  return commands.contains(cmd);
}
int exe::command(string cmd,vector<string> args){
     return -1;
}

int exe::prog(string prog,vector<char*> args){
args.push_back((char*)NULL);
  pid_t pid=fork();
  if(pid==0){
    execvp(const_cast<char*>(prog.c_str()),args.data());
  }else{
    waitpid(pid,NULL,0);
  }
  return 0;
}
bool exe::is_program(std::string cmd){
  return true;
}
int exe::exec(string cmd,vector<string> args){
  if(is_cmd(cmd))return command(cmd,args);
  vector<char*> arg;
  for(const auto& a:args)arg.push_back(const_cast<char*>(a.c_str()));
  arg.push_back(nullptr);
  if(is_program(cmd))return prog(cmd,arg);
  return -1;
}