#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <iostream>

#include <cstdlib>
#include <ctime>

#include "passwordgenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonFindPasswords_clicked();

    void on_pushButtonClearList_clicked();

private:
    Ui::MainWindow *ui;

    void generatePasswords(const int &inputPasswordsCount, const int &inputPasswordLength);
};

#endif // MAINWINDOW_H
