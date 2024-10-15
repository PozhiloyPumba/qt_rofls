#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

#include <memory>
#include <vector>
#include <algorithm>
#include <utility>
#include <QPoint>
#include <QList>
#include <QPolygon>
#include <QPainter>

namespace fig {

class Polygon {
private:
	struct Vertex;

	struct Edge {
		std::weak_ptr<Vertex> begin_;
		std::weak_ptr<Vertex> end_;
		int value_;
	};
	struct Vertex {
		QPointF p_;
		std::weak_ptr<Edge> begin_;
		std::weak_ptr<Edge> end_;
		int value_;
		Vertex(const QPointF &p): p_(p){}
	};

	std::vector<std::shared_ptr<Edge>> edges_;
	std::vector<std::shared_ptr<Vertex>> vertices_;
	static inline size_t nextId_ = 0;

	int layer_;
public:
	Polygon():id_(nextId_++){}

	const size_t id_;

	inline bool empty() const {
		return vertices_.empty();
	}

	void setLayer(int l) {layer_ = l;}
	int getLayer() const { return layer_;}
	void setPoints(std::vector<QPointF> &points);
	void draw(QPainter &painter, int width, int height) const;
	bool contains(const QPoint &cursorCoord, int width, int height) const;
	inline size_t size() const { return vertices_.size();}
	inline QPointF get_i(int idx) const { return vertices_[idx]->p_;}
};

}

#endif