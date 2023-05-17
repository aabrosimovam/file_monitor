#ifndef STATE_FILE_H
#define STATE_FILE_H
#include <QString>
#include <QFileInfo>
#include <QObject>


class StateFile : public QObject
{
    Q_OBJECT
private:

    QString FName;  //Имя файла
    qint64 FSize;   //Размер файла
    bool ExistStatus;   //Существование файла

public:
    StateFile(const QString & filename); //конструктор

    //геттеры для имени, размера и факта существования
    QString getFName() const;
    qint64 getFSize() const;
    bool getExistStatus() const;

    //перегрузки операторов копирования присвоения и сравнения
    StateFile(const StateFile& temp);
    StateFile & operator =(const StateFile& temp);
    bool operator == (const StateFile& temp) const;


};

#endif // STATE_FILE_H
