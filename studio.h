#ifndef FLAT_STUDIO
#define FLAT_STUDIO

#include <fstream>
#include <iostream>
#include <string>
#include "flat.h"
using namespace std;

class Studio : public Flat {
private:
  bool furnished_status; // Наличии мебели 
  bool has_kitchen; // Наличие частного лифта

public:
  // Конструктор по умолчанию
  Studio();

  // Конструктор с параметрами
  Studio(bool furnished_status, bool has_kitchen);

  // Метод для ввода данных с клавиатуры
  virtual void inputFromConsole();

  // Метод для вывода данных на экран
  virtual void display() const;

  // Метод для записи данных в файл
  virtual void writeToFile(ofstream &out) const;

  // Метод для чтения данных из файла
  virtual void readFromFile(ifstream &in);

  bool operator ==(Studio);
  friend ostream& operator<<(ostream&, const Studio&);
  friend istream& operator>>(istream&, Studio&);
  friend ofstream& operator<<(ofstream&, const Studio&);
  friend ifstream& operator>>(ifstream&, Studio&);

};

#endif // FLAT_PENTHOUSE
