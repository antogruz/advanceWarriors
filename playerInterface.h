class PlayerInterface
{
	virtual Order chooseOrder(const Map & map, std::list<const & Unit> readyUnits) = 0;
	virtual UnitAction chooseUnitAction(const Map & map, const Unit & unit, std::list<UnitAction> actions) = 0;
};



