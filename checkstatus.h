#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "state_file.h"

class Monitor : public QObject
{
    Q_OBJECT
private:
    QList<StateFile> objects; // список самих files


public:
    Monitor(); //конструктор по умолчанию

    //добавить и удалить файлы из списка QList
    bool AddFile(const QString &filename);
    bool DeleteFile(const QString &filename);

signals:
    void FileAddMon(StateFile file); // файл добавлен под наблюдение -> сигнал
    void FileDeleteMon(StateFile file); // файл удален из под наблюдения -> сигнал
    void fileCreate(const QString &FName, qint64 FSize); // файл создали -> сигнал
    void fileChange(const QString &FName, qint64 FSize); // файл изменили -> сигнал
    void fileDelete(const QString &FName); // файл удалили -> сигнал

public slots:
    void udFile();

};


#endif // CHECKSTATUS_H
