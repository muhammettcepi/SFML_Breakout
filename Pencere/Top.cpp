#include "Top.hpp"

Top::Top()
{
	m_radius = 25.0f;
	std::string seciliresim = resimSec();
	resimYukle("resimler/Balls/"+ seciliresim);
}

void Top::ilkKonum(sf::RenderWindow& pencere)
{
	m_topSekil.setRadius(m_radius);
	m_pencereBoyut = pencere.getSize();
	m_konum = { float(m_pencereBoyut.x / 2),float(m_pencereBoyut.y/2) };
	m_topSekil.setPosition(m_konum);
}

void Top::hareketEt(float boyutx,float boyuty,int aci)
{
	float x = aci * 3.14159 / 180;
	m_konum.y -= boyuty *sin(x);
	m_konum.x += boyutx * cos(x);
}

int Top::aciBelirle()
{
	srand(time(NULL));
	return (rand()%105)+15;
}

void Top::konum(sf::Vector2f yeniKonum)
{

}

sf::Vector2f Top::konumGetir() const
{
	return m_konum;
}

void Top::ciz(sf::RenderWindow& pencere)
{
	m_resArkaPlan.setPosition(m_konum);
	pencere.draw(m_resArkaPlan);
}
void Top::resimYukle(sf::String resimAdi)
{
	if (!m_texArkaPlan.loadFromFile(resimAdi));
	{

	}
	m_resArkaPlan.setTexture(m_texArkaPlan);

	//çizim fonksiyonu içerisinde
	m_resArkaPlan.setTextureRect(sf::IntRect({ 70,70 }, { 370,370 }));
	float sx = m_radius / 370;
	float sy = m_radius / (370);
	m_resArkaPlan.setScale(sx, sy);

}
std::string Top::resimSec()
{
std:srand(time(NULL));
	int deger = rand() % 6;
	if (deger == 1)
		return "ball_blue.png";
	else if (deger == 2)
		return "ball_green.png";
	else if (deger == 3)
		return "ball_orange.png";
	else if (deger == 4)
		return "ball_red.png";
	else if (deger == 5)
		return "ball_silver.png";
	else return "ball_yellow.png";
}
