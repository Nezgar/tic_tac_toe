#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include<QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0_0,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_0_1,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_0_2,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_1_0,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_1_1,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_1_2,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_2_0,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_2_1,SIGNAL(clicked()),this,SLOT(change_Text()));
    connect(ui->pushButton_2_2,SIGNAL(clicked()),this,SLOT(change_Text()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_Text(){

    const QPushButton  *button =(QPushButton *) sender();

    if(button == ui->pushButton_0_0){
        ui->lineEdit_0_0->setText(button->text());
        ui->pushButton_0_0->hide();
        field[0][0]=button->text();
        ifWin();
        if(button->text() == "X"){
            AI_choice("O");

        }else{
             AI_choice("X");

        }
 ifWin();
    }else if(button == ui->pushButton_0_1){
        ui->lineEdit_0_1->setText(button->text());
        ui->pushButton_0_1->hide();
        field[0][1]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");

        }else{
             AI_choice("X");

        }
         ifWin();
    }else if(button == ui->pushButton_0_2){
        ui->lineEdit_0_2->setText(button->text());
        ui->pushButton_0_2->hide();
        field[0][2]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");

        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_1_0){
        ui->lineEdit_1_0->setText(button->text());
        ui->pushButton_1_0->hide();
        field[1][0]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_1_1){
        ui->lineEdit_1_1->setText(button->text());
        ui->pushButton_1_1->hide();
        field[1][1]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_1_2){
        ui->lineEdit_1_2->setText(button->text());
        ui->pushButton_1_2->hide();
        field[1][2]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_2_0){
        ui->lineEdit_2_0->setText(button->text());
        ui->pushButton_2_0->hide();
        field[2][0]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_2_1){
        ui->lineEdit_2_1->setText(button->text());
        ui->pushButton_2_1->hide();
        field[2][1]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }else if(button == ui->pushButton_2_2){
        ui->lineEdit_2_2->setText(button->text());
        ui->pushButton_2_2->hide();
        field[2][2]=button->text();
         ifWin();
        if(button->text() == "X"){
            AI_choice("O");
        }else{
             AI_choice("X");
        }
         ifWin();
    }
delete button;
}


void MainWindow::on_pushButton_3_clicked()
{

    ui->pushButton_3->hide();
     ui->pushButton_4->hide();
      ui->pushButton_2->hide();
      X = true;

           ui->label->setText("Ваш знак: X");
           buttonChange("X");


}


void MainWindow::on_pushButton_4_clicked()
{

    ui->pushButton_3->hide();
     ui->pushButton_4->hide();
      ui->pushButton_2->hide();
X=false;
           ui->label->setText("Ваш знак: O");
           field[1][1]="X";
            fillLable1(1,1,"X");
           buttonChange("O");


}


void MainWindow::on_pushButton_2_clicked()
{
    srand(static_cast<unsigned int>(time(0)));
    X =0+rand()%2;
    ui->pushButton_3->hide();
     ui->pushButton_4->hide();
      ui->pushButton_2->hide();
      if(X == true){
           ui->label->setText("Ваш знак: X");
           buttonChange("X");
      }else{
           ui->label->setText("Ваш знак: O");
           field[1][1]="X";
           fillLable1(1,1,"X");
           buttonChange("O");
      }


}

void MainWindow::AI_choice (QString word) {
    int x{0},y{0},z{0},c{0},count1{1},count2{1},O{0},X2{0},O1{0},X1{0},WORK{0};



    for(int i=0;i < 3;i++){
        for(int j=0;j < 3;j++){
if(WORK < 1 ){
           if(field[i][j] == " " && count1 <2) {
               x=i;
               y=j;
               count1++;
               }else if(field[i][j] == "X"){
                   X2++;
               }else if(field[i][j] == "O"){
                   O++;
               }

           if(count1 == 2 && (X2 ==2 || O ==2)){
                field[x][y]=word;
              fillLable1(x,y,word);
               WORK++;
            break;
           }
}
if(WORK < 1 ){
           if(field[j][i] == " " && count2 <2) {
               z=i;
               c=j;

               count2++;
               }else if(field[j][i] == "X"){
                   X1++;
               } if(field[j][i] == "O"){
                   O1++;
               }

           if(count2 == 2 && (X1 ==2 || O1 ==2)){
               field[c][z]=word;
               fillLable1(c,z,word);
                WORK++;
                break;
           }
}
        }
        count1=1;
        count2=1;
        X2=0;
        O=0;
        X1=0;
        O1=0;
    }


    X2=0;
    O=0;
    count1 =1;
    if(WORK < 1 ){
    for(int i=0, j =0;i<3;i++,j++){
        if(field[i][j] == " " && count1 <2){
            x=i;
            y=j;
            count1++;
        }else if(field[i][j] == "X"){
            X2++;
        }else if(field[i][j] == "O"){
            O++;
        }

        if(count1 == 2 && (X2 ==2 || O ==2)){
             field[x][y]=word;
           fillLable1(x,y,word);
           WORK++;
           break;
        }
        }
}
    X2=0;
    O=0;
    count1 =1;


    if(WORK < 1 ){
    for(int i=2, j =0;i > -1 ;i--,j++){
        if(field[i][j] == " " && count1 <2){
            x=i;
            y=j;
            count1++;
        }else if(field[i][j] == "X"){
                X2++;
            }else if(field[i][j] == "O"){
                O++;
            }

        if(count1 == 2 && (X2 ==2 || O ==2)){
            field[x][y]=word;
            fillLable1(x,y,word);
            WORK++;
            break;
        }
        }
    }


if(WORK < 1 ){
    if(field[1][1] ==" "){
            field[1][1]=word;
            fillLable1(1,1,word);
    }else if(field[0][0] ==" "){
        field[0][0]=word;
        fillLable1(0,0,word);
    }else if(field[0][2] ==" "){
        field[0][2]=word;
        fillLable1(0,2,word);
    }else if(field[2][0] ==" "){
        field[2][0]=word;
        fillLable1(2,0,word);
    }else if(field[2][2] ==" "){
        field[2][2]=word;
        fillLable1(2,2,word);
    }
}

    }




void MainWindow::buttonChange(QString i){
    ui->pushButton_0_0->setText(i);
    ui->pushButton_0_1->setText(i);
    ui->pushButton_0_2->setText(i);
    ui->pushButton_1_0->setText(i);
    ui->pushButton_1_1->setText(i);
    ui->pushButton_1_2->setText(i);
    ui->pushButton_2_0->setText(i);
    ui->pushButton_2_1->setText(i);
    ui->pushButton_2_2->setText(i);
}

void MainWindow::fillLable1(int i,int j,QString word){
    if(i == 0 && j==0){
        ui->lineEdit_0_0->setText(word);
        ui->pushButton_0_0->hide();
    }else if(i == 0&&j==1){
        ui->lineEdit_0_1->setText(word);
        ui->pushButton_0_1->hide();
    }else if(i == 0&&j==2){
        ui->lineEdit_0_2->setText(word);
        ui->pushButton_0_2->hide();
    }else if(i == 1&&j==0){
        ui->lineEdit_1_0->setText(word);
        ui->pushButton_1_0->hide();
    }else if(i == 1&&j==1){
        ui->lineEdit_1_1->setText(word);
        ui->pushButton_1_1->hide();
    }else if(i == 1&&j==2){
        ui->lineEdit_1_2->setText(word);
        ui->pushButton_1_2->hide();
    }else if(i == 2&&j==0){
        ui->lineEdit_2_0->setText(word);
        ui->pushButton_2_0->hide();
    }else if(i == 2&&j==1){
        ui->lineEdit_2_1->setText(word);
        ui->pushButton_2_1->hide();
    }else if(i == 2&&j==2){
        ui->lineEdit_2_2->setText(word);
        ui->pushButton_2_2->hide();
    }
}

void MainWindow::ifWin(){

    int O{0},X2{0},O1{0},X1{0};
    QString message {"Ты победил, но я ещё учусь!"},message1{"Не сегодня, ты проиграл!"},message2{"Ну хорошо, ничья!"};



    for(int i=0;i < 3;i++){
        for(int j=0;j < 3;j++){

           if(field[i][j] == "X"){
                   X2++;
               }else if(field[i][j] == "O"){
                   O++;
               }

           if(X2 ==3 && X==true){

                  QMessageBox::information(this,"Победа!",message);
                  QApplication::quit();

           }else if(X2 ==3 && X==false){

                QMessageBox::information(this,"Ахаххаха!",message1);
                       QApplication::quit();
        }else if(O ==3 && X==true){
           QMessageBox::information(this,"Ахаххаха!",message1);

                       QApplication::quit();
        }else if(O ==3 && X==false){
               QMessageBox::information(this,"Победа!",message);
               QApplication::quit();
           }


           if(field[j][i] == "X"){
                   X1++;
               } if(field[j][i] == "O"){
                   O1++;
               }


           if(X1 ==3 && X==true){

               QMessageBox::information(this,"Победа!",message);
                       QApplication::quit();
        }else if(X1 ==3 && X==false){

             QMessageBox::information(this,"Ахаххаха!",message1);
                     QApplication::quit();
     }else if(O1 ==3 && X==true){
 QMessageBox::information(this,"Ахаххаха!",message1);

                     QApplication::quit();
     }else if(O1 ==3 && X==false){
            QMessageBox::information(this,"Победа!",message);
            QApplication::quit();
        }

        }

        X2=0;
        O=0;
        X1=0;
        O1=0;
}


    X2=0;
    O=0;


    for(int i=0, j =0;i<3;i++,j++){
        if(field[i][j] == "X"){
                X2++;
            }else if(field[i][j] == "O"){
                O++;
            }

        if(X2 ==3 && X==true){

               QMessageBox::information(this,"Победа!",message);
                        QApplication::quit();
        }else if(X2 ==3 && X==false){

             QMessageBox::information(this,"Ахаххаха!",message1);
                     QApplication::quit();
     }else if(O ==3 && X==true){
        QMessageBox::information(this,"Ахаххаха!",message1);

                     QApplication::quit();
     }else if(O ==3 && X==false){
            QMessageBox::information(this,"Победа!",message);
           QApplication::quit();
        }
        }

    X2=0;
    O=0;




    for(int i=2, j =0;i > -1 ;i--,j++){
        if(field[i][j] == "X"){
                X2++;
            }else if(field[i][j] == "O"){
                O++;
            }

        if(X2 ==3 && X==true){

               QMessageBox::information(this,"Победа!",message);
                QApplication::quit();
        }else if(X2 ==3 && X==false){

             QMessageBox::information(this,"Ахаххаха!",message1);
             QApplication::quit();
     }else if(O ==3 && X==true){
 QMessageBox::information(this,"Ахаххаха!",message1);

             QApplication::quit();
     }else if(O ==3 && X==false){
           QMessageBox::information(this,"Победа!",message);
            QApplication::quit();
        }
        }

    for(int i=0, p=0;i < 3;i++){
        for(int j=0;j < 3;j++){
            if(field[i][j] != " "){
                p++;
            }
        }
        if(p==9){
            QMessageBox::information(this,"Ничья!",message2);
             QApplication::quit();
        }
    }

}
