#include <tuple>
#include <functional>

#include <QComboBox>

#include "multimedia.hpp"
#include "ui_multimedia.h"

Multimedia::Multimedia(QWidget *parent) :
    QWidget(parent), ui(new Ui::Multimedia), renderTest(new RenderTest)
{
	ui->setupUi(this);
	ui->multimediaLayout->addWidget(renderTest.get(), 0, 0, 1, 2);

	auto addItemMem = QOverload<const QString &, const QVariant &>::of(&QComboBox::addItem);

	auto addItems = [addItemMem] (const auto &elems, const auto &box) {
		using namespace std::placeholders;
		std::for_each(std::begin(elems), std::end(elems), 
			[call_ = std::bind(addItemMem, box, _1, _2)] (auto &styleArgs)
		{
			std::apply(call_, styleArgs);
		}
		);
	};

	addItems(penStyles, ui->penStyleChoose);
	addItems(shapes, ui->shapeChoose);
	addItems(penCaps, ui->penCapChoose);
	addItems(penJoins, ui->penJoinChoose);
	addItems(brushStyles, ui->brushStyleChoose);
}

Multimedia::~Multimedia()
{
}