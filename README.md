Exemplul actual este pentru x^2 - 1<br><br>

Constante:<br><br>

[a, b] - intervalul utilizat pentru calcularea fenotipului<br>
G - lungimea genotipului<br>
N - numarul de cromozomi<br>
E - numarul de epoci<br>
Pm - numar foarte mic utilizat la mutatie<br>
timp - numarul de secunde pentru a rula algoritmul<br>
<br><br>
Structuri:<br>
crimizom:<br>
	genotip - sir binar de lungime G<br>
	fenotip - numar calculat dupa formula a + (b - a) * geno2dec()/(pow(2, G) - 1) - reprezinta minimul pe care il cautam<br>
	fitness - numar calculat dupa formula 1 / y(fenotip) - reprezinta un "scor" pentru a putea evalua performanta cromozomilor <br>
<br><br>
Functii:<br>
randoms() - random subunitar<br>
incrucisare_intrun_punct() - interschimba genotipul intre generatii de la un punct aleator. Spre exemplu, intre 2 genotipuri 0000 si 1111, din incrucisarea in punctul 1 rezulta 0011 si 1100<br>
mutatie() - este o sansa ca o gena din genotip sa isi schimbe valoarea<br>
selectie() - transforma o parte din populatia curenta in parinti pentru urmatoarea populatie
