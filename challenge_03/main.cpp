#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string> 


using namespace std; 

int main() {

    ifstream file("input.txt");
    vector<string> invalids_passwords;
    vector<string>valids_passwords;
    
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string password;
        int min, max;
        char letter, dash;
        ss >> min >> dash >> max >> letter >> dash >> password;
        

        int count = 0;
        for (char c : password) {
            if (c == letter) {
                count++;
            }
        }

        if (count < min || count > max) {
            invalids_passwords.push_back(password);
        }else { 
            valids_passwords.push_back(password);
        }
    }

    cout << "Invalid passwords: " << invalids_passwords.size() << endl;
    cout << "Position 42: " << invalids_passwords[42] << endl;
    cout << "Valid passwords: " << valids_passwords.size() << endl;

    return 0; 
}