#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow), menu(new Menu(this)), addPolygonButton(new QPushButton(this))
{
    ui->setupUi(this);
	render = new RenderTest(menu);
    setWindowTitle("APP_NAME");
    setWindowFlags(Qt::Window);
	setCentralWidget(ui->CentralCoridor);
	
	ui->MainLayout->addWidget(render, 0, 0, 1, 2);
	ui->MainLayout->addWidget(menu, 0, 1, 1, 1);
	menu->hide();

	addPolygonButton->setText("Add Polygon");
	ui->MainLayout->addWidget(addPolygonButton.get(), 1, 0, 1, 2);

	ui->MainLayout->setColumnStretch(0, 40);
	ui->MainLayout->setColumnStretch(1, 10);
	ui->MainLayout->setRowStretch(0, 99);
	ui->MainLayout->setRowStretch(1, 1);

	connect(addPolygonButton.get(), &QPushButton::clicked, 
		[this]() {
			menu->show();
		}
	);
}

MainWindow::~MainWindow()
{
}