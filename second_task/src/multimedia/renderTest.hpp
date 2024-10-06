#ifndef __RENDER_TEST_HPP__
#define __RENDER_TEST_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>
#include <QPen>
#include <QBrush>

class RenderTest : public QWidget {
    Q_OBJECT

public:
	enum Shape {
		Polygon,
		Rect,
		RoundedRect,
		Ellipse,
		Custom
	};

    RenderTest(QWidget *parent = 0);
    virtual ~RenderTest();

	void setShape(Shape new_shape);
	void setPen(const QPen &new_pen);
	void setBrush(const QBrush &new_brush);

	void paintEvent(QPaintEvent* event) override;
private:
	Shape shape_ = Polygon;
	QPen pen_;
	QBrush brush_;
};

#endif // WIDGET_H
