#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Blok.hpp"
class Sahne
{
public:
	Sahne();
	void olustur(float sahneGenislik,
		float sahneYukseklik,
		float hucreBoyut);
	void ciz(sf::RenderWindow& pencere);
	void duvarResimSayisi();
	sf::Vector2f boyutGetir();

	
private:
	std::vector<sf::Sprite> m_spriteListesi;
	std::vector<int>seciliDuvarResimleriEn;
	std::vector<int>seciliDuvarResimleriBoy;
	void duvarResimYukle();
	int m_enSayisi;
	int m_boySayisi;
	float m_duvarHucreBoyutu;
	float ucKonumY;
	float ucKonumX;
	float blokgenislik;
	sf::RectangleShape m_duvarHucresi;
	sf::RectangleShape m_Yem;
	sf::RectangleShape m_Blok;
	sf::Texture			m_texArkaPlan1;
	sf::Texture			m_texArkaPlan2;
	sf::Texture			m_texArkaPlan3;
	sf::Texture			m_texArkaPlan4;
	sf::Sprite			m_resArkaPlan1;
	sf::Sprite			m_resArkaPlan2;
	sf::Sprite			m_resArkaPlan3;
	sf::Sprite			m_resArkaPlan4;
	Blok blok;
};
