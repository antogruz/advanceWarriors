#include <map>

template <typename T>
class Map {
	public:
		Map(T emptyValue);
		void attach(T elem, int x, int y);
		void remove(int x, int y);
		void move(int xa, int ya, int xb, int yb);
		const T & get(int x, int y) const;

		typename std::map<std::pair<int, int>, T>::iterator begin() { return data.begin(); }
		typename std::map<std::pair<int, int>, T>::iterator end() { return data.end(); }
	private:
		T emptyValue;
		std::map<std::pair<int, int>, T> data;
};

template <typename T>
Map<T>::Map(T emptyValue)
{
	this->emptyValue = emptyValue;
};

template <typename T>
void Map<T>::attach(T elem, int x, int y)
{
	if (elem == emptyValue)
		return;

	std::pair<int,int> key = std::make_pair(x, y);
	if (data.count(key)) {
		throw std::invalid_argument("Double Attach in map");
	}
	data[std::make_pair(x, y)] = elem;
};

template <typename T>
void Map<T>::remove(int x, int y)
{
	std::pair<int,int> key = std::make_pair(x, y);
	if (!data.erase(key)) {
		throw std::invalid_argument("Erase empty in map");
	}
}

template <typename T>
void Map<T>::move(int xa, int ya, int xb, int yb)
{
	T value = get(xa, ya);
	attach(value, xb, yb);
	remove(xa, ya);
}


template <typename T>
const T & Map<T>::get(int x, int y) const
{
	try {
		return data.at(std::make_pair(x, y));
	} catch (std::out_of_range & e) {
		return emptyValue;
	}
}

template <typename T>
int getMaxRow(Map<T> map)
{
	int max = 0;
	for(auto it = map.begin(); it != map.end(); it++) {
		int row = it->first.first;
		if (row > max)
			max = row;
	}
	return max;
}

template <typename T>
int getMaxColumn(Map<T> map)
{
	int max = 0;
	for(auto it = map.begin(); it != map.end(); it++) {
		int col = it->first.second;
		if (col > max)
			max = col;
	}
	return max;
}

