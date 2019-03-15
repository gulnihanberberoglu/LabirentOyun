#include <time.h>
#include <stdio.h>
#define STACK_BOYUTU 200

typedef enum { false, true } bool;

//Stack yapisi tanýmlandi
typedef struct stack_s{
	int en_ust;
	int yigin[STACK_BOYUTU];
}STACK;

//yol taninimi yapildi , bagli liste
typedef struct yol {
    int satirNumarasi;
	int sutunNumarasi;
    struct yol * sonraki;
}yolDegiskeni;

STACK stack; // stack verisi tanimi
yolDegiskeni  *head=NULL; // bagli listenin basini isaret eden pointer  , gidilen tum noktalari tutuyor
yolDegiskeni  *head_control=NULL; //gezilen yollari tutan kontrol pointeri , bosuna gidilen noktalari tutuyor.
static int cikisaUlasildimi = 0; //  cikisa ulasip ulasimadigini kontrol degiskeni

static int sutunBoyutu = 0;
static int satirBoyutu = 0;

// labirentin giris ve cikis  noktalari tanimlandi , sonrasinda kullanicidan alinarak degisiyor.
static int baslangicSatirX = -1;
static int baslangicSatirY = -1;
static int cikisSatirX = -1;
static int cikisSatirY = -1;

// ---> Fonksiyonlarin govde tanimlamalari
void yolu_bul(int **labirent, int suankiX, int suankiY);
bool yolu_kontrol_et(int suankiX, int suankiY,int tipi);
void kordinatlari_yola_ekle(int kordinatX, int kordinatY);
void ekrana_yazdir();
void bosa_gidilmis_yol_kontrol(int kordinatX, int kordinatY);
void stacke_ekle(int sayi);
int  stackten_cikar();
void stack_yazdir();

int main()
{
    //olusturulacak labirent icin satir ve sutun bilgisi aliniyo
	printf("Satir Sayisi Giriniz: ");
	scanf("%d", &satirBoyutu);
	printf("Sutun Sayisi Giriniz:");
	scanf("%d", &sutunBoyutu);

	srand(time(NULL));

	int **labirent = (int **) malloc( sizeof(int) * satirBoyutu ); //girilen satir sayisi kadar bellekten yer ayriliyor.
    int i, j;

    // herbir satir icin girilen sutun sayisi kadar bellekten yer ayriliyor.
	for (i = 0; i < satirBoyutu; i++){
		labirent[i] = (int *)malloc(sizeof(int)* sutunBoyutu);
	}

    // matrisin degerlerini rastgele dolduruyoruz.
	for (i = 0; i < satirBoyutu; i++){
		for (j = 0; j < sutunBoyutu; j++){
			labirent[i][j] = rand() % 2; // 1 veya sifir seklinde rastgele atama yapiliyor
		}
    }
    // ----------------Rastgele degelerle Olusturulan Labirentin ekrana yazdirildigi bolum --------------------------
    printf("\n");

	for (i=0;i<satirBoyutu;i++){
		for (j = 0; j < sutunBoyutu; j++){
			printf("%d ", labirent[i][j]);
		}
		printf("\n");
    }
   // ------------------------------------------------------------------------------------


    //------ Noktalarin dogrulugu kontrolu ------------------------------------------------------------------------------------
	// sonsuz donguye girerek kullanicinin girdigi giris ve cikis noktalari dogru olana kadar donguyu devam ettiriyoruz
  	while (1==1){
        printf("\nLabirentin giris noktasi : \nSatir numarasi :  ");
        scanf("%d", &baslangicSatirX);
        printf("Baslangic Sutun numarasi --> ");
        scanf("%d", &baslangicSatirY);

        printf("Labirentin cikis noktasi:\nSatir numarasi : ");
        scanf("%d", &cikisSatirX);
        printf("Baslangic Sutun numarasi --> ");
        scanf("%d", &cikisSatirY);


        // sinir kontrolu yani girilen baslangic ve bitis noktalari belirlenen labirent boyutunu asmadiginin kontrolu
        // girilen deger sinirlarin icerisinde mi?
        if (baslangicSatirX < satirBoyutu && baslangicSatirY < sutunBoyutu && cikisSatirX < satirBoyutu && cikisSatirY < sutunBoyutu){
                // eger girilen nokta sinirlarin icinde ise noktanin 1 olup olmadigini kontrol et , eger 1 degilse  tekrar nokta iste
                if (labirent[baslangicSatirX][baslangicSatirY] == 1 && labirent[cikisSatirX][cikisSatirY] == 1){
                    break;
                }else{
                    printf("\n");
                    printf("HATA !! Yanlis nokta sectiniz.Sectiginiz noktada yol yoktur! tekrar girin!");
                    printf("\n\n");
                }
        }else{
            printf("\n");
            printf("HATA !! Girdiginiz noktalar labirent sinirinin disindadir!");
            printf("\n\n");
         }
	}
   // ------------------------------------------------------------------------------------

   	stack.en_ust = -1; // stack'in en ust degerini -1'e esitledik.

	kordinatlari_yola_ekle(baslangicSatirX,baslangicSatirY);
	yolu_bul(labirent, baslangicSatirX, baslangicSatirY);

	if (cikisaUlasildimi == 0){
		printf("\nMaalesef Yol yok....");
	}else{
		printf("\n---------ISTE CiKiS YOLUN-----------\n\n");
		ekrana_yazdir(labirent);
		stack_yazdir();
	}
    return 0;
}

