#include "기능1.h"
#include <iostream>

// 함수 정의
// 상위 지역의 목록을 출력하는 함수
void printMajorRegions(const std::vector<std::string>& majorRegions) {
    std::cout << "============================================" << std::endl;
    // 반복문을 이용해 majorRegions에 있는 모든 요소들 출력하기
    for (int i = 0; i < majorRegions.size(); i++) {
        std::cout << i + 1 << ": " << majorRegions[i] << std::endl;
    }
    std::cout << "============================================" << std::endl;
}

// 상위지역 입력 받는 함수
int selectMajorRegion(const std::vector<std::string>& majorRegions) {
    std::cout << "원하는 상위 지역을 선택하세요: ";
    int majorRegionIndex;
    std::cin >> majorRegionIndex;
    std::cout << "============================================" << std::endl;
    return majorRegionIndex;
}

// 상위 지역에 대한 하위 지역 목록을 사용자에게 출력하는 함수
void printMinorRegions(const std::map<std::string, std::vector<std::string>>& minorRegions, const std::string& selectedMajorRegion) {
    int i = 1;
    for (const auto& region : minorRegions.at(selectedMajorRegion)) {
        std::cout << i++ << ": " << region << std::endl;
    }
    std::cout << "============================================" << std::endl;
}

int selectMinorRegion(const std::map<std::string, std::vector<std::string>>& minorRegions, const std::string& selectedMajorRegion) {
    std::cout << selectedMajorRegion << " 내에서 하위 지역을 선택하세요: ";
    int minorRegionIndex;
    std::cin >> minorRegionIndex;
    std::cout << "============================================" << std::endl;
    return minorRegionIndex;
}


void printStores(const std::vector<Store>& stores, const std::string& majorRegion, const std::string& minorRegion) {
    bool found = false;
    std::cout << majorRegion << " " << minorRegion << "에 있는 옷 가게 목록:" << std::endl;
    for (const auto& store : stores) {
        if (store.majorRegion == majorRegion && store.minorRegion == minorRegion) {
            std::cout << store.name << ": " << store.address << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << majorRegion << " " << minorRegion << "에는 옷 가게가 없습니다." << std::endl;
    }
}


