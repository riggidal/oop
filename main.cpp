#include "flat.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <tuple>
using namespace std;

using FunctionType = void (*)(Flat *&, int &);

// Функция для расчета общей площади квартир в указанном районе
void calculateTotalAreaByInput(Flat *&flats, int &num_flats) {
  string district;
  int continue_input;

  do {
    cout << "Введите название района для расчета общей площади: ";
    cin.ignore();
    getline(cin, district, '\n');

    float total_area = 0;
    for (int i = 0; i < num_flats; ++i) {
      if (flats[i].getDistrict() == district) {
        total_area += flats[i].getTotalArea();
      }
    }

    cout << "Общая площадь квартир в районе " << district << ": " << total_area
         << " кв.м\n";

    cout << "Хотите продолжить? (1/0): ";
    if (!(cin >> continue_input)) {
      continue_input = -1;
    }

  } while (continue_input == 1);
}

// Функция для чтения из файла
void inputFromFile(Flat *&flats, int &num_flats) {
  string filename;

  cout << "\nЧтение квартир из файла:\n";
  cout << "Введите имя файла: ";
  cin >> filename;

  ifstream file(filename);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
  }

  file >> num_flats;
  file.ignore(); // Игнорируем символ новой строки

  delete[] flats; // Освобождаем массив перед чтением

  flats = new Flat[num_flats];

  // Ввод данных через разделитель ;
  for (int i = 0; i < num_flats; ++i) {
    flats[i].readFromFile(file);
  }

  file.close();
}

// Функция для вывода всех квартир
void displayAllFlats(Flat *&flats, int &num_flats) {
  cout << "\nДанные всех квартир:\n";
  for (int i = 0; i < num_flats; ++i) {
    flats[i].display();
  }
}

// Функция для чтения квартир с консоли
void inputFlatsFromConsole(Flat *&flats, int &num_flats) {
  cout << "\nПолучения квартир с консоли:\n";

  cout << "Количество квартир: ";
  cin >> num_flats;

  delete[] flats; // Освобождаем массив перед чтением

  flats = new Flat[num_flats];

  for (int i = 0; i < num_flats; ++i) {
    flats[i].inputFromConsole();
  }
}

// Функция для вывода квартир в файл
void outputFlatsToFile(Flat *&flats, int &num_flats) {
  string filename;

  cout << "\nЗапись новой квартиры в файл:\n";
  cout << "Введите имя файла: ";
  cin >> filename;

  ofstream file(filename, ios::app);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
  }

  for (int i = 0; i < num_flats; ++i) {
    flats[i].writeToFile(file);
  }
}

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

// Функция для вывода всех квартир на верхнем этаже
void displayAllFlatsTopFloor(Flat *&flats, int &num_flats) {
  cout << "\nКвартиры на верхнем этаже:\n";
  for (int i = 0; i < num_flats; ++i) {
    if (flats[i].isTopFloor()) {
      flats[i].display();
    }
  }
}
int main() {
  int num_flats = 0;
  Flat *flats = new Flat[num_flats];

  tuple<const char *, FunctionType> menu[] = {
      make_tuple("Input from console", inputFlatsFromConsole),
      make_tuple("Input from file", inputFromFile),
      make_tuple("Display all flats", displayAllFlats),
      make_tuple("Display all flats top floor", displayAllFlatsTopFloor),
      make_tuple("Calculate total area by input", calculateTotalAreaByInput),
      make_tuple("Output flats to file", outputFlatsToFile),
      make_tuple("Output flats to file (binary)", outputFlatsToFileBin)};
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
      get<1>(menu[select])(flats, num_flats);
    else
      cout << "Выход из приложения";

    cout << endl;

  } while (select >= 0 && select < menu_count);

  // Освобождение памяти
  delete[] flats;

  return 0;
}
