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
  }
  cmds[i] = NULL;
  return cmds;
}

int main(){
  char line[100] = "ls -l --all -color";
  char *s1 = line;
  char ** args = parse_args( s1 );
  int i = 0;
  while (args[i]){
    printf("[%s]\n", args[i]);
    i++;
  }
  execvp(args[0], args);
  free(args);
}
