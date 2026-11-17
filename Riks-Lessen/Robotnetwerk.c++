#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <ranges>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main() {
    std::ifstream MyReadFile("/home/daantje/Documents/Unreal Projects/C-Testing/Riks-Lessen/input.txt");
    if (!MyReadFile) {
        std::cerr << "Kan bestand niet openen" << std::endl;
        return 1;
    }
    std::string myText;
    std::map<std::string, std::vector<std::string>> volgende;

    while (std::getline(MyReadFile, myText)) {
        std::istringstream iss(myText);
        std::vector<std::string> delen;
        std::string deel;

        while (iss >> deel) {
            delen.push_back(deel);
        }

        if (delen.size() >= 3) {
           volgende[delen[0]].push_back(delen[2]);
        }
    }
    MyReadFile.close();

    set<string> bezocht;
    queue<string> wachtrij;

    bezocht.insert("HOOFD");
    wachtrij.push("HOOFD");

    while (!wachtrij.empty()) {
        string huidig = wachtrij.front();
        wachtrij.pop();

        for (const string& buur : volgende[huidig]) {
            if (bezocht.find(buur) == bezocht.end()) {
                bezocht.insert(buur);
                wachtrij.push(buur);
            }
        }
    }

    cout << bezocht.size() - 1 <<endl;

    return 0;
}