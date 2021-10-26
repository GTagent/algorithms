class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int p = image[sr][sc];
        image[sr][sc] = newColor;
        for(int i = 0; i < dir.size(); ++i){
            int nr = sr + dir[i][0];
            int nc = sc + dir[i][1];
            if(nr >=0 && nr < image.size() && nc >=0 && nc < image[0].size() && image[nr][nc] == p){
                floodFill(image, nr, nc, newColor);
            }
        }
        return image;
    }
};