class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            swap(matrix[i][j], matrix[j][i]);
        int k;
    for (int i = 0; i < N; i++)
    {
        k = N-1;
        for (int j = 0; j < k; j++)
        {
            swap(matrix[i][j], matrix[i][k]);
            k--;
        }}
    }
};