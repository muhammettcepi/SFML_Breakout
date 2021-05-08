#include "Blok.hpp"
#include <iostream>

Blok::Blok()
{
	
}

void Blok::ciz(sf::RenderWindow& pencere)
{
	for (auto siradaki:m_bloklar) {
		int seciliresim = siradaki.seciliResimGetir();
		if (seciliresim == 1) {
			if (siradaki.carpismaSayisiDondur() == 1) {
				m_resArkaPlan6.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan6);
			}
			else {
				m_resArkaPlan1.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan1);
			}
		}
		else if (seciliresim == 2) {
			if (siradaki.carpismaSayisiDondur() == 1) {
				m_resArkaPlan7.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan7);
			}
			else {
				m_resArkaPlan2.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan2);
			}
		}
		else if (seciliresim == 3) {
			if (siradaki.carpismaSayisiDondur() == 1) {
				m_resArkaPlan8.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan8);
			}
			else {
				m_resArkaPlan3.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan3);
			}
		}
		else if (seciliresim == 4) {
			if (siradaki.carpismaSayisiDondur() == 1) {
				m_resArkaPlan9.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan9);
			}
			else {
				m_resArkaPlan4.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan4);
			}
		}
		else if (seciliresim == 5) {
			if (siradaki.carpismaSayisiDondur() == 1) {
				m_resArkaPlan10.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan10);
			}
			else {
				m_resArkaPlan5.setPosition(siradaki.konumGetir());
				pencere.draw(m_resArkaPlan5);
			}
		}
	}
}

void Blok::bloklaraEkle()
{
	srand(time(NULL));
	float konumx = 40;
	float konumy = 40;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			Bloklar Blok;
			Blok.seciliResminNumarasý(rand() % 5 + 1);
			Blok.konum({ konumx,konumy });
			m_bloklar.push_back(Blok);
			konumx = konumx + m_blokBoyutu.x;
		}
		konumy += m_blokBoyutu.y;
		konumx = 40;
	}
}

void Blok::boyutBelirle(float boyutx, float boyuty)
{
	m_blokBoyutu.x = boyutx;
	m_blokBoyutu.y = boyuty;
	resimYukle();
}

void Blok::resimYukle()
{
	if (!m_texArkaPlan1.loadFromFile("resimler/Bricks/brick_blue_small.png")) {}
	m_resArkaPlan1.setTexture(m_texArkaPlan1);
	m_resArkaPlan1.setTextureRect(sf::IntRect({ 140,180 }, {255,100}));
	//çizim fonksiyonu içerisinde
	auto texBoyut = m_texArkaPlan1.getSize();
	float sx = m_blokBoyutu.x/ 255;
	float sy = m_blokBoyutu.y/ (100);
	m_resArkaPlan1.setScale(sx, sy);
	if (!m_texArkaPlan2.loadFromFile("resimler/Bricks/brick_green_small.png")) {
		std::cout << "2";
	}
	m_resArkaPlan2.setTexture(m_texArkaPlan2);
	m_resArkaPlan2.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan2.setScale(sx, sy);

	if (!m_texArkaPlan3.loadFromFile("resimler/Bricks/brick_pink_small.png")) {
		std::cout << "3";
	}
	m_resArkaPlan3.setTexture(m_texArkaPlan3);
	m_resArkaPlan3.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan3.setScale(sx, sy);

	if (!m_texArkaPlan4.loadFromFile("resimler/Bricks/brick_violet_small.png")) {
		std::cout << "4";
	}
	m_resArkaPlan4.setTexture(m_texArkaPlan4);
	m_resArkaPlan4.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan4.setScale(sx, sy);

	if (!m_texArkaPlan5.loadFromFile("resimler/Bricks/brick_yellow_small.png")) {
		std::cout << "5";
	}
	m_resArkaPlan5.setTexture(m_texArkaPlan5);
	m_resArkaPlan5.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan5.setScale(sx, sy);


	if (!m_texArkaPlan6.loadFromFile("resimler/Bricks/brick_blue_small_cracked.png")) {
		std::cout << "6";
	}
	m_resArkaPlan6.setTexture(m_texArkaPlan6);
	m_resArkaPlan6.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan6.setScale(sx, sy);

	if (!m_texArkaPlan7.loadFromFile("resimler/Bricks/brick_green_small_cracked.png")) {
		std::cout << "7";
	}
	m_resArkaPlan7.setTexture(m_texArkaPlan7);
	m_resArkaPlan7.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan7.setScale(sx, sy);

	if (!m_texArkaPlan8.loadFromFile("resimler/Bricks/brick_pink_small_cracked.png")) {
		std::cout << "8";
	}
	m_resArkaPlan8.setTexture(m_texArkaPlan8);
	m_resArkaPlan8.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan8.setScale(sx, sy);

	if (!m_texArkaPlan9.loadFromFile("resimler/Bricks/brick_violet_small_cracked.png")) {
		std::cout << "9";
	}
	m_resArkaPlan9.setTexture(m_texArkaPlan9);
	m_resArkaPlan9.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan9.setScale(sx, sy);

	if (!m_texArkaPlan10.loadFromFile("resimler/Bricks/brick_yellow_small_cracked.png")) {
		std::cout << "10";
	}
	m_resArkaPlan10.setTexture(m_texArkaPlan10);
	m_resArkaPlan10.setTextureRect(sf::IntRect({ 140,180 }, { 250,100 }));
	m_resArkaPlan10.setScale(sx, sy);
}

sf::Vector2f Blok::boyutGetir()
{
	return m_blokBoyutu;
}

BlokListesi Blok::bloklariDondur()
{
	return m_bloklar;
}

void Blok::blokSil(int blokNumarasi)
{
	m_bloklar.erase(m_bloklar.begin() + blokNumarasi);
}

void Blok::carpimSayisiniArtir(int blokIndeksi)
{
	m_bloklar[blokIndeksi].carpismaSayisiArtir();
}
