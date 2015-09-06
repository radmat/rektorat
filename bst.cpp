/*Radoslaw Matusik
  Program bada czas wstawiania oraz wyszukiwania roznej 
  liczby elementow w losowo wygenerowanym drzewie BST*/

#include<iostream.h>                
#include<conio.h>                    	
#include<assert.h>
#include<time.h>
#include<stdlib.h>
  
class Lisc
{
	friend class BST;                  
	private:        
	Lisc* prawy;        
	Lisc* lewy; 
	public:       
	Lisc(const int nowaWartosc=0,Lisc* r=NULL,Lisc* l=NULL)
	{  
		wartosc=nowaWartosc;
		prawy=r;
		lewy=l;
	} 
	~Lisc()
	{ 
		cout<<"\nNiszcze lisc";
	}           
	int wartosc;                     
};                                                                         
   
class BST
{
	public:
	Lisc* korzen;
	BST()
	{
		korzen=NULL;
	}   
	~BST()
	{
		korzen=NULL;
		cout<<"\nNiszcze korzen";
	}
	void wstaw(Lisc* &korzen,const int korzenWartosc);
	void wypisz(Lisc* &korzen,unsigned int l);    
	void usunDrzewo(Lisc* &korzen);                        
	void usunLisc(Lisc* &korzen,const int korzenWartosc);
	Lisc* szukaj( Lisc* &korzen,const int korzenWartosc);	
	Lisc* usunMin(Lisc* &korzen);
};   
   
void BST::wstaw(Lisc* &korzen,const int korzenWartosc)
{
	time_t start,stop;
	if(korzen==NULL)
	{
		korzen=new Lisc(korzenWartosc);
		assert(korzen!=0);              
	}
	else
	{
		start=clock();
		if(korzenWartosc<korzen->wartosc)            
			wstaw(korzen->lewy,korzenWartosc);              
		if(korzenWartosc>korzen->wartosc)               
			wstaw(korzen->prawy,korzenWartosc);                   
		stop=clock();
	}
}

Lisc* BST::szukaj(Lisc* &korzen,const int korzenWartosc)
{
	time_t start,stop;
	if((korzen==NULL) || (korzen->wartosc==korzenWartosc))
	{
		start=clock();
		return korzen;
		stop=clock();
	}
	if(korzenWartosc<korzen->wartosc)
	{
		start=clock();		                  
		return szukaj(korzen->lewy,korzenWartosc);
		stop=clock();
	}   
	else
	{
		start=clock();
		return szukaj(korzen->prawy,korzenWartosc);
		stop=clock();
	} 
}
   
void BST::wypisz(Lisc* &korzen,unsigned int l)
{
	unsigned int i;       
	if(korzen==NULL)
		return;       
	wypisz(korzen->lewy,l+1);
	for(i=0;i<l;i++)
		cout<<" ";
	cout<<endl;
	cout<<korzen->wartosc;
	wypisz(korzen->prawy,l+1);        
}

void BST::usunDrzewo(Lisc* &korzen)
{
	if(korzen!=NULL)
	{
		usunDrzewo(korzen->lewy);
		usunDrzewo(korzen->prawy);
		delete korzen;
		korzen=NULL;        
	}    
}
   
void BST::usunLisc(Lisc* &korzen,const int korzenWartosc)
{       
	Lisc* korzenTemp;       
	if(korzen==NULL)
		cout<<"\nNie ma w drzewie";
	else
	{
		if(korzenWartosc<korzen->wartosc)
			usunLisc(korzen->lewy,korzenWartosc);
		else if(korzenWartosc>korzen->wartosc)
			usunLisc(korzen->prawy,korzenWartosc);
		else       
		{
			korzenTemp=korzen;                   
			if(korzen->lewy==NULL)    
				korzen=korzen->prawy;
			else if(korzen->prawy==NULL)
				korzen=korzen->lewy;
			else
			{                               
				korzenTemp=usunMin(korzen->prawy);
				korzen->wartosc=korzenTemp->wartosc;                        
				delete korzenTemp;
			}                 
		}                
	}        
}

Lisc* BST::usunMin(Lisc* &korzen)
{
	Lisc* nowyKorzen;
	return nowyKorzen;
}
 
int main()
{
	time_t start,stop;
	int i;
	BST drzewo;         
	Lisc* znajdz;       
	int wartosc1[10];
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
		wartosc1[i]=rand();
	start=clock();
	for(i=0;i<(sizeof(wartosc1)/sizeof(wartosc1[0]));i++)
		drzewo.wstaw(drzewo.korzen,wartosc1[i]);
	stop=clock();
	cout<<"\n\nCzas wstawiania 10 elementow do drzewa BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();
	drzewo.wypisz(drzewo.korzen,NULL);
	getch();
	start=clock();
	for(i=0;i<10;i++)
	{
		znajdz=drzewo.szukaj(drzewo.korzen,wartosc1[i]);  
        cout<<endl<<endl;     
		cout<<znajdz->wartosc;
		if(znajdz->wartosc==wartosc1[i])
			cout<<" jest w drzewie";
		else
			cout<<" nie ma w drzewie"; 
	}
	stop=clock();
	cout<<endl<<endl;
	cout<<"\n\nCzas szukania 10 elementow w drzewie BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();                        
	drzewo.usunDrzewo(drzewo.korzen);                   
	getch();
	int wartosc2[10000];
	srand((unsigned)time(0));
	for(i=0;i<10000;i++)
		wartosc2[i]=rand();
	start=clock();
	for(i=0;i<(sizeof(wartosc2)/sizeof(wartosc2[0]));i++)
		drzewo.wstaw(drzewo.korzen,wartosc2[i]);
	stop=clock();
	cout<<"\n\nCzas wstawiania 10000 elementow do drzewa BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();
	drzewo.wypisz(drzewo.korzen,NULL);
	getch();
	start=clock();
	for(i=0;i<10000;i++)
	{
		znajdz=drzewo.szukaj(drzewo.korzen,wartosc2[i]);       
		cout<<endl<<endl;
		cout<<znajdz->wartosc;
		if(znajdz->wartosc==wartosc2[i])
			cout<<" jest w drzewie";
		else
			cout<<" nie ma w drzewie"; 
	}
	stop=clock();
	cout<<endl<<endl;
	cout<<"\n\nCzas szukania 10000 elementow w drzewie BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();                        
	drzewo.usunDrzewo(drzewo.korzen);                   
	getch();	
	int wartosc3[100000];
	srand((unsigned)time(0));
	for(i=0;i<100000;i++)
		wartosc3[i]=rand();
	start=clock();
	for(i=0;i<(sizeof(wartosc3)/sizeof(wartosc3[0]));i++)
		drzewo.wstaw(drzewo.korzen,wartosc3[i]);
	stop=clock();
	cout<<"\n\nCzas wstawiania 100000 elementow do drzewa BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();
	drzewo.wypisz(drzewo.korzen,NULL);
	getch();
	start=clock();
	for(i=0;i<100000;i++)
	{
		znajdz=drzewo.szukaj(drzewo.korzen,wartosc3[i]);       
		cout<<endl<<endl;
		cout<<znajdz->wartosc;
		if(znajdz->wartosc==wartosc3[i])
			cout<<" jest w drzewie";
		else
			cout<<" nie ma w drzewie"; 
	}
	stop=clock();
	cout<<endl<<endl;
	cout<<"\n\nCzas szukania 100000 elementow w drzewie BST wynosi: "<<(stop-start)<<" taktow"<<endl;
	getch();                        
	drzewo.usunDrzewo(drzewo.korzen);                   
	getch();	
	return 0;
}
