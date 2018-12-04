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
