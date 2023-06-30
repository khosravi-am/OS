#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"



// allocate more than half of physical memory,
// then fork. this will fail in the default
// kernel, which does not support copy-on-write.
void
test()
{
  uint64 phys_size = PHYSTOP - KERNBASE;
  int sz = (phys_size / 3) * 2;

  printf("simple: ");
  // allocate 2/3 of physical memory using sbrk
  char *p = sbrk(sz);
  if(p == (char*)0xffffffffffffffffL){
    printf("sbrk(%d) failed\n", sz);
    exit(-1);
  }

    // write in every page of allocated memory
  for(char *q = p; q < p + sz; q += 4096){
    *(int*)q = getpid();
  }
// fork
  int pid = fork();
  if(pid < 0){
    printf("fork() failed\n");
    exit(-1);
  }
    // exit in child
  if(pid == 0)
    exit(0);
// wait in parent
  wait(0);

  if(sbrk(-sz) == (char*)0xffffffffffffffffL){
    printf("sbrk(-%d) failed\n", sz);
    exit(-1);
  }

  printf("ok\n");
}

int
main(int argc, char *argv[])
{
  test();

  // check that the first simpletest() freed the physical memory.
  test();
  printf("COW test passed\n");

  exit(0);
}