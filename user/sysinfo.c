#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct sysinfo{
  long uptime;            // Seconds since boot
  unsigned long totalram; // Total usable main memory size
  unsigned long freeram;  // Available memory size
  unsigned short procs;   // Number of current processes
};


int main(int argc,char **argv){
  struct sysinfo s;
  //fprintf(2, "uptim:%d\n",s.uptime);
  if(sysinfo(&s)){
    fprintf(2, "ERROR");
    exit(1);
  }
  else{
    
    fprintf(2, "uptime:%d\ntotalram:%d\nfreeram:%d\nprocs:%d\n",s.uptime,s.totalram,s.freeram,s.procs);
  }
    
  
  exit(0);
}






