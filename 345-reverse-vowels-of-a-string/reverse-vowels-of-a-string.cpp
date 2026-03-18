class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string reverseVowels(string s) {
        int m = s.size();
        int l = 0;
        int r = m - 1;

        while (l <= r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
            }
            else if (isVowel(s[l]) && !isVowel(s[r])) {
                r--;
                continue;
            }
            else if (!isVowel(s[l]) && isVowel(s[r])) {
                l++;
                continue;
            }
            else {
                l++;
                r--;
            }
        }
        return s;
    }
};