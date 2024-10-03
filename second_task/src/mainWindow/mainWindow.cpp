#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow), mouseTracker(new MouseTracker), multimedia(new Multimedia)
{
    ui->setupUi(this);
    setWindowTitle("APP_NAME");
    setWindowFlags(Qt::Window);
	setCentralWidget(ui->CentralCoridor);

    ui->stackedLayouts->addWidget(mouseTracker.get());
    ui->stackedLayouts->addWidget(multimedia.get());
	ui->stackedLayouts->setCurrentWidget(mouseTracker.get());

	connect(ui->cursorTrackingBut, &QAbstractButton::clicked,
        [this](){
			ui->stackedLayouts->setCurrentWidget(mouseTracker.get());
			qDebug() << "Switch to tracking layout";
        }
    );
	connect(ui->multimediaBut, &QAbstractButton::clicked,
        [this](){
			ui->stackedLayouts->setCurrentWidget(multimedia.get());
			qDebug() << "Switch to multimedia layout";
        }
    );
}

MainWindow::~MainWindow()
{
}