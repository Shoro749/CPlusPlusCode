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

int main() {
	HomePet** homePet = new HomePet * [3] {
		new Dog("Bobik", "Dog"),
			new Cat("Pushok", "Cat"),
			new Parrot("Kesha", "Parrot"),
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
		delete homePet[i];
	}

	return 0;
}