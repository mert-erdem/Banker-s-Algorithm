#include<stdio.h>
#include<conio.h>
#include <stdbool.h> 

main()
{
	short p;//process say�s�
	short m;//kaynak say�s�
		
	bool control=true;
		
	short st=0;
	
	short i=0;
	short x=0;
	short j=0;
		
	printf("Kaynak sayisini giriniz:\n");
	scanf("%d",&m);
	printf("Process sayisini giriniz:\n");
	scanf("%d",&p);
	
	//kullan�lacak matrisler
	short need[p][m];short sources[m];short alloc[p][m];short max[p][m];short avaible[m];short basarililar[p];
	short guvenliDurum[p];//g�venli durum s�ras�n� olu�turmak i�in 
	
	short basarili=0;//herhangi bir process kayna�� kullan�p i�ini bitirdi�inde 1 artacak
		
	for(i=0;i<m;i++)
	{
		printf("%d. kaynagin miktari=",i+1);
		scanf("%d",&sources[i]);
		printf("\n");
	}
	
	for(i=0;i<p;i++)
	{
		
		for(j=0;j<m;j++)
		{		
			printf("%d. process icin %d. alloc degeri= ",i+1,j+1);	
			scanf("%d",&alloc[i][j]);
			printf("\n");
		}
		
	}
	printf("\n");
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d. processin %d kaynagina olan maximum ihtiyaci= ",i+1,j+1);
			scanf("%d",&max[i][j]);
			printf("\n");
		}
	}
		
	for(i=0;i<p;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];//ihtiya� matrisi olu�turuluyor			
		}
	}
	
	for(i=0;i<m;i++)
	{
		short toplam=0;
		for(j=0;j<p;j++)
		{
			toplam+=alloc[j][i];
		}
		avaible[i]=sources[i]-toplam;
	}
	
	//safe state i olu�turmak i�in kurulan d�ng�
	while(basarili!=p && control==true)//t�m process ler i�lerini hallettikten sonra d�ng� sona ericek----e�er sorun ��karsa(k�s�r d�ng�) control boolean de�i�keni zorunlu olarak d�ng�y� sona erdirecek
	{		
		for(i=0;i<p;i++)
		{			
			control=true;
			
			for(j=0;j<m;j++)
			{
				if(basarililar[i]==1)//d�ng� tekrarland���nda zaten tamamlanm�� process leri tekrar kontrol etmesin
				{
					control=false;					
					break;
				}
				if(need[i][j]>avaible[j])
				{
					control=false;
					break;
				}
			}
			if(control==true)//elimizdeki kaynaklar o process e yetiyorsa
			{
				basarili++;
				for(x=0;x<m;x++)
				{
					avaible[x]+=alloc[i][x];
				}
				basarililar[i]=1;
				guvenliDurum[st]=i;
				st++;								
			}
		}		
	}
	
		
	if(basarili==p)
	{
		if(p==0)
		{
			printf("Kaynaklari kullanacak herhangi bir process yok!!!");
		}		
		printf("*******Guvenli durum saglandi******* \nG�venli durum sirasi:\n");
		for(i=0;i<p;i++)
		{
			printf("P%d,\t",guvenliDurum[i]+1);			
		}		
	}
	else
	{
		printf("Guvenli durum saglanamadi ERROR!!!");		
	}
	
}
