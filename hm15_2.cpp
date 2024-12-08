#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);  // ������� ��� ������ (�������)

    stringstream ss(sentence);  // ��������� ��������� ���� ��� ����� ������� �� �����
    string word;
    vector<string> words;

    // ������ �� ����� � ������
    while (ss >> word) {
        words.push_back(word);
    }

    // ��������� ������� ���������� �����
    size_t maxLength = 0;
    for (const auto& w : words) {
        if (w.length() > maxLength) {
            maxLength = w.length();
        }
    }

    // �������� �� �����, �� ����� ����������� �������
    vector<string> longestWords;
    for (const auto& w : words) {
        if (w.length() == maxLength) {
            longestWords.push_back(w);
        }
    }

    // ��������� ����������
    cout << "longest words: ";
    for (const auto& w : longestWords) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
