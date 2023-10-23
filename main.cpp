// M x N lik matris oluþturulacak - > Tamamlandý
// Matris içindeki elemanlar elle girilecek ve deðerler farklý olacak -> Tamamlandý
// Girilen sayýnýn daha önce girilip girilmediðini belirten bir bool döndüren fonksiyon yazýlacak(sayiMevcudiyetiKontrol) -> Tamamlandý
// Bu matris rastgele olarak elemanlarý baþka bir matrise aktarýlacak -> Tamamlandý
// Birinci matris ile ikinci matristeki ayný elemanýn kendine göre uzaklýðý bulunacak -> Tamamlandý
// Birbirine en uzak eleman yazdýrýlacak -> Tamamlandý

// Uzaklýk = |1. Satýr - 2. Satýr| + |1. Sütun - 2. Sütun|

// ---------------------TAMAMLANDI---------------------


#include <iostream>
#include "Matris.h"


using namespace std;


int main() {
	int satirSayisi, sutunSayisi;

	cout << "Satir sayisi: ";
	cin >> satirSayisi;

	cout << "Sutun sayisi: ";
	cin >> sutunSayisi;


	Matris *matris = new Matris(satirSayisi, sutunSayisi);
	int boyut = satirSayisi * sutunSayisi;

	cout << "1. Matris" << endl;
	matris->matrisYazdir();
	cout << endl;
	
	int** yeniMatris = matris->rastgeleMatrisOlustur();
	
	cout << "2. Matris" << endl;
	for (int i = 0; i < satirSayisi; i++) {
		for (int j = 0; j < sutunSayisi; j++) {

			cout << yeniMatris[i][j] << " ";

		}
		cout << endl;
	}





	int enBuyukFark = 0;
	int sayi = 0;
	// Eski Matris
	for (int i = 0; i < satirSayisi; i++) {
		for (int j = 0; j < sutunSayisi; j++) {

			// Yeni Matris
			for (int k = 0; k < satirSayisi; k++) {
				for (int l = 0; l < sutunSayisi; l++) {
					if (matris->getMatris()[i][j] == yeniMatris[k][l]) {

						if ((abs(i - k) + abs(j - l)) > enBuyukFark) {
							
							enBuyukFark = abs(i - k) + abs(j - l);
							sayi = matris->getMatris()[i][j];
						}

					}



				}
			}
		}
	}
	
	cout << "Sayi: " << sayi << endl;
	cout << "Fark: " << enBuyukFark << endl;

	delete[] yeniMatris;
	delete matris;

	return 0;
}