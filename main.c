#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main();
char ** parse_args(char * line);
void print_arr(char ** arr);

int main(){

  char line[100] = "ls -a -l";
  char **args = parse_args(line);
  execvp(args[0],args);
  return 0;
}

char ** parse_args(char * line){
  int i;
  int size = 0;
  char ** args = calloc(6,sizeof(char*));
  args[0] = strsep(&line," ");
  for (i = 1; i < 5 && args[i-1]; i++){
    args[i] = strsep(&line," ");
    size++;
  }
  args[size] = NULL;
  return args;
}
