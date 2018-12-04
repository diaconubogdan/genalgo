#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

const int a = -0.5;
const int b = 0.5;

const int G = 6;
const int N = 100;
const float Pm = 0.001;
const int timp = 1;


double y(int x) {
	return x*x-1;
}

double randoms() {
	return (double)rand()*rand()/(RAND_MAX * RAND_MAX);
}
struct cromozom {
	int genotip[G];
	double fenotip;
	double fitness;
	
	void print() {
		cout << endl << endl;
		cout <<"Genotip: ";
		for(int i=0; i<G; i++) {
			cout << genotip[i] << " ";
		}
		cout << endl;
		cout << "Fenotip: " << fenotip << endl;
		cout << "Fitness" << fitness << endl;		
	}
	
	double geno2dec() {
		double rez = 0;
		for(int i=0; i<G; i++) {
			if(genotip[i] == 1) rez += pow(2, i);
		}
		return rez;
	}
	
	void initializare() {
		for(int i=0; i<G; i++) {
			genotip[i] = rand() % 2;
		}
		fenotip = a + (b - a) * geno2dec()/(pow(2, G) - 1);
		fitness = 1 / y(fenotip);
	}
	
	void calcul() { 
		fenotip = a + (b - a) * geno2dec()/(pow(2, G) - 1);
		fitness = 1 / y(fenotip);
	}
};

struct Populatie {
	cromozom cromozomi[N];
	
	cromozom getIndex(int index) {
		return cromozomi[index];
	}
};

void incrucisare_intrun_punct(Populatie *parinti, Populatie *copii) {
	int pct;
	
	for(int i = 0; i < N; i = i + 2){
		pct = 1 + rand() % (G - 1);
		for(int j = 0; j < G; j++) {
			if(j < pct){
				copii->cromozomi[i].genotip[j] = parinti->cromozomi[i].genotip[j];
				copii->cromozomi[i+1].genotip[j] = parinti->cromozomi[i+1].genotip[j]; 
			}
			else {
				copii->cromozomi[i].genotip[j] = parinti->cromozomi[i+1].genotip[j];
				copii->cromozomi[i+1].genotip[j] = parinti->cromozomi[i].genotip[j];
			}
		}
	}
	
	for(int i = 0; i < N; i++) {
		copii->cromozomi[i].calcul();
	}
}

void mutatie(Populatie *pop) {
	double random;
	for(int i = 0; i < N; i++) {
		for(int j = 0;j < G;j++) {
			random=randoms();
			if(random < Pm) 
				pop->cromozomi[i].genotip[j] = 1 - pop->cromozomi[i].genotip[j];
		}
	}
}

void afiseazaSolutie(Populatie *pop) {
	cromozom solutie = pop->cromozomi[0];
	for(int i=0; i<N; i++) {
		if(pop->cromozomi[i].fitness > solutie.fitness) solutie = pop->cromozomi[i];
	}
	cout<<"Solutie: " << solutie.fenotip << y(solutie.fenotip) << endl;
	solutie.print();
}

int selectie(Populatie *pop) {
	double fitnessT = 0;
	
	for(int i=0; i<N; i++) {
		fitnessT += pop->cromozomi[i].fitness;
	}
	double random = rand() / (double) RAND_MAX;
	double scor = 0;
	int pick = 0;
	
	for(int i=0; i<N; i++) {
		scor += (pop->cromozomi[i].fitness)/fitnessT;
		if (random < scor) {
			pick = i; 
			break;
		}
	}
	return pick;
}

int main() {
	srand(time(0));
	
	time_t start, end;
	time(&start);
	
	int epoci = 0;
	
	Populatie popcurenta;
	Populatie popparinti;
	Populatie popurmatoare;
	
	for(int i=0; i<N; i++) {
		popcurenta.cromozomi[i].initializare();
	}
	
	while(end - start < timp) {
		epoci++;
		cout<<"Suntem la epoca "<<epoci<<endl;
		for(int i=0; i<N; i++) {
			popparinti.cromozomi[i] = popcurenta.cromozomi[selectie(&popcurenta)];
		}
		incrucisare_intrun_punct(&popparinti, &popurmatoare);
		mutatie(&popurmatoare);
		popcurenta = popurmatoare;
		time(&end);
	}
	
	cout <<"----------- AG--------------"<<endl<<endl;
	cout<<"Numar epoci: "<<epoci<<endl;
	afiseazaSolutie(&popurmatoare);
	
	system("PAUSE");
	return 0;
}
