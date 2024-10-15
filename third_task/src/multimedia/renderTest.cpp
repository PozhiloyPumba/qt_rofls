#include "renderTest.hpp"
#include <QPainterPath>
#include "menu.hpp"

RenderTest::RenderTest(QWidget *parent) :
    QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
  	setAutoFillBackground(true);
	connect(parent, SIGNAL(addPoly(fig::Polygon &)), this, SLOT(addPolygon(fig::Polygon &)));
}

RenderTest::~RenderTest()
{
}

void RenderTest::paintEvent(QPaintEvent* event) {
	qDebug() << "In paint event render " << polygons_.size();

    QPainter painter(this);
	std::for_each(polygons_.begin(), polygons_.end(), 
		[&painter, w = width(), h = height()](const auto &p) {
			p.draw(painter, w, h);
		}
	);
}

void RenderTest::addPolygon(fig::Polygon &p) {
	qDebug() << "added Polygon";
	polygons_.push_back(p);
	update();
}