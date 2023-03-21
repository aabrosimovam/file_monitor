#ifndef STATE_FILE_H
#define STATE_FILE_H
#include <QString>
#include <QFileInfo>
#include <QObject>


class StateFile : public QObject
{
    //Q_OBJECT
private:

    QString FName;  //Имя файла
    qint64 FSize;   //Размер файла
    bool ExistStatus;   //Существование файла


public:
    StateFile(); //конструктор по умолчанию
    StateFile(const QString & filename); //конструктор

    //геттеры для имени, размера и факта существования
    QString getFName() const;
    qint64 getFSize() const;
    bool getExistStatus() const;




};

#endif // STATE_FILE_H
