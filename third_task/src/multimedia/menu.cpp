#include "menu.hpp"
#include <utility>
#include <QHeaderView>
#include <QStringList>
#include <QStandardItemModel>
#include "mainWindow/mainWindow.hpp"
#include "delegateField.hpp"

Menu::Menu(QWidget *parent) :
    QWidget(parent), nSpinBox(new QSpinBox), layerSpinBox(new QSpinBox), layout(new QGridLayout(this)),
	nSpinBoxName(new QLabel("N", nSpinBox.get())), 
	layerSpinBoxName(new QLabel("layer", layerSpinBox.get())), 
	input(new QTableWidget(3, 2)),
	drawPolygon(new QPushButton)
{
	setBackgroundRole(QPalette::Base);
  	setAutoFillBackground(true);

	layerSpinBox->setMinimum(0);
	layerSpinBox->setMaximum(N_MAX_COUNT);
	layerSpinBox->setSingleStep(1);
	nSpinBox->setMinimum(3);
	nSpinBox->setMaximum(N_MAX_COUNT);
	nSpinBox->setSingleStep(1);
	drawPolygon->setText("draw");

	QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
	spLeft.setHorizontalStretch(5);
	nSpinBox->setSizePolicy(spLeft);
	spLeft.setHorizontalStretch(1);
	nSpinBoxName->setSizePolicy(spLeft);
	spLeft.setVerticalStretch(25);
	input->setSizePolicy(spLeft);

	layout->addWidget(nSpinBoxName.get(), 0, 0, 1, 1, Qt::AlignVCenter);
	layout->addWidget(nSpinBox.get(), 0, 1, 1, 1, Qt::AlignVCenter);
	layout->addWidget(layerSpinBoxName.get(), 1, 0, 1, 1, Qt::AlignVCenter);
	layout->addWidget(layerSpinBox.get(), 1, 1, 1, 1, Qt::AlignVCenter);
	layout->addWidget(input.get(), 2, 0, 1, 2);
	layout->addWidget(drawPolygon.get(), 3, 0, 1, 2);

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
			fig::Polygon p = createPolygon();
			if (!p.empty()) {
				hide();
				input->clear();
				input->setHorizontalHeaderLabels({"x", "y"});
				emit addPolygon(p);
				if (deleting.has_value()) {
					qDebug() << "delete on edit";
					emit deletePolygon(deleting.value());
					deleting.reset();
				}
			}
		}
	);
}

Menu::~Menu()
{
}

void Menu::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    painter.drawRoundedRect(2,2,width()-5, height()-5,2,2);

    QWidget::paintEvent(event);
}

fig::Polygon Menu::createPolygon() const {
	qDebug() << "CreatePolygon";
	fig::Polygon p;
	std::vector<QPointF> points;
	auto model = input->model();
	for(int i = 0; i < input->rowCount(); ++i) {
		auto fst = model->data(model->index(i, 0)).toString();
		auto snd = model->data(model->index(i, 1)).toString();
		bool flag = fst.isEmpty();
		flag |= snd.isEmpty();

		if (!flag) {
			double x = fst.toDouble();
			double y = snd.toDouble();
			points.push_back(QPointF(x, y));
		}
		else {
			break;
		}
	}
	if (points.size() != input->rowCount())
		return p;

	p.setPoints(points);
	p.setLayer(layerSpinBox->value());
	return p;
}

void Menu::editPolygon(const fig::Polygon &p) {
	qDebug() << "edit";
	nSpinBox->setValue(p.size());
	layerSpinBox->setValue(p.getLayer());
	input->setHorizontalHeaderLabels({"x", "y"});
	input->setRowCount(p.size());

	auto model = input->model();
	for(int i = 0; i < p.size(); ++i) {
		auto point = p.get_i(i);
		model->setData(model->index(i, 0), point.x());
		model->setData(model->index(i, 1), point.y());
	}

	deleting = p.id_;
	show();
}
