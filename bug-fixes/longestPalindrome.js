function longestPalindrome(s) {
  let maxLen = 0;
  let start = 0;

  for (let i = 0; i < s.length; i++) {
    let left = i - 1;
    let right = i + 1;
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      if (right - left + 1 > maxLen) {
        maxLen = right - left + 1;
        start = left;
      }
      left--;
      right++;
    }
    left = i;
    right = i + 1;
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      if (right - left + 1 > maxLen) {
        maxLen = right - left + 1;
        start = left;
      }
      left--;
      right++;
    }
  }

  return s.substring(start, start + maxLen);
}
