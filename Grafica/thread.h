#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QObject>
#include <string>
#include <vector>
#include "Server.h"

using namespace std;

class Thread : public QThread
{
    Q_OBJECT
public:
     Thread(QObject *parent = nullptr,string* wstr = nullptr, string* SA = nullptr,string* SB= nullptr);
     void sendmsj(string);
     string* swapstr;
     string* SWA;
     string* SWB;
     Server *Servidor;


protected:
     void run() override;
signals:
     void valswap(string);



};

#endif // THREAD_H
