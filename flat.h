#ifndef FLAT_H
#define FLAT_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Flat {
protected:
  int rooms;         // Количество комнат
  float total_area;  // Общая площадь
  float living_area; // Жилая площадь
  int balconies;     // Количество балконов
  int floor;         // Этаж квартиры
  int storeys;       // Количество этажей в доме
  string district;   // Название района

public:
  // Конструктор по умолчанию
  Flat();

  // Метод для ввода данных с клавиатуры
  void inputFromConsole();

  // Метод для чтения данных из файла
  void readFromFile(ifstream &in);

  // Метод для вывода данных на экран
  void display() const;

  // Метод для записи данных в текстовый файл
  void writeToFile(ofstream &out) const;

  // Геттеры
  int getRooms() const { return rooms; }
  float getTotalArea() const { return total_area; }
  float getLivingArea() const { return living_area; }
  int getBalconies() const { return balconies; }
  int getFloor() const { return floor; }
  int getStoreys() const { return storeys; }
  string getDistrict() const { return district; }

  // Условие для квартир на верхнем этаже в домах с >= 5 этажами
  bool isTopFloor() const { return floor == storeys && storeys >= 5; }

  bool operator ==(Flat);
  friend ostream& operator<<(ostream&, const Flat&);
  friend istream& operator>>(istream&, Flat&);
  friend ofstream& operator<<(ofstream&, const Flat&);
  friend ifstream& operator>>(ifstream&, Flat&);
};

#endif // FLAT_H
