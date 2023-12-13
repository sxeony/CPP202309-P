#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// 가게 정보를 담는 구조체
struct Store {
  std::string name;
  std::string majorRegion;
  std::string minorRegion;
  std::string address;
};

// 함수 선언들
void printMajorRegions(const std::vector<std::string>& majorRegions);
int selectMajorRegion(const std::vector<std::string>& majorRegions);
void printMinorRegions(
    const std::map<std::string, std::vector<std::string>>& minorRegions,
    const std::string& selectedMajorRegion);
int selectMinorRegion(
    const std::map<std::string, std::vector<std::string>>& minorRegions,
    const std::string& selectedMajorRegion);
void printStores(const std::vector<Store>& stores,
                 const std::string& majorRegion,
                 const std::string& minorRegion);

class ClothingInventory {
 private:
  map<string, int> stock;  

  void saveToFile() {
    ofstream file("수량.txt");
    for (const auto& pair : stock) {
      file << pair.first << " " << pair.second << endl;
    }
    file.close();
  }

  void loadFromFile() {
    ifstream file("수량.txt",ios::trunc);
    string key;
    int quantity;
    while (file >> key >> quantity) {
      stock[key] = quantity;
    }
    file.close();
  }

 public:
  ClothingInventory() { loadFromFile(); }

  void updateStock(const Store& store, const string& item, int quantity) {
    string key = store.name + ":" + item;
    stock[key] = quantity;
    cout << "Store: " << store.name << ", Item: " << item
         << ", Stock: " << quantity << endl;
    saveToFile();
  }

  void checkStock(const Store& store, const string& item) {
    string key = store.name + ":" + item;
    auto it = stock.find(key);
    if (it != stock.end()) {
      cout << "Store: " << store.name << ", Item: " << item
           << ", Stock: " << it->second << endl;
    } else {
      cout << "Store: " << store.name << ", Item: " << item
           << ", Stock: Unavailable" << endl;
    }
  }
};

void manageInventory(ClothingInventory& inventory, const std::vector<Store>& stores);



