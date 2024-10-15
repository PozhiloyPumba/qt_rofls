#ifndef __RENDER_TEST_HPP__
#define __RENDER_TEST_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "polygon/polygon.hpp"

class RenderTest : public QWidget {
    Q_OBJECT

public:
    RenderTest(QWidget *parent = 0);
    virtual ~RenderTest();

	void paintEvent(QPaintEvent* event) override;
private:
	int temp;
	std::vector<fig::Polygon> polygons_;
public slots:
	void addPolygon(fig::Polygon &p);
};

#endif
