#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* encrypt with signature, 'p' and 'h' */

void create_pass(char* strength_pass){
  const char *hex = "0123456789abcdef";
  int i;
  for(i = 0; i < 18; i++)
  {
    if(i == 1)
      {
        strength_pass[i] = 'p';
      }
    else if(i == 16)
    {
      strength_pass[i] = 'h';
    }else{
      strength_pass[i] = hex[rand() % 16];
    }
    strength_pass[19] = '\0';
  }
}
