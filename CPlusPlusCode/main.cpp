#include <iostream>
using namespace std;

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
	virtual int getYear() = 0;

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
	int year;
public:
	Dog() {
		this->type = "unknown";
		this->year = 0;
	}

	Dog(string name, string type, int year) : HomePet(name)
	{
		try {
			if (year > 15) {
				throw exception("Dogs don't live that long");
			}
			else {
				this->type = type;
				this->year = year;
			}
		}
		catch (exception ex) {
			cout << ex.what() << endl;
		}
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
	virtual int getYear()
	{
		return this->year;
	}
	virtual ~Dog() {
		this->type.clear();
	}
};

class Cat : public HomePet {
protected:
	string type;
	int year;
public:
	Cat() {
		this->type = "unknown";
		this->year = 0;
	}

	Cat(string name, string type, int year) : HomePet(name)
	{
		try {
			if (year > 15) {
				throw exception("Cats don't live that long");
			}
			else {
				this->type = type;
				this->year = year;
			}
		}
		catch (exception ex) {
			cout << ex.what() << endl;
		}
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
	virtual int getYear()
	{
		return this->year;
	}
	virtual ~Cat() {
		this->type.clear();
	}
};

class Parrot : public HomePet {
protected:
	string type;
	int year;
public:
	Parrot() {
		this->type = "unknown";
		this->year = 0;
	}

	Parrot(string name, string type, int year) : HomePet(name)
	{
		try {
			if (year > 15) {
				throw exception("Parrots don't live that long");
			}
			else {
				this->type = type;
				this->year = year;
			}
		}
		catch (exception ex) {
			cout << ex.what() << endl;
		}
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
	virtual int getYear()
	{
		return this->year;
	}
	virtual ~Parrot() {
		this->type.clear();
	}
};

int main() {
	HomePet** homePet = new HomePet * [3] {
		new Dog("Bobik", "Dog", 5),
			new Cat("Pushok", "Cat", 20),
			new Parrot("Kesha", "Parrot", 3),
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
	for (size_t i = 0; i < 3; i++)
	{
		cout << homePet[i]->getYear() << endl;
	}
	cout << "\n\n";
	for (size_t i = 0; i < 3; i++)
	{
		delete homePet[i];
	}

	return 0;
}