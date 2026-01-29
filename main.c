#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Here it's just a DEMO password, puts your password to check  */

char* password = "pedroMucelin32!";

void helper(){
  printf("good luck budy");
}

int check_password(char* password){
  if(password == NULL || strlen(password) == 0){
    printf("Sua senha esta invalida.\n");
    return 0;
  }
  if(strlen(password) < 6){
    printf("Your password len it's to low\n");
    return 0;
  }
  const char* symbols = "!@#$%^&*-+";
  int check_upper = 0;
  int check_low = 0;
  int check_symbol = 0;
  int check_number = 0;
  int i;
  for(i = 0; i<(strlen(password) - 1); i++){
    if(isupper(password[i])){
      check_upper++;
    }else if(islower(password[i])){
      check_low++;
    } else if(isalnum(password[i])){
      check_symbol++;
    }else if(isdigit(password[i])){
      check_number++;
    }
  }
  if(check_upper <= 2 || check_low <= 2 || check_symbol <= 1 || check_number <= 2){
    printf("Sorry but your password don't pass in the check\n");
  }else{
    printf("- YES! your password passed in the checker");
  }
  return 1;
}


int main(int argc, char* argv[], char** password){
  printf(" passchecker\n");
  printf(" - your password need more than 8 of len and 2 Upper cases + 2 Lower cases + 1 symbols and 2 numbers\n");
  printf("go ahead: \n");
  if(argc == 1){
    helper();
    return 0;
  }
  if(strcmp(argv[1], "help") == 0){
    helper();
    return 0;
  }
  check_password(*password);
}
