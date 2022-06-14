#include<iostream>
#include<forward_list>

template<typename vt>
class reverse_forward_list {
	public:
		static void reverse (std::forward_list<vt>& list) {
			int size = distance(list.begin(),list.end());
			auto it = list.before_begin();
			it++;
		 for(int i = 0; i < size; i++) {
		 	list.push_front(*it);
		 	it++;
			}
			list.resize(size);
	}
};

int main() {
	reverse_forward_list<int> a;
	std::forward_list<int> b({1,2,3});
	a.reverse(b);
 for(int& val: b)
 	std::cout << val << " ";
	return 0;
} 
