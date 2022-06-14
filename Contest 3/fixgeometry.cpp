#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<vector>
#include<math.h>
#include <algorithm>

const double eps = 1e-6;

bool equal (double a, double b) {
 return std::fabs(a - b) < eps;
}

struct vector {
 double x, y;

 vector(const double z, const double t): x(z), y(t) {};
 vector() {
  x = 0.0;
  y = 0.0;
 };
 vector(const vector& other) {
  x = other.x;
  y = other.y;
 }
 vector& operator=(const vector& other) = default;
 ~vector() = default; 
 
 vector& operator+=(const vector& other) {
  x += other.x;
  y += other.y;
  return *this;
 }
 vector& operator-=(const vector& other) {
  x -= other.x;
  y -= other.y;
  return *this;
 }
 vector& operator*=(const double& num) {
  x *= num;
  y *= num;
  return *this;
 }
 vector& operator/=(const double& num) {
  x /= num;
  y /= num;
  return *this;
 }
 
 
 vector operator+() const {
  return *this;
 }
 vector operator-() const {
  vector res = *this;
  res.x *= -1;
  res.y *= -1;
  return res;
 }

 double length() const {
  return sqrt(x * x + y * y);
 }
};

bool operator==(const vector& first , const vector& second){
 return (equal(first.x , second.x) && equal(first.y , second.y));
}
bool operator!=(const vector& first , const vector& second){
 return (!equal(first.x , second.x) || !equal(first.y , second.y));
}
bool collinear (const vector& lhs, const vector& rhs) {
 return equal(cross_product(lhs, rhs),0.0);
}

vector operator+(const vector& first , const vector& second){
 return vector(first)+=second;
}
vector operator-(const vector& first , const vector& second){
 return vector(first)-=second;
}
vector operator*(const vector& first , const double& num){
 return vector(first)*=num;
}
vector operator*(const double& num , const vector& first){
 return (first*num);
}
vector operator/(const vector& first , const double& num){
 return vector(first)/=num;
}
vector operator/(const double& num , const vector& first){
 return (first/num);
}

double dot_product (const vector& lhs, const vector& rhs) {
 return (lhs.x * rhs.x + lhs.y * rhs.y);
}
double cross_product (const vector& lhs, const vector& rhs) {
 return (lhs.x * rhs.y - rhs.x * lhs.y);
}

class shape {
 public:
  virtual vector center() const = 0;

  virtual double perimeter() const = 0;
  virtual double area() const = 0;

  virtual bool operator==(const shape& another) const = 0;
  virtual bool operator!=(const shape& another) const = 0;
  virtual bool congruent_to(const shape& another) const = 0;

  virtual void rotate(const double angle) = 0;
  virtual void scale(const double coefficient) = 0;
  virtual void translate(const vector transform) = 0;
};

class polygon : public shape {
 public:
  std::vector<vector> vertex;
  polygon() {
   vertex.push_back(vector(0.0,0.0));
  };
  explicit polygon(const std::vector<vector>& init): vertex(init) {
   double dir = 0.0;
   for (size_t i = 0 ; i < vertex.size() ; i++)
    dir += cross_product(vertex[i],vertex[(i + 1) % vertex.size()]);
   if (dir < 0) 
    reverse(vertex.begin(), vertex.end());
  };
  
  vector center() const override {
   vector res(0,0);
   size_t n = vertex.size();
   double area = 0;
   for (size_t i = 0; i < vertex.size(); i++) {
    double tmp = cross_product(vertex[i], vertex[(i + 1) % vertex.size()]);
    area += tmp;
    res.x += (vertex[i].x + vertex[(i + 1) % vertex.size()].x) * tmp;
    res.y += (vertex[i].y + vertex[(i + 1) % vertex.size()].y) * tmp;
   }
   area *= 0.5;
   res.x = (res.x) / (6.0 * area);
   res.y = (res.y) / (6.0 * area);
   return res;
  }

  size_t vertices_count() const {
   return vertex.size();
  }

  const std::vector<vector>& get_vertices() const {
   return vertex;
  }

  double perimeter() const override {
   double res = 0.0;
   for (size_t i = 0; i < vertex.size(); i++)
    res += vector(vertex[i].x - vertex[(i + 1) % vertex.size()].x, 
                  vertex[i].y - vertex[(i + 1) % vertex.size()].y).length();
   return res;
  }
  double area() const override {
   double res = 0.0;
   for (size_t i = 0; i < vertex.size(); i++)
    res += 0.5 * cross_product(vertex[i], vertex[(i + 1) % vertex.size()]);
   return res;
  }

