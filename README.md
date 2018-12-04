Constante:  
  
[a, b] - intervalul utilizat pentru calcularea fenotipului  
G - lungimea genotipului  
N - numarul de cromozomi  
E - numarul de epoci  
Pm - numar foarte mic utilizat la mutatie  
timp - numarul de secunde pentru a rula algoritmul  
    
Structuri:  
crimizom:  
	genotip - sir binar de lungime G  
	fenotip - numar calculat dupa formula a + (b - a) * geno2dec()/(pow(2, G) - 1) - reprezinta minimul pe care il cautam  
	fitness - numar calculat dupa formula 1 / y(fenotip) - reprezinta un "scor" pentru a putea evalua performanta cromozomilor  
populatie:  
	cromozomi - populatie de N cromozomi  
  
Functii:  
randoms() - random subunitar  
incrucisare_intrun_punct() - interschimba genotipul intre generatii de la un punct aleator. Spre exemplu, intre 2 genotipuri 0000 si 1111, din incrucisarea in punctul 1 rezulta 0011 si 1100  
mutatie() - este o sansa ca o gena din genotip sa isi schimbe valoarea  
selectie() - transforma o parte din populatia curenta in parinti pentru urmatoarea populatie  
