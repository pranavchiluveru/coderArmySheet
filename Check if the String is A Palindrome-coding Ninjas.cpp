#include <bits/stdc++.h> 
//TC=O(Length(s)) Sc=O(1)
bool checkPalindrome(string str)
{
    // Write your code here.
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        // Skip non-alphanumeric characters from the start
        while (!isalnum(str[start]) && start < end) {
            ++start;
        }

        // Skip non-alphanumeric characters from the end
        while (!isalnum(str[end]) && start < end) {
            --end;
        }

        // Compare characters (case-insensitive)
        if (tolower(str[start]) != tolower(str[end])) {
            return false; // Characters are not equal, not a palindrome
        }

        // Move pointers towards each other
        ++start;
        --end;
    }

    return true; // All characters matched, it's a palindrome
}
