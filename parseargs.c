#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// test "ls -l --all -color"
char ** parse_args( char * line ) {
  char ** cmds = (char **) malloc(8 * sizeof(char *));
  char * p = line;
  int i;
  for (i = 0; p; i++ ) {
    cmds[i] = strsep( &p, " " );
    printf("[%s]\n", cmds[i]);
  }
  cmds[i] = NULL;
  return cmds;
}

int main(){
  char line[100] = "ls -l --all -color";
  char *s1 = line;
  char ** args = parse_args( s1 );
  execl("/bin/ls",args[0],NULL);
  // execvp("/bin/ls", args);
  free(args);
}
