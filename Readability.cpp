#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int count_letters(string text) {
    int letters = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }
    return letters;
}

int count_words(string text) {
    int words = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isspace(text[i]) || (i > 0 && isspace(text[i - 1]) && isalnum(text[i]))) {
            words++;
        }
    }
    if (!isspace(text.back())) {
        words++;
    }
    return words;
}

int count_sentences(string text) {
    int sentences = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    return sentences;
}

int calculate_grade(int letters, int words, int sentences) {
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

int main() {
    cout << "Text: ";
    string text;
    getline(cin, text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int grade = calculate_grade(letters, words, sentences);

    if (grade < 1) {
        cout << "Before Grade 1" << endl;
    } else if (grade >= 16) {
        cout << "Grade 16+" << endl;
    } else {
        cout << "Grade " << grade << endl;
    }

    return 0;
}
