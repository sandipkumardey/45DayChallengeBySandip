// Longest Substring without Repeating Characters - O(n²)
int lengthOfLongestSubstring(char * s) {
    int maxLen = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int visited[256] = {0}; // ASCII characters
        for (int j = i; j < len; j++) {
            if (visited[s[j]]) break;
            visited[s[j]] = 1;
            maxLen = fmax(maxLen, j - i + 1); // O(n²) complexity
        }
    }
    return maxLen;
}
