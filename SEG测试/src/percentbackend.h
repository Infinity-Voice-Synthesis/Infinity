#ifndef PERCENTBACKEND_H
#define PERCENTBACKEND_H

#include <QObject>
#include <QThread>
#include <QLibrary>

typedef double (*GetFunction)(QObject *);
typedef bool (*CheckFunction)(QObject *);

class percentbackend : public QThread
{
    Q_OBJECT
public:
    explicit percentbackend(QObject *parent = nullptr);
    QObject *segptr=nullptr;
    QLibrary *library=nullptr;
protected:
    void run() override;

signals:
    void percentchanged(double value);
    void segfinished();
private:
    double percent=100;
};

#endif // PERCENTBACKEND_H
