// M x N lik matris olu�turulacak - > Tamamland�
// Matris i�indeki elemanlar elle girilecek ve de�erler farkl� olacak -> Tamamland�
// Girilen say�n�n daha �nce girilip girilmedi�ini belirten bir bool d�nd�ren fonksiyon yaz�lacak(sayiMevcudiyetiKontrol) -> Tamamland�
// Bu matris rastgele olarak elemanlar� ba�ka bir matrise aktar�lacak -> Tamamland�
// Birinci matris ile ikinci matristeki ayn� eleman�n kendine g�re uzakl��� bulunacak -> Tamamland�
// Birbirine en uzak eleman yazd�r�lacak -> Tamamland�

// Uzakl�k = |1. Sat�r - 2. Sat�r| + |1. S�tun - 2. S�tun|

// ---------------------TAMAMLANDI---------------------


#include <iostream>
#include "Matris.h"
#include <vector>

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

	vector<int> sayilar;
	vector<int> farklar;

	// Eski Matris
	for (int i = 0; i < satirSayisi; i++) {
		for (int j = 0; j < sutunSayisi; j++) {

			// Yeni Matris
			for (int k = 0; k < satirSayisi; k++) {
				for (int l = 0; l < sutunSayisi; l++) {
					if (matris->getMatris()[i][j] == yeniMatris[k][l]) {

						if ((abs(i - k) + abs(j - l)) >= enBuyukFark) {
							
							enBuyukFark = abs(i - k) + abs(j - l);
							sayi = matris->getMatris()[i][j];
							sayilar.push_back(sayi);
							farklar.push_back((abs(i - k) + abs(j - l)));
						}

					}



				}
			}
		}
	}


	cout << "Sayilar: ";
	int index = 0;
	for (int i : sayilar) {
		
		if (farklar.at(index) == enBuyukFark) {
			cout << i << " ";
		}
		index++;

	}
	cout << endl;


	
	//cout << "Sayi: " << sayi << endl;
	cout << "Fark: " << enBuyukFark << endl;

	delete[] yeniMatris;
	delete matris;

	return 0;
}