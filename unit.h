class Unit {
	public:
		Unit(int power=1);
		int getHealth() const;
		void hit(Unit & opponent);

	private:
		float health;
		int power;

		float getDamage() const;
};
