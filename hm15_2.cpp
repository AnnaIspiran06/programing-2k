#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);  // Зчитуємо всю строку (речення)

    stringstream ss(sentence);  // Створюємо строковий потік для поділу речення на слова
    string word;
    vector<string> words;

    // Читаємо всі слова в реченні
    while (ss >> word) {
        words.push_back(word);
    }

    // Знаходимо довжину найдовшого слова
    size_t maxLength = 0;
    for (const auto& w : words) {
        if (w.length() > maxLength) {
            maxLength = w.length();
        }
    }

    // Виводимо всі слова, які мають максимальну довжину
    vector<string> longestWords;
    for (const auto& w : words) {
        if (w.length() == maxLength) {
            longestWords.push_back(w);
        }
    }

    // Виведення результату
    cout << "longest words: ";
    for (const auto& w : longestWords) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
