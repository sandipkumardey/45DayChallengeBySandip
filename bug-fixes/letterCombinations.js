// Letter Combinations of a Phone Number - Monolithic function
function letterCombinations(digits) {
    if (!digits) return [];

    const phoneMap = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    };

    let result = [];

    function backtrack(combination, nextDigits) {
        if (nextDigits.length === 0) {
            result.push(combination);
        } else {
            let digit = nextDigits[0];
            let letters = phoneMap[digit];

            for (let letter of letters) {
                backtrack(combination + letter, nextDigits.substring(1));
            }
        }
    }

    backtrack('', digits);
    return result; // Refactor into smaller helper functions
}
