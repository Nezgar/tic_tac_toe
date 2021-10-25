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

     bool X{true};
     QString field[3][3]={
         {" "," "," "},
         {" "," "," "},
         {" "," "," "},
     };
private slots:
    void change_Text();
    void AI_choice(QString );
    void buttonChange(QString );
    void fillLable1(int ,int ,QString );
    void ifWin();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
