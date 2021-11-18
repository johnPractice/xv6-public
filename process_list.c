#include "types.h"
#include "stat.h"
#include "user.h"
#include "proc_info.h"

void process_list(void)
{
  int i, main_pid, cur_pid;
  int j;
  char *ptr;
  struct proc_info array[6];

  main_pid = getpid();
  fork();
  fork();
  fork();
  fork();
  fork();

  cur_pid = getpid();
  ptr = (char *)malloc(((10000 + cur_pid) * cur_pid) * sizeof(char));
  memset(ptr, 'a', (10000 + cur_pid) * cur_pid);

  if (cur_pid == main_pid)
  {
    for (j = 0; j < 10000; j++)
      ;
    capture_process(6, array);

    for (i = 0; i < 6; i++)
      printf(1, " pid: %d, memsize: %d\n", array[i].pid, array[i].memsize);
  }
  else
  {
    for (j = 0; j < 10000000; j++)
      ;
  }

  while (wait() != -1)
    ;
}

int main(void)
{
  process_list();
  exit();
}