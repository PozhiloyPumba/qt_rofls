#ifndef __RENDER_TEST_HPP__
#define __RENDER_TEST_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <list>
#include <optional>
#include "polygon/polygon.hpp"

class RenderArea : public QWidget {
    Q_OBJECT

signals:
	void editPolygon(const fig::Polygon &p);

public slots:
	void addPolygon(const fig::Polygon &p);
	void deletePolygon(const size_t id);

public:
    RenderArea(QWidget *parent = 0);
    virtual ~RenderArea();

	void paintEvent(QPaintEvent* event) override;

protected:
	void mousePressEvent(QMouseEvent* event) override;
private:
	using PolygonIterator = std::list<fig::Polygon>::const_iterator;
	std::list<fig::Polygon> polygons_;
	void showContextMenu(const QPoint &pos, const PolygonIterator &p);
};

#endif
