#include <stddef.h>
#include <string.h>

char *rot13(const char *src)
{
  int len = strlen(src);
  int algo = 0;
  char *s = (char *)malloc((len+1)*sizeof(char));
  
  for(int i = 0; i < len; i++){  // ok
    if(src[i] <= 'z' && src[i] >= 'n'){ 
      algo = src[i]+13 - 'z';
      algo = 'a' + (algo-1);
      s[i] = algo;
    } else if (src[i] <= 'Z' && src[i] >= 'N'){
      algo = src[i]+13 - 'Z';
      algo = 'A' + (algo-1);
      s[i] = algo;
    } else if(src[i] >= '{' && src[i] <= '~' || src[i] >= '[' && src[i] <= '`' || src[i] >= ' ' && src[i] <= '@'){
      s[i] = src[i];
    } else if(src[i] <= 'M' && src[i] >= 'A' || src[i] <= 'm' && src[i] >= 'a'){
      s[i] = src[i]+13;
    } else {
      printf("Uh oh, something went wrong!\n");
    }
  }
  s[len] = '\0';
  printf("Result: %s\n", s);
  return s;
}

int main(){
    char *input[128];
    printf("Cipher String: ");
    scanf("%s", input);
    rot13(input);
    return 0;
}