void yolu_bul(int **labirent, int suankiX, int suankiY)
{
	if (suankiX == cikisSatirX && suankiY == cikisSatirY) // girilen hedef noktalarla bulunan noktalar birbirine esitse cikisa ulastin demektir.
	{
		cikisaUlasildimi = 1;
		return;
	}
	// saga dogru ilerleme durumu
    // suankiY + 1 < sutunBoyutu  --> labirentin boyutu asip asmadiginin kontrolu
    // labirent[suankiX][suankiY + 1] == 1   demek  benim sagimdaki eleman 1 mi?
    // cikisaUlasildimi == 0   demek cikisa ulasildi mi?
	if (suankiY + 1 < sutunBoyutu && labirent[suankiX][suankiY + 1] == 1  && cikisaUlasildimi == 0){

		// daha once buraya gittim mi?
		if ( yolu_kontrol_et(suankiX,suankiY+1,0) ){
			stacke_ekle(3);  // saga gittim diyoruz
			kordinatlari_yola_ekle(suankiX, suankiY+1); // gidilecek noktayi ekledik
			yolu_bul(labirent, suankiX, suankiY +1);
		}

	}
	// sola dogru ilerleme durumu
	if (suankiY -1 < sutunBoyutu &&  suankiY >=0  && labirent[suankiX][suankiY - 1] == 1  && cikisaUlasildimi == 0)
	{
		// daha once buraya gittim mi?
		if ( yolu_kontrol_et(suankiX, suankiY - 1,0) ){

			stacke_ekle(4);
			kordinatlari_yola_ekle(suankiX, suankiY - 1);
			yolu_bul(labirent, suankiX, suankiY - 1);
		}
	}
	// asagi dogru ilerleme durumu
	if (suankiX + 1 < satirBoyutu && labirent[suankiX+1][suankiY] == 1 && cikisaUlasildimi == 0)
	{
		// daha once buraya gittim mi?
		if ( yolu_kontrol_et(suankiX+1, suankiY,0) ){

			stacke_ekle(2);
			kordinatlari_yola_ekle(suankiX+1, suankiY);
			yolu_bul(labirent, suankiX+1, suankiY);
		}
	}
	//yukari dogru ilerleme durumu
	if (suankiX - 1 < satirBoyutu &&  suankiX - 1 >= 0 && labirent[suankiX - 1][suankiY] == 1 && cikisaUlasildimi == 0)
	{
		// daha once buraya gittim mi?
		if ( yolu_kontrol_et(suankiX-1, suankiY,0) ){
			stacke_ekle(1);
			kordinatlari_yola_ekle(suankiX-1, suankiY);
			yolu_bul(labirent, suankiX-1, suankiY);
		}
	}
	// eger zaten saga sola yukari asagi gidemiyorsam gittigim noktadan geri donmeliyim
	if (cikisaUlasildimi == 0)
	{
		bosa_gidilmis_yol_kontrol(suankiX, suankiY); // eger sag sol yukari asagi gidemiyorsa gittigi noktadan geri doner ve bunu control fonksiyonu ile kaydeder. gitmemek icin
		stackten_cikar(); // bosuna gittigimiz icin stackten son ekledigimiz yolu stackten_cikar yaparak cikarttik.
	}
	return;  // eger hic bi yere gidemiyosa recursive'den geri don . bu noktaya bosuna gittin yol yok.
}

