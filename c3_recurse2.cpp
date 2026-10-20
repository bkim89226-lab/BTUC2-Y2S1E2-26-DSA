#include <iostream>
#include <vector>
using namespace std;


// vector of character set 
// String word 
// int n  : size of word 

void print_all_words(int n, const vector<char>& char_set, string& word){
    // base case 
    if(word.length() >= n){
        cout << word << "\n";
        return;
    }
    
    // Recursive call with Backtracking
    for (int i=0; i< char_set.size(); i++){
        word.push_back(char_set[i]);
        print_all_words(n, char_set, word);
        word.pop_back();
    }
}

void print_all_words_nonrepeat(int n, 
    const vector<char>& char_set, string& word,
    vector<bool>& used){

    // base case 
    if(word.length() >= n){
        cout << word << "\n";
        return;
    }
    
    // Recursive call with Backtracking
    for (int i=0; i< char_set.size(); i++){
        if(used[i] == false){
            used[i] = true;
            word.push_back(char_set[i]);
            print_all_words_nonrepeat(n, char_set, word, used);
            word.pop_back();
            used[i] = false;
        }
    }
}

bool puzzle_solved(string& word){
    // word =  3451278
    // n1 = 345
    // n2 = 312
    // m =  787 

    string n1 = word.substr(0, 3);
    string n2 = word.substr(0, 1) + word.substr(3, 2);
    string m = word.substr(5, 2) + word.substr(5, 1);

    if (std::stoi(n1) + std::stoi(n2) == std::stoi(m) ) return true;
    else return false;
}

void solve_puzzle(int n, 
    const vector<char>& char_set, string& word,
    vector<bool>& used, std::vector<std::string>& all_solutions){

    // base case 
    if(word.length() >= n){
        // cout << word << "\n";
        if(puzzle_solved) {
            all_solutions.push_back(word);
        }
        return;
    }
    
    // Recursive call with Backtracking
    for (int i=0; i< char_set.size(); i++){
        if(used[i] == false){
            used[i] = true;
            word.push_back(char_set[i]);
            print_all_words_nonrepeat(n, char_set, word, used);
            word.pop_back();
            used[i] = false;
        }
    }
}


int main(){

    vector<char> K = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9'};
    int n = 7;
    string word;
    vector<bool> used(K.size(), false);

    //print_all_words(n, K, word);
    print_all_words_nonrepeat(n, K, word, used);

}