#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    C = new conversiones();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enviar(){
    QString num = ui->tnumeros->text().trimmed();
        QStringList temp;
        QString temporal = "";

        for(int i=0; i < num.count();i++){
            if(num.at(i) == '0' || num.at(i) == '1' || num.at(i) == '2' || num.at(i) == '3' || num.at(i) == '4' ||
               num.at(i) == '5' || num.at(i) == '6' || num.at(i) == '7' || num.at(i) == '8' || num.at(i) == '9'){
               temporal += num.at(i);
               if(i == num.count()-1)
                   temp.push_back(temporal);
            }else{
                temp.push_back(temporal);
                temp.push_back(num.at(i));
                temporal = "";
            }
        }
        C->convertir_pos_fija(temp);
        /*QString temp1="";
        for(int i=0; i < C->numeros.count();i++)
            temp1 += C->numeros.at(i);

       // ui->tposfija->setText(temp1);
            */
}

void MainWindow::on_pushButton_2_clicked()
{
}

void MainWindow::on_pushButton_clicked()
{
    //this->ui->tnumeros->clear();
    C->numeros.clear();
    C->operadores.clear();

    this->enviar();
    ui->tnumeros->clear();
    QString txt;
    for(int i=0; i<C->numeros.count();i++){
        if(C->numeros.at(i)==""){
           C->numeros.removeAt(i);
           qDebug()<<C->numeros.at(i);
           i--;
        }
    }

    txt.setNum(C->resolver_pos_fija(C->numeros));
    ui->tnumeros->setText(txt);

}

void MainWindow::on_buno_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"1");
}

void MainWindow::on_bdos_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"2");
}

void MainWindow::on_btres_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"3");
}

void MainWindow::on_bcuatro_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"4");
}

void MainWindow::on_bcinco_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"5");
}

void MainWindow::on_bseis_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"6");
}

void MainWindow::on_bsiete_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"7");
}

void MainWindow::on_bocho_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"8");
}

void MainWindow::on_bnueve_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"9");
}

void MainWindow::on_bcero_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"0");
}

void MainWindow::on_btres_7_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"(");
}

void MainWindow::on_btres_8_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+")");
}

void MainWindow::on_btres_4_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"+");
}

void MainWindow::on_btres_5_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"-");
}

void MainWindow::on_btres_3_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"*");
}

void MainWindow::on_btres_2_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"/");
}

void MainWindow::on_btres_6_clicked()
{
    ui->tnumeros->setText(ui->tnumeros->text()+"^");
}
