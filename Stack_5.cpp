#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(const string& s) {
    stack<int> countStack;
    stack<string> resultStack;
    string currentString;
    int count = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            count = count * 10 + (ch - '0');
        }
        else if (ch == '[') {
            countStack.push(count);
            resultStack.push(currentString);
            count = 0;
            currentString.clear();
        }
        else if (ch == ']') {
            int repeatCount = countStack.top();
            countStack.pop();
            string lastString = resultStack.top();
            resultStack.pop();

            for (int i = 0; i < repeatCount; ++i) {
                lastString += currentString;
            }

            currentString = lastString;
        }
        else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string input1 = "3[a]2[bc]";
    string input2 = "3[a2[c]]";
    string input3 = "2[abc]3[cd]ef";

    cout << "Example 1: " << decodeString(input1) << endl;
    cout << "Example 2: " << decodeString(input2) << endl;
    cout << "Example 3: " << decodeString(input3) << endl;

    return 0;
}
