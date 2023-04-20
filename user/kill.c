#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
  int i;

  // if (argc < 0)
  // {
  //   fprintf(2, "usage: kill pid...\n");
  //   exit(1);
  // }
  fprintf(2, "arg:%d,argv:\n",argc);
  for (i = 1; i < argc; i++){
    fprintf(2, "i:%d,%s",i,argv[i]);
    kill(atoi(argv[i]));
  }
  exit(0);
}
