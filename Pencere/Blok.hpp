#pragma once
#include "Bloklar.hpp"
#include <SFML/Graphics.hpp>
class Blok
{
public:
	Blok();
	void ciz(sf::RenderWindow& pencere);
	void bloklaraEkle();
	void boyutBelirle(float  boyutx,float boyuty);
	void resimYukle();
	sf::Vector2f boyutGetir();
	BlokListesi bloklariDondur();
	void blokSil(int blokNumarasi);
	void carpimSayisiniArtir(int blokIndeksi);

private:
	BlokListesi m_bloklar;
	sf::Texture			m_texArkaPlan1;
	sf::Texture			m_texArkaPlan2;
	sf::Texture			m_texArkaPlan3;
	sf::Texture			m_texArkaPlan4;
	sf::Texture			m_texArkaPlan5;
	sf::Texture			m_texArkaPlan6;
	sf::Texture			m_texArkaPlan7;
	sf::Texture			m_texArkaPlan8;
	sf::Texture			m_texArkaPlan9;
	sf::Texture			m_texArkaPlan10;
	sf::Vector2f m_blokBoyutu;
	sf::Sprite			m_resArkaPlan1;
	sf::Sprite			m_resArkaPlan2;
	sf::Sprite			m_resArkaPlan3;
	sf::Sprite			m_resArkaPlan4;
	sf::Sprite			m_resArkaPlan5;
	sf::Sprite			m_resArkaPlan6;
	sf::Sprite			m_resArkaPlan7;
	sf::Sprite			m_resArkaPlan8;
	sf::Sprite			m_resArkaPlan9;
	sf::Sprite			m_resArkaPlan10;
};
