#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Sovellus käynnistetty";

    //Nappien click-handlerit:
    //värit:
    connect(ui->eka,SIGNAL(clicked(bool)),this,SLOT(colourButtonHandler()));
    connect(ui->toka,SIGNAL(clicked(bool)),this,SLOT(colourButtonHandler()));
    connect(ui->kolmas,SIGNAL(clicked(bool)),this,SLOT(colourButtonHandler()));
    connect(ui->neljas,SIGNAL(clicked(bool)),this,SLOT(colourButtonHandler()));

    connect(ui->check,SIGNAL(clicked(bool)),this,SLOT(checkButtonHandler()));
    connect(ui->startti,SIGNAL(clicked(bool)),this,SLOT(startButtonHandler()));

    pQTimer = new QTimer(this);    //tuhoutuu automaattisesti, kun mainwindow tuhoutuu
    pQTimer->setSingleShot(false);// antaa varmasti jatkuvasti timeoutteja
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(taimeri()));
    pQTimer->start(1000);   //käynnistetään Timeri juoksemaan 1000ms välein
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colourButtonHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    QString sisalto = button->text();
    qDebug() << "Button name: "<< name;
    qDebug() << "Sen sisältö: "<< sisalto;
    if (name=="eka"){
        if (mEka==4){
            mEka=0;
            qDebug() << "mEka 5 to 0";
        }else {
            mEka++;
            qDebug() << "mEka++";
        };
    };
    if (name=="toka"){
        if (mToka==4){
            mToka=0;
            qDebug() << "mToka 5 to 0";
        } else {
            mToka++;
            qDebug() << "mToka++";
        };
    };
    if (name=="kolmas"){
        if (mKolmas==4){
            mKolmas=0;
            qDebug() << "mKolmas 5 to 0";
        } else {
            mKolmas++;
            qDebug() << "mKolmas++";
        };
    };
    if (name=="neljas"){
        if (mNeljas==4){
            mNeljas=0;
            qDebug() << "mNeljas 5 to 0";
        } else {
            mNeljas++;
            qDebug() << "mNeljas++";
        };
    };
    qDebug() << "mEka= "<<mEka;
    qDebug() << "mToka= "<< mToka;
    qDebug() << "mKolmas= "<< mKolmas;
    qDebug() << "mNeljas= "<< mNeljas;
}

void MainWindow::startButtonHandler()
{
    qDebug() << "startButton pressed";
    QString luku = ui->arpoja->text();
    qDebug()<<"Luettiin laatikosta teksti ="<<luku;
    int kerroin = luku.toInt();
    srand(sLuku*kerroin);
    aEka= rand() % 6;
    aToka= rand() % 6;
    aKolmas= rand() % 6;
    aNeljas= rand() % 6;
    qDebug() << "aEka= "<<aEka;
    qDebug() << "aToka= "<< aToka;
    qDebug() << "aKolmas= "<< aKolmas;
    qDebug() << "aNeljas= "<< aNeljas;
}

void MainWindow::checkButtonHandler()
{
    qDebug() << "checkButton pressed";
}

void MainWindow::taimeri()
{
    sLuku++;
    qDebug() << "sLuku= "<<sLuku;
}

