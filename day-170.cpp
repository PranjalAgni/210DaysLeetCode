/*
    Robot Bounded In Circle


On an infinite plane, a robot initially stands at (0, 0) and faces north.  The
robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the
robot never leaves the circle.



Example 1:

Input: "GGLLGG"
Output: true
Explanation:
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to
(0,0). When repeating these instructions, the robot remains in the circle of
radius 2 centered at the origin. Example 2:

Input: "GG"
Output: false
Explanation:
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation:
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...


Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}

*/

// Simple solution to solve the problem
class Solution {
   public:
    bool isRobotBounded(string instructions) {
        unordered_map<char, pair<char, char>> dir{{'N', {'W', 'E'}},
                                                  {'S', {'E', 'W'}},
                                                  {'E', {'N', 'S'}},
                                                  {'W', {'S', 'N'}}};

        unordered_map<char, pair<int, int>> moves{
            {'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

        int i = 0, j = 0;

        char facing = 'N';

        for (auto c : instructions) {
            if (c == 'L') {
                facing = dir[facing].first;
            }

            else if (c == 'R') {
                facing = dir[facing].second;
            }

            else if (c == 'G') {
                i += moves[facing].first;
                j += moves[facing].second;
            }
        }

        if (i == 0 and j == 0) {
            return true;
        }

        return facing != 'N';
    }
};