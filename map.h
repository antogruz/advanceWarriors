#include <map>

template <typename T>
class Map {
	public:
		Map(T emptyValue);
		Map(int xdim, int ydim, T emptyValue);
		void attach(T elem, int x, int y);
		const T & get(int x, int y) const;

	private:
		T emptyValue;
		std::map<std::pair<int, int>, T> data;
};

template <typename T>
Map<T>::Map(int xdim, int ydim, T emptyValue)
{
	this->emptyValue = emptyValue;
};

template <typename T>
Map<T>::Map(T emptyValue)
{
	this->emptyValue = emptyValue;
};

template <typename T>
void Map<T>::attach(T elem, int x, int y)
{
	data[std::make_pair(x, y)] = elem;
};

template <typename T>
const T & Map<T>::get(int x, int y) const
{
	try {
		return data.at(std::make_pair(x, y));
	} catch (std::out_of_range e) {
		return emptyValue;
	}
}

