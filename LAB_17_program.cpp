#include <iostream>
#include <string>
using namespace std;

// Клас Процесор
class Processor {
protected:
    string brand;
    double frequency;  // у ГГц
    int cacheSize;     // у КБ
    double price;      // у доларах
    bool valid;

public:
    Processor(string b, double f, int c, double p) {
        if (f <= 0 || c < 0 || p < 0) {
            cout << "❌ Некоректні параметри процесора!" << endl;
            valid = false;
            return;
        }
        brand = b;
        frequency = f;
        cacheSize = c;
        price = p;
        valid = true;
    }

    bool isValid() const { return valid; }

    void printProcessorInfo() const {
        if (!valid) {
            cout << "Дані процесора недійсні." << endl;
            return;
        }
        cout << "Марка процесора: " << brand << endl;
        cout << "Частота: " << frequency << " ГГц" << endl;
        cout << "Кеш: " << cacheSize << " КБ" << endl;
        cout << "Ціна: $" << price << endl;
    }
};

// Клас Материнська плата
class Motherboard : public Processor {
private:
    int ramSize;
    bool validMB;

public:
    Motherboard(string b, double f, int c, double p, int ram)
        : Processor(b, f, c, p) {
        if (!isValid() || ram <= 0) {
            cout << "❌ Некоректні параметри материнської плати!" << endl;
            validMB = false;
            return;
        }
        ramSize = ram;
        validMB = true;
    }

    bool isValidMB() const { return validMB; }

    void printInfo() const {
        if (!validMB) {
            cout << "Дані материнської плати недійсні." << endl;
            return;
        }
        cout << "=== Інформація про материнську плату ===" << endl;
        printProcessorInfo();
        cout << "Оперативна пам'ять: " << ramSize << " ГБ" << endl;
    }
};

// === Демонстрація ===
int main() {

    system("chcp 1251 > nul"); //підключення української мови

    Motherboard mb("Intel Core i5", 3.2, 6144, 180.0, 16);
    if (mb.isValidMB()) {
        mb.printInfo();
    }

    // Приклад з помилкою:
    Motherboard broken("Intel Core i5", -1.0, 6144, 180.0, 16);  // частота -1
    if (broken.isValidMB()) {
        broken.printInfo();
    }

    return 0;
}
