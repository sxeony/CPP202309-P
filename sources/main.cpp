#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ���� ������ ��� ����ü
struct Store {
    string name;
    string majorRegion;  // ���� ����
    string minorRegion;  // ���� ����
    string address;      // �� �ּ�
};

int main() {
    // �� ���� ����� ���ͷ� ����
    vector<Store> stores = {
        {"�ʰ���1", "���ֱ�����", "����", "����� "},
        {"�ʰ���1", "���ֱ�����", "����", "����� "},
        {"�ʰ���1", "���ֱ�����", "����", "����� 1���� 123"},
        {"�ʰ���1", "���ֱ�����", "����", "����� 1���� 123"},
        {"�ʰ���1", "���ֱ�����", "����", "����� 1���� 123"},
        {"�ʰ���1", "���ֱ�����", "����", "����� 1���� 123"},
        {"�ʰ���1", "���ֱ�����", "�ϱ�", "����� 1���� 123"},
        {"�ʰ���2", "���ֱ�����", "����", "��ȭ�� 2���� 456"},
        // �߰� ���� ����...
    };

    // ���� ���� ����� �̸� ����
    vector<string> majorRegions = {"���ֱ�����", "����Ư����","����������", "�뱸������", "��걤����", "�λ걤����",
        "����Ư����ġ��", "����Ư����ġ��", "����Ư����ġ��","���󳲵�", "����ϵ�", "��⵵", "������", "��û�ϵ�", 
        "��û����", "���ϵ�", "��󳲵�"};

    // ���� ���� ����� �̸� ����
    map<string, vector<string>> minorRegions = {
        {"���ֱ�����", {"����", "����", "�ϱ�", "����"}},
        {"���󳲵�", {"������", "������","..."}},
        {"����ϵ�", {"���ֽ�", "�����","..."}},
        {"����Ư����",{"������", "���α�","..."}}
        // �߰� ���� ����....
    };

    // ����ڿ��� ���� ������ ����
    cout << "============================================" << endl;
    for (int i = 0; i < majorRegions.size(); i++) {
        cout << i + 1 << ": " << majorRegions[i] << endl;
    }
    cout << "============================================" << endl;
    cout << "���ϴ� ���� ������ �����ϼ���: ";
    int majorRegionIndex;
    cin >> majorRegionIndex;
    cout << "============================================" << endl;


    // ���õ� ���� ������ ���� ���� ���
    string selectedMajorRegion = majorRegions[majorRegionIndex - 1];
    int i = 1;
    for (const auto& region : minorRegions[selectedMajorRegion]) {
        cout << i++ << ": " << region << endl;
    }
    cout << "============================================" << endl;
    cout << selectedMajorRegion << " ������ ���� ������ �����ϼ���: ";
    int minorRegionIndex;
    cin >> minorRegionIndex;
    cout << "============================================" << endl;

    // ������ ������ �� ���� ����� �����ɴϴ�.
    string selectedMinorRegion = minorRegions[selectedMajorRegion][minorRegionIndex - 1];
    vector<Store> selectedStores;
    for (const auto& store : stores) {
        if (store.majorRegion == selectedMajorRegion && store.minorRegion == selectedMinorRegion) {
            selectedStores.push_back(store);
        }
    }

    // ������ ������ �� ���� ��ϰ� �ּҸ� ����մϴ�.
    if (!selectedStores.empty()) {
        cout << selectedMajorRegion << " " << selectedMinorRegion << "�� �ִ� �� ���� ���:" << endl;
        for (const auto& store : selectedStores) {
            cout << store.name <<": "<< store.address << endl;
        }
    }
    else {
        cout << selectedMajorRegion << " " << selectedMinorRegion << "���� �� ���԰� �����ϴ�." << endl;
    }

    return 0;
}
