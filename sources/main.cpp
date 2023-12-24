#include "���.h"

int main() {
    // ���1. �ʰ��� ��ġ Ȯ��
    // ����,�ʰ��� �����ϱ�
    std::vector<Store> stores = {
        {"���÷��̱׶���", "���ֱ�����", "����", "���ֱ����� ���� ����� 90"},
        {"���ֿ��̺�", "���ֱ�����", "����", "���ֱ����� ���� ����ξȱ� 25"},
        {"ž��", "���ֱ�����", "����", "���ֱ����� ���� ���嵿 ����� 87"},
        {"���", "���ֱ�����", "����", "���ֱ����� ���� �ݳ���1��"},
        {"������", "���ֱ�����", "����", "���ֱ����� ���� �ҷε� 107-2"},
        {"MODA", "���ֱ�����", "����",
         "���ֱ����� ���� ���̵� �󹫹��ַ�76���� 11-2"},
        {"���� �ǻ��", "���ֱ�����", "�ϱ�", "���ֱ����� �ϱ� ��ġ��100���� 12"},
        {"���ѿʰ���", "���ֱ�����", "����", "���ֱ����� ���� �� 594-8����"},
        // ���...
    };
    std::vector<std::string> majorRegions = {
        "���ֱ�����",     "����Ư����",     "����������", "�뱸������",
        "��걤����",     "�λ걤����",     "��õ������", "����Ư����ġ��",
        "����Ư����ġ��", "����Ư����ġ��", "���󳲵�",   "����ϵ�",
        "��⵵",         "��û�ϵ�",       "��û����",   "���ϵ�",
        "��󳲵�" };
    std::map<std::string, std::vector<std::string>> minorRegions = {
        {"���ֱ�����", {"����", "����", "�ϱ�", "����"}},
        {"���󳲵�", {"������", "������", "��õ��", "���ֽ�", "..."}},
        {"����ϵ�", {"���ֽ�", "�����", "..."}},
        {"����Ư����", {"������", "���α�", "..."}}
        // ���....
    };

    // 1.1 majorRegions�� ��� ������������ ��� ���
    printMajorRegions(majorRegions);

    // 1.2 �������� �Է� �ޱ�
    int majorRegionIndex = selectMajorRegion(majorRegions);
    std::string selectedMajorRegion = majorRegions[majorRegionIndex - 1];

    // 1.3 ���õ� ���������� ���� �������� ��� ���
    printMinorRegions(minorRegions, selectedMajorRegion);

    // 1.4  �������� �Է� �ޱ�
    int minorRegionIndex = selectMinorRegion(minorRegions, selectedMajorRegion);
    std::string selectedMinorRegion =
        minorRegions[selectedMajorRegion][minorRegionIndex - 1];

    // 1.5 ���õ� ������ �ִ� �ʰ��Ե��� �̸��� �ּ� ���
    printStores(stores, selectedMajorRegion, selectedMinorRegion);

    // 2. �ʰ��� ���� Ȯ���ϰ�, ������Ʈ�ϱ�
    ClothingInventory inventory;
    manageInventory(inventory, stores);

    // 3. ���ϴ� �� ��ٱ��Ͽ� ���

    std::vector<ClothingItem> menu{
        // ���� ������ ���
        ClothingItem("ž��", "��Ʈ", "������", "��", "M"),
        ClothingItem("ž��", "����", "����", "����", "L"),
        ClothingItem("������", "����", "������", "����", "L"),
        ClothingItem("MODA", "�����", "����", "����", "M"),
        ClothingItem("���� �ǻ��", "û����", "��û", "����", "S"),
        // ... ������ �����۵�
    };

    std::vector<ClothingItem> cart;
    std::vector<StoreReview> storeReviews{
        StoreReview("ž��"),
        StoreReview("������")
        // ... ��Ÿ ���� �߰�
    };

    std::string storeName;
    std::string review;
    int mainChoice = -1;
    int subChoice;

    while (mainChoice != 0) {
        std::cout << "\n3~4. �� ��ٱ��� ��� ���, ���� ���� ��� �����ϱ� " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "1: �� ��ٱ��� ���" << std::endl;
        std::cout << "2: ���� �ۼ��ϱ�" << std::endl;
        std::cout << "0: ����" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "�ɼ��� �������ּ���: ";
        std::cin >> mainChoice;

        switch (mainChoice) {
        case 1: {
            subChoice = -1;
            while (subChoice != 0) {
                std::cout << "\n3. ��ٱ��� �޴�" << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "1: �� ��ǰ ����" << std::endl;
                std::cout << "2: ��ٱ��Ͽ� ���" << std::endl;
                std::cout << "0: ���� �޴��� ���ư���" << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "�ɼ��� �������ּ���: ";
                std::cin >> subChoice;

                // ��ٱ��Ͽ� ��� ���� �ڵ�
                if (subChoice == 1) {
                    // �� ��ǰ ����
                    for (size_t i = 0; i < menu.size(); ++i) {
                        std::cout << i + 1 << ": ";
                        menu[i].displayDetails();
                    }
                }
                else if (subChoice == 2) {
                    // ��ٱ��Ͽ� ���
                    std::cout << "���� �� ��ǰ�� ��ȣ�� �Է��ϼ���: ";
                    int index;
                    std::cin >> index;
                    --index;

                    if (index >= 0 && index < menu.size()) {
                        cart.push_back(menu[index]);
                        std::cout << "��ǰ�� ��ٱ��Ͽ� �����ϴ�." << std::endl;
                    }
                    else {
                        std::cout << "��ȿ���� �ʴ� ��ȣ�Դϴ�." << std::endl;
                    }
                }
            }
            break;
        }
        case 2: {
            subChoice = -1;
            while (true) {
                std::cout << "\n���� �޴�" << std::endl;
                std::cout << "1: ���� �ۼ��ϱ�" << std::endl;
                std::cout << "2: ���� Ȯ���ϱ�" << std::endl;
                std::cout << "0: ����" << std::endl;
                std::cout << "�ɼ��� �������ּ���: ";
                std::cin >> subChoice;

                if (subChoice == 0) break;

                switch (subChoice) {
                case 1:
                    std::cin.ignore(); // ���� �Է��� ���� ���۸� ���ϴ�
                    std::cout << "���� �̸��� �Է��ϼ���: ";
                    std::getline(std::cin, storeName);
                    std::cout << "���並 �Է��ϼ���: ";
                    std::getline(std::cin, review);
                    // StoreReview ��ü�� ã�ų� ���� �����Ͽ� �޼��� ȣ��
                    for (auto& reviewObj : storeReviews) {
                        if (reviewObj.getStoreName() == storeName) {
                            reviewObj.writeReviewToFile(review);
                            break;
                        }
                    }
                    break;

                case 2:
                    std::cin.ignore(); // ���� �Է��� ���� ���۸� ���ϴ�
                    std::cout << "���� �̸��� �Է��ϼ���: ";
                    std::getline(std::cin, storeName);
                    // StoreReview ��ü�� ã�� �޼��� ȣ��
                    for (auto& reviewObj : storeReviews) {
                        if (reviewObj.getStoreName() == storeName) {
                            reviewObj.showReviews();
                            break;
                        }
                    }
                    break;
                default:
                    std::cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << std::endl;
                }
            }

        case 0:
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break;
        default:
            std::cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << std::endl;
        }
        }

        return 0;
    }
}


