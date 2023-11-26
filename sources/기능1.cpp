#include "���1.h"
#include <iostream>

// �Լ� ����
// ���� ������ ����� ����ϴ� �Լ�
void printMajorRegions(const std::vector<std::string>& majorRegions) {
    std::cout << "============================================" << std::endl;
    // �ݺ����� �̿��� majorRegions�� �ִ� ��� ��ҵ� ����ϱ�
    for (int i = 0; i < majorRegions.size(); i++) {
        std::cout << i + 1 << ": " << majorRegions[i] << std::endl;
    }
    std::cout << "============================================" << std::endl;
}

// �������� �Է� �޴� �Լ�
int selectMajorRegion(const std::vector<std::string>& majorRegions) {
    std::cout << "���ϴ� ���� ������ �����ϼ���: ";
    int majorRegionIndex;
    std::cin >> majorRegionIndex;
    std::cout << "============================================" << std::endl;
    return majorRegionIndex;
}

// ���� ������ ���� ���� ���� ����� ����ڿ��� ����ϴ� �Լ�
void printMinorRegions(const std::map<std::string, std::vector<std::string>>& minorRegions, const std::string& selectedMajorRegion) {
    int i = 1;
    // �ݺ����� �̿��� selectedMajorRegion�� �ش��ϴ� ���� �������� ���͸� ��ȯ
    for (const auto& region : minorRegions.at(selectedMajorRegion)) {
        std::cout << i++ << ": " << region << std::endl;
    }
    std::cout << "============================================" << std::endl;
}

// �������� �Է� �޴� �Լ�
int selectMinorRegion(const std::map<std::string, std::vector<std::string>>& minorRegions, const std::string& selectedMajorRegion) {
    std::cout << selectedMajorRegion << " ������ ���� ������ �����ϼ���: ";
    int minorRegionIndex;
    std::cin >> minorRegionIndex;
    std::cout << "============================================" << std::endl;
    return minorRegionIndex;
}

// �־��� ������ ���ϴ� �� ���Ե��� ����ϴ� �Լ�
void printStores(const std::vector<Store>& stores, const std::string& majorRegion, const std::string& minorRegion) {
    bool found = false;  //found ���� ���� (�־��� ���������� ���Ը� ã�Ҵ����� ���� ����)
    std::cout << majorRegion << " " << minorRegion << "�� �ִ� �� ���� ���:" << std::endl;
   // store������ ��� Store ��ü�� ������� �� ���� ó���ϴ� �ݺ���
    for (const auto& store : stores) {
        // ã���� �ϴ� ������, �ʰ��԰� ���� ��� �̸��� �ּ� ���
        if (store.majorRegion == majorRegion && store.minorRegion == minorRegion) {
            std::cout << store.name << ": " << store.address << std::endl;
            found = true;
        }
    }

    // �ش� ������ �ʰ��԰� ���� ���
    if (!found) {
        std::cout << majorRegion << " " << minorRegion << "���� �� ���԰� �����ϴ�." << std::endl;
    }
}


