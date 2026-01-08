#include "env.h"

map<string,string> env::LocalEnv;
int env::exportVar(string var,string val){
    return setenv(var.c_str(),val.c_str(),1);
  }

int env::unexport(string var){
    return unsetenv(var.c_str());
  }
  
int env::set(string var,string val){
    try{
    LocalEnv.insert({var,val});
    return 0;
    }catch(...){
      return 1;
    }
  }
  string env::get(string var){
    
    if(LocalEnv.count(var))return LocalEnv[var];
    if(getenv(var.c_str()))return string(getenv(var.c_str()));
    throw var+": not found var \n";
    
  }