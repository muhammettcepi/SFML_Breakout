#pragma once
#include <SFML/Graphics.hpp>
#include "Bloklar.hpp"
class Top
{
public:
	Top();
	void ilkKonum(sf::RenderWindow& pencere);
	void hareketEt(float boyutx,float boyuty,int aci);
	int aciBelirle();
	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f konumGetir() const;
	void ciz(sf::RenderWindow& pencere);
	std::string resimSec();
private:
	void resimYukle(sf::String resimAdi);
	sf::Vector2u  m_pencereBoyut;
	sf::Vector2f m_konum;
	sf::CircleShape m_topSekil;
	float m_radius;
	sf::Sprite			m_resArkaPlan;
	sf::Texture			m_texArkaPlan;
	
};