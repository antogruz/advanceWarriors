#include "playerInterface.h"
#include "display.h"
#include "unit.h"

int main()
{
	Player blue, red;
	Map map(10, 10);

	Unit blueman(1, 1), redman(1, 1);
	std::list<Unit> blueArmy, redArmy;
	blueArmy.push_front(&blueman);
	redArmy.push_front(&redman);

	map.attachUnit(blueman, 0, 0);
	map.attachUnit(redman, 9, 9);

	std::list<Unit> readyUnits = blueArmy;
	while (Order order = blue.chooseOrder(map, readyUnits)) {
		if (order.type == END_TURN) {
			break;
		}
		executeOrder(map, order, readyUnits);
	}
}







