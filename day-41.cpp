/*
Flood Fill


An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:

Input: 

image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.


Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

// Beats 98.87% of CPP solutions. Solved using DFS
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size() - 1;
        int cols = image[0].size() - 1;

        unordered_map<pair<int, int>, int, hash_pair> hashMap;
        queue<pair<int, int>> root;
        root.push(make_pair(sr, sc));

        hashMap[make_pair(sr, sc)] = 1;

        vector<pair<int, int>> possibleIndex;

        while (!root.empty()) {
            queue<pair<int, int>> current;
            pair<int, int> start = root.front();
            root.pop();
            int curr_row = start.first;
            int curr_col = start.second;
            int status = image[curr_row][curr_col];

            possibleIndex.push_back(start);

            vector<vector<int>> dirs{{curr_row - 1, curr_col}, {curr_row, curr_col - 1}, {curr_row + 1, curr_col}, {curr_row, curr_col + 1}};

            int idx = 0;
            while (idx < dirs.size()) {
                int t_row = dirs[idx][0];
                int t_col = dirs[idx][1];
                pair<int, int> temp = make_pair(t_row, t_col);
                if ((t_row >= 0 && t_row <= rows) && (t_col >= 0 && t_col <= cols)) {
                    if (hashMap[temp] == 0 && image[t_row][t_col] == status) {
                        current.push(temp);
                        hashMap[temp] = 1;
                    }
                }

                idx += 1;
            }

            while (!current.empty()) {
                pair<int, int> newp = current.front();
                current.pop();
                root.push(newp);
            }
        }

        for (int i = 0; i < possibleIndex.size(); i++) {
            pair<int, int> p = possibleIndex[i];
            image[p.first][p.second] = newColor;
        }

        return image;
    }
};