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

  getline(in, district, ';');
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


bool Flat::operator ==(Flat other) {
  if(rooms == other.rooms && total_area == other.total_area 
      && living_area == other.living_area && balconies == other.balconies 
      && floor == other.floor && storeys == other.storeys && district == other.district ) {
    return true;
  }

  return false;
}

ostream& operator<<(ostream& stream, const Flat& flat) {
  stream << "Комнат: " << flat.rooms << ", Общая площадь: " << flat.total_area << " кв.м"
       << ", Жилая площадь: " << flat.living_area << " кв.м"
       << ", Балконов: " << flat.balconies << ", Этаж: " << flat.floor << "/" << flat.storeys
       << ", Район: " << flat.district << endl;

  return stream;
}
istream& operator>>(istream& stream, Flat& flat) {
  stream >> flat.rooms;
  stream >> flat.total_area;
  stream >> flat.living_area;
  stream >> flat.balconies;
  stream >> flat.floor;
  stream >> flat.storeys;
  getline(stream, flat.district);

  return stream;
}
ofstream& operator<<(ofstream& stream, const Flat& flat) {
  stream << flat.rooms << ";" << flat.total_area << ";" << flat.living_area << ";" << flat.balconies
      << ";" << flat.floor << ";" << flat.storeys << ";" << flat.district << endl;


  return stream;
}
ifstream& operator>>(ifstream& stream, Flat& flat) {
  string temp;

  getline(stream, temp, ';');
  flat.rooms = atoi(temp.c_str());

  getline(stream, temp, ';');
  flat.total_area = atof(temp.c_str());

  getline(stream, temp, ';');
  flat.living_area = atof(temp.c_str());

  getline(stream, temp, ';');
  flat.balconies = atoi(temp.c_str());

  getline(stream, temp, ';');
  flat.floor = atoi(temp.c_str());

  getline(stream, temp, ';');
  flat.storeys = atoi(temp.c_str());

  getline(stream, flat.district);

  return stream;
}
