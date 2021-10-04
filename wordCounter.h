//
// Created by Алина on 03.10.2021.
//

#ifndef LAB0B_WORDCOUNTER_H
#define LAB0B_WORDCOUNTER_H

#include <map>
#include <string>

using namespace std;

class wordCounter {

    int countOfWords;
    map<string, int> words;

public:

    wordCounter();

    void readFile (string input);

    void sortingAndWriting (string output);

};


#endif //LAB0B_WORDCOUNTER_H
