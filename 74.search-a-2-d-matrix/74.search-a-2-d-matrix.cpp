class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowStart = 0, rowEnd = matrix.size()-1, rowMid;
        while (rowStart <= rowEnd) {
            rowMid = (rowStart + rowEnd) / 2;
            if (target < matrix[rowMid][0]) rowEnd = rowMid - 1;
            else if (target > matrix[rowMid].back()) rowStart = rowMid + 1;
            else break;
        }
        return binarySearch(matrix[rowMid], target);
    }
    bool binarySearch(vector<int> vec, int target) {
        int start = 0, end = vec.size()-1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (vec[mid] == target) return true;
            else if (vec[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};