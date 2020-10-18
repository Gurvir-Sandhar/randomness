#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000

void vigenere_cipher(){

}

int main(){

  //array holding input string
  char input[MAXCHAR];

  //holds number of times a letter is seen in input array
  int letters[26];
  for(int i = 0; i < 26; i++){
    letters[i] = 0;
  }

  //total number of letters in input array 
  float total_letters = 0;

  //read in file contents into input array
  FILE *fp;
  fp = fopen("text.txt", "r");
  fgets(input, MAXCHAR, fp);
  fclose(fp);
 
  //count how many times a letter is seen in the input array
  for(int j = 0; j < strlen(input); j++){
    if(input[j] >= 97 && input[j] <= 122){
      letters[input[j]-97]++;
      total_letters++;
    }
  }
  
  printf("\n%s\n", input);
  printf("total letters: %f\n", total_letters);

  for(int k = 0; k < 26; k++){
    char letter = k + 97;
    float freq = letters[k] / total_letters;
    printf("%c: %f\n", letter, freq);
  }
  

  return(0);

}
