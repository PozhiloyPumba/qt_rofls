#ifndef __RENDER_TEST_HPP__
#define __RENDER_TEST_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>

class RenderTest : public QWidget {
    Q_OBJECT

public:
	enum  Shape {
		Polygon,
		Rect,
		RoundedRect,
		Ellipse,
		Custom
	};

    RenderTest(QWidget *parent = 0);
    virtual ~RenderTest();

	void paintEvent(QPaintEvent* event) override;
};

#endif // WIDGET_H
