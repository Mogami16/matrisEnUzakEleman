#include <iostream>

using namespace std;


class Matris {
public:

	// Constructor
	Matris(int &_satirSayisi, int &_sutunSayisi);

	// Destructor
	~Matris();

	// Getters
	int** getMatris();
	int getSatirSayisi();
	int getSutunSayisi();

	// Setters
	void setSatirSayisi(int &_satirSayisi);
	void setSutunSayisi(int &_sutunSayisi);

	// Fonksiyonlar
	void matrisYazdir();
	void matriseDegerVer();
	void matrisOlustur();
	bool sayiMevcudiyetiKontrol(int& deger, int& diziYeri);
	int** rastgeleMatrisOlustur();


private:
	int** matris;
	int *satirSayisi;
	int *sutunSayisi;
	int diziYeri = 0;
	int* girilenSayilar;
	int* uzunluk;
	int* yeniMatrisYerleri;


};