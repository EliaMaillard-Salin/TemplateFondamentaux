#pragma once
class Personnage
{


public:
	Personnage(int hp, int dps, int def) : m_hp(hp), m_dps(dps), m_def(def) {}
	
	int m_hp;
	int m_dps;
	int m_def;
};

