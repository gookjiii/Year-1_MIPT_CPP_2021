#include"vector.h"

const double eps = 1e-6;

class shape {
	public:
		virtual vector center() const = 0;
		virtual double perimeter() const = 0;
		virtual double area() const = 0;
		virtual operator==(const shape& another) const = 0;
		virtual operator!=(const shape& another) const = 0;
		virtual bool congruent_to(const shape& another) const = 0;
		virtual void rotate(const double angle) = 0;
		virtual void scale(const double coefficient) = 0;
		virtual void translate(const vector transform) = 0;
};

class polygon : public shape {
	private:
		std::vector<vector> vertex;
	public:
		polygon() {
			vertex.push_back(0.0,0.0);
		};
		polygon(const polygon& other) = default;
		polygon& operator=(const polygon& other) = default;
		~polygon = default;
		int vertices_count() {
			return vertex.size();
		}
		const std::vector<vector> get_vertices() {
			return vertex;
		}
		double perimeter() const override {
		 	double res = 0;
			for(size_t i = 0; i < vertex.size(); i++)
				res += vector(vertex[i].x - vertex[(i + 1) % vertex.size()].x,vertex[i].y - vertex[(i + 1) % vertex.size()].y).length();
			return res;
		}
		double area() {
			double res = 0;
			for(size_t i = 0; i < vertex.size(); i++)
				res += cross_product(vertex[i],vertex[(i + 1) % vertex.size()]);
			return res;
		}
		operator==(const shape& another);
		operator!=(const shape& another);
		bool congruent_to(const shape& another);
		void rotate(const double angle);
		void scale(const double coefficient) ;
		void translate(const vector transform);
};
