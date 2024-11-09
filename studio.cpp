#include "studio.h"

// Конструктор по умолчанию
Studio::Studio() : Flat(), furnished_status(false), has_kitchen(false) {}

// Конструктор с параметрами
Studio::Studio(bool furnished_status, bool has_kitchen)
  : Flat(),
  furnished_status(furnished_status), has_kitchen(has_kitchen) {}

// Метод для ввода данных с клавиатуры
void Studio::inputFromConsole() {
  Flat::inputFromConsole();
  cout << "Площадь террасы: ";
  cin >> furnished_status;
  cout << "Наличие частного лифта (1 - да, 0 - нет): ";
  cin >> has_kitchen;
}

// Метод для чтения данных из файла
void Studio::readFromFile(ifstream &in) {
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
  furnished_status = atoi(temp.c_str());

  getline(in, temp);
  has_kitchen = atoi(temp.c_str());
}

// Метод для вывода данных на экран
void Studio::display() const {
  cout << "Пентхаус -- " << "Комнат: " << rooms << ", Общая площадь: " << total_area << " кв.м"
    << ", Жилая площадь: " << living_area << " кв.м"
    << ", Балконов: " << balconies << ", Этаж: " << floor << "/" << storeys
    << ", Район: " << district << ", " << (furnished_status ? "Мебелированна" : "Без мебели") 
    << ", Частный лифт: " << (has_kitchen ? "Имеется кухня" : "Отсутствует кухня") << endl;
}

// Метод для записи данных в текстовый файл
void Studio::writeToFile(ofstream &out) const {
  out << rooms << ";" << total_area << ";" << living_area << ";" << balconies
    << ";" << floor << ";" << storeys << ";" << district << ";" << furnished_status << ";" << has_kitchen << endl;
}


bool Studio::operator ==(Studio other) {
  if(rooms == other.rooms && total_area == other.total_area 
    && living_area == other.living_area && balconies == other.balconies 
    && floor == other.floor && storeys == other.storeys && district == other.district
    && furnished_status == other.furnished_status && has_kitchen == other.has_kitchen ) {
    return true;
  }

  return false;
}

ostream& operator<<(ostream& stream, const Studio& studio) {
  stream << "Пентхаус -- " << "Комнат: " << studio.rooms << ", Общая площадь: " << studio.total_area << " кв.м"
    << ", Жилая площадь: " << studio.living_area << " кв.м"
    << ", Балконов: " << studio.balconies << ", Этаж: " << studio.floor << "/" << studio.storeys
    << ", Район: " << studio.district << ", " << (studio.furnished_status ? "Мебелированна" : "Без мебели") 
    << ", Частный лифт: " << (studio.has_kitchen ? "Имеется кухня" : "Отсутствует кухня") << endl;

  return stream;
}
istream& operator>>(istream& stream, Studio& studio) {
  stream >> studio.rooms;
  stream >> studio.total_area;
  stream >> studio.living_area;
  stream >> studio.balconies;
  stream >> studio.floor;
  stream >> studio.storeys;
  getline(stream, studio.district);
  stream >> studio.furnished_status;
  stream >> studio.has_kitchen;

  return stream;
}
ofstream& operator<<(ofstream& stream, const Studio& studio) {
  stream << studio.rooms << ";" << studio.total_area << ";" << studio.living_area << ";" << studio.balconies
    << ";" << studio.floor << ";" << studio.storeys << ";" << studio.district
    << ";" << studio.furnished_status << ";" << studio.has_kitchen << endl;


  return stream;
}
ifstream& operator>>(ifstream& stream, Studio& studio) {
  string temp;

  getline(stream, temp, ';');
  studio.rooms = atoi(temp.c_str());

  getline(stream, temp, ';');
  studio.total_area = atof(temp.c_str());

  getline(stream, temp, ';');
  studio.living_area = atof(temp.c_str());

  getline(stream, temp, ';');
  studio.balconies = atoi(temp.c_str());

  getline(stream, temp, ';');
  studio.floor = atoi(temp.c_str());

  getline(stream, temp, ';');
  studio.storeys = atoi(temp.c_str());

  getline(stream, studio.district, ';');

  getline(stream, temp, ';');
  studio.furnished_status = atof(temp.c_str());

  getline(stream, temp);
  studio.has_kitchen = atoi(temp.c_str());

  return stream;
}
