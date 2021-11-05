#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <thread> 

using namespace std;

float mean(float *Array, int tmp);
float median(float *Array, int tmp);
float result1, result2 = 0;
	int main()
{
	
	float Array[10000] = {0};
    int tmp = 0;
    
    ifstream liczby("data.txt");
    
    while (!liczby.eof())
       liczby >> Array[tmp++]; 
       
    liczby.close();
/*-----------------------------------------*/
thread firstT(mean, Array, tmp);
thread secondT(median, Array, tmp);

firstT.join();
secondT.join();

cout<<"Wartosc sredniej wynosi: "<<result1<<endl;
cout<<"Wartosc mediany wynosi: "<<result2<<endl;

if (result1>result2)
{
	cout<<"Wieszka jest wartosc sredniej ktora wynosi: "<<result1<<endl;
}
else if (result1<result2)
{
	cout<<"Wieszka jest wartosc mediany ktora wynosi: "<<result2<<endl;
}
else
{
	cout<<"Mediana i srednia sa sobie rowne"<<endl;
}
	
	return 0;
}
float mean(float *Array, int tmp)
{

	float sum=0;
	
            for(int i = 0; i < tmp; i++)   
			{
				sum = sum + Array[i];
			}
	result1 = sum/tmp;
	return result1;
}

// Funkcja wyznaczajaca mediana
float median(float *Array, int tmp)
{
	
	// Sortowanie wektora
	int empty = 0;
	int median = 0;
	for(int i=0; i<tmp; i++)
	{
		if(Array[i] > Array[i+1])
		{
			empty = Array[i];
			Array[i] = Array[i + 1];
			Array[i + 1] = empty;
		}
	}
 //Wyznaczenie mediany
 int center = 0;
 if (tmp % 2 == 0)
 {
 	center = tmp/2;
 	median = Array[center-1] + Array[center];
 	result2 = median/2;
 }
 else
 {
 	result2 = Array[(tmp % 2)];
 }
 return result2;
}
