#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidgetItem>
#include <QLayoutItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //estas son las dimensiones del hash y del arreglo para la sopa
                                     //el primero es del hash y el segundo es de la sopa

    ; //aqui se le da el tamanio a la sopa
}

void MainWindow::llenar_listaPalabras(){
    QString pal;
    QString dirname = QFileDialog::getOpenFileName(
            this,
            tr("Seleccionar Diccionario"),
            QDir::currentPath() );
    ifstream in(dirname.toStdString().c_str());

    while (in.good())
        {
        string linea;
        getline(in, linea);
        pal = QString::fromStdString(linea);
        pal = pal.toLower();
        list_palabras.push_back(pal);
      //  qDebug()<<pal;
        }
    list_palabras.removeDuplicates();
    tab->Agregar_palabra(list_palabras);
    QMessageBox::about(this,"INFORMACION         ","Palabras Agregadas con exito ");
}

void MainWindow::llenar_array(){
    QString pal;
    QString dirname = QFileDialog::getOpenFileName(
            this,
            tr("Seleccionar Sopa de Letras"),
            QDir::currentPath() );

    ifstream in(dirname.toStdString().c_str());
    int cont=0;
    while (in.good())
        {
         string linea;
         getline(in, linea);
         pal = QString::fromStdString(linea);
         arr_palabras.push_back(pal);
        qDebug()<<pal;
         cont++;
        }
    this->tab = new puzzle(515,cont);
    this->cantidad = cont;
    tab->llenar_tablero(arr_palabras);

}

void MainWindow::llenar_tabla(int cant){
    this->ui->tableWidget->setRowCount(cant);
    this->ui->tableWidget->setColumnCount(cant);
    for (int i=0;i<cant;i++)
    {
        for (int j=0; j<cant;j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(tab->tablero[i][j]);
            this->ui->tableWidget->setItem(i,j,item);
        }
    }
    ui->tableWidget->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    llenar_array();
    llenar_tabla(cantidad);
}

void MainWindow::on_pushButton_clicked()
{
    llenar_listaPalabras();
}

void MainWindow::on_pushButton_3_clicked()
{
    tiempo.start();
    this->tab->Resolver_puzzle();
    int t = tiempo.elapsed();
    qDebug()<<t;
    ui->listWidget->addItems(tab->list_palabras);
    QString time;
    time.setNum(t);
    qDebug()<<tab->list_palabras.count();
    ui->letiempo->setText(time);

}

