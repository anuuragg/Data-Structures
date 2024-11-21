#include <stdio.h>
#include <string.h>

//Custom Funnctions;
//length;
int length(char str[]){
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  return i;
}

//copy
void copy(char dest[], char src[]){
  int i=0;
  while(src[i] != '\0'){
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

//upper
char* upper(char og_char[]){
  int i = 0;
  while(og_char[i] != '\0'){
    if(og_char[i] >= 'a' && og_char[i] <= 'z'){
      og_char[i] = og_char[i] - 32;
    }
    i++;
  }
  return og_char;
}

//lower
char* lower(char og_char[]){
  int i = 0;
  while(og_char[i] != '\0'){
    if(og_char[i] >= 'A' && og_char[i] <= 'Z'){
      og_char[i] = og_char[i] + 32;
    }
    i++;
  }
  return og_char;
}


//Concat
char*  concat(char dest[], char src[]){
  int i = 0;
  int dest_len = length(dest);
  int src_len = length(src);

  if(dest_len + src_len + 1 > 100){
    printf("Destination string is too small.\n");
    return NULL;
  }

  for(i=0; i <= dest_len; i++){
    dest[dest_len+i] = src[i];
  }
  return dest;
}


//Main Function;
int main(){
  //Inbuilt Functions;
  char a[10] = "hello";
  char b[10];
  char c[10] = "World!";
  int len = strlen(a);
  printf("length: %d\n", len);
  printf("copy: %s\n", strcpy(b, a));
  strcat(a, c);
  printf("cat: %s\n", a);

  int result = strcmp(a,c);
  printf("length: %d\n", result);
  if(result > 0){
    printf("a is greater\n");
  } else {
    printf("a is smaller\n");
  }

  // Custom Functions
  //length
  int l = length("strr");
  printf("%d\n", l);

  //copy
  char y[10] = "yellow";
  char z[10];
  copy(z, y);
  printf("%s\n", z);

  //upper
  char k[100] = "lower";
  printf("%s\n", upper(k));
  
  //lower
  char g[100] = "UPPER";
  printf("%s\n", lower(g));

  //concat
  char w[50] = "Hello";
  char q[50] = "World!";
  printf("%s\n", concat(w, q));
}
