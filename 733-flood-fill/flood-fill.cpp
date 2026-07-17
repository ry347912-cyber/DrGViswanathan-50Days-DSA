class Solution {
public:
    void dfs(int i, int j,
             vector<vector<int>>& image,
             int oldColor, int newColor,
             int n, int m) {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        if (image[i][j] != oldColor)
            return;

        image[i][j] = newColor;

        dfs(i - 1, j, image, oldColor, newColor, n, m);
        dfs(i + 1, j, image, oldColor, newColor, n, m);
        dfs(i, j - 1, image, oldColor, newColor, n, m);
        dfs(i, j + 1, image, oldColor, newColor, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;

        int n = image.size();
        int m = image[0].size();

        dfs(sr, sc, image, oldColor, newColor, n, m);
        return image;
    }
};
