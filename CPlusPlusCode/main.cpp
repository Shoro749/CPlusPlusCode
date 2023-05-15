#include <iostream>
using namespace std;

/*Описати базовий клас «Рядок».
Методи:
1) конструктор без параметрів;
2) конструктор, що приймає як параметр C-рядок (закінчується нульовим байтом);
3) конструктор копіювання; ************
4) оператор присвоєння;
5) отримання довжини рядка;
6) очищення рядка (зробити рядок порожнім);
7) деструктор;
8) конкатенація рядків (перевантажити оператори + і +=);
9) перевірка на рівність (==) і на нерівність (!=).
Описати клас «Бітовий рядок» похідний від класу «Рядок» (Рядки цього класу можуть містити тільки символи
0 і 1). Якщо в основі рядка, який ініціалізує зустрінуться
будь-які символи, відмінні від допустимих, то «Бітовий
рядок» стає порожнім. Вміст рядка розглядається як
двійкове подання цілого числа зі знаковим розрядом.
Негативні числа зберігаються в додатковому коді.
Методи:
1) конструктор без параметрів;
2) конструктор, що приймає як параметр C-рядок;
3) конструктор копіювання;
4) оператор присвоєння;
5) деструктор;
6) зміна знаку числа (переклад числа в додатковий код).
7) складання бітових рядків (перевантажити оператори
+ і +=);
8) перевірка на рівність (==) і на нерівність (!=).*/

class Line {
private:
	string line;
public:
	Line() {
		this->line = "NULL";
	}

	Line(string line) {
		this->line = line;
	}

	string setLine(string line) {
		this->line = line;
	}

	int getLength() {
		return this->line.length();
	}

	void Clear() {
		line.clear();
		cout << "Line has cleared!" << endl;
	}

	Line operator+(const Line& other) const {
		return Line(this->line + other.line);
	}

	Line& operator+=(const Line& other) {
		this->line += other.line;
		return *this;
	}

	bool operator==(const Line& other) const {
		return this->line == other.line;
	}

	bool operator!=(const Line& other) const {
		return !(*this == other);
	}

	~Line() {
		this->line.clear();
	}
};

class BitString : public Line {
private:
    // Перевірка, що рядок містить лише символи 0 та 1
    bool IsValidBitString(string str) const {
        for (char c : str) {
            if (c != '0' && c != '1') {
                return false;
            }
        }
        return true;
    }

public:
    BitString() : Line() {}

    BitString(const char* str) {
        if (!IsValidBitString(str)) {
            line.clear();
            return;
        }
        line = str;
    }

    BitString(const BitString& other) : Line(other) {}

    BitString& operator=(const BitString& other) {
        if (this != &other) {
            Line::operator=(other);
        }
        return *this;
    }

    ~BitString() {}

    void Negate() {
        if (line.empty()) {
            return;
        }

        for (char& c : line) {
            c = (c == '0') ? '1' : '0';
        }

        int carry = 1;
        for (int i = line.length() - 1; i >= 0; i--) {
            if (carry == 0) {
                break;
            }
            if (line[i] == '0') {
                line[i] = '1';
                carry = 0;
            }
            else {
                line[i] = '0';
            }
        }

        if (carry == 1) {
            line = '1' + line;
        }
    }

    BitString operator+(const BitString& other) const {
        if (line.empty() || other.line.empty()) {
            return BitString();
        }

        string result;
        int carry = 0;
        int i = line.length() - 1;
        int j = other.line.length() - 1;

        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += (line[i] - '0');
                i--;
            }
            if (j >= 0) {
                sum += (other.line[j] - '0');
                j--;
            }
            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }

        if (carry != 0) {
            result = '1' + result;
        }

        return BitString(result.c_str());
    }

    BitString& operator+=(const BitString& other) {
        BitString temp = *this + other;
        *this = temp;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return line == other.line;
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }
};

int main() {
	Line a("Hello");
	Line b(" World");
	Line c = a + b;
	a += b;

	if (a == c) {
		cout << "A and b are equal!!" << endl;
	}

	if (a != b) {
		cout << "A and b are not equal!" << endl;
	}

	return 0;
}