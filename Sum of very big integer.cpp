/*
 * Enes Elma
 * 1306120054
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 * char a = '6';    *char to int*
 * int b = a-48;    --> b=6 olur
 * ASCII tablosunda rakamlar 48-57 arasındadır
 */

int main(){
    string bigNumber;       //sayıyı string olarak alıyoruz kullanıcıdan

    cout<<"1.sayiyi giriniz: \n";
    cin>>bigNumber;
    int sayiBoyutu1=bigNumber.size();
    int maxBoyut=sayiBoyutu1;            //hangi sayi büyükse ona göre döngü oluşturacağız

    char stringArray1[sayiBoyutu1+1];     //stringi arraya dönüştürdükten sonra içine atmak için karakter dizisi tanımlıyoruz
    strcpy(stringArray1,bigNumber.c_str());    //c_str() ile stringi arraya dönüştürüp stringArray içine kopyalıyoruz

    static int *sayi1=new int[sayiBoyutu1+1];       //char dizisini int e dönüştürüp içine atmak için int arrayi oluşturuyoruz, array döndürmek için static yapmak lazım

    for(int i=0;i<sayiBoyutu1;i++){
        sayi1[i]=stringArray1[i]-48;  //stringArray içindeki değerleri tek tek integer a dönüştürüyoruz.
    }


    cout<<"2.sayiyi giriniz: \n";
    cin>>bigNumber;
    int sayiBoyutu2= bigNumber.size();
    if(sayiBoyutu2>maxBoyut) maxBoyut=sayiBoyutu2;

    char stringArray2[sayiBoyutu2+1];     //stringi arraya dönüştürdükten sonra içine atmak için karakter dizisi tanımlıyoruz
    strcpy(stringArray2,bigNumber.c_str());    //c_str() ile stringi arraya dönüştürüp stringArray içine kopyalıyoruz

    static int *sayi2=new int[sayiBoyutu2+1];       //char dizisini int e dönüştürüp içine atmak için int arrayi oluşturuyoruz, array döndürmek için static yapmak lazım

    for(int i=0;i<sayiBoyutu2;i++){
        sayi2[i]=stringArray2[i]-48;  //stringArray içindeki değerleri tek tek integer a dönüştürüyoruz.
    }

    vector <int> toplamDizi;
    int elde=0;
    int toplam;
    for(int i=0;i<maxBoyut;i++){        //iki dizinin elemanlarını toplayıp toplamDizi vektörüne push ediyoruz

        if(sayiBoyutu1!=0 && sayiBoyutu2!=0) {
            toplam = sayi1[sayiBoyutu1 - 1] + sayi2[sayiBoyutu2 - 1] + elde;
            elde = 0;
            if (toplam > 9) {
                elde = 1;
                toplam = toplam % 10;
            }
            toplamDizi.push_back(toplam);
            sayiBoyutu1--;
            sayiBoyutu2--;
        }
        if(sayiBoyutu2==0 && sayiBoyutu1!=0){
            toplam = sayi1[sayiBoyutu1 - 1]+elde;
            elde = 0;
            if (toplam > 9) {
                elde = 1;
                toplam = toplam % 10;
            }
            toplamDizi.push_back(toplam);
            sayiBoyutu1--;
        }
        if(sayiBoyutu1==0 && sayiBoyutu2!=0){
            toplam = sayi2[sayiBoyutu2 - 1]+elde;
            elde = 0;
            if (toplam > 9) {
                elde = 1;
                toplam = toplam % 10;
            }
            toplamDizi.push_back(toplam);
            sayiBoyutu2--;
        }

    }

    if(elde==1){    //son toplama işleminde elde kaldıysa eğer onu da toplamDizi vektörüne push ediyoruz.
        maxBoyut++;
        toplamDizi.push_back(elde);
    }

    cout<<"Toplam: \n";
    for(int i=maxBoyut;i>0;i--){    //vektöre tersten ekleme yaptığımız için eğer vektörü yeniden ters çevirip yazdırırsak işlem sonucunu bulmuş oluruz
        cout<<toplamDizi[i-1];
    }
    
    cout<<endl;
    return 0;
}