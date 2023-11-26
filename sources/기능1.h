#include <iostream>
#include <map>
#include <string>
#include <vector>
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
