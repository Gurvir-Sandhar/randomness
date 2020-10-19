#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXCHAR 1000


int vigenere_cipher(char* input, char* k){
  int count = 0;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] >= 97 && input[i] <= 122){
      int temp = ( (input[i]-97) + k[i % strlen(k)] ) % 26 + 97;
      input[i] = temp;
      count++;
    }
  }
  return count;
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

  //print letter frequencies
  for(int k = 0; k < 26; k++){
    char letter = k + 97;
    float freq = letters[k] / total_letters;
    printf("%c: %f\n", letter, freq);
  }
  
  printf("\n%s\n", input);
  char plaintext[MAXCHAR];
  strcpy(plaintext, input);
  //get key
  char* k;
 // int length = 0;
 // while(length <= 0 || length > 4){
    printf("\nType a key that is 1-4 char long...\n");
    scanf("%s", k);
 // length = strlen(key);
 // printf("key length: %d", length);
  
  float count = vigenere_cipher(plaintext, k);

  printf("\n%s\n", plaintext);
  printf("cipher count %f\n", count);

  for(int i = 0; i < 26; i++){
    letters[i] = 0;
  }

  for(int i = 0; i < count; i++){
    letters[plaintext[i]-97]++;
  }

  for(int i = 0; i < 26; i++){
    char letter = i + 97;
    float freq = letters[i] / count;
    printf("%c: %f\n", letter, freq);
  }

  return(0);
}
