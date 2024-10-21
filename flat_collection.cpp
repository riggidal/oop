#include "flat_collection.h"
#include "flat.h"
#include <ostream>

// Конструктор по умолчанию
FlatCollection::FlatCollection()
    : count_num(0), count_max(2), flats(new Flat[count_max]) {}

FlatCollection::~FlatCollection() {
  count_num = 0;
  count_max = 0;
  delete[] flats;
}

// Метод для ввода данных с клавиатуры
void FlatCollection::flatsFromConsole() {
  int count_elements;

  cout << "\nПолучения квартир с консоли:\n";

  cout << "Количество квартир: ";
  cin >> count_elements;

  for (int i = 0; i < count_elements; ++i) {
    cout << endl;

    Flat new_flat;
    new_flat.inputFromConsole();

   *this += new_flat;
  }
}

// Удаление по вводу из консоли
void FlatCollection::removeFromConsole() {
  int index;

  cout << "\nУдаление записи по индексу:\n";

  cout << "Индекс квартиры: ";
  cin >> index;

  remove(index);
}

// Метод для чтения данных из файла
void FlatCollection::flatsFromFile() {
  string filename;
  int count_element;

  cout << "\nЧтение квартир из файла:\n";
  cout << "Введите имя файла: ";
  cin >> filename;

  ifstream file(filename);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
  }

  file >> count_element;
  file.ignore(); // Игнорируем символ новой строки

  clean();

  // Ввод данных через разделитель ;
  for (int i = 0; i < count_element; ++i) {
    Flat new_flat;
    file >> new_flat;

   *this += new_flat;
  }

  file.close();
}

// Метод для вывода данных на экран
void FlatCollection::display() const {
  cout << "\nДанные всех квартир:\n";
  for (int i = 0; i < count_num; ++i) {
    cout << flats[i];
  }
}

// Метод для записи данных в текстовый файл
void FlatCollection::writeToFile() const {
  string filename;

  cout << "\nЗапись новой квартиры в файл:\n";
  cout << "Введите имя файла: ";
  cin >> filename;


  ofstream file(filename, ios::app);
  if (!file) {
    cerr << "Ошибка открытия файла: " << filename << endl;
  }

  file << count_num << endl;
  for (int i = 0; i < count_num; ++i) {
    file << flats[i];
  }
}

// Все квартиры на верхнем этаже => 5
void FlatCollection::displayAllFlatsTopFloor() {
  cout << "\nКвартиры на верхнем этаже:\n";
  for (int i = 0; i < count_num; ++i) {
    if (flats[i].isTopFloor()) {
      cout << flats[i];
    }
  }
}

// Расчет по району
void FlatCollection::calculateTotalAreaByInput() {
  string district;
  int continue_input;

  do {
    cout << "Введите название района для расчета общей площади: ";
    cin.ignore();
    getline(cin, district, '\n');

    float total_area = 0;
    for (int i = 0; i < count_num; ++i) {
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

void FlatCollection::clean() {
  count_num = 0;
  count_max = 2;
  delete[] flats;

  flats = new Flat[count_max];
}

void FlatCollection::increseMaxElemehts() {
  int new_count_max = count_max * 2;
  Flat *new_flats = new Flat[new_count_max];

  for (int i = 0; i < count_num; i++) {
    new_flats[i] = flats[i];
  }

  delete[] flats;
  flats = new_flats;
  count_max = new_count_max;
}

void FlatCollection::add(Flat flat) {
  if ((count_num + 1) == count_max) {
    increseMaxElemehts();
  }

  flats[count_num] = flat;
  count_num++;
}

void FlatCollection::remove(int index) {

  Flat *new_flats = new Flat[count_max];

  for (int i = 0, j = 0 ; i < count_num; i++) {
    if (i == index) {
      continue;
    }

    new_flats[j] = flats[i];
    j++;
  }
  
  count_num--;

  delete[] flats;
  flats = new_flats;
}


void FlatCollection::operator +=(const Flat& other){
  add(other);
}
