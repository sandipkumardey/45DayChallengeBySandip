#include <stdio.h>
#include <string.h>

#define max_len 100

int main() {
    printf("Enter the string (only in uppercase letters): ");
    char str[max_len],tmp;
    int len = 0;
    scanf("%s", str);
    tmp = str[0];
    while(tmp != ' ' && tmp != '\0'){
     tmp = str[len];
     len++;
    }
    len--;
    int i, j;
    int found = 1;  // Flag to check if changes were made

    while (found) {
        found = 0;
        i = 0;
        j = 0;
        
        while (i < len) {
            if (i < len - 1 && str[i] == 'A' && str[i + 1] == 'B') {
                i += 2;
                found = 1;
            } else if (i < len - 1 && str[i] == 'C' && str[i + 1] == 'D') {
                i += 2;
                found = 1;
            } else {
                str[j++] = str[i++];
            }
        }
        str[j] = '\0';  
        len = j;        
    }
    printf("The final length of the string is: %d", len);
}
