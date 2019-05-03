#include <iostream>
#include <vector>
#include <cstring>
#include <string>
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
    int sayiBoyutu=bigNumber.size();

    char stringArray1[sayiBoyutu+1];     //stringi arraya dönüştürdükten sonra içine atmak için karakter dizisi tanımlıyoruz
    strcpy(stringArray1,bigNumber.c_str());    //c_str() ile stringi arraya dönüştürüp stringArray içine kopyalıyoruz

    static int *sayi1=new int[sayiBoyutu+1];       //char dizisini int e dönüştürüp içine atmak için int arrayi oluşturuyoruz, array döndürmek için static yapmak lazım

    for(int i=0;i<sayiBoyutu;i++){
        sayi1[i]=stringArray1[i]-48;  //stringArray içindeki değerleri tek tek integer a dönüştürüyoruz.
    }


    cout<<"2.sayiyi giriniz: \n";
    cin>>bigNumber;
    sayiBoyutu= bigNumber.size();

    char stringArray2[sayiBoyutu+1];     //stringi arraya dönüştürdükten sonra içine atmak için karakter dizisi tanımlıyoruz
    strcpy(stringArray2,bigNumber.c_str());    //c_str() ile stringi arraya dönüştürüp stringArray içine kopyalıyoruz

    static int *sayi2=new int[sayiBoyutu+1];       //char dizisini int e dönüştürüp içine atmak için int arrayi oluşturuyoruz, array döndürmek için static yapmak lazım


    for(int i=0;i<sayiBoyutu;i++){
        sayi2[i]=stringArray2[i]-48;  //stringArray içindeki değerleri tek tek integer a dönüştürüyoruz.
    }

    cout<< sizeof(sayi1);





    return 0;
}