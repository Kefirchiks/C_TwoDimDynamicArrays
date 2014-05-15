#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
/* ------------------------------------------------------------------------- *
*	Two dimensional dynamic array	                                         *
*   Written in C                                                             *
*          by Klâvs Ceicâns P2-4                                             *
*         	(Github - Kefirchiks | https://github.com/Kefirchiks )           *
* -------------------------------------------------------------------------- *
*	SHARING IS CARING                                                        *
* -------------------------------------------------------------------------- *
* 	Jâbût iespçjai mainît elementu skaitu rindâ un apskatîties masîvu        *
*		INDIVIDUÂLAIS UZDEVUMS                                               *
*			Masîva elementu tips == short int                                *
*			Atrast nepâra elementu summu katrâ rindâ un visâ masîvâ			 *
* -------------------------------------------------------------------------- *
*	Individuâlais uzdevums (2.uzdevums)                                      *
*	DB "Bibliotçla". Lauki: adrese, nosaukums, id, esoðo grâmatu skaits.     *
*	Pamatvienîba: nosaukums.                                                 *
*	Atrast bibliotçkas, kuru grâmatu skaits < vai > par                      *
*		lietotâja ievadîto skaitu.                                           *
* -------------------------------------------------------------------------- */

short *garumi;
// Pointeris uz dynamicArray, kura elementi ir masîva rindu garumi
short **dmas; // Norâde uz matricu (pointer to pointer)
int rinda, n, m, at;

void izveide();
void izvade();
void maina_gar();
void summas();
void aizvert();

void main() {
	int i; // MENU
	rinda = 0;
	do {
		clrscr();
		printf("\n 1 - Aizpildit masivu");
		printf("\n 2 - Izdzest masivu");
		printf("\n 3 - Mainit masiva rindas garumu");
		printf("\n 4 - Apskatit masiivu");
		printf("\n 5 - Atrast neparu elementu summu katra rinda un visa masiva"
			);
		printf("\n 6 - Iziet\n");
		printf("Jusu izveele: ");
		flushall();
		scanf("%d", &i); // MENU izvçlne
		switch (i) {
		case (1):
			izveide();
			break;
		case (2):
			aizvert();
			break; //
		case (3):
			maina_gar();
			break;
		case (4):
			izvade();
			break;
		case (5):
			summas();
		}
	}
	while (i != 6);
	aizvert(); // Iziet un izpildît visas vajadzîgâs darbîbas

}

void izveide() // 2D masîva izveide
{
	if (dmas == NULL || garumi == NULL) {
		do {
			printf("\nIevadiet rindu skaitu(naturaalu skaitli): ");
			scanf("%d", &rinda);
		}
		while (rinda <= 0);
		garumi = (short *)calloc(rinda, sizeof(short));
		// Rezervç vietu, katras rindas garums == 0
		dmas = (short**)malloc(rinda*sizeof(short *));
		// Rezervç atmiòu pointeru masîvam
		if ((garumi == NULL) || (dmas == NULL))
		{
			printf("\nERROR: Nepietiek atminas!");
			return;
		}
		do {
			printf("\nLai aizpilditu manuali, nospiediet 1\n");
			printf("Lai aizpilditu automatiski, nospiediet 2\n");
			scanf("%d", &at);
		}
		while ((at != 1) && (at != 2));
		for (int n = 0; n < rinda; n++) // Izveidot masîva rindas
		{
			do {
				printf("\nIevadiet %d. rindas garumu(nenegativu skaitli): ", n + 1);
				scanf("%hd", &garumi[n]);
			}
			while (garumi[n] < 0);
			dmas[n] = (short *)calloc(garumi[n], sizeof(short));
			// Izveido masîva rindas
			if (at == 1)
				for (int m = 0; m < garumi[n];
				m++) // dynArray aizpildîðanai
				{
					printf("\nmat [%d][%d] = ", n + 1, m + 1);
					scanf("%hd", &dmas[n][m]);
				}
			else
				for (int m = 0; m < garumi[n];
				m++) // dynArray aizpildîðanai ar random skaitïiem
						dmas[n][m] = random(100);

		}
	}
	else
		printf("Masivs nav tuksh! Lai izveidotu jaunu masiivu izdzeesiet iepriekshejo!\n"
			);
	printf("\n Nospiediet jebkuru taustinu: \n");
	getch();
}