  bool operator==(const shape& another) const override {
   const polygon* other = dynamic_cast<const polygon*>(&another);
   if (other == nullptr)
             return false;
   size_t pos = 0;
   if (vertex.size() != (*other).vertex.size()) return false;
   for (size_t i = 0; i < vertex.size(); i++)
    if (vertex[0] == (*other).vertex[i]) {
     pos = i;
     break;
    }
   for (size_t i = 0; i < vertex.size(); i++) {
    if (vertex[i] != (*other).vertex[pos % vertex.size()])
     return false;
    ++pos;
   }
   return true;
  };
  bool operator!=(const shape& another) const override {
   const polygon* other = dynamic_cast<const polygon*>(&another);
   if (other == nullptr)
   	return true;
   return !(*this == (*other));
  }
  bool congruent_to(const shape& another) const override {
   const polygon* other = dynamic_cast<const polygon*>(&another);
   if (other == nullptr) 
    return false;
   std::vector<vector> pol1(vertex.size()), pol2(vertex.size());
   for (size_t i = 0; i < vertex.size(); i++)
    pol1[i] = vector(vertex[i].x - vertex[(i + 1) % vertex.size()].x, 
                     vertex[i].y - vertex[(i + 1) % vertex.size()].y),
    pol2[i] = vector((*other).vertex[i].x - (*other).vertex[(i + 1) % vertex.size()].x, 
                     (*other).vertex[i].y - (*other).vertex[(i + 1) % vertex.size()].y);
    for (size_t dist = 0; dist < vertex.size(); dist++) 
    if (equal(pol1[0].length(), pol2[dist].length())) {
     for (size_t i = 0; i < vertex.size(); i++) {
      if(!equal(pol1[i].length(), pol2[(i + dist) % vertex.size()].length()) ||
         !equal(pol1[(i + 1) % vertex.size()].length(), 
                pol2[(i + dist + 1) % vertex.size()].length()) ||
         !equal(std::fabs(cross_product(pol1[i], pol1[(i + 1) % vertex.size()])),
                std::fabs(cross_product(pol2[(i + dist) % vertex.size()], 
			pol2[(i + 1 + dist) % vertex.size()]))))
        break;
      if(i == vertex.size() - 1)
       return true;
     }
     for (size_t i = 0; i < vertex.size(); i++) {
      if(!equal(pol1[i].length(), 
	          pol2[(dist - i + vertex.size()) % vertex.size()].length()) ||
         !equal(pol1[(i + 1) % vertex.size()].length(), 
		    pol2[(dist - i - 1 + vertex.size()) % vertex.size()].length()) ||
         !equal(std::fabs(cross_product(pol1[i],pol1[(i + 1) % vertex.size()])), 
                std::fabs(cross_product(pol2[(dist - i + vertex.size()) % vertex.size()], 
		                            pol2[(dist - i - 1 + vertex.size()) % vertex.size()]))))
       break;
      if(i == vertex.size() - 1)
       return true;
     }
    }
   return false;
  }

  void rotate(const double angle) override {
   const vector centroid = center();
   vector tmp1, tmp2;
   for (size_t i = 0; i < vertex.size(); i++) {
    tmp1 = vertex[i] - centroid;
    tmp2.x = tmp1.x*cos(angle) - tmp1.y*sin(angle);
             tmp2.y = tmp1.x*sin(angle) + tmp1.y*cos(angle);
             vertex[i] = tmp2 + centroid;
   }
  }
  void scale(const double coefficient) override {
   const vector centroid = center();
   for (size_t i = 0; i < vertex.size(); i++) 
    vertex[i] = (vertex[i] - centroid) * coefficient + centroid;
  }
  void translate(const vector transform) override {
   for (size_t i = 0; i < vertex.size(); i++)
    vertex[i] += transform;
  }
};

class circle : public shape {
 private:
     double radius_;
     vector center_;
 public:
     explicit circle(const vector& other_center , const double& other_radius) {
      radius_ = other_radius;
      center_ = other_center;
     }
 
     vector center() const override {
      return center_;
     }

     double perimeter() const override {
      return (2*M_PI*radius_);
     }
     double area() const override {
      return (M_PI*pow(radius_,2));
     }
     const double radius() const {
      return radius_;
     }

     bool operator==(const shape& another) const override {
         const circle* other = dynamic_cast<const circle*>(&another);
         if (other == nullptr)
          return false;
         if (equal(radius_, (*other).radius_) && center_ == (*other).center_)
          return true;
         return false;
     }
     bool operator!=(const shape& another) const override{
         const circle* other = dynamic_cast<const circle*>(&another);
         if (other == nullptr)
          return true;
         return !((*this)==(*other));
     }
     bool congruent_to(const shape& another) const override{
         const circle* other = dynamic_cast<const circle*>(&another);
         if (other == nullptr)
          return false;
         return equal(radius_, (*other).radius_);
     }
 
     void rotate(double angle){};
     void scale(double coefficient) override{
         radius_ *= fabs(coefficient);
     }
     void translate(vector transform) override{
      center_ += transform;
     }
};

