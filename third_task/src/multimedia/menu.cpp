#include "menu.hpp"
#include <QHeaderView>
#include <QStringList>
#include "mainWindow/mainWindow.hpp"
#include "delegateField.hpp"

Menu::Menu(QWidget *parent) :
    QWidget(parent), nSpinBox(new QSpinBox), layout(new QGridLayout(this)),
	nSpinBoxName(new QLabel("N", nSpinBox.get())), input(new QTableWidget(3, 2)),
	drawPolygon(new QPushButton), deletePolygon(new QPushButton)
{
	setBackgroundRole(QPalette::Base);
  	setAutoFillBackground(true);

	nSpinBox->setMinimum(3);
	nSpinBox->setMaximum(N_MAX_COUNT);
	nSpinBox->setSingleStep(1);
	drawPolygon->setText("draw");
	deletePolygon->setText("delete");

	QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
	spLeft.setHorizontalStretch(5);
	nSpinBox->setSizePolicy(spLeft);
	spLeft.setHorizontalStretch(1);
	nSpinBoxName->setSizePolicy(spLeft);
	spLeft.setHorizontalStretch(25);
	input->setSizePolicy(spLeft);

	layout->addWidget(nSpinBoxName.get(), 0, 0, 1, 1, Qt::AlignVCenter);
	layout->addWidget(nSpinBox.get(), 0, 1, 1, 1, Qt::AlignVCenter);
	layout->addWidget(input.get(), 0, 2, 3, 1);
	layout->addWidget(drawPolygon.get(), 1, 0, 1, 2);
	layout->addWidget(deletePolygon.get(), 2, 0, 1, 2);

	input->setHorizontalHeaderLabels({"x", "y"});
	input->setShowGrid(true);
	input->setAlternatingRowColors(true);
	input->setStyleSheet("alternate-background-color: AliceBlue;background-color: Beige;");
	input->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	input->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	input->setItemDelegate(new DelegateField(this));

	connect(nSpinBox.get(), &QSpinBox::valueChanged, 
		[this](int n) {
			input->setRowCount(n);
		}
	);

	connect(drawPolygon.get(), &QPushButton::clicked, 
		[this]() {
			((MainWindow*)parentWidget())->drawPolygon();
			hide();
		}
	);
	connect(deletePolygon.get(), &QPushButton::clicked, 
		[this]() {
			((MainWindow*)parentWidget())->deletePolygon();
			hide();
		}
	);
}
// setValidator
// for(int trow=0; trow <= 2; trow++ )
//     {
//         for(int tcolumn=0; tcolumn <= 3; tcolumn++ )
//         {
//             QLineEdit * tableline = new QLineEdit;
//             tableline->setValidator( new QDoubleValidator(0, 100, 2, this) );
//             ui->tableWidget->setCellWidget ( trow, tcolumn,  tableline);
//         }
// }
Menu::~Menu()
{
}

void Menu::paintEvent(QPaintEvent* event) {
	// qDebug() << "In paint event Menu " << width() << height();

    // QPainter p(this);
}
