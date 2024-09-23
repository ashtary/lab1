#include <iostream>
#include <iomanip>

using namespace std;

int sizeOfTypes() {
    cout << setfill(' ') << setw(74) << "Размер разных типов данных" << "\n";
    cout << "Тип данных int занимает " << sizeof(int) << " байта" << endl;
    cout << "Тип данных short int занимает " << sizeof(short int) << " байта" << endl;
    cout << "Тип данных long int занимает " << sizeof(long int) << " байта" << endl;
    cout << "Тип данных float занимает " << sizeof(float) << " байта" << endl;
    cout << "Тип данных double занимает " << sizeof(double) << " байт" << endl;
    cout << "Тип данных char занимает " << sizeof(char) << " байт" << endl;
    cout << "Тип данных bool занимает " << sizeof(bool) << " байт" << "\n";
    return (0);
}
int mistake(int n) {
    while (cin.fail() || cin.peek() != '\n') {
        cout << "Введите верное значение!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }
    return n;
}
int mistakeFloat(float n) {
    while (cin.fail() || cin.peek() != '\n') {
        cout << "Введите верное значение!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }
    return n;
}
int moveToLeft(int n) {
    cout << "\n" << "Если хотите сдвинуть все биты влево, то нажмите 1, иначе введите любое другое число: ";
    int answer;
    cin >> answer;
    answer = mistake(answer);
    if (answer) {
        int amount;
        cout << "На сколько единиц сдвинуть? ";
        cin >> amount;
        amount = mistake(amount);
        n <<= amount;
    }
    return n;
}

int main() {
    setlocale(0, "");
    sizeOfTypes();

    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти целого числа " << "\n";
    cout << "\n" << "Введите любое целое число: ";
    int number;
    cin >> number;
    mistake(number);
    moveToLeft(number);
    unsigned int mask = 1 << 31;
    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i < 32; i++) {
        putchar(number & mask ? '1' : '0');
        mask >>= 1;
        if (i % 8 == 0 || i == 31) {
            putchar(' ');
        }
    }
    cout << endl;
    cin.clear();

    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти типа float " << endl;
    cout << "\n" << "Введите любое число типа float: ";
    union {
        int tool;
        float numberFloat;
    };
    cin >> numberFloat;
    mistakeFloat(numberFloat);
    moveToLeft(numberFloat);
    unsigned int maskFloat = 1 << 31;
    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i < 32; i++) {
        putchar(tool & maskFloat ? '1' : '0');
        maskFloat >>= 1;
        if (i == 0 || i == 11) {
            putchar(' ');
        }
    }
    cout << endl;
    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти числа типа double" << endl;
    cout << "\n" << "Введите любое число типа double: ";

    union {
        unsigned int Double[2];
        double numberDouble;


    };
    cin >> numberDouble;
    mistake(numberDouble);
    moveToLeft(numberDouble);
    unsigned int maskD = 1 << 31;
    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i <= 32; ++i) {
        putchar(Double[1] & maskD ? '1' : '0');
        maskD >>= 1;
        if (i == 0 || i == 11) {
            putchar(' ');
        }
    }
    maskD = 1 << 31;
    for (int i = 0; i <= 32; ++i) {
        putchar(Double[0] & maskD ? '1' : '0');
        maskD >>= 1;
    }
    cout << endl;
    return(0);
}

