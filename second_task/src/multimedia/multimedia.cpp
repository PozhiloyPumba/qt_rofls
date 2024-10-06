#include <tuple>
#include <functional>

#include <QComboBox>

#include "multimedia.hpp"
#include "ui_multimedia.h"

Multimedia::Multimedia(QWidget *parent) :
    QWidget(parent), ui(new Ui::Multimedia), renderTest(new RenderTest)
{
	ui->setupUi(this);
	ui->multimediaLayout->addWidget(renderTest.get(), 0, 0, 3, 2);

	auto addItemMem = QOverload<const QString &, const QVariant &>::of(&QComboBox::addItem);
	auto addComboBox = [this, addItemMem] (const auto &elems, const auto &box, const auto &slot) {
		using namespace std::placeholders;
		std::for_each(std::begin(elems), std::end(elems), 
			[call_ = std::bind(addItemMem, box, _1, _2)] (auto &styleArgs)
			{
				std::apply(call_, styleArgs);
			}
		);
		connect(box, &QComboBox::activated, this, slot);
	};

	addComboBox(shapes, ui->shapeChoose, &Multimedia::shapeChanged);
	addComboBox(penStyles, ui->penStyleChoose, &Multimedia::penChanged);
	addComboBox(penCaps, ui->penCapChoose, &Multimedia::penChanged);
	addComboBox(penJoins, ui->penJoinChoose, &Multimedia::penChanged);
	addComboBox(brushStyles, ui->brushStyleChoose, &Multimedia::brushChanged);

	connect(ui->penWidthChoose, &QSlider::valueChanged, this, &Multimedia::penChanged);

	textureBrush = QBrush(QPixmap(":/texture.png").scaled({100, 100}, Qt::KeepAspectRatio));
	shapeChanged();
	penChanged();
	brushChanged();
}

void Multimedia::shapeChanged() {
	RenderTest::Shape shape = RenderTest::Shape(ui->shapeChoose->itemData(
		ui->shapeChoose->currentIndex()).toInt());
	renderTest->setShape(shape);
}

void Multimedia::penChanged() {
	int width = ui->penWidthChoose->sliderPosition();
	Qt::PenStyle style = Qt::PenStyle(ui->penStyleChoose->itemData(
		ui->penStyleChoose->currentIndex()).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(ui->penCapChoose->itemData(
		ui->penCapChoose->currentIndex()).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(ui->penJoinChoose->itemData(
		ui->penJoinChoose->currentIndex()).toInt());

	renderTest->setPen(QPen(Qt::blue, width, style, cap, join));
}

void Multimedia::brushChanged() {
  	Qt::BrushStyle style = Qt::BrushStyle(ui->brushStyleChoose->itemData(
    	ui->brushStyleChoose->currentIndex()).toInt());

	auto setupGrad = [this](auto &grad) {
		grad.setColorAt(0.0, Qt::white);
		grad.setColorAt(0.2, Qt::green);
		grad.setColorAt(1.0, Qt::black);
		renderTest->setBrush(grad);
	};

	switch(style) {
		case Qt::LinearGradientPattern: {
			QLinearGradient linearGradient(0, 0, renderTest->width(), renderTest->height());
			setupGrad(linearGradient);
			break;
		}
		case Qt::RadialGradientPattern: {
			QRadialGradient radialGradient(renderTest->width() / 2, renderTest->height() / 2, 
				std::max(renderTest->width() / 2, renderTest->height() / 2), renderTest->width() / 4, renderTest->height() / 4);
			setupGrad(radialGradient);
			break;
		}
		case Qt::ConicalGradientPattern: {
			QConicalGradient conicalGradient(renderTest->width() / 2, renderTest->height() / 2, 150);
			setupGrad(conicalGradient);
			break;
		}
		case Qt::TexturePattern: {
			renderTest->setBrush(textureBrush);
			break;
		}
		default: {
			renderTest->setBrush(QBrush(Qt::green, style));
		}
	}
}

void Multimedia::resizeEvent(QResizeEvent* event) {
	brushChanged();
}

Multimedia::~Multimedia()
{
}