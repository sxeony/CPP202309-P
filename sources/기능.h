#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// 기능	1: 가게 정보를 담는 구조체
struct Store {
	std::string name;
	std::string majorRegion;
	std::string minorRegion;
	std::string address;
};

// 기능 2: 옷가게의 재고 관리하는 클래스
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
		ifstream file("수량.txt", ios::trunc);
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
		}
		else {
			cout << "Store: " << store.name << ", Item: " << item
				<< ", Stock: Unavailable" << endl;
		}
	}
};

// 기능 3: 옷에 관한 정보를 나타내는 클래스
class ClothingItem {
public:
	std::string type;  // ex) 상의, 하의 
	std::string color;  // 옷 색깔
	std::string material;  // 옷 재질
	std::string size;  // 옷 사이즈

	ClothingItem(std::string t, std::string c, std::string m, std::string s);

	void displayDetails();
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

void manageInventory(ClothingInventory& inventory, const std::vector<Store>& stores);

void saveToCart(const std::vector<ClothingItem>& cart, const std::string& filename);




