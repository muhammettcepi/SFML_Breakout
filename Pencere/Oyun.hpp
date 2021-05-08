#pragma once

#include "Pencere.hpp"
#include "Sahne.hpp"
#include "Raket.hpp"
#include "Top.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	bool bittimi();
	bool raketSahneIcindemi();
	bool bloklaraAlttanveyaUsttenCarptimi();
	bool bloklaraYandanCarptimi();
	Sahne m_sahne;
	float m_hucreBoyutu;
	void carpismaKontrol();
	bool topSahneDisindami();
	bool blokBittimi();
private:
	Pencere			m_pencere;
	sf::Clock		m_saat;
	sf::Time		m_gecenSure;
	YON			m_siradakiYon;
	float m_cerceveSuresi;
	bool m_kapalimi;
	Raket m_raket;
	BlokListesi Bloklar;
	Top m_top;
	int acidegeri;
	int m_topHareketBoyutux;
	int m_topHareketBoyutuy;
	bool m_oyunBasladiMi;
	Blok m_blok;
};