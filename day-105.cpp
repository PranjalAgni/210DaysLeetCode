/*
Angle Between Hands of a Clock

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 12, minutes = 30
Output: 165

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5

Example 4:
Input: hour = 3, minutes = 15
Output: 7.5

Example 5:
Input: hour = 12, minutes = 0
Output: 0
*/

class Solution {
   public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour * 30 + minutes * 0.5);
        double minutesAngle = minutes * 6;
        double angleOne = fabs(hourAngle - minutesAngle);
        double angleTwo = 360 - angleOne;

        return min(angleOne, angleTwo);
    }
};