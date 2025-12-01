#include <iostream>
#include <string>
#include <vector>
#include <limits> 

struct Item {
    std::string name;
    int value;
    int quantity;

    Item(std::string n, int v, int q) 
        : name(n), value(v), quantity(q) {}
    Item() : value(0), quantity(0) {}
};

// Khai báo các hàm
void addItems(std::vector<Item> &items);
void viewItems(const std::vector<Item> &items);
void pauseScreen(); // Hàm tiện ích mới để dừng màn hình

int main(){
    std::vector<Item> bag;
    int choice = 0;
    do{
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Them vat pham\n";
        std::cout << "2. Xem tui do\n";
        std::cout << "3. Thoat\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Vui long chi nhap so.\n";
            std::cin.clear(); // Xóa trạng thái lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ đệm
            choice = 0; // Đặt lại choice để không thoát vòng lặp
            pauseScreen();
            continue; // Quay lại đầu vòng lặp
        }

        switch (choice)
        {
        case 1:
            addItems(bag);
            break;
        case 2:
            viewItems(bag);
            break;
        case 3:
            std::cout << "Tam biet!\n";
            break;
        default:
            std::cout << "Lua chon khong hop le... Vui long thu lai.\n";
            pauseScreen();
            break;
        }
    }while(choice != 3);
    return 0;
}

void addItems(std::vector<Item> &items){
    Item newItem;
    std::cout << "Nhap ten vat pham: ";
    std::cin.ignore(); // Chính xác, để xóa Enter thừa từ `cin >> choice;`
    std::getline(std::cin, newItem.name);
    
    std::cout << "Nhap gia tri va so luong (vi du: 100 5): ";
    std::cin >> newItem.value >> newItem.quantity;

    items.emplace_back(newItem.name, newItem.value, newItem.quantity);
    
    std::cout << "Da them " << newItem.quantity << " " << newItem.name << "!\n"; 
    
    pauseScreen(); // Gọi hàm dừng màn hình chuyên dụng
}

void viewItems(const std::vector<Item> &items){
    std::cout << "\n--- TUI DO CUA BAN ---\n";
    if(items.empty()){
        std::cout << "Tui do rong.\n";
    }
    else {
        int i = 1;
        for(const Item &x : items){
            std::cout << i << ". " << x.name 
                      << " (So luong: " << x.quantity 
                      << ", Gia tri: " << x.value <<")\n";
            i++;
        }
    }
    std::cout << "-----------------------\n";
    
    pauseScreen(); // Gọi hàm dừng màn hình chuyên dụng
}

void pauseScreen() {
    std::cout << "\nNhan Enter de tiep tuc...";

    if(std::cin.peek() == '\n') std::cin.ignore();

    std::string dummy;
    std::getline(std::cin, dummy);
}