// labirenti ekrana yazdir
void ekrana_yazdir(int **labirent)
{
	int i,j;
	for (i = 0; i < satirBoyutu; i++ ){

			for (j = 0; j < sutunBoyutu; j++){
				printf("%d ", labirent[i][j] );
			}

			if (i == satirBoyutu / 2){
				printf("   ----->     ");
			}else{
				printf("              ");
			}


			for (j = 0; j < sutunBoyutu; j++)
			{
				if ( yolu_kontrol_et(i,j,0) == false ){

					if (yolu_kontrol_et(i, j, 1) == false){
						printf("0 ");
					}else{
						printf("1 ");
					}
				}
				else{
					printf("0 ");
				}
			}
		printf("\n");
	}
}


// 3 tane argümant alýr.2 si kordinat sonuncusu tip .Tip ' deðiþkenine göre 2 türlü kontrol yapar. tip 0 ise gezilen
// bütün gelen kordinatlarý, daha önce gezilmiþ mi onu kontrol eder.tip 0 olmadýðý durumda ise gelen korinatýnýn return olup
// olmadýðýný kontrol eder.
bool yolu_kontrol_et(int suankiX,int curretY,int tipi)
{
	if (tipi == 0)
	{
		yolDegiskeni *suanki = head;
		while (suanki != NULL){

			if (suanki->sutunNumarasi == curretY && suanki->satirNumarasi == suankiX){
				return false;
			}
			suanki = suanki->sonraki;
		}

		return true;
	}
	else{
		yolDegiskeni *suanki = head_control;

		while (suanki != NULL) {

			if (suanki->sutunNumarasi == curretY && suanki->satirNumarasi == suankiX){
				return false;
			}
			suanki = suanki->sonraki;
		}
		return true;
	}
}

// gezilen bütün koordinatlarý tutar.linked liste head deðiþkeninde saklanýr
void kordinatlari_yola_ekle(int valueX, int valueY)
{
		yolDegiskeni * ilkNokta = (yolDegiskeni *) malloc(sizeof(yolDegiskeni));
		ilkNokta->satirNumarasi = valueX;
		ilkNokta->sutunNumarasi = valueY;
		ilkNokta->sonraki = head;
		head = ilkNokta;
}

// foksiyonun içerisinden dönen koordinatlarý tutar. yolu bulurken boþa gidilmiþ yerler linked liste head_control deðiþkeninde saklanýr
void bosa_gidilmis_yol_kontrol(int valueX, int valueY)
{
	yolDegiskeni * ilkNokta = (yolDegiskeni *)malloc(sizeof(yolDegiskeni));

	ilkNokta->satirNumarasi = valueX;
	ilkNokta->sutunNumarasi = valueY;
	ilkNokta->sonraki = head_control;
	head_control = ilkNokta;
}

void stacke_ekle(int sayi)
{
	if (stack.en_ust == (STACK_BOYUTU - 1)){
		printf("Stack Dolu!!");
		return;
	}else{
		stack.en_ust = stack.en_ust + 1;
		stack.yigin[stack.en_ust] = sayi;
	}
	return;
}

int stackten_cikar()
{
	int sayi;
	if (stack.en_ust == -1){
		printf("Stack boþ!!\n");
		return;
	}else{
		sayi = stack.yigin[stack.en_ust];
		stack.en_ust = stack.en_ust - 1;
	}
	return(sayi); // stackten cikarilan elemani dondur
}

void stack_yazdir()
{
	int i;
	if (stack.en_ust == -1){
		printf("Stack bos!!\n\n");
		return;
	}
	else
	{
		printf("\nbulunan yol ----> ((4-sol, 3-sag, 2-asagi,1-yukari))\n\n");
		for (i = 0; i <= stack.en_ust; i++)
		{
			printf(" -> %d", stack.yigin[i]);
		}
	}
	printf("\n");
}
