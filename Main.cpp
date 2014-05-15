#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
/* ------------------------------------------------------------------------- *
*	Two dimensional dynamic array	                                         *
*   Written in C                                                             *
*          by Kl�vs Ceic�ns P2-4                                             *
*         	(Github - Kefirchiks | https://github.com/Kefirchiks )           *
* -------------------------------------------------------------------------- *
*	SHARING IS CARING                                                        *
* -------------------------------------------------------------------------- *
* 	J�b�t iesp�jai main�t elementu skaitu rind� un apskat�ties mas�vu        *
*		INDIVIDU�LAIS UZDEVUMS                                               *
*			Mas�va elementu tips == short int                                *
*			Atrast nep�ra elementu summu katr� rind� un vis� mas�v�			 *
* -------------------------------------------------------------------------- *
*	Individu�lais uzdevums (2.uzdevums)                                      *
*	DB "Bibliot�la". Lauki: adrese, nosaukums, id, eso�o gr�matu skaits.     *
*	Pamatvien�ba: nosaukums.                                                 *
*	Atrast bibliot�kas, kuru gr�matu skaits < vai > par                      *
*		lietot�ja ievad�to skaitu.                                           *
* -------------------------------------------------------------------------- */

short *garumi;
// Pointeris uz dynamicArray, kura elementi ir mas�va rindu garumi
short **dmas; // Nor�de uz matricu (pointer to pointer)
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
		scanf("%d", &i); // MENU izv�lne
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
	aizvert(); // Iziet un izpild�t visas vajadz�g�s darb�bas

}

void izveide() // 2D mas�va izveide
{
	if (dmas == NULL || garumi == NULL) {
		do {
			printf("\nIevadiet rindu skaitu(naturaalu skaitli): ");
			scanf("%d", &rinda);
		}
		while (rinda <= 0);
		garumi = (short *)calloc(rinda, sizeof(short));
		// Rezerv� vietu, katras rindas garums == 0
		dmas = (short**)malloc(rinda*sizeof(short *));
		// Rezerv� atmi�u pointeru mas�vam
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
		for (int n = 0; n < rinda; n++) // Izveidot mas�va rindas
		{
			do {
				printf("\nIevadiet %d. rindas garumu(nenegativu skaitli): ", n + 1);
				scanf("%hd", &garumi[n]);
			}
			while (garumi[n] < 0);
			dmas[n] = (short *)calloc(garumi[n], sizeof(short));
			// Izveido mas�va rindas
			if (at == 1)
				for (int m = 0; m < garumi[n];
				m++) // dynArray aizpild��anai
				{
					printf("\nmat [%d][%d] = ", n + 1, m + 1);
					scanf("%hd", &dmas[n][m]);
				}
			else
				for (int m = 0; m < garumi[n];
				m++) // dynArray aizpild��anai ar random skait�iem
						dmas[n][m] = random(100);

		}
	}
	else
		printf("Masivs nav tuksh! Lai izveidotu jaunu masiivu izdzeesiet iepriekshejo!\n"
			);
	printf("\n Nospiediet jebkuru taustinu: \n");
	getch();
}

void izvade() // Funkcija, kura izdruk� matricu
{
	if ((dmas == NULL) || (garumi == NULL))
		printf("Massivs ir tuksh! Aizpildiet masivu!");
	else {
		printf("\nMasiva saturs: ");
		for (n = 0; n < rinda; n++) // Izvad�t mas�vu (rinda)
		{
			printf("\n");
			for (int m = 0; m < garumi[n];
			m++) // Izvad�t mas�vu (kolonna - labi, ja ne piekt� kolonna)
					printf("\t%d", dmas[n][m]);
		}
	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void aizvert() // Atbr�vot atmi�u + iziet
{
	if ((dmas == NULL) || (garumi == NULL))
		printf("ERROR: Masivs jau ir tuksh!");
	else {
		for (int m = 0; m < rinda; m++)
			free(dmas[m]); // Atbr�vo rindas atmi�u
		free(dmas); // Atbr�vo mas�va atmi�u
		free(garumi);
		dmas = NULL;
		garumi = NULL;
		printf("\nMASIVA ATMINA ATBRIVOTA!");
	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void maina_gar() // Main�t rindas garumus
{
	int p; // Saglab� iepriek��jo garumu
	int nr; // Rindas NR, kuru main�sim

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
		if (p < garumi[nr - 1]) { // Ja vairak elementu, k� iepriek�
			do {
				printf("\nLai aizpilditu manuali, nospiediet 1\n");
				printf("Lai aizpilditu automatiski, nospiediet 2\n");
				scanf("%d", &at);
			}
			while ((at != 1) && (at != 2));
			if (at == 1)
				for (m = p; m < garumi[nr - 1];
				m++) // Aizpildam no klaviat�ras
				{
					printf("\dmas [%d][%d] = ", nr, m + 1);
					scanf("%hd", &dmas[nr - 1][m]);
					// Nolasam jauno elementu v�rt�bas
				}
			else
				for (m = p; m < garumi[nr - 1];
				m++) // Aizpild�t ar random skait�iem
						dmas[nr - 1][m] = random(100);

		}

	}
	printf("\n Nospiediet jebkuru taustinu: ");
	getch();
}

void summas() // Nep�ra elementu summas atra�anai
{
	int sum, sum2;
	// sum - nep�ra elementu summa katr� rind�
	// sum2 - nep�ra elementu summa vis� mas�v�
	sum2 = 0;

	if ((dmas == NULL) || (garumi == NULL))
			printf("Masivs ir tuksh! Aizpildiet masivu!");
	else {
		printf("\nMasiva saturs\n");
		for (int n = 0; n < rinda; n++) // rinda
		{
			printf("\n");
			for (m = 0; m < garumi[n]; m++) // kolonna (ceru, ka ne piekt�)
					printf("\t%d", dmas[n][m]);

		}
		for (n = 0; n < rinda; n++) // rinda
		{
			sum = 0;
			for (m = 0; m < garumi[n]; m++) // kolonna
			{
				if ((dmas[n][m]) % 2 != 0)
					sum = sum + dmas[n][m];
				// Nep�ra elementu summa katr� rind�
			}
			sum2 = sum2 + sum; // NES vis� mas�v�
			printf("\n%d. rindas masiva nepaaru elementu summa ir %d",
				n + 1, sum); // Rezult�ts

		}
		printf("\nVisa masiva nepara elementu summa ir %d ", sum2);
	}
	printf("\nNospiediet jebkuru taustinu: ");
	getch();
}
