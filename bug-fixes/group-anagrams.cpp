// Group Anagrams - Redundant sorting
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());  // Sorting done for each string
        anagramMap[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto it : anagramMap) {
        result.push_back(it.second);
    }

    return result;
}
