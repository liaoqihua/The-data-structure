#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include "huffman.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel *head_label;
    QVBoxLayout *main_layout;
    QWidget *cenWidget;
    QLineEdit *file_path_lineEdit1;
    QLineEdit *file_path_lineEdit2;
    QLineEdit *file_path_lineEdit3;
    QPushButton *file_path_Button1;
    QPushButton *file_path_Button2;
    QPushButton *file_path_Button3;
    QVBoxLayout *file_path_layout;
    QHBoxLayout *code_layout;
    QPushButton *encode_button;
    QPushButton *decode_button;
    QString sor_file_path;
    QString dst_file_path;
    QString fre_file_path;
    Huffman *h;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initialHead();
    void initialMainWidget();
    void set_blackground(QString icon_path);
    void initialConnect();
    void receiveEncode();
    void receiveDecode();
    void openfile();
    void savefile();
    void frefileAddress();
    void initialChooseLayout();
    void initialCodeLayout();
};

#endif // MAINWINDOW_H
