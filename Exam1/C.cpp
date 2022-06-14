#include <iostream>
#include <vector>
 
struct coordinates {
	public:
	coordinates () = delete;
    coordinates (const int x, const int y): x(x), y(y) {}
    coordinates (const coordinates& other) = default;
    coordinates& operator= (const coordinates& other) = default;
    ~coordinates () = default;
    int x;
    int y;
    coordinates& operator+= (const coordinates& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    coordinates& operator-= (const coordinates& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    const coordinates operator+ () const { return coordinates(x, y); }
    const coordinates operator- () const { return coordinates(-x, -y); }
};
 
const coordinates operator+ (const coordinates& lhs, const coordinates& rhs) { return coordinates(lhs) += rhs; }
const coordinates operator- (const coordinates& lhs, const coordinates& rhs) { return coordinates(lhs) -= rhs; }

bool operator== (const coordinates& lhs, const coordinates& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
bool operator!= (const coordinates& lhs, const coordinates& rhs) { return !(lhs == rhs); }

std::istream& operator>> (std::istream& is, coordinates& instance) { return is >> instance.x >> instance.y; }
std::ostream& operator<< (std::ostream& is, const coordinates& instance) { return is << instance.x << instance.y; }

class robot {
public:
    enum direction {
        e_up,
        e_right,
        e_down,
        e_left
    };
 	int n;
 	std::vector<coordinates> rocks;
    robot () = delete;
	robot (const int _n, const std::vector<coordinates>& _rocks): n(_n), rocks(_rocks) {}
    robot (const robot& other) {
    	n = other.n;
    	rocks = other.rocks;
    	_coordinates = other._coordinates;
    	_direction = other._direction;
	};
    robot& operator= (const robot& other) { 
    	n = other.n;
    	rocks = other.rocks;
    	_coordinates = other._coordinates;
    	_direction = other._direction;
		return *this;
	};
    ~robot () = default;
 
    void try_move () {
    	coordinates tmp_coord = _coordinates;
        switch (_direction) {
            case e_up:
                tmp_coord += coordinates(0, 1);
                break;
            case e_right:
                tmp_coord += coordinates(1, 0);
                break;
            case e_down:
                tmp_coord += coordinates(0, -1);
                break;
            case e_left:
                tmp_coord += coordinates(-1, 0);
                break;
        }
        bool check = true;
    	for (int i = 0; i < rocks.size(); i++)
    		if(tmp_coord == rocks[i]) check =false;
    	if (check && tmp_coord.x >= 0 && tmp_coord.y >= 0 && tmp_coord.x < n && tmp_coord.y < n)
    		_coordinates = tmp_coord;
    	//std::cout << _coordinates.x << " " << _coordinates.y << std::endl;
    }
    
    void set_direction (const direction dir) {
    	_direction = dir;
	}
    const coordinates& get_coordinates () const { return _coordinates; }
    const direction get_direction () const { return _direction; }
 
private:
    coordinates _coordinates = {0, 0};
    direction _direction = e_up;
};

int main() {
	robot r1(6, {{1, 3}, {2, 5}, {4, 0}, {1, 2}, {3, 3}, {2, 4}, {0, 3}});
	r1.set_direction(robot::direction::e_right);
	r1.try_move();
	r1.set_direction(robot::direction::e_left);
	r1.set_direction(robot::direction::e_right);
	r1.set_direction(robot::direction::e_up);
	r1.try_move();
	r1.try_move();
	r1.set_direction(robot::direction::e_right);
	r1.try_move();
	r1.try_move();
	r1.set_direction(robot::direction::e_right);
	r1.try_move();
	r1.try_move();
	r1.try_move();
	r1.set_direction(robot::direction::e_up);
	r1.set_direction(robot::direction::e_down);
	r1.set_direction(robot::direction::e_up);
	r1.set_direction(robot::direction::e_up);
	r1.try_move();
	r1.try_move();
	r1.set_direction(robot::direction::e_up);
	r1.set_direction(robot::direction::e_up);
	r1.set_direction(robot::direction::e_right);
	const coordinates& coords = r1.get_coordinates();
	std::cout << coords.x << " " << coords.y << std::endl;	
	return 0;
}
