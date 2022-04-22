#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <thread.h>
#include <Server.h>
#include <QMainWindow>
#include <iostream>
using namespace std;

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int row;
    int col;
    int range;
    QList<QPushButton*> ButtonList;
    QList<QPixmap*> pixmapList;
};
#endif // MAINWINDOW_H
