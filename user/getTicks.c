#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,char **argv)
{
  int i;

  if (argc !=2){
    fprintf(2, "valid pid !!\nuse getTicks pid ");
    exit(1);
  }
  i= getTicks(atoi(argv[1]));
  fprintf(2, "ticks:%d\n",i);
  exit(0);
}
