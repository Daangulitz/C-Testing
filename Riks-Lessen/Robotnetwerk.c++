#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <ranges>
#include <algorithm>

using namespace std;

int main() {
    ifstream MyReadFile("/home/daantje/Documents/Unreal Projects/C-Testing/Riks-Lessen/input.txt");
    if (!MyReadFile) {
    cerr << "Kan bestand niet openen" << endl;
    return 1;
}
    string myText;
    string lastname;
    bool hoofdbool = false;
    int Count = 0;

    while (getline (MyReadFile, myText)){
        istringstream iss(myText);
        vector<string> delen;
        string deel;

        while (iss >> deel){
            delen.push_back(deel);
        }

        if (delen.size() >= 3) {
            string eerstenaam = delen[0];
            string tweedenaam = delen[2];

            
            if(hoofdbool){
                Count++;
            }

            if(eerstenaam == "HOOFD"){
                hoofdbool = true;
                Count--;
            }else if (tweedenaam == "HOOFD"){
                hoofdbool = false;
                Count--;
            }

        }
    }

    MyReadFile.close();
    cout << Count << endl;
    return 0;
}