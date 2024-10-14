#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow), render(new RenderTest(this)), menu(new Menu(this)), addPolygonButton(new QPushButton(this))
{
    ui->setupUi(this);
    setWindowTitle("APP_NAME");
    setWindowFlags(Qt::Window);
	setCentralWidget(ui->CentralCoridor);
	
	addPolygonButton->setText("Add Polygon");
	QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
	spLeft.setVerticalStretch(1);
	addPolygonButton->setSizePolicy(spLeft);
	spLeft.setVerticalStretch(19);
	render->setSizePolicy(spLeft);
	spLeft.setVerticalStretch(5);
	menu->setSizePolicy(spLeft);

	ui->MainLayout->addWidget(render.get());
	ui->MainLayout->addWidget(menu.get());
	menu->hide();
	ui->MainLayout->addWidget(addPolygonButton.get());
	connect(addPolygonButton.get(), &QPushButton::clicked, 
		[this]() {
			menu->show();
		}
	);
}

void MainWindow::drawPolygon() {

}

void MainWindow::deletePolygon() {

}

MainWindow::~MainWindow()
{
}