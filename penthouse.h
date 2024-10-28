#ifndef FLAT_PENTHOUSE
#define FLAT_PENTHOUSE

#include <fstream>
#include <iostream>
#include <string>
#include "flat.h"
using namespace std;

class Penthouse : Flat {
private:
  float terrace_area; // Площадь террасы
  bool has_private_elevator; // Наличие частного лифта

public:
  // Конструктор по умолчанию
  Penthouse();

  // Конструктор с параметрами
  Penthouse(float terrace_area, bool has_private_elevator);

  // Метод для ввода данных с клавиатуры
  void inputFromConsole();

  // Метод для вывода данных на экран
  void display() const;

  // Метод для записи данных в файл
  void writeToFile(ofstream &out) const;

  // Метод для чтения данных из файла
  void readFromFile(ifstream &in);

  bool operator ==(Penthouse);
  friend ostream& operator<<(ostream&, const Penthouse&);
  friend istream& operator>>(istream&, Penthouse&);
  friend ofstream& operator<<(ofstream&, const Penthouse&);
  friend ifstream& operator>>(ifstream&, Penthouse&);

};

#endif // FLAT_PENTHOUSE
