#pragma once
#include <iostream>

template <typename T>
class Projectile
{
public: 
	Projectile(T type, float speed, float m_dps);
	~Projectile();

	void Attack();



protected:
	float m_speed;
	float m_dps;
	int m_x, m_y;
	int m_directionX, m_directionY;
	bool is_destroyed;
	int m_enemyKilled;

	T m_projectileType;
};


template<typename T>
Projectile<T>::Projectile(T type, float speed, float m_dps) : m_projectileType(type), m_speed(speed), m_dps(dps)
{
}

template <typename T>
void Projectile<T>::Attack()
{
	std::cout << "Enemu Killed";
}

template <>
void Projectile<int>::Attack()
{
	m_enemyKilled += 1;
	std::cout << "Enemy Killed with Arrow";
}

template <>
void Projectile<float>::Attack()
{
	float attackRadius = 3.5f;
	std::cout << "Bomb Explode, Radius : " << attackRadius << " damage : " << m_dps;
}

