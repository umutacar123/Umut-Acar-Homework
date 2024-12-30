#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool check_key(string key) {
    if (key.length() != 26) {
        return false;
    }

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            return false;
        }
        for (int j = i + 1; j < 26; j++) {
            if (tolower(key[i]) == tolower(key[j])) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, string argv[]) {
    if (argc != 2) {
        cout << "Usage: ./substitution key" << endl;
        return 1;
    }

    string key = argv[1];
    if (!check_key(key)) {
        cout << "Key must contain 26 characters and no duplicates" << endl;
        return 1;
    }

    string plaintext;
    cout << "plaintext: ";
    getline(cin, plaintext);

    string ciphertext = plaintext;
    for (int i = 0; i < plaintext.length(); i++) {
        if (isupper(plaintext[i])) {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        } else if (islower(plaintext[i])) {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }

    cout << "ciphertext: " << ciphertext << endl;
    return 0;
}
