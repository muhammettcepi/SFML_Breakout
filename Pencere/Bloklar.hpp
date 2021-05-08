#pragma once
#pragma once
#include<SFML/Graphics.hpp>
class Bloklar
{
public:
	Bloklar();
	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f konumGetir() const;
	sf::String seciliResim();
	void seciliResminNumarasý(int deger);
	int seciliResimGetir();
	void yeniBoyut(sf::Vector2f boyut);
	void carpismaSayisiArtir();
	int carpismaSayisiDondur();

private:
	sf::Vector2f boyut;
	sf::Vector2f m_konum;
	sf::Color m_renk;
	sf::Vector2f		m_boyut;
	int m_secilenResim;
	int m_carpismaSayisi;
};
typedef std::vector<Bloklar> BlokListesi;