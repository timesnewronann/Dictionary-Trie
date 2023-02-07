#include <iostream>
#include <fstream>
#include "dictionary.h"
#include <cstring>
#include "string.h"
using namespace std;

// RONAN BORJA 825164880
/*
In C++, use std::ifstream and std::getline.
• std::ifstream dictstream(filepath); // open file for parsing
• std::string line;
• // iterate over dictionary file line by line
• while (std::getline(dictstream, line))
*/

int main(int argc, char **argv)
{

    trieNode *root = new trieNode();

    // check if the parameters will be the proper amount we need
    if (argc != 3)
    {
        cout << "Incorrect parameters passed" << endl;
    }
    std::string line;

    // file path passed to the text file
    // open file for parsing
    std::ifstream dictstream(argv[1]);
    std::ifstream dictstream2(argv[2]);

    // delimiter
    const char *delimiters = "\n\r !\"#$%&()*+,./0123456789:;<=>?@[\\]^`{|}~";

    // read through line by line
    while (std::getline(dictstream, line))
    {
        // char *l = const_cast<char *>(line.c_str());
        char *word = strtok(const_cast<char *>(line.c_str()), delimiters);
        // tokenizer was in the wrong spot
        while (word != nullptr)
        {
            root->insert(word);
            word = strtok(NULL, delimiters);
        }
        // at the end of the while loop
        // line = ifstring,
    }

    // searching line
    while (std::getline(dictstream2, line))
    {
        // char *l = const_cast<char *>(line.c_str());
        // char *p = strtok(l, delimiters);
        char *word = strtok(const_cast<char *>(line.c_str()), delimiters);
        while (word != nullptr)
        {
            int count = 0;
            root->findEndingNodeOfAStr(word)->countWordsStartingFromANode(count);
            std::cout << word << " " << count << std::endl;
            word = strtok(NULL, delimiters);
        }

        // at the end of the while loop
        // line = ifstring,
    }

    // if opens successfully
    /* if(dictsteam.is_open())
     {
         do
         {
             dictsteam >>num;
             if(!dictsteam.fail())
             {
                 count++;
                 sum += num;
             }
         } while (!dictsteam.fail());
         dictsteam.close();

         cout << "Count: " << count << endl;
         cout << "Sum: " << sum << endl;

     }
     //error message
     else
     {
          cout<< "Could not open the file" << endl;
     }
     std::string line;
     */
}