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
    ifstream MyReadFile("/home/daantje/Documents/Projects/Riks-Lessen/input.txt");
    string myText;
    map<string, int> aanSinds;
    map<string, int> totaal;
    int nutotaalrobots = 0;
    int maxRobots = 0;

    while (getline(MyReadFile, myText)) {
        istringstream iss(myText);
        vector<string> delen;
        string deel;

        while (iss >> deel) {
            delen.push_back(deel);
        }

        if (delen.size() >= 3) {
            int tijd;
            try {
                tijd = stoi(delen[0]);
            } catch (const exception&) {
                cerr << "Fout bij het converteren van tijd: " << delen[0] << endl;
                continue;
            }
            string naamrobot = delen[1];
            string switchwaarde = delen[2];
            
            if (switchwaarde == "AAN") {
                aanSinds[naamrobot] = tijd;
                nutotaalrobots++;

            } else if (switchwaarde == "UIT"){
                    if (nutotaalrobots > maxRobots) {
                    maxRobots = nutotaalrobots;
                }
                    nutotaalrobots--;
                if (aanSinds.find(naamrobot) != aanSinds.end()) {
                    int duur = tijd - aanSinds[naamrobot];
                    totaal[naamrobot] += duur;

                    aanSinds.erase(naamrobot);
                }
            } 

            //cout << "Naam: " << naam << ", Naam robot: " << naamrobot << ", Switchwaarde: " << switchwaarde << endl;
        }
    }
    MyReadFile.close();
    // if (!totaal.empty()) {
    //     auto maxIt = max_element(
    //         totaal.begin(),
    //         totaal.end(),
    //         [](const auto& a, const auto& b) { return a.second < b.second; }
    //     );
    //         cout << "Key: " << maxIt->first << ", Value: " << maxIt->second << endl;
    // }

    cout << "Maximaal aantal robots tegelijk aan: " << maxRobots << endl;

    return 0;
}