#include <stdio.h>
#include <string.h>

#define max_str 100
#define max_len 100

void longestCommonPrefix(char strs[][max_len], int n) {
    if (n == 0) {
        printf("\n-1\n");
        return;
    }

    char prefix[max_len];
    strcpy(prefix, strs[0]);

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (strs[i][j] == prefix[j] && strs[i][j] != '\0') {
            j++;
        }
        prefix[j] = '\0'; 

        if (prefix[0] == '\0') {
            printf("-1\n");
            return;
        }
    }
    printf("%s\n", prefix);
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("-1\n");
        return 0;
    }

    char strs[max_str][max_len];
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
    }

    longestCommonPrefix(strs, n);
    return 0;
}
