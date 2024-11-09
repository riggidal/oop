#ifndef FLAT_COMMERCIAL
#define FLAT_COMMERCIAL

#include <fstream>
#include <iostream>
#include <string>
#include "flat.h"
using namespace std;

class Commercial : public Flat {
private:
  float rental_price; // Оплата
  int lease_duration; // Продолжительность аренды

public:
  // Конструктор по умолчанию
  Commercial();

  // Конструктор с параметрами
  Commercial(float rental_price, int lease_duration);

  // Метод для ввода данных с клавиатуры
  virtual void inputFromConsole();

  // Метод для вывода данных на экран
  virtual void display() const;

  // Метод для записи данных в файл
  virtual void writeToFile(ofstream &out) const;

  // Метод для чтения данных из файла
  virtual void readFromFile(ifstream &in);

  bool operator ==(Commercial);
  friend ostream& operator<<(ostream&, const Commercial&);
  friend istream& operator>>(istream&, Commercial&);
  friend ofstream& operator<<(ofstream&, const Commercial&);
  friend ifstream& operator>>(ifstream&, Commercial&);

};

#endif // FLAT_PENTHOUSE
