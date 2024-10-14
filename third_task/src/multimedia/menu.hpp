#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidget>

#define N_MAX_COUNT 100

class Menu : public QWidget {
    Q_OBJECT

public:
    Menu(QWidget *parent = 0);
    virtual ~Menu();

	void paintEvent(QPaintEvent* event) override;
private:
	QScopedPointer<QSpinBox> nSpinBox;
	QScopedPointer<QGridLayout> layout;
	QScopedPointer<QLabel> nSpinBoxName;
	QScopedPointer<QTableWidget> input;
	QScopedPointer<QPushButton> drawPolygon;
	QScopedPointer<QPushButton> deletePolygon;
};

#endif
