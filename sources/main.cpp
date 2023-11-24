#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 가게 정보를 담는 구조체
struct Store {
    string name;
    string majorRegion;  // 상위 지역
    string minorRegion;  // 하위 지역
    string address;      // 상세 주소
};

int main() {
    // 옷 가게 목록을 벡터로 정의
    vector<Store> stores = {
        {"옷가게1", "광주광역시", "동구", "충장로 "},
        {"옷가게1", "광주광역시", "동구", "충장로 "},
        {"옷가게1", "광주광역시", "동구", "충장로 1번길 123"},
        {"옷가게1", "광주광역시", "동구", "충장로 1번길 123"},
        {"옷가게1", "광주광역시", "동구", "충장로 1번길 123"},
        {"옷가게1", "광주광역시", "서구", "충장로 1번길 123"},
        {"옷가게1", "광주광역시", "북구", "충장로 1번길 123"},
        {"옷가게2", "광주광역시", "남구", "국화로 2번길 456"},
        // 추가 가게 정보...
    };

    // 상위 지역 목록을 미리 정의
    vector<string> majorRegions = {"광주광역시", "서울특별시","대전광역시", "대구광역시", "울산광역시", "부산광역시",
        "세종특별자치시", "강원특별자치도", "제추특별자치도","전라남도", "전라북도", "경기도", "강원도", "충청북도", 
        "충청남도", "경상북도", "경상남도"};

    // 하위 지역 목록을 미리 정의
    map<string, vector<string>> minorRegions = {
        {"광주광역시", {"동구", "남구", "북구", "서구"}},
        {"전라남도", {"목포시", "여수시","..."}},
        {"전라북도", {"전주시", "군산시","..."}},
        {"서울특별시",{"강남구", "종로구","..."}}
        // 추가 지역 정보....
    };

    // 사용자에게 상위 지역을 선택
    cout << "============================================" << endl;
    for (int i = 0; i < majorRegions.size(); i++) {
        cout << i + 1 << ": " << majorRegions[i] << endl;
    }
    cout << "============================================" << endl;
    cout << "원하는 상위 지역을 선택하세요: ";
    int majorRegionIndex;
    cin >> majorRegionIndex;
    cout << "============================================" << endl;


    // 선택된 상위 지역의 하위 지역 출력
    string selectedMajorRegion = majorRegions[majorRegionIndex - 1];
    int i = 1;
    for (const auto& region : minorRegions[selectedMajorRegion]) {
        cout << i++ << ": " << region << endl;
    }
    cout << "============================================" << endl;
    cout << selectedMajorRegion << " 내에서 하위 지역을 선택하세요: ";
    int minorRegionIndex;
    cin >> minorRegionIndex;
    cout << "============================================" << endl;

    // 선택한 지역의 옷 가게 목록을 가져옵니다.
    string selectedMinorRegion = minorRegions[selectedMajorRegion][minorRegionIndex - 1];
    vector<Store> selectedStores;
    for (const auto& store : stores) {
        if (store.majorRegion == selectedMajorRegion && store.minorRegion == selectedMinorRegion) {
            selectedStores.push_back(store);
        }
    }

    // 선택한 지역의 옷 가게 목록과 주소를 출력합니다.
    if (!selectedStores.empty()) {
        cout << selectedMajorRegion << " " << selectedMinorRegion << "에 있는 옷 가게 목록:" << endl;
        for (const auto& store : selectedStores) {
            cout << store.name <<": "<< store.address << endl;
        }
    }
    else {
        cout << selectedMajorRegion << " " << selectedMinorRegion << "에는 옷 가게가 없습니다." << endl;
    }

    return 0;
}
