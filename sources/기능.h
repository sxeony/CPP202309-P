#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// ���	1: ���� ������ ��� ����ü
struct Store {
	std::string name;
	std::string majorRegion;
	std::string minorRegion;
	std::string address;
};

// ��� 2: �ʰ����� ��� �����ϴ� Ŭ����
class ClothingInventory {
private:
	map<string, int> stock;

	// ��� ������ ���Ͽ� �����ϴ� �Լ�
	void saveToFile() {
		ofstream file("����.txt");
		for (const auto& pair : stock) {
			file << pair.first << " " << pair.second << endl;
		}
		file.close();
	}

	// ������ �д� �Լ�
	void loadFromFile() {
		// ���ϸ��� ������ �޶����� ������ ������ ���� ������ ������ ����� (���)
		ifstream file("����.txt", ios::trunc);
		string key;
		int quantity;
		while (file >> key >> quantity) {
			stock[key] = quantity;
		}
		file.close();
	}

public:
	ClothingInventory() { loadFromFile(); }
	// ��� ������Ʈ�ϴ� �Լ�
	void updateStock(const Store& store, const string& item, int quantity) {
		string key = store.name + ":" + item;
		stock[key] = quantity;
		cout << "����: " << store.name << ", ��ǰ: " << item
			<< ", ����: " << quantity << endl;
		saveToFile();
	}

	// ��� üũ�ϴ� �Լ�
	void checkStock(const Store& store, const string& item) {
		string key = store.name + ":" + item;
		// stock ���� key�� �ش��ϴ� ��� ã��
		auto it = stock.find(key);
		// ã���� �ϴ� Ű�� �����ϸ� ���� ����ϱ�
		if (it != stock.end()) {
			cout << "����: " << store.name << ", ��ǰ: " << item
				<< ", ����: " << it->second << endl;
		}
		else {
			cout << "��� �����ϴ�." << endl;
		}
	}
};

// ��� 3: �ʿ� ���� ������ ��Ÿ���� Ŭ����
class ClothingItem {
public:
	std::string store;     // ���� �̸�
	std::string type;      // ex) ����, ����
	std::string color;     // �� ����
	std::string material;  // �� ����
	std::string size;      // �� ������

	ClothingItem(std::string st, std::string t, std::string c, std::string m,
		std::string s);

	void displayDetails() const;

	std::string getStoreName() const { return store; }
};

// ��� 4 : ���� ���� Ȯ���ϴ� Ŭ����
class StoreReview {
private:
	std::string storeName;

public:
	StoreReview(const std::string& storeName);

	void writeReviewToFile(const std::string& review);
	void showReviews() const;
	std::string getStoreName() const;
};




// �Լ� �����
// ���1 : �ʰ��� ��ġ Ȯ��
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

// ���2 : �� ��� ����
void manageInventory(ClothingInventory& inventory,
	const std::vector<Store>& stores);

// ��� 3: ���ϴ� �� ��ٱ��Ͽ� ��Ƶα�
void saveCartToFile(const std::vector<ClothingItem>& cart,
	const std::string& filename);


