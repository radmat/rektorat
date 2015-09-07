/*Radoslaw Matusik
  Program bada czasy wyswietlania roznej liczby elementow*/

#include<iostream.h>
#include<conio.h>
#include<time.h>

main()
{
	time_t start,stop;
	int i;
	start=clock();
	for(i=0;i<10000;i++)
		cout<<"x";
	stop=clock();
	cout<<"\nCzas wypisywania 10000 elementow: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" sekund";	
	start=clock();
	for(i=0;i<100000;i++)
		cout<<"x";
	stop=clock();
	cout<<"\nCzas wypisywania 100000 elementow: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" sekund";
	getch();
	start=clock();
	for(i=0;i<1000000;i++)
		cout<<"x";
	stop=clock();
	cout<<"\nCzas wypisywania 1000000 elementow: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" sekund";
	getch();
	start=clock();
	for(i=0;i<10000000;i++)
		cout<<"x";
	stop=clock();
	cout<<"\nCzas wypisywania 10000000 elementow: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" sekund";
	getch(); 	
	start=clock();
	for(i=0;i<100000000;i++)
		cout<<"x";
	stop=clock();
	cout<<"\nCzas wypisywania 100000000 elementow: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" sekund";
	getch();	
	return 0;
}
