#include "Sahne.hpp"
#include <iostream>
Sahne::Sahne()
{
	m_duvarHucresi.setFillColor(sf::Color::Green);
	std::srand(std::time(nullptr));
	
}
void Sahne::olustur(float sahneGenislik,
	float sahneYukseklik,
	float hucreBoyut)
{
	this->ucKonumX = sahneGenislik;
	this->ucKonumY = sahneYukseklik;
	m_enSayisi = sahneGenislik / hucreBoyut;
	m_boySayisi = sahneYukseklik / hucreBoyut;
	m_duvarHucreBoyutu = 20.f;
	m_duvarHucresi.setSize({ m_duvarHucreBoyutu,m_duvarHucreBoyutu });
	duvarResimYukle();
	duvarResimSayisi();

}
void Sahne::ciz(sf::RenderWindow& pencere)
{
	
	sf::Vector2f konum;
	pencere.draw(m_Yem);
	for (int i = 0; i < m_enSayisi; i++) {
		konum.x = i*20;
		konum.y = 0;
		if (seciliDuvarResimleriEn[i] == 0) {
			m_resArkaPlan1.setPosition(konum);
			pencere.draw(m_resArkaPlan1);
		}
		else if (seciliDuvarResimleriEn[i] == 1) {
			m_resArkaPlan2.setPosition(konum);
			pencere.draw(m_resArkaPlan2);
		}
		else if (seciliDuvarResimleriEn[i] == 2) {
			m_resArkaPlan3.setPosition(konum);
			pencere.draw(m_resArkaPlan3);
		}
		else
		{
			m_resArkaPlan4.setPosition(konum);
			pencere.draw(m_resArkaPlan4);
		}
		if (seciliDuvarResimleriEn[(2 * m_enSayisi) -i-1] == 0) {
			m_resArkaPlan1.setPosition(konum.x, this->ucKonumY - 20);
			pencere.draw(m_resArkaPlan1);
		}
		else if (seciliDuvarResimleriEn[(2 * m_enSayisi) - i - 1] == 1) {
			m_resArkaPlan2.setPosition(konum.x, this->ucKonumY - 20);
			pencere.draw(m_resArkaPlan2);
		}
		else if (seciliDuvarResimleriEn[(2 * m_enSayisi) - i - 1] == 2) {
			m_resArkaPlan3.setPosition(konum.x, this->ucKonumY - 20);
			pencere.draw(m_resArkaPlan3);
		}
		else
		{
			m_resArkaPlan4.setPosition(konum.x, this->ucKonumY - 20);
			pencere.draw(m_resArkaPlan4);
		}
		
	}
	for (int i = 0; i < m_boySayisi; i++) {
		konum.x = 0;
		konum.y = i * 20;
		if (seciliDuvarResimleriBoy[i] == 0) {
			m_resArkaPlan1.setPosition(konum);
			pencere.draw(m_resArkaPlan1);
		}
		else if (seciliDuvarResimleriBoy[i] == 1) {
			m_resArkaPlan2.setPosition(konum);
			pencere.draw(m_resArkaPlan2);
		}
		else if (seciliDuvarResimleriBoy[i] == 2) {
			m_resArkaPlan3.setPosition(konum);
			pencere.draw(m_resArkaPlan3);
		}
		else
		{
			m_resArkaPlan4.setPosition(konum);
			pencere.draw(m_resArkaPlan4);
		}
		if (seciliDuvarResimleriBoy[(2 * m_boySayisi) - i - 1] == 0) {
			m_resArkaPlan1.setPosition(this->ucKonumX - 20, konum.y);
			pencere.draw(m_resArkaPlan1);
		}
		else if (seciliDuvarResimleriBoy[(2 * m_boySayisi) - i - 1] == 1) {
			m_resArkaPlan2.setPosition(this->ucKonumX - 20, konum.y);
			pencere.draw(m_resArkaPlan2);
		}
		else if (seciliDuvarResimleriBoy[(2 * m_boySayisi) - i - 1] == 2) {
			m_resArkaPlan3.setPosition(this->ucKonumX - 20, konum.y);
			pencere.draw(m_resArkaPlan3);
		}
		else
		{
			m_resArkaPlan4.setPosition(this->ucKonumX - 20, konum.y);
			pencere.draw(m_resArkaPlan4);
		}
	}
	
	
}
void Sahne::duvarResimSayisi()
{

	for (int i = 0; i < 2*m_enSayisi; i++) {
		seciliDuvarResimleriEn.push_back(rand() % 4);
	}
	for (int i = 0; i < 2*m_boySayisi; i++) {
		seciliDuvarResimleriBoy.push_back(rand() % 4 );

	}
}
sf::Vector2f Sahne::boyutGetir()
{
	sf::Vector2f boyut;
	boyut.x = this->ucKonumX;
	boyut.y = this->ucKonumY;
	return boyut;
}


void Sahne::duvarResimYukle()
{
	if (!m_texArkaPlan1.loadFromFile("resimler/Walls/brick.png")) {}
	m_resArkaPlan1.setTexture(m_texArkaPlan1);
	m_resArkaPlan1.setTextureRect(sf::IntRect({ 40,40 }, { 80,80 }));
	//çizim fonksiyonu içerisinde
	float sx = m_duvarHucreBoyutu / 80;
	float sy = m_duvarHucreBoyutu / (80);
	m_resArkaPlan1.setScale(sx, sy);
	m_spriteListesi.push_back(m_resArkaPlan1);

	if (!m_texArkaPlan2.loadFromFile("resimler/Walls/brick_blue.png")) {}
	m_resArkaPlan2.setTexture(m_texArkaPlan2);
	m_resArkaPlan2.setTextureRect(sf::IntRect({ 40,40 }, { 80,80 }));
	m_resArkaPlan2.setScale(sx, sy);
	m_spriteListesi.push_back(m_resArkaPlan2);

	if (!m_texArkaPlan3.loadFromFile("resimler/Walls/brick_pink_side.png")) {}
	m_resArkaPlan3.setTexture(m_texArkaPlan3);
	m_resArkaPlan3.setTextureRect(sf::IntRect({ 40,40 }, { 80,80 }));
	m_resArkaPlan3.setScale(sx, sy);
	m_spriteListesi.push_back(m_resArkaPlan3);

	if (!m_texArkaPlan4.loadFromFile("resimler/Walls/brick_red.png")) {}
	m_resArkaPlan4.setTexture(m_texArkaPlan4);
	m_resArkaPlan4.setTextureRect(sf::IntRect({ 40,40 }, { 80,80 }));
	m_resArkaPlan4.setScale(sx, sy);
	m_spriteListesi.push_back(m_resArkaPlan4);
}
