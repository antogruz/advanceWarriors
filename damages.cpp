float damages(int att, int def)
{
	if (att <= 0)
		return 0;
	if (def <= 0)
		return 10;
	return float(att) * 5.0 / float(def);
}

