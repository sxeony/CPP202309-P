#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// ���� ������ ��� ����ü
struct Store {
  std::string name;
  std::string majorRegion;
  std::string minorRegion;
  std::string address;
};

// �Լ� �����
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
