#include "renderTest.hpp"
#include <QPainterPath>

RenderTest::RenderTest(QWidget *parent) :
    QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
  	setAutoFillBackground(true);
}

RenderTest::~RenderTest()
{
}

void RenderTest::paintEvent(QPaintEvent* event) {
	qDebug() << "In paint event multimedia " << width() << height();

    QPainter p(this);
}
