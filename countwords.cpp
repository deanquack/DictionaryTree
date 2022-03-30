/*CS480, Spring 2022
Assignment #1, Dictionary Tree
FILE: countwords.cpp
Dean Quach, cssc1445
Copyright (c) 2022 Dean Quach. All rights reserved.
*/

#include "dicttree.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "string.h"
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char** argv){ //For reading a text file line by line

    if(argc < 3){//checks if there are at least two arguments, dictionarysource.txt and another .txt file
        printf("not enough paramters");
        return 1;
    }

    //this is for the dictionarysource.txt file
    std::ifstream dictstream(argv[1]); // open file for parsing
    std::string line;
    dictNode* dictionaryNode = node(false); 

    const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~"; //this is needed for parsing the testfile

    
    char ptrArr[300]; //for dictionary
    char *c;

    //this is for tokenizing and add the entire dictionary line by line
    char *word = strtok(ptrArr, delimiters);
    while (std::getline(dictstream, line)){ // iterate over dictionary file line by line, using a char array
        //printf("%s \n", line.c_str());
        add(dictionaryNode, line.c_str());
    }
    //this is for the entire testfile
    FILE *testFile = fopen(argv[2], "r");
    std::ifstream testStream(argv[2]);
    std::string test;
    char stream[150]; //this is an array of chars held by the testfiles

    if (testFile == NULL){//checks if the test file doesn't exist
        printf("this test file doesn't exist", argv[2]);
        return 1;
    }
    while (std::getline(testStream, test)){ //iterate and insert the testfile words/characters
        int count = 0;
        if (fgets(stream, 150, testFile) == NULL){
            break;
        }  
        char *word = strtok(stream, delimiters);
        while (word != NULL){ //replace back with null after testing
            int count = dictionaryNode->isWord ? 1 : 0; //determines where the count variable should be 1 or 0
            dictNode *tmp = findEndingNodeOfAStr(dictionaryNode,word, line.c_str()); //initializes the word as 
            countWordsStartingFromANode(tmp, count);
            printf("%s %d\n", word, count);
            word = strtok(NULL, delimiters); //replace back with null after testing
            
        }
    }
    fclose(testFile); //closes the testfile after insertion 
}  

