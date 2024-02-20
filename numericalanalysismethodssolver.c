#include <stdio.h>
#include <math.h>
#define DEGER	15


void Polinomal(double polinomuskatsayi[2][DEGER],int	terimsay){                       // kullanicinin hesaplatacagi polinomun katsayi ve us degerlerini bir matrise girdirir. 
    int i;

    for (i = 0; i < terimsay; i++){
        printf("\n%d.terimdeki x'in derecesini girin: ",i+1);
        scanf("%lf",&polinomuskatsayi[0][i]);
        printf("\n%d.terimdeki x'in katsayisini girin: ",i+1);
        scanf("%lf",&polinomuskatsayi[1][i]);
    }
}
double fonkhesabi(double polinomuskatsayi[2][DEGER], double x, int terimsay){        //icine yazilan ve Polinomal fonksiyonunda girilen degerlerle ilgili fonksiyon degerini hesaplar
    int i;
    double sonuc = 0;
    for(i = 0; i < terimsay; i++){
        sonuc += polinomuskatsayi[1][i]*pow(x,polinomuskatsayi[0][i]);
    }
    return sonuc;
}
void Matrisal(double matris[DEGER][DEGER], int boyut){
	int i;
	int j;
	for(i = 0 ; i < boyut ; i++){
		for(j = 0 ; j < boyut ; j++){
			printf("matris[%d][%d]:",i,j);
			scanf("%lf",&matris[i][j]);
		}
		printf("\n");
	}
}
void Sonucmatrisi(double sonucmatris[DEGER], int boyut){
	int	i,j;
	
	for(i = 0; i < boyut; i++){
		printf("Sonuc matris[%d][1] icin deger: ",i+1);
		scanf("%lf",&sonucmatris[i]);
		printf("\n");
	}
}
void tureval(double polinomuskatsayi[2][DEGER], double turevlipoli[2][DEGER], int terimsay){
	int	i;
	int j;
	
	for(i=0;i<2;i++){
		for(j=0;j<terimsay;j++){
	        turevlipoli[i][j]=polinomuskatsayi[i][j];
        }
    }
	
	for(i = 0; i < terimsay; i++){
		if(turevlipoli[0][i] == 0){
			turevlipoli[1][i] = 0;
		}else{
			turevlipoli[1][i] = turevlipoli[1][i]* turevlipoli[0][i];
			turevlipoli[0][i]=turevlipoli[0][i]-1;
		}
	}
}

void invertMatrix(double matris[DEGER][DEGER], int boyut){
	int 	i,j,k;
	double 	kosegen;
	double bos;
	double 	yardimcimatris[DEGER][DEGER] = {0};
	for(i=0;i<DEGER;i++){
		yardimcimatris[i][i]=1;
	}

	for(i = 0; i < boyut; i++){                       
		kosegen = matris[i][i];                                            
		for(j = 0; j < boyut; j++){
			matris[i][j]=matris[i][j]/kosegen; 
			yardimcimatris[i][j]= yardimcimatris[i][j]/kosegen;
		}	
		for(j = 0; j < boyut; j++){
			if(i != j){
				bos = matris[j][i]; 
				for(k = 0; k < boyut; k++){
					matris[j][k] = matris[j][k] - matris[i][k]*bos;
					yardimcimatris[j][k] = yardimcimatris[j][k] - yardimcimatris[i][k]*bos;
				}
			}
		}
	}
	for(i = 0; i < boyut; i++){
		for(j = 0; j < boyut; j++){
			printf("%lf ",yardimcimatris[i][j]);
		}
		printf("\n");
	}
}
int secim;
void menu(){
	printf("\n0-Cikis\n\n1-Bisection Yontemi\n\n2-Regula Falsi Yontemi\n\n3-Newton - Raphson Yontemi\n\n4-NxN Bir Matrisin Tersi\n\n5-Gauss Eleminasyonu\n\n6-Gauss-Seidal Yontemleri\n\n7-Sayisal Turev(Geri-Ileri-Merkezi)\n\n8-Simpson Yontemi\n\n9-Trapez Yontemi\n\n");
}


