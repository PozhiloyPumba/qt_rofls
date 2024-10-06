#ifndef __MULTIMEDIA_HPP__
#define __MULTIMEDIA_HPP__

#include <tuple>

#include <QWidget>
#include <QScopedPointer>
#include "renderTest.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Multimedia;
}
QT_END_NAMESPACE

class Multimedia : public QWidget {
    Q_OBJECT

public:
    Multimedia(QWidget *parent = 0);
    virtual ~Multimedia();

public slots:
	void shapeChanged();
	void penChanged();
	void brushChanged();

private:
	QScopedPointer<Ui::Multimedia> ui;
	QScopedPointer<RenderTest> renderTest;
	QBrush textureBrush;

	void resizeEvent(QResizeEvent* event) override;

	using ArgType =  std::tuple<const char *, const int>;
	constexpr static inline ArgType penStyles[] = {
		{"Solid", Qt::SolidLine},
		{"Dash", Qt::DashLine},
		{"Dot", Qt::DotLine},
		{"Dash Dot", Qt::DashDotLine},
		{"Dash Dot Dot", Qt::DashDotDotLine},
		{"None", Qt::NoPen}
	};

	constexpr static inline ArgType shapes[] = {
		{"Polygon", RenderTest::Polygon},
		{"Rectangle", RenderTest::Rect},
		{"Rounded Rectangle", RenderTest::RoundedRect},
		{"Ellipse", RenderTest::Ellipse},
		{"Custom", RenderTest::Custom}
	};

	constexpr static inline ArgType penCaps[] = {
		{"Flat", Qt::FlatCap},
		{"Square", Qt::SquareCap},
		{"Round", Qt::RoundCap}
	};

	constexpr static inline ArgType penJoins[] = {
		{"Miter", Qt::MiterJoin},
		{"Bevel", Qt::BevelJoin},
		{"Round", Qt::RoundJoin}
	};

	constexpr static inline ArgType brushStyles[] = {
		{"Linear Gradient", Qt::LinearGradientPattern},
		{"Radial Gradient", Qt::RadialGradientPattern},
		{"Conical Gradient", Qt::ConicalGradientPattern},
		{"Texture", Qt::TexturePattern},
		{"Solid", Qt::SolidPattern},
		{"Horizontal", Qt::HorPattern},
		{"Vertical", Qt::VerPattern},
		{"Cross", Qt::CrossPattern},
		{"Backward Diagonal", Qt::BDiagPattern},
		{"Forward Diagonal", Qt::FDiagPattern},
		{"Diagonal Cross", Qt::DiagCrossPattern},
		{"Dense 1", Qt::Dense1Pattern},
		{"Dense 2", Qt::Dense2Pattern},
		{"Dense 3", Qt::Dense3Pattern},
		{"Dense 4", Qt::Dense4Pattern},
		{"Dense 5", Qt::Dense5Pattern},
		{"Dense 6", Qt::Dense6Pattern},
		{"Dense 7", Qt::Dense7Pattern},
		{"None", Qt::NoBrush}
	};

};

#endif // WIDGET_H
