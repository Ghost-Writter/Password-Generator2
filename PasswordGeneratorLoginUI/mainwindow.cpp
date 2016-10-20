#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFindPasswords_clicked()
{
    int tempPasswordsCount = ui->textEditPasswordsCount->toPlainText().toInt();
    int tempPasswordLength = ui->textEditPasswordLength->toPlainText().toInt();

    generatePasswords(tempPasswordsCount, tempPasswordLength);
}

void MainWindow::generatePasswords(const int &inputPasswordsCount, const int &inputPasswordLength)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    srand((time_t)ts.tv_nsec);

    for(int i = 0; i < inputPasswordsCount; i++)
    {
        QApplication::processEvents();

        QString login = ui->textEditLogin->toPlainText();

        PasswordGenerator password(login.toStdString(), login.length(), inputPasswordLength);
        password.generatePassword();

        QString outputPassword = QString::fromLocal8Bit(password.getPassword().c_str());

        ui->listWidget->insertItem(0, outputPassword);
    }
}

void MainWindow::on_pushButtonClearList_clicked()
{
    ui->textEditLogin->clear();
    ui->textEditPasswordsCount->clear();
    ui->textEditPasswordLength->clear();
    ui->listWidget->clear();
}
