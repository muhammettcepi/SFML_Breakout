#include "Bloklar.hpp"
#include <iostream>
Bloklar::Bloklar()
{
	m_carpismaSayisi = 0;
}
void Bloklar::konum(sf::Vector2f yeniKonum)
{
	m_konum = yeniKonum;
}
sf::Vector2f Bloklar::konumGetir() const
{
	return m_konum;
}

void Bloklar::seciliResminNumarasý(int deger)
{
	m_secilenResim = deger;
}

int Bloklar::seciliResimGetir()
{
	return m_secilenResim;
}

void Bloklar::yeniBoyut(sf::Vector2f boyut)
{
	m_boyut = boyut;
}

void Bloklar::carpismaSayisiArtir()
{
	m_carpismaSayisi++;
}

int Bloklar::carpismaSayisiDondur()
{
	return m_carpismaSayisi;
}
sf::String Bloklar::seciliResim()
{
	
	if (m_secilenResim == 1)
		return "blue";
	else if (m_secilenResim == 2) return "green";
	else if (m_secilenResim == 3) return "pink";
	else if (m_secilenResim == 4) return "violet";
	else return "yellow";
}


