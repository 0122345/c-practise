#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isBinaryString(const char *str) {
     for (int i = 0; str[i] != '\0'; i++) {
          if (str[i] != '0' && str[i] != '1') {
           return 0;
          }
     }
     return 1;
}

void BinaryToHex(const char *binary, char *hex) {
   int len = strlen(binary);
   int remainder = len % 4;
   int paddedlen = len + (remainder ? 4 - remainder : 0);
   char paddedBinary[paddedlen + 1];

   memset(paddedBinary, '0', paddedlen - len);
   strcpy(paddedBinary + (paddedlen - len), binary);
   paddedBinary[paddedlen] = '\0';

   int hexIndex = 0;
   for (int i = 0; i  < paddedlen; i += 4) {
     int value = 0;
     for (int j = 0; j < 4; j ++) {
       value = value * 2 + (paddedBinary[i + j] - '0');
     }
     if (value < 10) {
          hex[hexIndex++] = '0' + value;
     } else {
          hex[hexIndex++] = 'A' + (value - 10);
     }
   
   }
   hex[hexIndex] = '\0';
   
}


int main() {
     char binary[100];
     char hex[25];

     printf("Enter a binary string: ");
     scanf("%s", binary);

     if (!isBinaryString(binary)) {
          printf("Error: Input contains non-binary characters. \n");
          return 1;
     }

     BinaryToHex(binary, hex);

     printf("Hexadecimal equivalent: %s\n", hex);

     return 0;
}