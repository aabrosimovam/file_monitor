#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "state_file.h"

class CheckStatus : public QObject
{
    Q_OBJECT
private:
    QList<StateFile> objects; // список самих files


public:
    CheckStatus(); //конструктор по умолчанию
    ~CheckStatus(); //деструктор

    //добавить и удалить файлы из списка
    bool AddFile(const QString &filename);
    bool DeleteFile(const QString &filename);

signals:
    void FileAddMon(StateFile file); // файл добавлен под наблюдение -> сигнал
    void FileDeleteMon(StateFile file); // файл удален из под наблюдения -> сигнал
    void fileCreate(const QString &m_fileName, qint64 m_Size); // файл создали -> сигнал
    void fileChange(const QString &m_fileName, qint64 m_Size); // файл изменили -> сигнал
    void fileDelete(const QString &m_fileName); // файл удалили -> сигнал

public slots:
    void udFile();

};


#endif // CHECKSTATUS_H
