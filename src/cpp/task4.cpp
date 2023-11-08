#include <iostream>
#include <string>
#include <algorithm>
#include <set>

int main() {
    int x;
    std::cout << "Enter the number of strings: ";
    std::cin >> x;

    std::set<char> letters;
    for (int i = 0; i < x; ++i) {
        std::string str;
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> str;

        for (char ch : str) {
            if (islower(ch)) {
                letters.insert(ch);
            }
        }
    }

    std::string sortedString;
    for (char ch : letters) {
        sortedString += ch;
    }

    std::sort(sortedString.begin(), sortedString.end());

    std::cout << "Final string containing sorted letters: " << sortedString << std::endl;

    return 0;
}
