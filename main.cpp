#include "flat.h"
#include "flat_collection.h"
#include <fstream>
#include <functional>
#include <iostream>
#include <ostream>
#include <tuple>
using namespace std;

using FunctionType = std::function<void()>;

// Функция для вывода квартир в файл (бинарный)
void outputFlatsToFileBin(Flat *&flats, int &num_flats) {
  string filename;

  cout << "\nЗапись новой квартиры в файл (бинарный):\n";
  cout << "Введите имя файла: ";
  cin >> filename;

  ofstream file(filename, ios::binary);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
  }

  for (int i = 0; i < num_flats; ++i) {
    file.write((char *)&flats[i], sizeof(flats[i]));
    flats[i].writeToFile(file);
  }
}

int main() {

  FlatCollection flats;

  tuple<const char *, FunctionType> menu[] = {
      make_tuple("Input from console",
                 std::bind(&FlatCollection::flatsFromConsole, &flats)),
      make_tuple("Input from file",
                 std::bind(&FlatCollection::flatsFromFile, &flats)),
      make_tuple("Display all flats",
                 std::bind(&FlatCollection::display, &flats)),
      make_tuple("Display all flats top floor",
                 std::bind(&FlatCollection::displayAllFlatsTopFloor, &flats)),
      make_tuple("Calculate total area by input",
                 std::bind(&FlatCollection::calculateTotalAreaByInput, &flats)),
      make_tuple("Remove element by index",
                 std::bind(&FlatCollection::removeFromConsole, &flats)),
      make_tuple("Clean all elements",
                 std::bind(&FlatCollection::clean, &flats)),
      make_tuple("Output flats to file",
                 std::bind(&FlatCollection::writeToFile, &flats))};
  int menu_count = sizeof(menu) / sizeof(menu[0]);

  cout << "Начало работы программы" << endl;
  int select = -1;
  do {
    cout << endl << "Меню: " << endl;

    // Выводим меню программы
    for (int i = 0; i < menu_count; i++) {
      cout << i << ". " << get<0>(menu[i]) << endl;
    }

    cout << endl
         << "Выберите номер (любое другое число это выход из программы): ";
    if (!(cin >> select)) {
      select = -1;
    }

    if (select >= 0 && select < menu_count)
      get<1>(menu[select])();
    else
      cout << "Выход из приложения";

    cout << endl;

  } while (select >= 0 && select < menu_count);

  return 0;
}
