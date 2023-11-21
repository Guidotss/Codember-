#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::ifstream file("input.txt");

    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        words.push_back(word);
    }

    std::map<std::string, int> words_repeat_quantity;
    std::vector<std::string> insertion_order;

    for (const std::string& word : words) {
        words_repeat_quantity[word]++;
        if (std::find(insertion_order.begin(), insertion_order.end(), word) == insertion_order.end()) {
            insertion_order.push_back(word);
        }
    }

    for (const std::string& word : insertion_order) {
        std::cout << word << words_repeat_quantity[word]; 
    }

    return 0;
}

