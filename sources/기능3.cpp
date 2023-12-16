#include <fstream>
#include "���.h"

ClothingItem::ClothingItem(std::string t, std::string c, std::string m,
	std::string s)
	: type(t), color(c), material(m), size(s) {}

// ���� ������ ����ϴ� �Լ�
void ClothingItem::displayDetails() {
	std::cout << "�� ����: " << type << ", ����: " << color
		<< ", ����: " << material << ", ������: " << size << std::endl;
}

// ���� ��ٱ���(����)�� ��� �Լ�
void saveToCart(const std::vector<ClothingItem>& cart,
	const std::string& filename) {
	std::ofstream file(filename);

	for (const auto& item : cart) {
		file << item.type << "," << item.color << "," << item.material << ","
			<< item.size << std::endl;
	}

	file.close();
}
