#include <stdio.h>
    
/*Öğrencilerin Adı-Soyadı/Numarası/Fakülteleri
Sergen Ege Gençer/22181616026/Teknoloji
Uygar Gökhan Koca/22181616007/Teknoloji
Yusuf Ferhat Yılmaz/221816160032/Teknoloji*/


void kullanicicevabi(){
    int puan = 0;
    char yanitiniz;
    char sayac = 0;
    char deger[10][4] = {80,100,90,60,80,50,100,10,50,90,50,50,80,90,50,60,80,90,60,20,80,90,50,70,90,70,80,40,60,50,100,60,80,90,90,70,70,80,40,90};
    char soru = -1;
    

    FILE *hedef_dosya; 
    char satir[128];
    hedef_dosya = fopen("quiz.txt", "r"); 
    
    if(hedef_dosya == NULL){

        printf("Dosya bulunamadi.");
        return;

    }

    
    while((fgets(satir, sizeof(satir), hedef_dosya))){
        
        
        printf(satir);
        yanitiniz = 0;
        
        if(sayac % 6 == 5){
            
            scanf(" %c", &yanitiniz);
            
            do{
                while((yanitiniz != 'A') && (yanitiniz != 'a') && (yanitiniz != 'B') && (yanitiniz != 'b') && (yanitiniz != 'C') && (yanitiniz != 'c') && (yanitiniz != 'D') && (yanitiniz != 'd') && (yanitiniz != 'Q') && (yanitiniz != 'q')){
                    printf("Gecerli bir cevap giriniz (A,B,C,D):\n");
                    scanf(" %c", &yanitiniz);
                }
                
                if((yanitiniz == 'Q') || (yanitiniz == 'q')){
                    printf("Testten cikmak istediginize emin misiniz?(E/H):");
                    scanf(" %c", &yanitiniz);
                
                    while((yanitiniz != 'E') && (yanitiniz != 'e') && (yanitiniz != 'H') && (yanitiniz != 'h')){
                        printf("Gecerli bir cevap giriniz (E/H):");
                        scanf(" %c", &yanitiniz);
                    }
                
                    switch(yanitiniz){
                        case 'E': 
                        case 'e': printf("Testten ciktiniz."); break;
                        case 'H': 
                        case 'h': break;
                        
                    }  
                
                    if((yanitiniz == 'E') || (yanitiniz == 'e'))
                    break;
                
                    if((yanitiniz == 'H') || (yanitiniz == 'h')){
                        printf("Cevabiniz:");
                        scanf(" %c", &yanitiniz);
                        
                        while((yanitiniz != 'A') && (yanitiniz != 'a') && (yanitiniz != 'B') && (yanitiniz != 'b') && (yanitiniz != 'C') && (yanitiniz != 'c') && (yanitiniz != 'D') && (yanitiniz != 'd')){
                            printf("Gecerli bir cevap giriniz (A,B,C,D):");
                            scanf(" %c", &yanitiniz);
                        }

                    }
                
                }
            
            }
            
            while((yanitiniz != 'A') && (yanitiniz != 'a') && (yanitiniz != 'B') && (yanitiniz != 'b') && (yanitiniz != 'C') && (yanitiniz != 'c') && (yanitiniz != 'D') && (yanitiniz != 'd') && (yanitiniz != 'E') && (yanitiniz != 'e'));

            if((yanitiniz == 'E') || (yanitiniz == 'e'))
            break;

            soru++;
        
        }

            
            switch(yanitiniz){

                case'A': 
                case'a': puan += deger[soru][0]; break; 
                case'B':
                case'b': puan += deger[soru][1]; break;
                case'C': 
                case'c': puan += deger[soru][2]; break;
                case'D':
                case'd': puan += deger[soru][3]; break;
                
                
            }

            sayac++;
        
    }

    fclose(hedef_dosya);

    FILE *sonuc_dosya;

    sonuc_dosya = fopen("sonuc.txt","w");
    
    
    
    if(sayac == 60){

        if((440 <= puan) && (puan <= 485)){
            printf("SONUC: Siz Homelander'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Homelander'siniz!\n");
        }

        if((485 < puan) && (puan <= 550)){
            printf("SONUC: Siz Deadpool'sunuz!");
            fprintf(sonuc_dosya, "SONUC: Siz Deadpool'sunuz!\n");
        }

        if((550 < puan) && (puan <= 610)){
            printf("SONUC: Siz Eric Draven'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Eric Draven'siniz!\n");
        }


        if((610 < puan) && (puan <= 650)){
            printf("SONUC: Siz Wolverine'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Wolverine'siniz!\n");
        }

        if((650 < puan) && (puan <= 725)){
            printf("SONUC: Siz Iron-Man'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Iron-Man'siniz!\n");
        }

        if((725 < puan) && (puan <= 775)){
            printf("SONUC: Siz Spider-Man'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Spider-Man'siniz!\n");
        }

        if((775 < puan) && (puan <= 820)){
            printf("SONUC: Siz Captain America'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Captain America'siniz!\n");
        }

        if((820 < puan) && (puan <= 875)){
            printf("SONUC: Siz Superman'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Superman'siniz!\n");
        }

        if(875 < puan){
            printf("SONUC: Siz Batman'siniz!");
            fprintf(sonuc_dosya, "SONUC: Siz Batman'siniz!\n");
        }
    }

    fclose(sonuc_dosya);

}


int main(){

    char basla;
    char yanit;
    
    printf("Hangi super kahramansiniz testimize hos geldiniz.\n");
    printf("Testimize baslamak icin R'yi, istediginiz zaman cikmak icin Q'yu giriniz:");
    
    scanf(" %c", &basla);

    while((basla != 'R') && (basla != 'r') && (basla != 'Q') && (basla != 'q')){

        printf("Lutfen R ya da Q'yu giriniz:");
        scanf(" %c", &basla);
        
    }

    if((basla == 'Q') || (basla == 'q')){

        printf("Testten ciktiniz.");
        
        return 0;

    }

    if((basla == 'R') || (basla == 'r'))
    kullanicicevabi();

    return 0;

}    
