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
    ui->tristate->setCheckable(true);
    connect(ui->pushButton, &QAbstractButton::clicked,
        [this](){
            const auto &textToPush = ui->textInput->toPlainText();
            qDebug() << "Text to push:" << textToPush;
            ui->textOutput->setText(textToPush);
            if(ui->tristate->isChecked()) {
                qDebug() << "Unchecked tristate clown button";
                ui->tristate->setChecked(false);
            }
        }
    );
    connect(ui->tristate, &QPushButton::clicked, 
        [this](bool) {
            ui->tristate->setChecked(true);
        }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}