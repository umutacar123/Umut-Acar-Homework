#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string caesar_cipher(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key) % 26 + base;
        }
        result += c;
    }
    return result;
}

int main() {
    int key;
    cout << "Key: ";
    cin >> key;
    key = key % 26;

    cin.ignore();

    string plaintext;
    cout << "Plaintext: ";
    getline(cin, plaintext);

    string ciphertext = caesar_cipher(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
