// Matrix Zeroes - No tracking of zero count
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool firstRow = false, firstCol = false;
    int rows = matrix.size(), cols = matrix[0].size();

    // Check if first row has zeros
    for (int i = 0; i < cols; i++) {
        if (matrix[0][i] == 0) {
            firstRow = true;
            break;
        }
    }

    // Check if first column has zeros
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }

    // Use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero the marked rows and columns
    for (int i = 1; i < rows; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < cols; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero the first row/column if necessary
    if (firstRow) {
        for (int i = 0; i < cols; i++) matrix[0][i] = 0;
    }
    if (firstCol) {
        for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }

    // No return or tracking of zero counts yet
}
