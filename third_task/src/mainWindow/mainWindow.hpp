#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <QMainWindow>
#include <QPushButton>
#include <multimedia/renderTest.hpp>
#include <multimedia/menu.hpp>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final: public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

	void drawPolygon();
	void deletePolygon();
private:
    QScopedPointer<Ui::MainWindow> ui;
	QScopedPointer<RenderTest> render;
	QScopedPointer<Menu> menu;
	QScopedPointer<QPushButton> addPolygonButton;
};

#endif