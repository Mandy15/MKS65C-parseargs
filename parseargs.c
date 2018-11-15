#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// test "ls -l --all -color"
char ** parse_args( char * line ) {
  char ** cmds = (char **) malloc(6 * sizeof(char *));
  char * p = line;
  for (int i = 0; p; i++ ) {
    printf("[%s]\n", strsep( &p, " " ));
  }
  cmds[5] = NULL;
  return cmds;
}

 // get rid of the program name from argv
// char ** helper(char * arg[]){
//   for(int i = 0; i < sizeof(arg); i++){
//     arg[i] = arg[i+1];
//   }
//   return arg;
// }

int main(int argc, char * argv[]){
  // char str[100] = "";
  // // argv = helper(argv);
  // for(int i = 0; i < sizeof(argv); i++){
  //   str += *argv[i];
  // }

  char line[100] = "ls -l --all -color";
  char *s1 = line;
  // free(parse_args(s1));

  // for(int i = 0; i < sizeof(argv); i++){
  //   printf("argv[%d]: %s\n", i, argv[i]);
  // }
  // argv = helper(argv);
  // for(int i = 0; i < sizeof(argv); i++){
  //   printf("argv[%d]: %s\n", i, argv[i]);
  // }

  // argv = helper(argv);
  // char *s1 = *argv;
  // for(int i = 0; i < sizeof(s1); i++){
  //   printf("arg %d: %c\n", i, s1[i]);
  // }
  // free(parse_args(s1));

  char ** args = parse_args( s1 );
  // execvp(args[0], args);
  free(args);
}
