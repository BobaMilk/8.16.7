#include <iostream>
using namespace std;

// Example: crypt -d -kFEATHER encrypt.txt output.txt
// We just need what ever is after -k so in this case, "FEATHER"

int main(int avgc,const char* argv[]) //array[char userString[50]]
{
    bool dup = false;
    string key;
    string result = "";
    string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0;i < avgc;i++) { //Goes through the size of the array
        if (argv[i][0] == '-' && argv[i][1] == 'k') { //argv[i] is each word and then argv[i][0] is each character of the word
            key = &argv[i][2]; //Copies the key after the -k
            break; //Breaks out
        }
    }

    for (int i = 0;i < key.size();i++) { //Goes through each character of the key
        for (int j = 0;j < result.size();j++) { //Goes through each character of result. The first time it runs, result = "" so it won't run this loop because the size is 0.
            if (key[i] == result[j]) { //If they are the same then
                dup = true; //dup is set to true
                break;
            }
        }
        if (dup == false) {
            result.push_back(key[i]);
        }
        else {
            dup = false;
        }
    }

    string copy = result;
    dup = false;

    for (int i = letter.size()-1;i >= 0;i--) { //Runs the letters string backwards
        for (int j = 0;j < copy.size();j++) { //Goes through each character of the copy up till it finds a duplicate
            if (letter[i] == copy[j]) {
                dup = true;
                break;
            }
        }
        if (dup == false) {
            result.push_back(letter[i]);
        }
        else {
            dup = false;
        }
    }

    cout << result << endl;
}
