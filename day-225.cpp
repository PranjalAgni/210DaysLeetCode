/*
  Valid Square


Given the coordinates of four points in 2D space, return whether the four points
could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two
integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles
(90-degree angles). Input points have no order.


*/

// Simple math based solution
class Solution {
   public:
    long long int dist(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3,
               vector<int>& p4) {
        return dist(p1, p2) > 0 and dist(p1, p2) == dist(p2, p3) and
               dist(p2, p3) == dist(p3, p4) and dist(p3, p4) == dist(p4, p1) and
               dist(p1, p3) == dist(p2, p4);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        return check(p1, p2, p3, p4) or check(p1, p3, p2, p4) or
               check(p1, p2, p4, p3);
    }
};