class rectangle : public polygon {
 public:
 double height_, width_;
 vector center_;

 explicit rectangle(const vector& other_center, 
	              const double& other_height, 
                    const double& other_width): 
  polygon(std::vector<vector>{vector(other_center.x + (other_height / 2), 
		                            other_center.y + (other_width / 2)),
                              vector(other_center.x - (other_height / 2), 
						 other_center.y + (other_width / 2)),
                              vector(other_center.x - (other_height / 2), 
					       other_center.y - (other_width / 2)),
                              vector(other_center.x + (other_height / 2), 
					       other_center.y - (other_width / 2))}),
  center_(other_center), height_(other_height), width_(other_width) {};

 vector center() const override {
     return center_;
 }
 
 double height() const {
     return height_;
 }
 double width() const {
     return width_;
 }
 double perimeter() const override {
     return 2 * (height_ + width_);
 }
 double area() const override {
     return height_ * width_;
 }
 
 bool congruent_to(const shape& another) const override{
     const rectangle* other = dynamic_cast<const rectangle*>(&another);
     if (other == nullptr)
         return true;
     return equal(width_, (*other).width_) && equal(height_, (*other).height_);
 }
 
 void scale(double coefficient) override{
  height_ *= std::fabs(coefficient);
  width_ *= std::fabs(coefficient);
  for (size_t i = 0; i < vertex.size(); i++) 
   vertex[i] = (vertex[i] - center_) * std::fabs(coefficient) + center_;
 }
};

class square : public rectangle {
 public:
  double side_;
  vector center_;

  explicit square(const vector& other_center, const double& other_side): 
                        rectangle(other_center, other_side, other_side),
                             center_(other_center), side_(other_side){};
  
  double side() const {
      return side_;
  }
     
  circle circumscribed_circle() const {
   return circle(center_, sqrt(2) * side_);
  }
  circle inscribed_circle() const {
   return circle(center_, side_);
  }
  
  bool congruent_to(const shape& another) const {
  	const square* other = dynamic_cast<const square*>(&another);
  	if (other == nullptr)
    return true;
   return (equal(side_, (*other).side_));
  }
};


class triangle : public polygon {
 public:
  vector vertex1, vertex2, vertex3;

  explicit triangle(const vector& vertex1_other,
		        const vector& vertex2_other,
			  const vector& vertex3_other): 
                    polygon(std::vector<vector>{vertex1_other, vertex2_other, vertex3_other}),
                    vertex1(vertex1_other), vertex2(vertex2_other), vertex3(vertex3_other) {};

  circle circumscribed_circle() const {
   vector side1 = vertex2 - vertex1;
   vector side2 = vertex3 - vertex2;
   vector side3 = vertex3 - vertex1;
   double radius = (side1.length() * side2.length() * side3.length()) / sqrt(perimeter() 
                 * (side1.length() + side2.length() - side3.length()) 
                 * (side2.length() + side3.length() - side1.length()) 
                 * (side3.length() + side1.length() - side2.length()));
   double d = 2 * (vertex1.x * (vertex2.y - vertex3.y) + 
              vertex2.x * (vertex3.y - vertex1.y) + 
              vertex3.x * (vertex1.y - vertex2.y));
   double d1 = vertex1.x * vertex1.x + vertex1.y * vertex1.y;
   double d2 = vertex2.x * vertex2.x + vertex2.y * vertex2.y;
   double d3 = vertex3.x * vertex3.x + vertex3.y * vertex3.y;
   vector center_cir((d1 * (vertex2.y - vertex3.y) + 
			        d2 * (vertex3.y - vertex1.y) + 
			        d3 * (vertex1.y - vertex2.y)) / d,
                     (d1 * (vertex3.x - vertex2.x) + 
			        d2 * (vertex1.x - vertex3.x) + 
			        d3 * (vertex2.x - vertex1.x)) / d);
   return circle(center_cir, radius);
  }
  circle inscribed_circle() const {
   vector side1 = vertex3 - vertex2;
   vector side2 = vertex3 - vertex1;
   vector side3 = vertex2 - vertex1;
   vector center_cir((side1.length() * vertex1.x + 
			        side2.length() * vertex2.x + 
				   side3.length() * vertex3.x) / perimeter(),
                     (side1.length() * vertex1.y + 
				   side2.length() * vertex2.y + 
				   side3.length() * vertex3.y) / perimeter());
   return circle(center_cir, 2.0 * area() / perimeter());
  }
};

int main() {
 std::cout << polygon(std::vector<vector>({vector(4, 0), vector(4, 2), vector(0, 2), vector(0, 4), vector(4, 4), vector(4, 6), vector(6, 6), vector(6, 4), vector(10, 4), vector(10, 2), vector(6, 2), vector(6, 0)})).congruent_to(circle(vector(2,3), 5));
 return 0;
}
