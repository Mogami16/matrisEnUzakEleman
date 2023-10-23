#include "Matris.h"
#include <random>

// Constructor
Matris::Matris(int &_satirSayisi, int &_sutunSayisi){
	Matris::satirSayisi = &_satirSayisi;
	Matris::sutunSayisi = &_sutunSayisi;

	Matris::uzunluk = new int(_satirSayisi * _sutunSayisi);
	Matris::girilenSayilar = new int[*uzunluk];

	matrisOlustur(); // Matris::matris
	matriseDegerVer();

}


// Destructor
Matris::~Matris() {

	delete[] matris;
	delete uzunluk;
	delete[] girilenSayilar;

}



// Getters
int Matris::getSatirSayisi(){

	return *satirSayisi;

}

int Matris::getSutunSayisi(){

	return *sutunSayisi;

}

int** Matris::getMatris(){

	return matris;

}



// Setters
void Matris::setSatirSayisi(int &_satirSayisi){

	*satirSayisi = _satirSayisi;

}

void Matris::setSutunSayisi(int &_sutunSayisi){

	*sutunSayisi = _sutunSayisi;

}


// Fonksiyonlar


// For loop i�inde her bir elemana yeni matrisdeki yerini belirle -> int *yeniMatrisYerleri = new int[uzunluk]

// Rastgele matris olu�turma
int** Matris::rastgeleMatrisOlustur() {

	int* matrisSayilari = new int[*uzunluk];

	// Matris say�lar�n�n bir dizinde tutulmas�
	int sayac = 0;
	for (int i = 0; i < *satirSayisi; i++) {
		for (int j = 0; j < *sutunSayisi; j++) {

			matrisSayilari[sayac] = matris[i][j];
			sayac++;
		}
	}


	int* olusanSayilar = new int[*uzunluk];
	for (int i = 0; i < *uzunluk; i++) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> sayi(0, *(uzunluk)-1);

		bool dahaOnceOlustuMu = false; // False ise olu�mam�� demektir

		int diziYeri = sayi(rng);
		// Olu�turulan rastgele say� daha �nce olu�turuldu mu kontrol�
		for (int k = 0; k < *uzunluk; k++) {

			if (olusanSayilar[k] == diziYeri) {

				dahaOnceOlustuMu = true;
				break;
			}
		}
		if (!dahaOnceOlustuMu) {
			olusanSayilar[i] = diziYeri;
		}

		else {
			i--;
		}
	}

	// Rastgele say�lar -> her say�n� yeni indexi
	int** yeniMatris = new int*[*satirSayisi];
	for (int i = 0; i < *satirSayisi; i++) {
		yeniMatris[i] = new int[*sutunSayisi];
	}

	
	// matrisSayilari(5,6,7,8) - olusanSayilar(0,3,2,1)
	// Yeni matrise rastgele de�erlerin verilmesi
	for (int i = 0; i < *uzunluk; i++) {
		sayac = 0;
		for (int k = 0; k < *satirSayisi; k++) {
			for (int j = 0; j < *sutunSayisi; j++) {

				if (i == olusanSayilar[sayac]) {
					yeniMatris[k][j] = matrisSayilari[i];
					
				}
				sayac++;
			}
		}

	}
	
	
	
	delete[] olusanSayilar;
	return yeniMatris;

}

// Matrisin olu�turulmas�
void Matris::matrisOlustur() {

	Matris::matris = new int* [*satirSayisi];

	for (int i = 0; i < *satirSayisi; i++) {
		matris[i] = new int[*sutunSayisi];
	}


}


// Girilen say�n�n daha �nce girilip girilmedi�inin belirlenmesi
bool Matris::sayiMevcudiyetiKontrol(int& deger, int& diziYeri){

	for (int i = 0; i < *uzunluk; i++) {
		if (deger == girilenSayilar[i]) {
			return false;
		}
	}
	girilenSayilar[diziYeri] = deger;

	return true; // True ise bu say� mevcut de�ildir

	
}



// Matrisin yazd�r�lmas�
void Matris::matrisYazdir(){

	int sutunHesap = 0;
	for (int i = 0; i < *satirSayisi; i++) {
		for (int j = 0; j < *sutunSayisi; j++) {

			cout << matris[i][j] << " ";

		}
		cout << endl;
	}

}


// Matrise de�erlerin verilmesi
void Matris::matriseDegerVer(){


	for (int i = 0; i < *satirSayisi; i++) {
		for (int j = 0; j < *sutunSayisi; j++) {

			int deger;
			cout << i + 1 << ". Satir " << j + 1 << ". Sutun: ";
			cin >> deger;

			bool sonuc = sayiMevcudiyetiKontrol(deger, diziYeri);

			if (sonuc) {
				matris[i][j] = deger;
				diziYeri++;
			}
			else {

				cout << "Bu sayiyi daha once girdiniz lutfen tekrar giris yapin!" << endl;
				j--;
				continue;

			}
		}
	}
}







