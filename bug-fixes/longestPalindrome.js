// Longest Palindromic Substring - Fails with full-string palindromes
function longestPalindrome(s) {
    let maxLen = 0;
    let start = 0;

    for (let i = 0; i < s.length; i++) {
        for (let j = i; j < s.length; j++) {
            let substring = s.substring(i, j + 1);
            let reversed = substring.split('').reverse().join('');

            if (substring === reversed && substring.length > maxLen) {
                maxLen = substring.length;
                start = i;
            }
        }
    }

    return s.substring(start, start + maxLen); // Fails for palindromes that span the entire string
}
