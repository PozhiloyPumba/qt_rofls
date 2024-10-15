#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

#include <memory>
#include <vector>
#include <algorithm>
#include <utility>
#include <QPoint>
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

public:
	Polygon(){}

	inline bool empty() const {
		return vertices_.empty();
	}

	inline void setPoints(std::vector<QPointF> &points) {
		vertices_.clear();
		edges_.clear();
		std::for_each(points.begin(), points.end(), 
			[this](const auto &p){
				vertices_.push_back(std::make_shared<Vertex>(p));
				edges_.push_back(std::make_shared<Edge>());
			}
		);
		// link
		int sz = points.size();
		for(int i = 0; i < sz; ++i) {
			vertices_[i]->begin_ = edges_[(i - 1 + sz) % sz];
			edges_[i]->end_ = vertices_[(i + 1) % sz];
			edges_[i]->begin_ = vertices_[i];
			vertices_[i]->end_ = edges_[i];
		}
	}

	void draw(QPainter &painter, int width, int height) const {
		std::vector<QPoint> p;
		std::for_each(vertices_.begin(), vertices_.end(), 
			[this, &p, w = width, h = height](const auto &v){
				p.push_back(QPoint(int(v->p_.x() * w), int(v->p_.y() * h)));
			}
		);
		painter.drawPolygon(p.data(), p.size());
	}

	inline bool contains(const QPoint &cursorCoord, int width, int height) {
	}
};

}

#endif