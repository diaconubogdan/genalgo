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

Functii:
randoms() - random subunitar
