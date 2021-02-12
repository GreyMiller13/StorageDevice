#pragma once
#include "IDataProcessing.h"
#include <iostream>

using namespace std;

class MD : public IDataProcessing {
private:
	const double totalAmountOfinfomation = 200;
	double freeAmountOfInformation = 0;
	double occupiedAmountOfInformation = 0;
public:
	MD() {}

	MD(double occupiedAmountOfInformation) {
		try {
			if (occupiedAmountOfInformation > totalAmountOfinfomation) {
				throw 2.0;
			} else if (occupiedAmountOfInformation < 0) {
				throw - 1;
			} else {
				this->occupiedAmountOfInformation = occupiedAmountOfInformation;
			}
		} catch (double) {
			cout << "Носитель не имеет столько памяти" << endl;
		} catch (int) {
			cout << "Некорректный объем памяти" << endl;
		}
	}

	void Reading() override {
		(occupiedAmountOfInformation == 0) ? cout << "Носитель не содержит информации" << endl :
											 cout << "Вывелась информация содержащаяся на носителе" << endl;
	}

	void Recording(double file) override {
		(freeAmountOfInformation - file >= 0) ? cout << "Записана информация на носитель" << endl :
												cout << "Недостаточно свободного места для записи" << endl;
	}

	void Search() override { cout << "Вывод результата поиска" << endl; }

	void AmountOfInformation() override {
		cout << "Общий объем информации носителя: " << totalAmountOfinfomation << endl;
		cout << "Осталось свободного места на носителе: " << totalAmountOfinfomation - occupiedAmountOfInformation << endl;
	}

	void Formatting() override {
		occupiedAmountOfInformation = 0;
		freeAmountOfInformation = totalAmountOfinfomation;
		cout << "Носитель успешно отформатирован" << endl;
	}
};