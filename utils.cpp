
// Метод для записи массива объектов в текстовый файл
void writeArrayToTextFile(const string &filename, Flat *flats, int size) {
  ofstream outFile(filename);
  if (!outFile) {
    cerr << "Ошибка открытия файла для записи: " << filename << endl;
    return;
  }

  for (int i = 0; i < size; ++i) {
    flats[i].writeToFile(
        outFile); // Используем метод writeToFile для записи одного объекта
  }

  outFile.close();
  cout << "Данные успешно записаны в текстовый файл: " << filename << endl;
}

// Метод для записи массива объектов в бинарный файл
void writeArrayToBinaryFile(const string &filename, Flat *flats, int size) {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    cerr << "Ошибка открытия бинарного файла для записи: " << filename << endl;
    return;
  }

  for (int i = 0; i < size; ++i) {
    outFile.write((char *)&flats[i],
                  sizeof(Flat)); // Записываем каждый объект как бинарный блок
  }

  outFile.close();
  cout << "Данные успешно записаны в бинарный файл: " << filename << endl;
}
