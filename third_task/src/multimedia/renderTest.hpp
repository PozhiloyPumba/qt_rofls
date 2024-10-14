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
    RenderTest(QWidget *parent = 0);
    virtual ~RenderTest();

	void paintEvent(QPaintEvent* event) override;
private:
	
};

#endif