void izvade() // Funkcija, kura izdrukâ matricu
{
	if ((dmas == NULL) || (garumi == NULL))
		printf("Massivs ir tuksh! Aizpildiet masivu!");
	else {
		printf("\nMasiva saturs: ");
		for (n = 0; n < rinda; n++) // Izvadît masîvu (rinda)
		{
			printf("\n");
			for (int m = 0; m < garumi[n];
			m++) // Izvadît masîvu (kolonna - labi, ja ne piektâ kolonna)
					printf("\t%d", dmas[n][m]);
		}
	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void aizvert() // Atbrîvot atmiòu + iziet
{
	if ((dmas == NULL) || (garumi == NULL))
		printf("ERROR: Masivs jau ir tuksh!");
	else {
		for (int m = 0; m < rinda; m++)
			free(dmas[m]); // Atbrîvo rindas atmiòu
		free(dmas); // Atbrîvo masîva atmiòu
		free(garumi);
		dmas = NULL;
		garumi = NULL;
		printf("\nMASIVA ATMINA ATBRIVOTA!");
	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void maina_gar() // Mainît rindas garumus
{
	int p; // Saglabâ iepriekðçjo garumu
	int nr; // Rindas NR, kuru mainîsim

	if ((dmas == NULL) || (garumi == NULL))
		printf("Masivs ir tuksh! Aizpildiet masivu!");
	else {
		do {
			printf("\nKurai rindai mainit garumu(%d)?", rinda);
			scanf("%d", &nr);
		}
		while ((nr < 1) || (nr > rinda));
		p = garumi[nr - 1];
		do {
			printf("\nIevadiet %d. rindas garumu(nenegativu skaitli): ", nr);
			scanf("%hd", &garumi[nr - 1]); // Nolasa jauno rindas garumu
		}
		while (garumi[nr - 1] < 0);
		dmas[nr - 1] = (short *)realloc(dmas[nr - 1],
			garumi[nr - 1]*sizeof(short));
		if (p < garumi[nr - 1]) { // Ja vairak elementu, kâ iepriekð
			do {
				printf("\nLai aizpilditu manuali, nospiediet 1\n");
				printf("Lai aizpilditu automatiski, nospiediet 2\n");
				scanf("%d", &at);
			}
			while ((at != 1) && (at != 2));
			if (at == 1)
				for (m = p; m < garumi[nr - 1];
				m++) // Aizpildam no klaviatûras
				{
					printf("\dmas [%d][%d] = ", nr, m + 1);
					scanf("%hd", &dmas[nr - 1][m]);
					// Nolasam jauno elementu vçrtîbas
				}
			else
				for (m = p; m < garumi[nr - 1];
				m++) // Aizpildît ar random skaitïiem
						dmas[nr - 1][m] = random(100);

		}

	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void summas() // Nepâra elementu summas atraðanai
{
	int sum, sum2;
	// sum - nepâra elementu summa katrâ rindâ
	// sum2 - nepâra elementu summa visâ masîvâ
	sum2 = 0;

	if ((dmas == NULL) || (garumi == NULL))
			printf("Masivs ir tuksh! Aizpildiet masivu!");
	else {
		printf("\nMasiva saturs\n");
		for (int n = 0; n < rinda; n++) // rinda
		{
			printf("\n");
			for (m = 0; m < garumi[n]; m++) // kolonna (ceru, ka ne piektâ)
					printf("\t%d", dmas[n][m]);

		}
		for (n = 0; n < rinda; n++) // rinda
		{
			sum = 0;
			for (m = 0; m < garumi[n]; m++) // kolonna
			{
				if ((dmas[n][m]) % 2 != 0)
					sum = sum + dmas[n][m];
				// Nepâra elementu summa katrâ rindâ
			}
			sum2 = sum2 + sum; // NES visâ masîvâ
			printf("\n%d. rindas masiva nepaaru elementu summa ir %d",
				n + 1, sum); // Rezultâts

		}
		printf("\nVisa masiva nepara elementu summa ir %d ", sum2);
	}
	printf("\nNospiediet jebkuru taustinu: ");
	getch();
}
