#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QCoreApplication>
#include <QTextStream>
#include <QDataStream>
#include "QMessageBox"
#include "QPixmap"
#include "QRandomGenerator"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1,5);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*\\,*\\d*"), this));
    QMessageBox msgBox;
    msgBox.setWindowTitle("Заставка");
    msgBox.setText("Група 472.\nМельник Михайло Сергійович.\nЕкзаменаційний білет № 15\nДата 17.04.2020");
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int n,sum;
void MainWindow::on_pushButton_clicked()
{
    sum=0;
    int g=0,m=0,count=0,r;
    n=ui->spinBox->value();
    r=n;
    QString k="",s=ui->lineEdit->text();
    int mas[n][n];
    while (g < s.size())
    {
        back1:
        if(s[g] == ","){
            g++;goto back1;
        }
        while(s[g].isDigit()){
           g++;}count++;}
        if(count!=(n*n)){ui->textBrowser->insertPlainText("Введіть корректну кількість цифер\n");}else{
            g=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
        if(s[g]=="-"){
        m++;g++;}
            back2:
            if(s[g] == ","){
                g++;goto back2;
            }
            while(s[g].isDigit()){
                k=k+s[g];g++;
            }
            mas[i][j] = k.toInt();if(m>0){mas[i][j]=mas[i][j]*-1;}g++;k="";m=0;
    }}
    int j=n-1;
    for(int i=0;i<n;i++){
        sum=sum+mas[i][j];j--;
        }

ui->textBrowser->insertPlainText(QString::number(sum)+"\n");
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    int d=0;
    n=ui->spinBox->value();
    QString ls="";
    for(int i=0;i<n*n;i++){
          std::uniform_int_distribution<int> r(1,9);
          ls=ls+QString::number(r(*QRandomGenerator::global()));
          if(d<n*n-1){
        ls=ls+",";d++;}
    }
 ui->lineEdit->setText(ls);
}

void MainWindow::on_action_triggered()
{
    close();
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Довідка");
    msgBox.setText("Програма для обчислення суми елементiв оберненої дiагоналi.\nВведіть числа через кому.\nДані можуть бути збережені в файл.");
    msgBox.exec();
}

void MainWindow::on_action_3_triggered()
{
    QFile file("C:/Users/User/Desktop/RES.txt");
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
           stream<<"Your sum of reverse diagonal: "<<sum;
}
}
