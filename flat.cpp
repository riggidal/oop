#include "flat.h"

// Конструктор по умолчанию
Flat::Flat()
    : rooms(0), total_area(0), living_area(0), balconies(0), floor(0),
      storeys(0), district("") {}

// Метод для ввода данных с клавиатуры
void Flat::inputFromConsole() {
  cout << "Введите количество комнат: ";
  cin >> rooms;
  cout << "Введите общую площадь: ";
  cin >> total_area;
  cout << "Введите жилую площадь: ";
  cin >> living_area;
  cout << "Введите количество балконов: ";
  cin >> balconies;
  cout << "Введите этаж: ";
  cin >> floor;
  cout << "Введите количество этажей в доме: ";
  cin >> storeys;
  cin.ignore(); // Очистка буфера
  cout << "Введите район: ";
  getline(cin, district);
}

// Метод для чтения данных из файла
void Flat::readFromFile(ifstream &in) {
  string temp;

  getline(in, temp, ';');
  rooms = atoi(temp.c_str());

  getline(in, temp, ';');
  total_area = atof(temp.c_str());

  getline(in, temp, ';');
  living_area = atof(temp.c_str());

  getline(in, temp, ';');
  balconies = atoi(temp.c_str());

  getline(in, temp, ';');
  floor = atoi(temp.c_str());

  getline(in, temp, ';');
  storeys = atoi(temp.c_str());

  getline(in, district);
}

// Метод для вывода данных на экран
void Flat::display() const {
  cout << "Комнат: " << rooms << ", Общая площадь: " << total_area << " кв.м"
       << ", Жилая площадь: " << living_area << " кв.м"
       << ", Балконов: " << balconies << ", Этаж: " << floor << "/" << storeys
       << ", Район: " << district << endl;
}

// Метод для записи данных в текстовый файл
void Flat::writeToFile(ofstream &out) const {
  out << rooms << ";" << total_area << ";" << living_area << ";" << balconies
      << ";" << floor << ";" << storeys << ";" << district << endl;
}
