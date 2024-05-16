#include <iostream>
#include <string>
#include <stack>

using namespace std;

void reverseWords(string input) {
    stack<string> s;
    string word;
    int i = 0;

    while (i < input.length()) {
        if (input[i] == ' ') {
            s.push(word);
            word = "";
        } else {
            word += input[i];
        }
        i++;
    }

    s.push(word);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    cout << "Original: " << input << endl;
    cout << "Reversed: ";
    reverseWords(input);
    cout << endl;

    return 0;
}
