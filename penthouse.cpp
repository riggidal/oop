#include "penthouse.h"

// Конструктор по умолчанию
Penthouse::Penthouse() : Flat(), terrace_area(0.0), has_private_elevator(false) {}

// Конструктор с параметрами
Penthouse::Penthouse(float terrace_area, bool has_private_elevator)
  : Flat(),
  terrace_area(terrace_area), has_private_elevator(has_private_elevator) {}

// Метод для ввода данных с клавиатуры
void Penthouse::inputFromConsole() {
  Flat::inputFromConsole();
  cout << "Площадь террасы: ";
  cin >> terrace_area;
  cout << "Наличие частного лифта (1 - да, 0 - нет): ";
  cin >> has_private_elevator;
}

// Метод для чтения данных из файла
void Penthouse::readFromFile(ifstream &in) {
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

  getline(in, temp, ';');
  terrace_area = atof(temp.c_str());

  getline(in, temp, ';');
  has_private_elevator = atoi(temp.c_str());
}

// Метод для вывода данных на экран
void Penthouse::display() const {
  cout << "Пентхаус -- " << "Комнат: " << rooms << ", Общая площадь: " << total_area << " кв.м"
    << ", Жилая площадь: " << living_area << " кв.м"
    << ", Балконов: " << balconies << ", Этаж: " << floor << "/" << storeys
    << ", Район: " << district << ", Площадь террасы: " << terrace_area 
    << ", Частный лифт: " << has_private_elevator << endl;
}

// Метод для записи данных в текстовый файл
void Penthouse::writeToFile(ofstream &out) const {
  out << rooms << ";" << total_area << ";" << living_area << ";" << balconies
    << ";" << floor << ";" << storeys << ";" << district << ";" << terrace_area << ";" << has_private_elevator << endl;
}


bool Penthouse::operator ==(Penthouse other) {
  if(rooms == other.rooms && total_area == other.total_area 
    && living_area == other.living_area && balconies == other.balconies 
    && floor == other.floor && storeys == other.storeys && district == other.district
    && terrace_area == other.terrace_area && has_private_elevator == other.has_private_elevator ) {
    return true;
  }

  return false;
}

ostream& operator<<(ostream& stream, const Penthouse& penthouse) {
  stream << "Пентхаус -- " << "Комнат: " << penthouse.rooms << ", Общая площадь: " << penthouse.total_area << " кв.м"
    << ", Жилая площадь: " << penthouse.living_area << " кв.м"
    << ", Балконов: " << penthouse.balconies << ", Этаж: " << penthouse.floor << "/" << penthouse.storeys
    << ", Район: " << penthouse.district << ", Площадь террасы: " << penthouse.terrace_area 
    << ", Частный лифт: " << penthouse.has_private_elevator << endl;

  return stream;
}
istream& operator>>(istream& stream, Penthouse& penthouse) {
  stream >> penthouse.rooms;
  stream >> penthouse.total_area;
  stream >> penthouse.living_area;
  stream >> penthouse.balconies;
  stream >> penthouse.floor;
  stream >> penthouse.storeys;
  getline(stream, penthouse.district);
  stream >> penthouse.terrace_area;
  stream >> penthouse.has_private_elevator;

  return stream;
}
ofstream& operator<<(ofstream& stream, const Penthouse& penthouse) {
  stream << penthouse.rooms << ";" << penthouse.total_area << ";" << penthouse.living_area << ";" << penthouse.balconies
    << ";" << penthouse.floor << ";" << penthouse.storeys << ";" << penthouse.district
    << ";" << penthouse.terrace_area << ";" << penthouse.has_private_elevator << endl;


  return stream;
}
ifstream& operator>>(ifstream& stream, Penthouse& penthouse) {
  string temp;

  getline(stream, temp, ';');
  penthouse.rooms = atoi(temp.c_str());

  getline(stream, temp, ';');
  penthouse.total_area = atof(temp.c_str());

  getline(stream, temp, ';');
  penthouse.living_area = atof(temp.c_str());

  getline(stream, temp, ';');
  penthouse.balconies = atoi(temp.c_str());

  getline(stream, temp, ';');
  penthouse.floor = atoi(temp.c_str());

  getline(stream, temp, ';');
  penthouse.storeys = atoi(temp.c_str());

  getline(stream, penthouse.district, ';');

  getline(stream, temp, ';');
  penthouse.terrace_area = atof(temp.c_str());

  getline(stream, temp, ';');
  penthouse.has_private_elevator = atoi(temp.c_str());

  return stream;
}
