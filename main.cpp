#include <iostream>
#include "Floppy.h"
#include "HDD.h"
#include "SSD.h"
#include "DVD.h"
#include "CD.h"
#include "MD.h"
#include "Flash.h"
#include "Menu.h"
#include "Template_class.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	/*Menu menu;
	menu.UI();*/

	StorageDevice<double> floppy(2.88, 1.4);
	floppy.AmountOfInformation();

	return 0;
}