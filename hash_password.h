#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <create_hard_pass.h>


unsigned char* create_pass_hash(const char* str, unsigned char pass[32]){
    unsigned char* pass= SHA256((unsigned char*)str, strlen(str), pass);
    return pass;
}