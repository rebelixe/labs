#include <iostream>
#include "wordCounter.h"
#include <string>

int main(const int argc, char **argv) {

    wordCounter counter;
    const std::string &input = "input.txt";
    const std::string &output = "output.csv";

    counter.readFile(input);
    counter.sortingAndWriting(output);

    return 0;
}