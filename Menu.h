#pragma once
#include <iostream>

using namespace std;

class Menu {
public:
	void UI() {
		cout << "==========================" << endl
			 << "= Выберите тип носителя: =" << endl
			 << "= 1. Floppy              =" << endl
			 << "= 2. HDD                 =" << endl
			 << "= 3. SSD                 =" << endl
			 << "= 4. DVD                 =" << endl
			 << "= 5. CD                  =" << endl
			 << "= 6. MD                  =" << endl
			 << "= 7. Flash drive         =" << endl
			 << "==========================" << endl;
	}
};