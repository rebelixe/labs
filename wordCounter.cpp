#include "wordCounter.h"
#include <fstream>
#include <list>
#include <map>

using namespace std;

bool isLetter(char symbToCheck) {
    return (symbToCheck >= 'a' && symbToCheck <= 'z') || (symbToCheck >= 'A' && symbToCheck <= 'Z');
}

bool isNumber(char symbToCheck) {
    return (symbToCheck >= '0' && symbToCheck <= '9');
}

bool compareFrequency(pair<string, int> &word1, pair<string, int> &word2) {

    return word1.second > word2.second;

}

wordCounter::wordCounter() {
    countOfWords = 0;
}

void wordCounter::readFile(string input) {

    ifstream fin;
    fin.open(input, fstream::in);

    string buffer;
    string currentWord;

    bool wordIsEnded = true;

    while ((getline(fin, buffer))) {   // != 0

        for (int i = 0; i < buffer.size(); i++) {

            if ((isLetter(buffer[i])) || (isNumber(buffer[i]))) {
                currentWord += buffer[i];

                if (wordIsEnded) {
                    countOfWords++;
                    wordIsEnded = false;
                }


            } else if (!wordIsEnded) {
                words[currentWord]++;
                currentWord = "";
                wordIsEnded = true;
            }
        }
    }

    fin.close();

}

void wordCounter::sortingAndWriting(string output) {
    map<string, int>::iterator i;
    pair<string, int> pairToWrite;
    list<pair<string, int>> listOfWords;

    for (i = words.begin(); i != words.end(); i++) {
        pairToWrite.first = i->first;
        pairToWrite.second = i->second;
        listOfWords.push_back(pairToWrite);
    }
    listOfWords.sort(compareFrequency);


    ofstream fout;
    fout.open(output, fstream::out);

    list<pair<string, int>>::iterator iq;

    double freqInPercents;

    for (iq = listOfWords.begin(); iq != listOfWords.end(); iq++) {

        freqInPercents = ((double)iq->second / (double)countOfWords) * 100;

        fout << iq->first << ", " << iq->second << ", " << freqInPercents << "%" << endl;
    }

    fout.close();
}

