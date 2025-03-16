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
