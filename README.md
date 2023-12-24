# acikartirma
Fonksiyon, typedef ve struct yapıları kullanılarak yapılan bir açık artırma uygulaması. English : An auction application using function, typedef and struct structures.

**Typedef Yapısı**
Typedef yapısı kullanılarak örneğin **int** ile tanımlanan bir veriyi başka veriler için mantıksal olarak tanımlanmış olunur. Kod içinde anlatılmak gerekilirse : 

typedef int tamsayi;

int main() {
tamsayi ts1;

}

**Struct Yapısı**
Struct yapısı, tanımlanan verileri ilişkili şekilde alır. Örneğin bir öğrencinin adını, soyadını, okul numarası ve sınıfını tanımlamak istersek bunu struct yapısı içinde yaparsak veriyi çektiğimizde girilen öğrencinin verileri bir bütün olur. Kod içinde anlatılmak gerekilirse :

struct ogrenci_bilgi {
  char ogrenci_isim;
  char ogrenci_soyisim;
  int okul_numarasi;
  char sinif;
  
};

**Pointer(İşaretçiler)**
İşaretçiler fonksiyon içinde sonradan tanımlanacak verinin yerinde tanımlanır. Sonradan tanımlanan veri bu işaretçinin yerine geçerek fonksiyon sonradan tanımlanan veriyi kullanır. Kod içinde anlatılmak gerekilirse :

int main(char *h) {

char harf = 'a';
h = &harf;
printf("%c",*h); //Tanımladığımız harf ekranda gözükecektir.

}
