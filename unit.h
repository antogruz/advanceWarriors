class Unit {
	public:
		Unit(int att=1, int def=1);
		int getHealth() const;
		void hit(Unit & opponent);

	private:
		float health;
		int att;
		int def;
		void getInjured(float damage);
};
