#include "commercial.h"

// Конструктор по умолчанию
Commercial::Commercial() : Flat(), rental_price(0), lease_duration(0) {}

// Конструктор с параметрами
Commercial::Commercial(float rental_price, int lease_duration)
  : Flat(),
  rental_price(rental_price), lease_duration(lease_duration) {}

// Метод для ввода данных с клавиатуры
void Commercial::inputFromConsole() {
  Flat::inputFromConsole();
  cout << "Оплата за квартиру: ";
  cin >> rental_price;
  cout << "Количество месяцев для оплаты";
  cin >> lease_duration;
}

// Метод для чтения данных из файла
void Commercial::readFromFile(ifstream &in) {
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
  rental_price= atof(temp.c_str());

  getline(in, temp);
  lease_duration = atoi(temp.c_str());
}

// Метод для вывода данных на экран
void Commercial::display() const {
  cout << "Коммерческая квартира -- " << "Комнат: " << rooms << ", Общая площадь: " << total_area << " кв.м"
    << ", Жилая площадь: " << living_area << " кв.м"
    << ", Балконов: " << balconies << ", Этаж: " << floor << "/" << storeys
    << ", Район: " << district << ", Оплата в месяц: " << rental_price 
    << ", Количество месяцев: " << lease_duration << endl;
}

// Метод для записи данных в текстовый файл
void Commercial::writeToFile(ofstream &out) const {
  out << "3;" << rooms << ";" << total_area << ";" << living_area << ";" << balconies
    << ";" << floor << ";" << storeys << ";" << district << ";" << rental_price << ";" << lease_duration << endl;
}


bool Commercial::operator ==(Commercial other) {
  if(rooms == other.rooms && total_area == other.total_area 
    && living_area == other.living_area && balconies == other.balconies 
    && floor == other.floor && storeys == other.storeys && district == other.district
    && rental_price == other.rental_price && lease_duration == other.lease_duration ) {
    return true;
  }

  return false;
}

ostream& operator<<(ostream& stream, const Commercial& commercial) {
  stream << "Коммерческая квартира -- " << "Комнат: " << commercial.rooms << ", Общая площадь: " << commercial.total_area << " кв.м"
    << ", Жилая площадь: " << commercial.living_area << " кв.м"
    << ", Балконов: " << commercial.balconies << ", Этаж: " << commercial.floor << "/" << commercial.storeys
    << ", Район: " << commercial.district << ", Оплата в месяц: " << commercial.rental_price 
    << ", Количество месяцев: " << commercial.lease_duration << endl;

  return stream;
}
istream& operator>>(istream& stream, Commercial& commercial) {
  stream >> commercial.rooms;
  stream >> commercial.total_area;
  stream >> commercial.living_area;
  stream >> commercial.balconies;
  stream >> commercial.floor;
  stream >> commercial.storeys;
  getline(stream, commercial.district);
  stream >> commercial.rental_price;
  stream >> commercial.lease_duration;

  return stream;
}
ofstream& operator<<(ofstream& stream, const Commercial& commercial) {
  stream << "3;" << commercial.rooms << ";" << commercial.total_area << ";" << commercial.living_area << ";" << commercial.balconies
    << ";" << commercial.floor << ";" << commercial.storeys << ";" << commercial.district
    << ";" << commercial.rental_price << ";" << commercial.lease_duration << endl;


  return stream;
}
ifstream& operator>>(ifstream& stream, Commercial& commercial) {
  string temp;

  getline(stream, temp, ';');
  commercial.rooms = atoi(temp.c_str());

  getline(stream, temp, ';');
  commercial.total_area = atof(temp.c_str());

  getline(stream, temp, ';');
  commercial.living_area = atof(temp.c_str());

  getline(stream, temp, ';');
  commercial.balconies = atoi(temp.c_str());

  getline(stream, temp, ';');
  commercial.floor = atoi(temp.c_str());

  getline(stream, temp, ';');
  commercial.storeys = atoi(temp.c_str());

  getline(stream, commercial.district, ';');

  getline(stream, temp, ';');
  commercial.rental_price = atof(temp.c_str());

  getline(stream, temp);
  commercial.lease_duration = atoi(temp.c_str());

  return stream;
}
