#include "Raket.hpp"

Raket::Raket()
{
	m_raketBoyutu.x = 200.f;
	m_raketBoyutu.y = 20.f;
	m_raketSekil.setFillColor(sf::Color::Red);
	std::string seciliresim = resimSec();
	resimYukle("resimler/Bats/"+ seciliresim);
	
	yon(YON::SAG);
}

void Raket::ilkKonum(sf::RenderWindow& pencere)
{
	m_raketSekil.setSize(m_raketBoyutu);
	m_pencereBoyut = pencere.getSize();
	m_konum = { float(m_pencereBoyut.x / 2)-m_raketBoyutu.x/2,float(m_pencereBoyut.y - 200) };
	m_raketSekil.setPosition(m_konum);
}

void Raket::ciz(sf::RenderWindow& pencere)
{
	m_resArkaPlan.getLocalBounds();
	m_resArkaPlan.setPosition(m_konum);
	pencere.draw(m_resArkaPlan);
}

void Raket::yon(YON yeniYon)
{
	m_yon = yeniYon;
}

void Raket::hareket(float boyut)
{
sf::Vector2f konum;
	switch (m_yon)
	{
	case YON::SAG:
		konum = m_konum;
		konum += sf::Vector2f(boyut, 0);
		if (sahneIcindemi(konum))
			m_konum = konum;
		break;
	case YON::SOL:
		
		konum = m_konum;
		konum -= sf::Vector2f(boyut, 0);
		if (sahneIcindemi(konum))
			m_konum = konum;
		break;
	}

}

sf::Vector2f Raket::raketBoyutGetir()
{
	return m_raketBoyutu;
}

void Raket::konum(sf::Vector2f yeniKonum)
{
	
	m_konum = yeniKonum;
}
bool Raket::sahneIcindemi(sf::Vector2f yeniKonum)
{
	auto konum = yeniKonum;
	auto boyut = m_pencereBoyut;
	if (konum.x <= 20 ||
		konum.x+m_raketBoyutu.x >= boyut.x-20 )
	{
		return false;
	}
	return true;
}
std::string Raket::resimSec()
{
std:srand(time(NULL));
	int deger = rand() % 5;
	if (deger == 1)
		return "bat_black.png";
	else if (deger == 2)
		return "bat_blue.png";
	else if (deger == 3)
		return "bat_orange.png";
	else if (deger == 4)
		return "bat_pink.png";
	else return "bat_yellow.png";
}
void Raket::resimYukle(sf::String resimAdi)
{
	if (!m_texArkaPlan.loadFromFile(resimAdi));
	{

	}
	m_resArkaPlan.setTexture(m_texArkaPlan);
	m_resArkaPlan.setTextureRect(sf::IntRect({ 25,180 }, { 465,100 }));
	float sx = m_raketBoyutu.x / 465;
	float sy = m_raketBoyutu.y / (100);
	m_resArkaPlan.setScale(sx, sy);
}
sf::Vector2f Raket::konumGetir() {
	return m_konum;
}
