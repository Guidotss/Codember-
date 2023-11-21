#include<iostream>
#include<fstream>
#include<istream>
#include<vector>
#include<string> 

using namespace std; 

int main() {

    ifstream file("input.txt");
    vector<char> symbols;

    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line; 
    while (getline(file, line)) {
        for (char c : line) {
            symbols.push_back(c);
        }
    }

    int initial_value = 0;
    string result = "";

    for (int i = 0; i < symbols.size(); i++) {
        if(symbols[i] == '#') { 
            initial_value += 1; 
        }
        else if(symbols[i] == '@') {
            initial_value -= 1; 
        }
        else if(symbols[i] == '*') {
            initial_value *= initial_value;
        }
        else if(symbols[i] == '&') {
            result += to_string(initial_value);
        }
    }

    cout << result << endl;

    return 0; 
}