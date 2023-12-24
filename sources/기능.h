#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
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

	// 재고 정보를 파일에 저장하는 함수
	void saveToFile() {
		ofstream file("수량.txt");
		for (const auto& pair : stock) {
			file << pair.first << " " << pair.second << endl;
		}
		file.close();
	}

	// 파일을 읽는 함수
	void loadFromFile() {
		// 매일매일 수량이 달라지기 때문에 파일이 열릴 때마다 내용이 비워짐 (고민)
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
	// 재고 업데이트하는 함수
	void updateStock(const Store& store, const string& item, int quantity) {
		string key = store.name + ":" + item;
		stock[key] = quantity;
		cout << "가게: " << store.name << ", 상품: " << item
			<< ", 수량: " << quantity << endl;
		saveToFile();
	}

	// 재고 체크하는 함수
	void checkStock(const Store& store, const string& item) {
		string key = store.name + ":" + item;
		// stock 에서 key에 해당하는 요소 찾기
		auto it = stock.find(key);
		// 찾고자 하는 키가 존재하면 정보 출력하기
		if (it != stock.end()) {
			cout << "가게: " << store.name << ", 상품: " << item
				<< ", 수량: " << it->second << endl;
		}
		else {
			cout << "재고가 없습니다." << endl;
		}
	}
};

// 기능 3: 옷에 관한 정보를 나타내는 클래스
class ClothingItem {
public:
	std::string store;     // 가게 이름
	std::string type;      // ex) 상의, 하의
	std::string color;     // 옷 색깔
	std::string material;  // 옷 재질
	std::string size;      // 옷 사이즈

	ClothingItem(std::string st, std::string t, std::string c, std::string m,
		std::string s);

	void displayDetails() const;

	std::string getStoreName() const { return store; }
};

// 기능 4 : 리뷰 쓰고 확인하는 클래스
class StoreReview {
private:
	std::string storeName;

public:
	StoreReview(const std::string& storeName);

	void writeReviewToFile(const std::string& review);
	void showReviews() const;
	std::string getStoreName() const;
};




// 함수 선언들
// 기능1 : 옷가게 위치 확인
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

// 기능2 : 옷 재고 관리
void manageInventory(ClothingInventory& inventory,
	const std::vector<Store>& stores);

// 기능 3: 원하는 옷 장바구니에 담아두기
void saveCartToFile(const std::vector<ClothingItem>& cart,
	const std::string& filename);


