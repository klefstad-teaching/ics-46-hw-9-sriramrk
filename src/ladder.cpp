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
