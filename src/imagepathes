// Example: find each menu item's picture from its id.
// Reads data/menu.csv (exported from the Google Sheet) and builds
//   assets/food/<station folder>/<id>.png
// Compile: g++ -std=c++17 image_paths.cpp -o image_paths

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Sheet station id -> folder name in assets/food/
// (Only needed while the sheet says "casaitaliana" and the folder says "casa_italiana".)
const map<string, string> STATION_FOLDERS = {
    {"casaitaliana", "casa_italiana"},
    {"bcoven", "bc_oven"},
    {"southernhospitality", "southern_hospitality"},
    {"bikinibottomtavern", "bikini_bottom_tavern"},
    {"internationalcuisine", "international_cuisine"},
    {"edendiet", "eden_diet"},
};

class MenuItem {
private:
    string id;
    string name;
    string station;

public:
    MenuItem(string i, string n, string s) : id(i), name(n), station(s) {}

    string getId() const { return id; }
    string getName() const { return name; }

    // assets/food/casa_italiana/alfredopasta.png
    string getImagePath() const {
        auto folder = STATION_FOLDERS.find(station);
        string stationFolder = (folder != STATION_FOLDERS.end()) ? folder->second : station;
        return "assets/food/" + stationFolder + "/" + id + ".png";
    }

    bool hasImage() const { return filesystem::exists(getImagePath()); }
};

// Splits one CSV line on commas (the sheet has no commas inside cells)
vector<string> splitLine(const string& line) {
    vector<string> cells;
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ',')) cells.push_back(cell);
    return cells;
}

int main() {
    ifstream file("data/menu.csv");
    if (!file) {
        cout << "Couldn't open data/menu.csv" << endl;
        return 1;
    }

    vector<MenuItem> menu;
    string line;
    getline(file, line);  // skip the header row
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();  // Windows line endings
        vector<string> c = splitLine(line);
        if (c.size() >= 3) menu.push_back(MenuItem(c[0], c[1], c[2]));
    }

    for (const MenuItem& item : menu) {
        cout << item.getName() << "  ->  " << item.getImagePath()
             << (item.hasImage() ? "" : "   (no picture yet)") << endl;
    }
    return 0;
}
