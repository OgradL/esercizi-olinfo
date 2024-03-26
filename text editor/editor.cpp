#include <iostream>
#include <vector>

using namespace std;

bool isBold(char ch) {
    return (ch == 'N' || ch == 'I');
}

bool isItalic(char ch) {
    return (ch == 'i' || ch == 'I');
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int length;
    cin >> length;
    vector<char> characters;
    for (int i = 0; i < length; i++) {
        char ch;
        cin >> ch;
        characters.push_back(ch);
    }

    int nitalic = 0;
    int nbold = 0;
    for (int i = 0; i < characters.size(); i++) {
        bool bold = isBold(characters[i]);
        bool italic = isItalic(characters[i]);
        bool boldprevious = false;
        bool italicprevious = false;
        if (i > 0) {
            boldprevious = isBold(characters[i - 1]);
            italicprevious = isItalic(characters[i - 1]);
        }
        if (bold && !boldprevious) {
            nbold++;
        }
        if (italic && !italicprevious) {
            nitalic++;
        }
    }
    cout << nitalic + nbold;
}
