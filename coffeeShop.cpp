#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class Staff() {
protected:
	string name;
	double salary;
	int level;

public:
	// конструктор
	Staff(string name, double salary, int level) : name(name), salary(salary), level(level) {}

	// деконструктор
	virtual ~Staff() {}

	// методы для получения данных
	string getName() {
		return name;
	}

	double getSalary() {
		return salary;
	}

	int getLevel() {
		return level;
	}

	virtual void work() const {
		cout << name << "выполняет работу" << endl;
	}
}

class Barista : class Staff {
public:
	Barista(string name, double salary, int level) : name(name), salary(salary), level(level) {}

	void work() const override {
		cout << name << "готовит кофе, уровень навыков -> " << level << endl;
	}
};

class Waiter : public Staff {
public:
	Waiter(string name, double salary, int level) : name(name), salary(salary), level(level) {}

	void work() const override {
		cout << name << " обслуживает клиентов, уровень навыка -> " << level << endl;
	}
};

class Ingredients {
private:
	int coffee;
	int milk;
	int sugar;
	int cups;

public:
	Ingredients(int c, int m, int s, int cp) : coffe(c), milk(m), sugar(s), cups(cp) {}

	// Добавление ингридиентов
	void addCoffee(int amount) {
		coffee += amount;
	}

	void addMilk(int amount) {
		milk += amount;
	}

	void addSugar(int amount) {
		sugar += amount;
	}

	void addCups(int amount) {
		cups += amount;
	}

	// Использование ингридиентов
	bool useCoffe(int amount) {
		if (coffee >= amount) {
			coffee -= amount;
			return true
		}
		else {
			return false
		}
	}

	bool useSugar(int amount) {
		if (sugar >= amount) {
			sugar -= amount;
			return true
		}
		else {
			return false
		}
	}

	bool useMilk(int amount) {
		if (milk >= amount) {
			milk -= amount;
			return true
		}
		else {
			return false
		}
	}

	bool useCups(int amount) {
		if (cups >= amount) {
			cups -= amount;
			return true
		}
		else {
			return false
		}
	}

	void printStatus() const {
		cout << "\n <-- Ингредиенты -->" << endl;
		cout << "Кофе:" << coffee << endl;
		cout << "Молоко:" << milk << endl;
		cout << "Сахар:" << sugar << endl;
		cout << "Стаканы:" << cups << endl;
	}
};

class CoffeShop {
private:
	string name;
	double balance;
	Ingredients ingredients;
	vector<Staff*> staff;
	int reputation;
	int day;

public:
	CoffeShop(string n, double b) :
		name(n),
		balance(b),
		ingredients(15, 15, 15, 15),
		reputation(4),
		day(1) {}

	~CofeeShop() {
		for (auto s : staff) {
			delete s;
		}
	}


	void hireStaff(Staff* s) {
		stuff.push_back(s);
	}

	void paySalaries() {
		cout << "\n <-- Выплата зарплат -->" << endl;

		for (const auto& s : staff) {
			if (balance >= s->getSalary()) {
				balance -= s->getSalary();
				cout << "Выплачено" << s->getSalary() << "для" << s->getName() << endl;
			}
			else {
				cout << "Не хватает денег для выплаты зарплаты" << s->getName() << endl;
				reputation--;
			}
		}
	}


	void buyIngredients() {
		int choice;
		int amount;

		cout << "/n<-- Закупка ингредиентов -->" << endl;
		cout << "1. Кофе (5$ за порцию)" << endl;
		cout << "2. Молоко (3$ за порцию)" << endl;
		cout << "3. Сахар (2$ за порцию)" << endl;
		cout << "4. Стаканчик с крышкой (1$ за штуку)" << endl;
		cout << "0. Выход" << endl;
		cout << "Ваш баланс:" << balance << endl;
		cout << "Выберите что купить:" << endl;
		cin >> choice;

		if (choice == 0) return;

		cout << "Сколько купить?";
		cin >> amount;

		switch (choice) {
			case 1:
				if (balance >= amount * 5) {
					ingredients.addCoffee(amount);
					balance -= amount * 5;
					cout << "Куплено" << amount << "порций кофе" << endl;
				}
				else {
					cout << "Недостаточно средств" << endl;
				}

			case 2:
				if (balance >= amount * 3) {
					ingredients.addMilk(amount);
					balance -= amount * 3;
					cout << "Куплено" << amount << "порций молока" << endl;
				}
				else {
					cout << "Недостаточно средств" << endl;
				}

			case 3:
				if (balance >= amount * 2) {
					ingredients.addSugar(amount);
					balance -= amount * 2;
					cout << "Куплено" << amount << "порций сахара" << endl;
				}
				else {
					cout << "Недостаточно средств" << endl;
				}

			case 4:
				if (balance >= amount) {
					ingredients.addCups(amount);
					balance -= amount;
					cout << "Куплено" << amount << "стаканчиков" << endl;
				}
				else {
					cout << "Недостаточно средств" << endl;
				}

			default:
				cout << "Неверный выбор" << endl;
		}
	}

	void serveClients() {
		int clients = rand() % 10 + 1;
		int served = 0;

		cout << "\n<-- Обслуживание клиентов -->" << endl;
		cout << "Сегодня пришло" << clients << "клиентов" << endl;

		for (int i = 0; i < clients; i++) {
			if (ingredients.useCoffe(1)) {
				if (ingredients.useMilk(rand() % 2) {
					if (ingredients.useSugar(rand() % 3)) {
						if (ingredients.useCups()) {
							balance += 10;
							served++;

							cout << "Обслужен клиент №" << i + 1 << endl;

							for (const auto& s : staff) {
								s->work();
							}

							continue;
						}
					}
				}
			}
			cout << "Не удалось обслужить клиента №" << i + 1 << "закончились ингредиенты" << endl;
			reputation--;
		}

		cout << "Обслужено" << served << "клиентов из" << clients << endl;
		cout << "Заработано" << served * 10 << "$" << endl;

		if (served == clients) {
			reputation++;
			cout << "Отличная работа! Репутация повышена" << endl;
		}
	}

	void payBills() {
		double rent = 50;
		double utilites = 30;

		cout << "\n<-- Оплата счетов -->" << endl;
		cout << "Аренда: " << rent << "$" << endl;
		cout << "Комунальные услуги: " << utilites << "$" << endl;

		if (balance >= rent + utilites) {
			balance -= rent + utilites;
			cout << "счета оплачены" << endl;
		}
		else {
			cout << "Не хватает средств для оплаты счетов! Репутация снижена!";
			reputation--;
		}
	}

	void nextDay() {
		day++;
		cout << "\nНаступил " << day << "день" << endl;
	}
	 
}

int main() {

}
}