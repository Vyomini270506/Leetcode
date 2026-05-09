class Solution {
public:
    string intToRoman(int num) {
        string s;
        int x = to_string(num).size();
        int y = x - 1;
        while(y >= 0) {
            int div = pow(10, y);
            int r = num / div;
            if(y == 3) {
                while(r--) s += "M";
            }
            else if(y == 2) {
                if(r <= 3) {
                    while(r--) s += "C";
                }
                else if(r == 4) {
                    s += "CD";
                }
                else if(r <= 8) {
                    s += "D";
                    while(r-- > 5) s += "C";
                }
                else {
                    s += "CM";
                }
            }

            else if(y == 1) {

                if(r <= 3) {
                    while(r--) s += "X";
                }
                else if(r == 4) {
                    s += "XL";
                }
                else if(r <= 8) {
                    s += "L";
                    while(r-- > 5) s += "X";
                }
                else {
                    s += "XC";
                }
            }

            else {

                if(r <= 3) {
                    while(r--) s += "I";
                }
                else if(r == 4) {
                    s += "IV";
                }
                else if(r <= 8) {
                    s += "V";
                    while(r-- > 5) s += "I";
                }
                else {
                    s += "IX";
                }
            }

            num %= div;
            y--;
        }

        return s;
    }
};