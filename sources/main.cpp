#include "���1.h"

int main() {
    // ���1. ���� ������, �ʰ��� �ּ� ���
    // ����,�ʰ��� �����ϱ�
    std::vector<Store> stores = {
        {"���÷��̱׶���", "���ֱ�����", "����", "���ֱ����� ���� ����� 90"},
        {"���ֿ��̺�", "���ֱ�����", "����", "���ֱ����� ���� ����ξȱ� 25"},
        {"ž��", "���ֱ�����", "����", "���ֱ����� ���� ���嵿 ����� 87"},
        {"���", "���ֱ�����", "����", "���ֱ����� ���� �ݳ���1��"},
        {"������", "���ֱ�����", "����", "���ֱ����� ���� �ҷε� 107-2"},
        {"MODA", "���ֱ�����", "����", "���ֱ����� ���� ���̵� �󹫹��ַ�76���� 11-2"},
        {"���� �ǻ��", "���ֱ�����", "�ϱ�", "���ֱ����� �ϱ� ��ġ��100���� 12"},
        {"���ѿʰ���", "���ֱ�����", "����", "���ֱ����� ���� �� 594-8����"},
        // ���...
    };
    std::vector<std::string> majorRegions = { "���ֱ�����", "����Ư����","����������", "�뱸������", "��걤����", "�λ걤����",
        "����Ư����ġ��", "����Ư����ġ��", "����Ư����ġ��","���󳲵�", "����ϵ�", "��⵵", "������", "��û�ϵ�",
        "��û����", "���ϵ�", "��󳲵�" };
    std::map<std::string, std::vector<std::string>> minorRegions = { 
        {"���ֱ�����", {"����", "����", "�ϱ�", "����"}},
        {"���󳲵�", {"������", "������","..."}},
        {"����ϵ�", {"���ֽ�", "�����","..."}},
        {"����Ư����",{"������", "���α�","..."}}
        // ���....
    };

    // �Լ� ȣ��
    printMajorRegions(majorRegions);
    int majorRegionIndex = selectMajorRegion(majorRegions);
    std::string selectedMajorRegion = majorRegions[majorRegionIndex - 1];

    printMinorRegions(minorRegions, selectedMajorRegion);
    int minorRegionIndex = selectMinorRegion(minorRegions, selectedMajorRegion);
    std::string selectedMinorRegion = minorRegions[selectedMajorRegion][minorRegionIndex - 1];

    printStores(stores, selectedMajorRegion, selectedMinorRegion);

    return 0;
}
