#include "ladder.h"

void error(string word1, string word2, string msg)
 
{
    cerr << "Error: " << message << "  " << word1 << word2 << endl;
}

void load_words(set<string> &word_list, const string& file_name) 
{
    ifstream file(file_name);
    if (!file) {
        cerr << "Canot open file: " << file_name << endl;
        exit(1);
    }
    string word;
    while (file >> word) 
    {
        word_list.insert(word);
    }
    file.close();
}

bool edit_distance_within(const string& str1, const string& str2, int d) 
{
    int str_len1 = str1.length()
    int str_len2 = str2.length();
    if (abs(str_len2 - str_len2) > 1) 
        return false; 
    int i = 0
    int j = 0
    int diff = 0;
    while (i < str_len1 && j < str_len2) 
    {
        if (str1[i] != str2[j]) {
            if (++diff > d) 
                return false;
            if (str_len1 > str_len2) 
                i++; 
            else if (str_len1 < str_len2) 
                j++; 
            else { 
                i++; 
                j++; 
            } 
        } 
        else {
            i++; 
            j++;
        }
    }
    return diff + (str_len1 - i) + (str_len2 - j) <= d;
}

bool edit_distance_within(const string& str1, const string& str2, int d) 
{
    int str_len1 = str1.length()
    int str_len2 = str2.length();
    if (abs(str_len2 - str_len2) > 1) 
        return false; 
    int i = 0
    int j = 0
    int diff = 0;
    while (i < str_len1 && j < str_len2) 
    {
        if (str1[i] != str2[j]) {
            if (++diff > d) 
                return false;
            if (str_len1 > str_len2) 
                i++; 
            else if (str_len1 < str_len2) 
                j++; 
            else { 
                i++; 
                j++; 
            } 
        } 
        else {
            i++; 
            j++;
        }
    }
    return diff + (str_len1 - i) + (str_len2 - j) <= d;
}

void print_word_ladder(const vector<string>& ladder) 
{
    if (ladder.empty()) 
    {
        cout << "No ladder found." << endl;
        return;
    }
    for (size_t i = 0; i < ladder.size(); ++i) 
    {
        cout << ladder[i];
        if (i < ladder.size() - 1) cout << " -> ";
    }
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}

