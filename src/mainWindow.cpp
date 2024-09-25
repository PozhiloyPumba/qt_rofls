#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("APP_NAME");
    setCentralWidget(ui->Hueim);
    setWindowFlags(Qt::Window);
    connect(ui->pushButton, &QAbstractButton::clicked, this, 
        [this](){
            const auto &textToPush = ui->textInput->toPlainText();
            qDebug() << "Text to push:" << textToPush;
            ui->textOutput->setText(ui->textInput->toPlainText());
        }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}