#include <iostream>
using namespace std;

/*В рамках попередніх самостійних і домашніх завдань ви створили набір класів для роботи 
з різними примітивними математичними операціям(дріб, точка в двови-мірному просторі, точка в тривимірному просторі і т.д.). 
Додайте вже створені класи в простори імен. Продумайте правильну структуру створених просторів. 
Використо-вуючи механізм просторів напишіть код з тестування отриманої програми.*/

namespace fraction {
	class Fraction {
	private:
		int numerator;
		int denominator;
		friend Fraction operator+ (const Fraction& p1, const Fraction& p2);
		friend Fraction operator- (const Fraction& p1, const Fraction& p2);
		friend Fraction operator* (const Fraction& p1, const Fraction& p2);
		friend Fraction operator/ (const Fraction& p1, const Fraction& p2);

	public:
		//getters
		int getNum() {
			return numerator;
		}

		int getDen() {
			return denominator;
		}

		Fraction(int numerator = 0, int denominator = 1) {
			if (denominator == 0) {
				cout << "Denominator is zero!" << endl;
			}
			else {
				this->numerator = numerator;
				this->denominator = denominator;
			}
		}
	};

	Fraction operator+ (const Fraction& p1, const Fraction& p2) {
		return Fraction((p2.denominator * p1.numerator) + (p2.numerator * p1.denominator), p1.denominator * p2.denominator);
	}

	Fraction operator- (const Fraction& p1, const Fraction& p2) {
		return Fraction((p2.denominator * p1.numerator) - (p2.numerator * p1.denominator), p1.denominator * p2.denominator);
	}

	Fraction operator* (const Fraction& p1, const Fraction& p2) {
		return Fraction(p1.numerator * p2.numerator, p1.denominator * p2.denominator);
	}

	Fraction operator/ (const Fraction& p1, const Fraction& p2) {
		return Fraction(p1.numerator * p2.denominator, p1.denominator * p2.numerator);
	}
}

namespace Pets {
	class HomePet abstract
	{
	protected:
		string name;
	public:
		HomePet() {
			this->name = "unknown";
		}

		HomePet(string name) {
			this->name = name;
		}

		virtual void about() = 0;
		virtual string getType() = 0;

		void setName(string name)
		{
			this->name = name;
		}

		string getName()
		{
			return this->name;
		}

		virtual ~HomePet() {
			this->name.clear();
		}
	};

	class Dog : public HomePet {
	protected:
		string type;
	public:
		Dog() {
			this->type = "unknown";
		}

		Dog(string name, string type) : HomePet(name)
		{
			this->type = type;
		}

		virtual void about()
		{
			cout << "This " << getType() << " is " << getName() << endl;
		}
		void setType(string type)
		{
			this->type = type;
		}
		virtual string getType()
		{
			return this->type;
		}
		virtual ~Dog() {
			this->type.clear();
		}
	};

	class Cat : public HomePet {
	protected:
		string type;
	public:
		Cat() {
			this->type = "unknown";
		}

		Cat(string name, string type) : HomePet(name)
		{
			this->type = type;
		}

		virtual void about()
		{
			cout << "This " << getType() << " is " << getName() << endl;
		}
		void setType(string type)
		{
			this->type = type;
		}
		virtual string getType()
		{
			return this->type;
		}
		virtual ~Cat() {
			this->type.clear();
		}
	};

	class Parrot : public HomePet {
	protected:
		string type;
	public:
		Parrot() {
			this->type = "unknown";
		}

		Parrot(string name, string type) : HomePet(name)
		{
			this->type = type;
		}

		virtual void about()
		{
			cout << "This " << getType() << " is " << getName() << endl;
		}
		void setType(string type)
		{
			this->type = type;
		}
		virtual string getType()
		{
			return this->type;
		}
		virtual ~Parrot() {
			this->type.clear();
		}
	};
}

namespace passport {
	class Passport {
	protected:
		string name;
		string surname;
		short age;
		int passportNumber;
	public:
		Passport() {
			this->name = "Incogrito";
			this->surname = "Incogrito";
			this->age = 18;
			this->passportNumber = 12345;
		}
		Passport(string name, string surname, short age, int passportNumber) {
			this->name = name;
			this->surname = surname;
			this->age = age;
			this->passportNumber = passportNumber;
		}

		string getName() { return name; }
		string getSurname() { return surname; }
		short getAge() { return age; }
		int getPassportNumber() { return passportNumber; }

		~Passport() {
			cout << "del passport" << endl;
			this->name.clear();
			this->surname.clear();
			this->age = 0;
			this->passportNumber = 0;
		}
	};

	class ForeignPassport : public Passport {
	protected:
		bool visa;
		int ForeignPassportNumber;
	public:
		ForeignPassport() {
			this->visa = false;
			this->ForeignPassportNumber = 54321;
		}

		ForeignPassport(bool visa, int ForeignPassportNumber) {
			this->visa = visa;
			this->ForeignPassportNumber = ForeignPassportNumber;
		}

		bool getVisa() { return visa; }
		int getForeignPassportNumber() { return ForeignPassportNumber; }

		~ForeignPassport() {
			cout << "del ForeignPassport" << endl;
			this->visa = false;
			this->ForeignPassportNumber = 0;
		}
	};
}

namespace cats_sound {
	void sound(){
		cout << "Myau!" << endl;
	}
}

namespace dogs_sound {
	void sound() {
		cout << "Barking!" << endl;
	}
}

namespace parrots_sound {
	void sound() {
		cout << "Parrot sound!" << endl;
	}
}

int main() {
	fraction::Fraction p1(3, 7);
	fraction::Fraction p2(2, 5);
	fraction::Fraction p3 = p1 + p2;
	fraction::Fraction p4 = p1 - p2;
	fraction::Fraction p5 = p1 * p2;
	fraction::Fraction p6 = p1 / p2;

	cout << "+ " << p3.getNum() << "/" << p3.getDen() << "\n";
	cout << "- " << p4.getNum() << "/" << p4.getDen() << "\n";
	cout << "* " << p5.getNum() << "/" << p5.getDen() << "\n";
	cout << "/ " << p6.getNum() << "/" << p6.getDen() << "\n";

	cout << "-----------------------------------------------------\n\n";

	Pets::HomePet** homePet = new Pets::HomePet * [3] {
		new Pets::Dog("Bobik", "Dog"),
			new Pets::Cat("Pushok", "Cat"),
			new Pets::Parrot("Kesha", "Parrot"),
	};
	for (size_t i = 0; i < 3; i++)
	{
		homePet[i]->about();
	}
	cout << "\n\n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << homePet[i]->getName() << endl;
	}
	cout << "\n\n";
	dogs_sound::sound();
	cats_sound::sound();
	parrots_sound::sound();
	cout << "\n\n";
	for (size_t i = 0; i < 3; i++)
	{
		delete homePet[i];
	}

	cout << "-----------------------------------------------------\n\n";

	passport::ForeignPassport* foreignpassport = new passport::ForeignPassport();
	cout << foreignpassport->getName() << " " << foreignpassport->getSurname() << endl;
	cout << foreignpassport->getAge() << endl << "Passport Number: "
		<< foreignpassport->getPassportNumber() << endl << "Foreign Passport Number: "
		<< foreignpassport->getForeignPassportNumber() << endl << foreignpassport->getVisa();
	cout << "\n\n";
	delete foreignpassport;

	return 0;
}