#include "renderTest.hpp"

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

	QRect rect(10, 20, 80, 60);
	p.drawRect(rect);
}
