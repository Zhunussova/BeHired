//Reverse Integer 
//https://oj.leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int y = 0, sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }
        
        while(x){
            y = y*10 + x%10;
            x /= 10;
        }
        
        return y*sign;
    }
};