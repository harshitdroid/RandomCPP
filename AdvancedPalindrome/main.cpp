#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    // Remove punctuation and convert to lowercase
    string cleaned = "";
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    // Check if cleaned string is a palindrome
    int left = 0;
    int right = cleaned.length() - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a word or phrase: ";
    getline(cin, input);
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }
    return 0;
}
