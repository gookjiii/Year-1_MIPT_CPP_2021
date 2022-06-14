#include <iostream>
#include <array>
#include <vector>

class rubiks_cube {
	public:
	    enum color { e_white, e_red, e_green, e_orange, e_blue, e_yellow };
	    enum side { e_top, e_front, e_left, e_back, e_right, e_bottom };
	    enum direction { e_middle, e_equator, e_standing };
	    std::vector<std::vector<std::vector<rubiks_cube::color>>> cube;
		std::array<rubiks_cube::color, 4> res_side[6];	
		void update_cube() {
			for(int k = 0; k <= 5; k++) {
				int cnt = 0;
				for (int i = 0; i < 2; i++) 
					for (int j = 0; j < 2; j++)
						res_side[k][cnt++] = cube[k][i][j];
			}
		};
		static void rotate_matrix(std::vector<std::vector<rubiks_cube::color>> &matrix, int count) {
			for (int i = 1; i <= count; i++) {
				std::vector<std::vector<rubiks_cube::color>> matrix_tmp = matrix;
				matrix[0][1] = matrix_tmp[0][0];
				matrix[1][1] = matrix_tmp[0][1];
				matrix[0][0] = matrix_tmp[1][0];
				matrix[1][0] = matrix_tmp[1][1];
			}
		};
		
		void rotate_matrix_reverse(std::vector<std::vector<rubiks_cube::color>> &matrix, int count) {
			for (int i = 1; i <= count; i++) {
				std::vector<std::vector<rubiks_cube::color>> matrix_tmp = matrix;
				matrix[0][0] = matrix_tmp[0][1];
				matrix[0][1] = matrix_tmp[1][1];
				matrix[1][0] = matrix_tmp[0][0];
				matrix[1][1] = matrix_tmp[1][0];
			}
		};
		
