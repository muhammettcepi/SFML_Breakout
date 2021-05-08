#include "Oyun.hpp"

#include<iostream>

Oyun::Oyun()
{
	m_raket.ilkKonum(m_pencere.pencereGetir());
	m_top.ilkKonum(m_pencere.pencereGetir());
	m_kapalimi = false;
	m_cerceveSuresi = 1.0f / 180.0f;
	m_hucreBoyutu = 20.0f;
	auto boyut = m_pencere.pencereGetir().getSize();
	m_sahne.olustur(boyut.x, boyut.y, m_hucreBoyutu);
	acidegeri=m_top.aciBelirle();
	m_topHareketBoyutux = 1;
	m_topHareketBoyutuy = 1;
	m_oyunBasladiMi = false;
	int blokgenislik = ceil((boyut.x - 80) / 5);
	m_blok.boyutBelirle(blokgenislik, 40);
	m_blok.bloklaraEkle();
}

Oyun::~Oyun()
{
}
void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_siradakiYon = YON::SAG;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_siradakiYon = YON::SOL;
	else 
		m_siradakiYon = YON::BOS;
}
bool Oyun::raketSahneIcindemi()
{
	auto konum = m_raket.konumGetir();
	auto boyut = m_sahne.boyutGetir();
	if (konum.x <= 0 ||
		konum.y <= 0 ||
		konum.x + m_hucreBoyutu >= boyut.x ||
		konum.y + m_hucreBoyutu >= boyut.y)
	{
		return false;
	}
	return true;
}
void Oyun::sahneGuncelle()
{
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		if (topSahneDisindami() == true ||
			blokBittimi() == true)
		{
			m_kapalimi = true;
			return;
		}
		m_gecenSure -= sf::seconds(m_cerceveSuresi);
		m_raket.yon(m_siradakiYon);
		m_raket.hareket(5);
		carpismaKontrol();
		if(m_oyunBasladiMi)
			m_top.hareketEt(m_topHareketBoyutux, m_topHareketBoyutuy, acidegeri);
		
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	m_sahne.ciz(m_pencere.pencereGetir());
	m_raket.ciz(m_pencere.pencereGetir());
	m_blok.ciz(m_pencere.pencereGetir());
	m_top.ciz(m_pencere.pencereGetir());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	m_oyunBasladiMi = true;
	
	m_pencere.cizimiBitir();
	
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

bool Oyun::bittimi()
{
	if (m_kapalimi)
		return true;

	return m_pencere.kapandimi();
}

bool Oyun::bloklaraAlttanveyaUsttenCarptimi()
{
	int bloklarSayisi = 0;
	sf::Vector2f blokBoyut = m_blok.boyutGetir();
	for (auto blok : m_blok.bloklariDondur()) {
		auto blokKonum=blok.konumGetir();
		auto topKonum = m_top.konumGetir();
		
		if (topKonum.x >= blokKonum.x && topKonum.x <= blokKonum.x + blokBoyut.x && blokKonum.y + blokBoyut.y >= topKonum.y) {
			m_blok.carpimSayisiniArtir(bloklarSayisi);
			if (blok.carpismaSayisiDondur() >= 1)
				m_blok.blokSil(bloklarSayisi);
			return true;
		}
		else if (topKonum.x >= blokKonum.x && topKonum.x <= blokKonum.x + blokBoyut.x && blokKonum.y >= topKonum.y) {
			m_blok.carpimSayisiniArtir(bloklarSayisi);
			if (blok.carpismaSayisiDondur() >= 1)
				m_blok.blokSil(bloklarSayisi);
			return true;
		}
		bloklarSayisi++;
	}
	return false;
}
bool Oyun::bloklaraYandanCarptimi()
{
	int bloklarSayisi = 0;
	sf::Vector2f blokBoyut = m_blok.boyutGetir();
	for (auto blok : m_blok.bloklariDondur()) {
		auto blokKonum = blok.konumGetir();
		auto topKonum = m_top.konumGetir();

		if (topKonum.y >= blokKonum.y && topKonum.y <= blokKonum.y + blokBoyut.y && blokKonum.x== topKonum.x) {
			m_blok.carpimSayisiniArtir(bloklarSayisi);
			if (blok.carpismaSayisiDondur() == 1)
				m_blok.blokSil(bloklarSayisi);
			return true;
		}
		else if (topKonum.y >= blokKonum.y && topKonum.y <= blokKonum.y + blokBoyut.y &&
			blokKonum.x+blokBoyut.x == topKonum.x) {
			m_blok.carpimSayisiniArtir(bloklarSayisi);
			if (blok.carpismaSayisiDondur() >= 1)
				m_blok.blokSil(bloklarSayisi);
			return true;
		}
		bloklarSayisi++;
	}
	return false;
}


void Oyun::carpismaKontrol()
{
	auto konum = m_top.konumGetir();
	auto sahneKonum = m_sahne.boyutGetir();
	if (konum.x >= sahneKonum.x - 40) {
		m_topHareketBoyutux = -m_topHareketBoyutux;
	}
	if (konum.x <= 20) {
		m_topHareketBoyutux = -m_topHareketBoyutux;
	}
	if (konum.y <= 20)
		m_topHareketBoyutuy = -m_topHareketBoyutuy;
	sf::Vector2f raketBoyut=m_raket.raketBoyutGetir();
	sf::Vector2f raketKonum=m_raket.konumGetir();
	int fark = konum.y - raketKonum.y +raketBoyut.y;
	if (fark==0&& konum.x >= raketKonum.x && konum.x<=raketKonum.x+raketBoyut.x) {
		acidegeri = m_top.aciBelirle();
		m_topHareketBoyutuy = -m_topHareketBoyutuy;
	}
	if (bloklaraYandanCarptimi())
		m_topHareketBoyutux = -m_topHareketBoyutux;
	if (bloklaraAlttanveyaUsttenCarptimi()) {
		m_topHareketBoyutuy = -m_topHareketBoyutuy;
	}
}

bool Oyun::topSahneDisindami()
{
	if (m_top.konumGetir().y >= m_sahne.boyutGetir().y)
		return true;
}

bool Oyun::blokBittimi()
{
	if (m_blok.bloklariDondur().size() == 0)
		return true;
}
