#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

const std::pair<int,int> warrior_move[] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; 
const std::pair<int,int> witch_move[] = {{-2,0},{-1,0},{0,-2},{0,-1},{0,1},{0,2},{1,0},{2,0}};
const std::pair<int,int> jumper_move[] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

class no_such_move {
	public:
		no_such_move(const std::string& msg): msg_(msg) {}
		~no_such_move() {}
		std::string getMessage() const {
			return(msg_);
		}
	private:
		std::string msg_;
};

class figure {
 public:
 	std::pair<int,int> coor;
		virtual const std::pair<int, int>& get_coordinates () const {
			return coor;
		}
		
		virtual std::vector<std::pair<int, int> > get_possible_moves() const = 0;
		virtual void make_move (const std::pair<int, int>& move) = 0; 
};

class warrior : public figure {
	public:
		warrior() {
  	coor = {0,0};
		}
		warrior(const std::pair<int,int> coor_pair) {
			coor = coor_pair;
		}
		warrior(const warrior& other) {
			coor.first = other.coor.first;
			coor.second = other.coor.second;
		}
		~warrior() = default;
		warrior& operator=(const warrior &p) = default;
		std::vector<std::pair<int, int> > get_possible_moves() const override {
			std::vector<std::pair<int, int> > res;
			for (int i = 0; i < 8; i++) {
				res.push_back({coor.first + warrior_move[i].first, coor.second + warrior_move[i].second});
			}
			return res;
		}
		void make_move (const std::pair<int, int>& move) override {
			std::vector<std::pair<int, int> > moves = get_possible_moves();
			if (std::find(moves.cbegin(), moves.cend(), move) != moves.cend())
				coor = move;
			else
				throw(no_such_move("no_such_move"));
		}
};

class witch : public figure {
	public:
		witch() {
  	coor = {0,0};
		}
		witch(const std::pair<int,int> coor_pair) {
			coor = coor_pair;
		}
		witch(const witch& other) {
			coor.first = other.coor.first;
			coor.second = other.coor.second;
		}
		~witch() = default;
		witch& operator=(const witch &p) = default;
		std::vector<std::pair<int, int> > get_possible_moves() const override {
			std::vector<std::pair<int, int> > res;
			for (int i = 0; i < 8; i++) {
				res.push_back({coor.first + witch_move[i].first, coor.second + witch_move[i].second});
			}
			return res;
		}
		void make_move (const std::pair<int, int>& move) override {
			std::vector<std::pair<int, int> > moves = get_possible_moves();
			if (std::find(moves.cbegin(), moves.cend(), move) != moves.cend())
				coor = move;
			else
				throw(no_such_move("no_such_move"));
		}
};

class jumper : public figure {
	public:
		jumper() {
  	coor = {0,0};
		}
		jumper(const std::pair<int,int> coor_pair) {
			coor = coor_pair;
		}
		jumper(const jumper& other) {
			coor.first = other.coor.first;
			coor.second = other.coor.second;
		}
		~jumper() = default;
		jumper& operator=(const jumper &p) = default;
		std::vector<std::pair<int, int> > get_possible_moves() const override {
			std::vector<std::pair<int, int> > res;
			for (int i = 0; i < 8; i++) {
				res.push_back({coor.first + jumper_move[i].first, coor.second + jumper_move[i].second});
			}
			return res;
		}
		void make_move (const std::pair<int, int>& move) override {
			std::vector<std::pair<int, int> > moves = get_possible_moves();
			if (std::find(moves.cbegin(), moves.cend(), move) != moves.cend())
				coor = move;
			else
				throw(no_such_move("no_such_move"));
		}
};

int main() {
	return 0;
}
