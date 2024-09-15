// Zigzag Conversion - Missing reverse functionality
function convert(s, numRows) {
    if (numRows === 1) return s;

    let rows = Array.from({ length: Math.min(numRows, s.length) }, () => '');
    let curRow = 0, goingDown = false;

    for (let c of s) {
        rows[curRow] += c;
        if (curRow === 0 || curRow === numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    return rows.join(''); // Implement reverse conversion functionality
}