		static void rotate_fmatrix(std::vector<std::vector<rubiks_cube::color>> &matrix1, 
							std::vector<std::vector<rubiks_cube::color>> &matrix2,
							std::vector<std::vector<rubiks_cube::color>> &matrix3,
							std::vector<std::vector<rubiks_cube::color>> &matrix4, int count, int type) {
			if (type == 1) {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[0][0] = matrix_tmp2[0][0]; matrix1[0][1] = matrix_tmp2[0][1];
					matrix2[0][0] = matrix_tmp3[0][0]; matrix2[0][1] = matrix_tmp3[0][1];
					matrix3[0][0] = matrix_tmp4[0][0]; matrix3[0][1] = matrix_tmp4[0][1];
					matrix4[0][0] = matrix_tmp1[0][0]; matrix4[0][1] = matrix_tmp1[0][1];
				}
			} else if (type == 2) {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[1][0] = matrix_tmp2[1][0]; matrix1[1][1] = matrix_tmp2[1][1];
					matrix2[1][0] = matrix_tmp3[1][0]; matrix2[1][1] = matrix_tmp3[1][1];
					matrix3[1][0] = matrix_tmp4[1][0]; matrix3[1][1] = matrix_tmp4[1][1];
					matrix4[1][0] = matrix_tmp1[1][0]; matrix4[1][1] = matrix_tmp1[1][1];
				}
			} else if (type == 3) {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[0][0] = matrix_tmp2[0][0]; matrix1[1][0] = matrix_tmp2[1][0];
					matrix2[0][0] = matrix_tmp3[0][0]; matrix2[1][0] = matrix_tmp3[1][0];
					matrix3[0][0] = matrix_tmp4[1][1]; matrix3[1][0] = matrix_tmp4[0][1];
					matrix4[1][1] = matrix_tmp1[0][0]; matrix4[0][1] = matrix_tmp1[1][0];
				}
			} else if (type == 4) {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[0][1] = matrix_tmp2[0][1]; matrix1[1][1] = matrix_tmp2[1][1];
					matrix2[0][1] = matrix_tmp3[0][1]; matrix2[1][1] = matrix_tmp3[1][1];
					matrix3[0][1] = matrix_tmp4[1][0]; matrix3[1][1] = matrix_tmp4[0][0];
					matrix4[1][0] = matrix_tmp1[0][1]; matrix4[0][0] = matrix_tmp1[1][1];
				}
			} else if (type == 5) {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[0][1] = matrix_tmp2[0][0]; matrix1[1][1] = matrix_tmp2[0][1];
					matrix2[0][0] = matrix_tmp3[1][0]; matrix2[0][1] = matrix_tmp3[0][0];
					matrix3[1][0] = matrix_tmp4[1][1]; matrix3[0][0] = matrix_tmp4[1][0];
					matrix4[1][1] = matrix_tmp1[0][1]; matrix4[1][0] = matrix_tmp1[1][1];
				}
			} else {
				for (int i = 1; i <= count; i++) {
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp1 = matrix1;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp2 = matrix2;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp3 = matrix3;
					std::vector<std::vector<rubiks_cube::color>> matrix_tmp4 = matrix4;
					matrix1[1][0] = matrix_tmp2[0][0]; matrix1[0][0] = matrix_tmp2[0][1];
					matrix2[0][0] = matrix_tmp3[0][1]; matrix2[0][1] = matrix_tmp3[1][1];
					matrix3[0][1] = matrix_tmp4[1][1]; matrix3[1][1] = matrix_tmp4[1][0];
					matrix4[1][1] = matrix_tmp1[1][0]; matrix4[1][0] = matrix_tmp1[0][0];
			}
			}
		};
	    rubiks_cube() {
	    	cube.resize(6);
	    	for (size_t k = 0; k < 6; k++) {
	    		cube[k].resize(2);
	    		for (size_t i = 0; i < 2; i++)
	    		{
	    			cube[k][i].resize(2);
	    			for (size_t j = 0; j < 2; j++)
	    				cube[k][i][j] = (color)k;
	    		}
			}
			update_cube();
		};
	    /*~rubiks_cube() {
	    	cube.clear();
		};
	    rubiks_cube(const rubiks_cube &Cube2){
	    	cube = Cube2.cube;
	    	for(int k = 0; k <= 5; k++) {
				int cnt = 0;
				for (int i = 0; i < 2; i++) 
					for (int j = 0; j < 2; j++)
						res_side[k][cnt++] = cube[k][i][j];
			}
		};
	    rubiks_cube& operator=(const rubiks_cube &Cube2) {
	    	for (size_t k = 0; k < 6; k++) 
	    		for (size_t i = 0; i < 2; i++)
	    			for (size_t j = 0; j < 2; j++)
	    				cube[k][i][j] = Cube2.cube[k][i][j];
	    	for(int k = 0; k <= 5; k++) {
				int cnt = 0;
				for (int i = 0; i < 2; i++) 
					for (int j = 0; j < 2; j++)
						res_side[k][cnt++] = cube[k][i][j];
			}
	    	return *this;
		};*/
		rubiks_cube& operator=(const rubiks_cube &Cube2) = default;
		~rubiks_cube() = default;
		rubiks_cube(const rubiks_cube &Cube2) = default;
	    void rotate_side(side side_to_rotate, int count) {
	    	count %= 4;
			if (count < 0) { 
				if (count == -1)
					count = 3;
				else if (count == -2) 
					count = 2;
				else if (count == -3) 
					count = 1;						
			}
	    	if (side_to_rotate == e_top) {
	    		rotate_matrix(cube[e_top], count);
	    		rotate_fmatrix(cube[e_left], cube[e_front], cube[e_right], cube[e_back], count, 1);
			} else if (side_to_rotate == e_bottom) {
				rotate_matrix(cube[e_bottom], count);
	    		rotate_fmatrix(cube[e_left], cube[e_back], cube[e_right], cube[e_front], count, 2);
			} else if (side_to_rotate == e_left) {
				rotate_matrix(cube[e_left], count);
	    		rotate_fmatrix(cube[e_bottom], cube[e_front], cube[e_top], cube[e_back], count, 3);
			} else if (side_to_rotate == e_right) {
				rotate_matrix(cube[e_right], count);
	    		rotate_fmatrix(cube[e_top], cube[e_front], cube[e_bottom], cube[e_back], count, 4);
			} else if (side_to_rotate == e_front) {
				rotate_matrix(cube[e_front], count);
	    		rotate_fmatrix(cube[e_left], cube[e_bottom], cube[e_right], cube[e_top], count, 5);
			} else if (side_to_rotate == e_back) {
				rotate_matrix(cube[e_back], count);
	    		rotate_fmatrix(cube[e_left], cube[e_top], cube[e_right], cube[e_bottom], count, 6);
			}
			update_cube();
		};
		void rotate_cube(direction direction_to_rotate, int count) {
			count %= 4;
			if (count < 0) { 
				if (count == -1)
					count = 3;
				else if (count == -2) 
					count = 2;
				else if (count == -3) 
					count = 1;	
			}
			if (direction_to_rotate == e_middle) {
				rotate_matrix(cube[e_right], count);
	    		rotate_fmatrix(cube[e_top], cube[e_front], cube[e_bottom], cube[e_back], count, 4);
				rotate_matrix(cube[e_left], (4 - count) % 4);
	    		rotate_fmatrix(cube[e_bottom], cube[e_front], cube[e_top], cube[e_back], (4 - count) % 4, 3);
			} else if (direction_to_rotate == e_equator) {
				rotate_matrix(cube[e_top], count);
	    		rotate_fmatrix(cube[e_left], cube[e_front], cube[e_right], cube[e_back], count, 1);
				rotate_matrix(cube[e_bottom], (4 - count) % 4);
	    		rotate_fmatrix(cube[e_left], cube[e_back], cube[e_right], cube[e_front], (4 - count) % 4, 2);
			} else if (direction_to_rotate == e_standing) {
				rotate_matrix(cube[e_front], count);
	    		rotate_fmatrix(cube[e_left], cube[e_bottom], cube[e_right], cube[e_top], count, 5);
				rotate_matrix(cube[e_back], (4 - count) % 4);
	    		rotate_fmatrix(cube[e_left], cube[e_top], cube[e_right], cube[e_bottom], (4 - count) % 4, 6);
			}
			update_cube();
		};
		const std::array<rubiks_cube::color, 4>& get_side(side side_to_get) const {
			return res_side[(int)side_to_get];
		};
};
 
int main() {
	rubiks_cube obj;
    std::array<rubiks_cube::color,4> abc;
    obj.rotate_side(rubiks_cube::side::e_top,1);
    for (int i=0;i<4;++i) {
        if (i==0){
            abc= obj.get_side(rubiks_cube::side::e_front);
        }
        else if(i==1){
            abc= obj.get_side(rubiks_cube::side::e_left);
        }
        else if (i==2){
            abc= obj.get_side(rubiks_cube::side::e_back);;
        }
        else if (i==3){
            abc= obj.get_side(rubiks_cube::side::e_right);
        }
          for (int f=0;f<4;++f){
              if (abc[f]==0){
                  std::cout << "w " ;
              }
              else if (abc[f]==1){
                  std::cout << "r ";
              }
              else if (abc[f]==2){
                  std::cout << "g ";
              }else if (abc[f]==3){
                  std::cout << "o ";
              }
              else if (abc[f]==4){
                  std::cout << "b ";
              }
              else if (abc[f]==5){
                  std::cout << "y ";
              }
          }
        std::cout << std::endl;
    }
}
 
