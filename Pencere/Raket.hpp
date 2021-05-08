#pragma once
#include <SFML/Graphics.hpp>
enum class YON { BOS, SOL, SAG };
class Raket
{
public:
	Raket();
	void ilkKonum(sf::RenderWindow& pencere);
	void ciz(sf::RenderWindow& pencere);
	void yon(YON yeniYon);
	void hareket(float boyut);
	sf::Vector2f raketBoyutGetir();
	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f(konumGetir());
	bool sahneIcindemi(sf::Vector2f yeniKonum);
	std::string  resimSec();

private:
	void resimYukle(sf::String resimAdi);
	YON m_yon;
	sf::Vector2u m_pencereBoyut;
	sf::Vector2f m_konum;
	sf::RectangleShape m_raketSekil;
	sf::Vector2f m_raketBoyutu;
	sf::Sprite			m_resArkaPlan;
	sf::Texture			m_texArkaPlan;
};
