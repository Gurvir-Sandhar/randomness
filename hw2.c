#include <stdio.h>
#define MAXCHAR 1000

int main(){

  char input[MAXCHAR];  
  //int total_letters;
 
  FILE *fp;
  fp = fopen("text.txt", "r");
  fgets(input, MAXCHAR, fp);
  fclose(fp);

  printf("%s", input);

  return(0);

}
