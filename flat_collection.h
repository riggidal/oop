#ifndef FLAT_COLLECTION_H
#define FLAT_COLLECTION_H

#include "flat.h"
#include "penthouse.h"
#include "commercial.h"
#include "studio.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FlatCollection {
private:
  int count_num; // Количество квартир
  int count_max; // Максимальное хранение элементов
  Flat **flats;   // Хранение элементов

  void increseMaxElemehts();

public:
  // Конструктор по умолчанию
  FlatCollection();

  // Деструктор по умолчанию
  ~FlatCollection();

  // Метод для ввода данных с клавиатуры
  void flatsFromConsole();

  // Метод для чтения данных из файла
  void flatsFromFile();

  // Метод для вывода данных на экран
  void display() const;

  // Метод для записи данных в текстовый файл
  void writeToFile() const;

  // Все квартиры на верхнем этаже => 5
  void displayAllFlatsTopFloor();

  // Расчет по району
  void calculateTotalAreaByInput();

  // Добавить квартиру в коллекцию
  void add(Flat*);

  // Удаление по индексу
  void remove(int);

  // Очистка контейнера
  void clean();

  // Удаление по вводу из консоли
  void removeFromConsole();

  void operator +=(Flat*);

  // Сравнение двух элементов в коллекции
  void diff(int,int);

  void diffByInput();
};

#endif // FLAT_COLLECTION_H
