#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  execlp("cat", "cat" , "/etc/passwd" , 0);
  //execlp("grep", "grep", "root" , 0);
  
  return 0;
}
