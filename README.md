Exemplul actual este pentru x ^ 2 - 1  
  
Constante:  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[a, b] - intervalul utilizat pentru calcularea fenotipului  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;G - lungimea genotipului  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;N - numarul de cromozomi  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;E - numarul de epoci  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pm - numar foarte mic utilizat la mutatie  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;timp - numarul de secunde pentru a rula algoritmul  
    
Structuri:  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cromozom:  
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;genotip - sir binar de lungime G  
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fenotip - numar calculat dupa formula a + (b - a) * geno2dec()/(pow(2, G) - 1) - reprezinta minimul pe care il cautam  
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fitness - numar calculat dupa formula 1 / y(fenotip) - reprezinta un "scor" pentru a putea evalua performanta cromozomilor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;populatie:  
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cromozomi - populatie de N cromozomi  
  
Functii:  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;randoms() - random subunitar  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;incrucisare_intrun_punct() - interschimba genotipul intre generatii de la un punct aleator. Spre exemplu, intre 2 genotipuri 0000 si 1111, din incrucisarea in punctul 1 rezulta 0011 si 1100  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mutatie() - este o sansa ca o gena din genotip sa isi schimbe valoarea  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;selectie() - transforma o parte din populatia curenta in parinti pentru urmatoarea populatie  
