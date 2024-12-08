#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);  // Зчитуємо рядок слів

    stringstream ss(sentence);  // Створюємо потік для розділення рядка на слова
    string word;
    vector<string> participles;  // Вектор для зберігання причастій

    // Читаємо всі слова
    while (ss >> word) {
        // Перевіряємо, чи закінчується слово на "ings"
        if (word.length() >= 4 && word.substr(word.length() - 4) == "ings") {
            participles.push_back(word);  // Додаємо до списку причастя
        }
    }

    // Виводимо знайдені причастя
    if (!participles.empty()) {
        cout << "Communion found: ";
        for (const auto& p : participles) {
            cout << p << " ";
        }
        cout << endl;
    }
    else {
        cout << "Причастя не знайдено." << endl;
    }

    return 0;
}