int main(){
	int		secim;
    double	polinomuskatsayi[2][DEGER] = {0};
    double	turevlipoli[2][DEGER];
    double 	matris[DEGER][DEGER];
    double	sonucmatris[DEGER];
    double	degisken[DEGER] = {0}; 
    double  GregNewton[2][DEGER] = {0};
    int     terimsay; 
    double	a;
    double 	b; 
    double  c = 0;
    double  basla; 
    double	xdeg; 
    double	hdeg;
    double h;
    int	iterasyonsay;
    int n;
    double bos;
    int sayac=0;
    double	hatadeg;
    double	kosegen;
    double	sonuc = 0; 
    double	entResult = 0;
    int		i,j,k;
    int		kontrol = 1;
    int		boyut; 
    double temptemp;
    
	menu();
	printf("\n\n");
	printf("Istediginiz hesaplama turunu seciniz.\n\n");
	scanf("%d",&secim);
	printf("\n\n");
	
	if(secim == 1){
		printf("En fazla kac iterasyon olsun? ");
        scanf("%d", &iterasyonsay);
        printf("\nHata degerini girin ");
        scanf("%lf",&hatadeg);    
        printf("\nPolinomunuz kac terimli olacak? ");
        scanf("%d",&terimsay);
        Polinomal(polinomuskatsayi, terimsay);
		printf("\n[a,b] araligi icin fonksiyonda negatif degerli a sayisi girin : ");
        scanf("%lf",&a);
        printf("\n[a,b] araligi icin fonksiyonda pozitif degerli b sayisi girin : ");
        scanf("%lf",&b);
        
		for(i = 0; i < iterasyonsay ; i++){
            c = (b + a)/2; 
            if((b - a)/ pow(2,i) < hatadeg){
               	i = iterasyonsay;
               	kontrol = 0;
           	}
           	
           	if(kontrol == 1){ 
           		if(fonkhesabi(polinomuskatsayi,c,terimsay)*fonkhesabi(polinomuskatsayi,a,terimsay) < 0){
               		printf("\n%d.Iterasyon: \n",i+1);
               		printf("Baslangic: %lf\nOrtanokta: %lf\nBitis: %lf\n",a,c,b);
               		printf("f(a): %lf\n",fonkhesabi(polinomuskatsayi,a,terimsay));
               		printf("f(ortanokta): %lf\n",fonkhesabi(polinomuskatsayi,c,terimsay));
               		printf("f(b): %lf\n",fonkhesabi(polinomuskatsayi,b,terimsay));
              		b = c;
            	}else{
            		printf("\n%d.Iterasyon: \n",i+1);
               		printf("Baslangic: %lf\nOrtasi: %lf\nBitis: %lf\n",a,c,b);
               		printf("f(a): %lf\n",fonkhesabi(polinomuskatsayi,a,terimsay));
               		printf("f(ortanokta): %lf\n",fonkhesabi(polinomuskatsayi,c,terimsay));
               		printf("f(b): %lf\n",fonkhesabi(polinomuskatsayi,b,terimsay));
           			a = c;
				}
			}
        }
        printf("\nSonuc: %lf\n\n",c);
        main();
	}
	
	else if(secim==2){
		 printf("En fazla kac iterasyon olsun? ");
        scanf("%d",&iterasyonsay);
        printf("Hata degerini girin ");
        scanf("%lf",&hatadeg);    
        printf("Polinomunuz kac terimli olacak? ");
        scanf("%d",&terimsay);
        Polinomal(polinomuskatsayi, terimsay);
		printf("[a,b] araligi icin fonksiyonda negatif degerli a sayisi girin : ");
        scanf("%lf",&a);
        printf("[a,b] araligi icin fonksiyonda pozitif degerli b sayisi girin : ");
        scanf("%lf",&b);
        
		for(i = 0; i < iterasyonsay ; i++){
             c = (fonkhesabi(polinomuskatsayi,b,terimsay)*a-fonkhesabi(polinomuskatsayi,a,terimsay)*b)/(fonkhesabi(polinomuskatsayi,b,terimsay)-fonkhesabi(polinomuskatsayi,a,terimsay));
            
			if((b - a)/ pow(2,i) < hatadeg){
               	i = iterasyonsay;
               	kontrol = 0;
           	}
           	
           	if(kontrol == 1){  
           		
				   if(fonkhesabi(polinomuskatsayi,c,terimsay)*fonkhesabi(polinomuskatsayi,a,terimsay) < 0){
               		printf("\n%d.Iterasyon: \n",i+1);
               		printf("Baslangic: %lf\nOrtanokta: %lf\nBitis: %lf\n",a,c,b);
               		printf("f(a): %lf\n",fonkhesabi(polinomuskatsayi,a,terimsay));
               		printf("f(ortanokta): %lf\n",fonkhesabi(polinomuskatsayi,c,terimsay));
               		printf("f(b): %lf\n",fonkhesabi(polinomuskatsayi,b,terimsay));
              		b = c;
                 	}
				    else{
            		printf("\n%d.Iterasyon: \n",i+1);
               		printf("Baslangic: %lf\nOrtasi: %lf\nBitis: %lf\n",a,c,b);
               		printf("f(a): %lf\n",fonkhesabi(polinomuskatsayi,a,terimsay));
               		printf("f(ortanokta): %lf\n",fonkhesabi(polinomuskatsayi,c,terimsay));
               		printf("f(b): %lf\n",fonkhesabi(polinomuskatsayi,b,terimsay));
           			a = c;
				}
			}
        }
        printf("\nSonuc: %lf\n\n",c);
        main();
	}
	
	else if(secim==3){
		printf("En fazla kac iterasyon olsun? ");
        scanf("%d",&iterasyonsay);
        printf("Hata degerini girin ");
        scanf("%lf",&hatadeg);    
        printf("Polinomunuz kac terimli olacak? ");
        scanf("%d",&terimsay);
        Polinomal(polinomuskatsayi, terimsay);
        printf("Bir baslangic noktasi girin: ");
        scanf("%lf",&basla);
        tureval(polinomuskatsayi, turevlipoli, terimsay);
        
		for(i = 0; i < iterasyonsay ; i++){
        	if(fonkhesabi(turevlipoli,basla,terimsay-1) == 0){
        		printf("f'(x)=0 oldugu icin bu hesaplama yapilmaz.");
        		i = iterasyonsay;
        		kontrol = 0;
			}
        	c = basla - fonkhesabi(polinomuskatsayi,basla,terimsay)/fonkhesabi(turevlipoli,basla,terimsay-1);
            
			if(fabs(c - basla) >= hatadeg){
            	printf("\n%d.Iterasyon: \n",i+1);
            	printf("xn: %lf",c);
            	printf("\nf(xn): %lf\n ",fonkhesabi(polinomuskatsayi,c,terimsay));
            	temptemp = basla;
            	basla = c;
            	c = temptemp;
            }
            
			else{
            	i=iterasyonsay;
			}
	}
	printf("Sonuc: %lf\n\n",basla);
	main();
}
	
	else if(secim==4){
		printf("Kare matris icin boyut girin: \n");
		scanf("%d",&boyut);
		Matrisal(matris,boyut);
		invertMatrix(matris,boyut);
		printf("\n\n");
		main();
	}
	
	else if(secim==5){
		printf("Matris boyutunu giriniz:\n");
        scanf("%d",&boyut);
        Matrisal(matris,boyut);
        Sonucmatrisi(sonucmatris,boyut);
        
		for(i=0;i<boyut;i++){
	        
			for(j=i+1;j<boyut;j++){
		        
				if(matris[j][i]!=0){
			        bos=matris[j][i];
			        
					for(k=i;k<boyut;k++){
				        matris[j][k]=matris[j][k]-bos;
			        }
			        sonucmatris[j]=sonucmatris[j]-bos;
		        }
        }
        }
        
		for(i=0;i<boyut;i++){
        bos=matris[i][i];
        
		for(j=i;j<boyut;j++){
	        matris[i][j]=matris[i][j]/bos;
        }
        sonucmatris[i]=sonucmatris[i]/bos;
        }
        
		for(i=0;i<boyut;i++){
	        printf("x%d:%lf\n",i+1,sonucmatris[i]);
        }
        printf("\n\n");
        main();
	}
	
	else if(secim==6){
    kontrol=0;
    printf("En fazla kac iterasyon olsun? ");
        scanf("%d",&iterasyonsay);
        printf("Hata degerini girin ");
        scanf("%lf",&hatadeg);    
        printf("Kare matris icin boyut belirtin.");
        scanf("%d",&boyut);
        printf("Satirin en buyuk sayisi kosegende olacak sekilde bir matris girin.\n");
		Matrisal(matris,boyut);
		
		for(i = 0 ; i < boyut ; i++){
			
			for(j = 0 ; j < boyut; j ++){
				
				if(matris[i][i]<matris[i][j]){
					kontrol=1;
					i=boyut;
					j=boyut;
				}
			}
		}
		
		if (kontrol==0){
			Sonucmatrisi(sonucmatris,boyut);
			printf("degiskenler icin baslangic degerleri:\n");
			
			for(i=0;i<boyut;i++){
				printf("%d.degisken icin baslangic:",i+1);
				scanf("%lf", &degisken[i]);
			}
			
			while(sayac<iterasyonsay+1){
				for(i=0;i<boyut;i++){
					bos=degisken[i];
					degisken[i]=sonucmatris[i];
					
					for(k=0;k<boyut;k++){
						
						if(i!=k){
					degisken[i]=degisken[i]-matris[i][k]*degisken[k];
			    }
			}
			degisken[i]=degisken[i]/matris[i][i];
		}
		    
			printf("\n%d.iterasyon:\n",sayac);
			
			for(j=0;j<boyut;j++){
			   printf("%d.x= %lf  ",j+1,degisken[j]);
			   	
				if(fabs(bos-degisken[j])<hatadeg){
				j=boyut;
				sayac=iterasyonsay;
			}
		       }
			sayac=sayac+1;
		
			}
		}
		
		else{
			printf("Satirin en buyuk elemanlari kosegende olmaliydi.");
		}
		printf("\n\n");
		main();
	}
	
	else if(secim==7){
		printf("Hangi hesaplamayi kullanmak istersiniz?\n");
        printf("1)Geri fark formulu ile\n2)Orta nokta ile\n3)Ileri fark formulu ile\n");
        secim=0;
        scanf("%d",&secim);
        printf("Polinomunuz kac terimli olacak?\n");
        scanf("%d",&terimsay);
        Polinomal(polinomuskatsayi, terimsay);
        printf("Formul hangi x sayisi icin uygulansin?\n");
        scanf("%lf",&xdeg);
        printf("Fark(h) degeri ne olsun?\n");
        scanf("%lf",&hdeg);
        
		if (secim==1){
        	sonuc=(fonkhesabi(polinomuskatsayi,xdeg,terimsay)-fonkhesabi(polinomuskatsayi,xdeg-hdeg,terimsay))/hdeg;
        	printf("Sonuc:%lf",sonuc);
		}
		
		if (secim==2){
        	sonuc=(fonkhesabi(polinomuskatsayi,xdeg+hdeg,terimsay)-fonkhesabi(polinomuskatsayi,xdeg-hdeg,terimsay))/2*hdeg;
        	printf("Sonuc:%lf",sonuc);
		}
        
		if (secim==3){
        	sonuc=(fonkhesabi(polinomuskatsayi,xdeg+hdeg,terimsay)-fonkhesabi(polinomuskatsayi,xdeg,terimsay))/hdeg;
        	printf("Sonuc:%lf",sonuc);
        }
        printf("\n\n");
        main();
	}
	
	else if(secim==8){
	printf("Hangi simpson kuralini secmek istersiniz?\n1) 1/3 Simpson\n2) 3/8 Simpson \n");
	secim=0;
	scanf("%d",&secim);
	printf("Integralin alt degerini giriniz: \n");
    scanf("%lf",&a);
    printf("Integralin ust degerini giriniz: \n");
    scanf("%lf",&b);
    printf("Polinomunuz kac terimli olacak? ");
    scanf("%d",&terimsay);
    Polinomal(polinomuskatsayi, terimsay);
	printf("n degerini giriniz.\n");
	scanf("%d",&n);
	hdeg=(b-a)/n;
	
	if(secim==1){
	
		for(i=0;i<n;i++){
			c=a+hdeg;
		    sonuc=sonuc+(c-a)*(fonkhesabi(polinomuskatsayi,a,terimsay)+fonkhesabi(polinomuskatsayi,(a+c)/2,terimsay)*4+fonkhesabi(polinomuskatsayi,c,terimsay))/6;
			a=a+hdeg;
		}
		printf("1/3 Simspon ile bulunan sonuc: %lf",sonuc);
	}		
	
	else if(secim==2){
	
		for(i=0;i<n;i++){
			c=a+hdeg;
		    sonuc=sonuc+(c-a)*(fonkhesabi(polinomuskatsayi,a,terimsay)+fonkhesabi(polinomuskatsayi,a+((c-a)/3),terimsay)*3+fonkhesabi(polinomuskatsayi,a+(2*((c-a)/3)),terimsay)*3+fonkhesabi(polinomuskatsayi,c,terimsay))/8;
			a=a+hdeg;
		}
		printf("3/8 Simspon ile bulunan sonuc: %lf",sonuc);
	}

	else{
		printf("Gecersiz bir sayi girdiniz");
	}
	printf("\n\n");
	main();
	}

	else if(secim==9){
		printf("Integralin alt degerini giriniz: \n");
        scanf("%lf",&a);
        printf("Integralin ust degerini giriniz: \n");
        scanf("%lf",&b);
        printf("Polinomunuz kac terimli olacak? ");
        scanf("%d",&terimsay);
        Polinomal(polinomuskatsayi, terimsay);
        printf("n sayisini giriniz(Kac tane yamuga bolunecek):\n");
        scanf("%d",&n);
        hdeg=(b-a)/n;
        
        for(a;a<b;a=a+hdeg){
        	c=hdeg+a;
        	sonuc=sonuc+(c-a)*(fonkhesabi(polinomuskatsayi,a,terimsay)+fonkhesabi(polinomuskatsayi,c,terimsay))/2;
		}
		printf("Sonuc: %lf\n\n",sonuc);
		main();
	}
	
	else if(secim==0){
		printf("Gorusuruz.");
	}
	
	else{
		printf("Gecersiz bir sayi girdiniz.\n\n");
		main();
	}
	
	return 0;
}
