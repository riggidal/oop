#include <cstdlib> // Для функции atoi
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Структура для описания квартиры
struct Flat {
  int rooms;         // Количество комнат
  float total_area;  // Общая площадь
  float living_area; // Жилая площадь
  int balconies;     // Количество балконов
  int floor;         // Этаж квартиры
  int storeys;       // Количество этажей в доме
  string district;   // Название района
};

// Функция для чтения данных из файла
Flat *inputFlatsFromFile(const string &filename, int &num_flats) {
  ifstream file(filename);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
    return nullptr;
  }

  file >> num_flats;
  file.ignore(); // Игнорируем символ новой строки
  Flat *flats = new Flat[num_flats];

  // Ввод данных через разделитель ;
  for (int i = 0; i < num_flats; ++i) {
    string temp;

    getline(file, temp, ';'); // Количество комнат
    flats[i].rooms = atoi(temp.c_str());

    getline(file, temp, ';'); // Общая площадь
    flats[i].total_area = atof(temp.c_str());

    getline(file, temp, ';'); // Жилая площадь
    flats[i].living_area = atof(temp.c_str());

    getline(file, temp, ';'); // Количество балконов
    flats[i].balconies = atoi(temp.c_str());

    getline(file, temp, ';'); // Этаж
    flats[i].floor = atoi(temp.c_str());

    getline(file, temp, ';'); // Количество этажей в доме
    flats[i].storeys = atoi(temp.c_str());

    getline(file,
            flats[i].district); // Название района
  }

  file.close();
  return flats;
}

// Функция для вывода данных по всем квартирам
void displayFlats(const Flat *flats, int size) {
  cout << "\nДанные всех квартир:\n";
  for (int i = 0; i < size; ++i) {
    cout << "Квартира #" << i + 1 << ":\n";
    cout << "Количество комнат: " << flats[i].rooms
         << ", Общая площадь: " << flats[i].total_area
         << " кв.м, Жилая площадь: " << flats[i].living_area
         << " кв.м, Балконов: " << flats[i].balconies
         << "\nЭтаж: " << flats[i].floor
         << ", Этажей в доме: " << flats[i].storeys
         << ", Район: " << flats[i].district << endl;
  }
}

// Функция для вывода квартир на верхнем этаже в домах с >= 5 этажами
void displayTopFloorFlats(const Flat *flats, int size) {
  cout << "\nКвартиры на верхних этажах (дома с 5 и более этажами):\n";
  for (int i = 0; i < size; ++i) {
    if (flats[i].floor == flats[i].storeys && flats[i].storeys >= 5) {
      cout << "Квартира в районе " << flats[i].district
           << ", Этаж: " << flats[i].floor
           << ", Общая площадь: " << flats[i].total_area
           << " кв.м, Комнат: " << flats[i].rooms << endl;
    }
  }
}

// Функция для расчета общей площади квартир в указанном районе
void calculateTotalAreaByInput(const Flat *flats, int size) {
  string district;
  int continue_input;

  do {
    cout << "Введите название района для расчета общей площади: ";
    cin.ignore();
    getline(cin, district, '\n');

    float total_area = 0;
    for (int i = 0; i < size; ++i) {
      if (flats[i].district == district) {
        total_area += flats[i].total_area;
      }
    }

    cout << "Общая площадь квартир в районе " << district << ": " << total_area
         << " кв.м\n";

    cout << "Хотите продолжить? (1/0): ";
    cin >> continue_input;

  } while (continue_input == 1);
}

int main() {
  int num_flats;

  // Чтение данных из файла
  Flat *flats = inputFlatsFromFile("flats.txt", num_flats);
  if (flats == nullptr) {
    return 1; // Завершаем программу при ошибке чтения файла
  }

  // Вывод всех квартир
  displayFlats(flats, num_flats);

  // Расчет общей площади по району
  calculateTotalAreaByInput(flats, num_flats);

  // Вывод квартир на верхнем этаже
  displayTopFloorFlats(flats, num_flats);

  // Освобождение памяти
  delete[] flats;

  return 0;
}
