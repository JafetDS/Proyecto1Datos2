#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/algorithm/string.hpp>
#include <cstring>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    sThread = new Thread(this,&swapstr,&SWA,&SWB);

    progress = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
* \brief Cliente TArgetas: Inicia y mezcla el juego
* @param
*/
void MainWindow::on_mixinit_clicked()
{
    range = col*row;
    int wei = 1200/col;
    int lon = 1200/row;
    Rlist = new int[range];
    slist = new int[range*range];




    for(int i = 0; i<row ;i++){
        for(int j = 0; j<col ;j++){
            QLabel *label = new QLabel(this);
            label->setScaledContents(true);
            QPixmap *pixmap = new QPixmap("://Image/Image2.jpg");
            *pixmap = pixmap->copy(j*wei,i*lon,wei,lon);
           //slist
            label->setPixmap(*pixmap);
            ui->Grid->addWidget(label,i,j);

            labelList.append(label);
            pixmapList.append(pixmap);


        }
    }
    QPixmap *pixmap = new QPixmap("://Image/black.jpg");
    *pixmap = pixmap->scaled(QSize(wei,lon));
    pixmapList[range-1] = &*pixmap;
    labelList[range-1]->setPixmap(*pixmap);


    string msj;


    sThread->sendmsj(msj);




}
/**
* \brief Cliente Rompeca: Empieza a correr el juego en el servidor
* @param
*/
void MainWindow::on_play_clicked()
{
        swap(stoi(SWA),stoi(SWB));
}


void MainWindow::swap(int a,int b){
    QPixmap *var = &*pixmapList[a];

    pixmapList[a] = &*pixmapList[b];

    pixmapList[b] = &*var;

    labelList[a]->setPixmap(*pixmapList[a]);
    labelList[b]->setPixmap(*pixmapList[b]);

//-----------------List swap
    int ivar = Rlist[a];
    Rlist[a] = Rlist[b];
    Rlist[b] = ivar;

}






/**
* \brief Cliente: Boton para el soguiente cambio
* @param
*/
void MainWindow::nextOrder(){


    string sa = SWA;
    string sb = SWB;
    this->sThread->sendmsj("next");
    this->sThread->start();
    //swap(stoi(SWA),stoi(SWB));

    progress = progress+1;
    ui->progressBar->setValue(progress);

}


/**
* \brief Cliente Rompeca: Boton el cambio anterior
* @param
*/
void MainWindow::prevOrder(){
    progress = progress-1;
    ui->progressBar->setValue(progress);
    this->sThread->sendmsj("p");
    this->sThread->start();



}

/**
* \brief Cliente Rompeca: genera lista para resolover el juego
* @param int list[n]
*/
void MainWindow::genRlist(){
    for (int i = 0; i<range ; i++){
        Rlist[i] = i;
        cout<<Rlist[i]<<endl;
    }
}


/**
* \brief Cliente Rompeca: tomar cantidad de fichas
* @param int a, int b
*/
void MainWindow::on_set_clicked()
{
    this->row=ui->spinBoxX->value();
    this->col= ui->spinBoxY->value();
}

/**
* \brief Cliente Rompeca: Resetear el tablero
* @param
*/
void MainWindow::on_reset_clicked()
{
    this->SWA=to_string(ui->spinBoxX->value());
    this->SWB= to_string(ui->spinBoxY->value());

    this->nextOrder();



}
/**
* \brief Cliente: Boton para el soguiente cambio
* @param
*/

void MainWindow::on_next_clicked()
{
    nextOrder();
}











void MainWindow::on_prev_clicked()
{
    prevOrder();
}

