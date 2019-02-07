#include <stdio.h>
//functia care va desena tabla de joc, omuletul si obstacolele daca exita
void careu(int N, int M, int x, int y, char c, 
		int x1, int y1, int x2, int y2, int x3, int y3)
{
	int i, j;
	for(i = 0; i <= M+1; i++)
		printf("*");
	printf("\n");
	for(i = 1; i <= N; i++)
	{
		printf("*");
		for(j = 1; j <= M; j++)
		{
			if(i == x && j == y)
				printf("%c", c);
			else 
				if(i == x1 && j == y1)
					printf("x");
			else
				if(i == x2 && j == y2)
					printf("x");
			else
				if(i == x3 && j == y3)
					printf("x");
			else
				printf(" ");
		}
	printf("*\n");
	}
	for(i = 0;i <= M+1; i++)
		printf("*");
	printf("\n");
}

int main()
{
	/*initializem variabilele de inceput, k, k1 si t vor fi luate pentru a
		a putea verifica unele conditii*/
	int N, M, x, y, P, k = 0, k1 = 5, t = 0;
	//coordonatele obstacolelor
	int x1, x2, x3, y1, y2, y3;
	/* variabilele pentru caracterul introdus pentru mutare, orientarea
		omuletului, tipul obstacolelor si z este pentru a citi
		ultimul caracter 'enter' introdus */
	char c, c1, m1, m2, m3, z;
	//citirea variabilelor
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &P);
	/*in functie de valoarea lui P, programul va citi coordonatele si tipul
		obstacolelor. Acestea vor primi 0 si 'f' daca nu sunt citite*/
	if(P == 0)
	{
		x1 = 0;
		x2 = 0;
		x3 = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
		m1 = 'f';
		m2 = 'f';
		m3 = 'f';
	}
	if(P == 1)
	{
		scanf("%d %d %c", &x1, &y1, &m1);
		x2 = 0;
		x3 = 0;
		y2 = 0;
		y3 = 0;
		m2 = 'f';
		m3 = 'f';
	}
	if(P == 2)
	{
		scanf("%d %d %c %d %d %c", &x1, &y1, &m1, &x2, &y2, &m2);
		x3 = 0;
		y3 = 0;
		m3 = 'f';
	}
	if(P == 3)
		scanf("%d %d %c %d %d %c %d %d %c", &x1, &y1, &m1, &x2, 
						&y2, &m2, &x3, &y3, &m3);
	//citirea ultimului enter dupa introducerea valorilor
	scanf("%c", &z);
	//afisarea primei table de joc
	careu(N, M, x, y, 'v', x1, y1, x2, y2, x3, y3);
	//verificarea daca punctul se afla pe marginea tablei de joc
	if(x == N || y == M || x == 1 || y == 1)
	/*"primul while" in care k1 ramane nemodificat cat timp omuletul
		nu efectueaza o mutare "valida", adica acesta nu se muta
		intr-un spatiu ocupat de perete. Programul o sa acceseze 
		acest while doar daca omuletul se afla pe marginea tablei.*/
	while(k1 == 5)
	{
		//citirea caracterelor de miscare
		scanf("%c", &c);
		scanf("%c", &z);
		//oprirea in cazul citirii caracterului 'q'
		if(c == 'q')
		{
			break;
		}
		/*daca omuletul efectueaza a doua mutare, programul o sa intre 
			in acest if*/
		if(t == 1)
		{
			//resetarea t-ului
			t = 0;
			//verificarea daca caracterul introdus este 'd'
			if(c == 'd')
			{
				//verificarea daca mutarea este valida
				if((y + 1) < (M + 1))
				{
					/*mutarea obiectului si iesirea din
						while cat si pastrarea 
						pozitiei*/
					k1 = 1;
					y++;
					c1 = '>';
					/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
					if(m1 == 'm')
					{
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}		
				}
				else
				{
					/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			}
			//verificarea daca caracterul introdus este 'a'
			if(c == 'a')
			{
				//verificarea daca mutarea este valida
				if((y - 1) > 0)
				{
					/*mutarea obiectului si iesirea din
						while cat si pastrarea 
						pozitiei*/
					k1 = 1;
					y--;
					c1 = '<';
					/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
				else
				{
					/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			}
			//verificarea daca caracterul introdus este 's'
			if(c == 's')
			{
				//verificarea daca mutarea este valida
				if((x + 1) < (N + 1))
				{
					k1 = 1;
					x++;
					c1 = 'v';
					/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
				else
				{
					/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			}
			//verificarea daca caracterul introdus este 'w'
			if(c == 'w')
			{
				//verificarea daca mutarea este valida
				if((x - 1) > 0)
				{
					k1 = 1;
					x--;
					c1 = '^';
					/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
					
				}
				else
				{
					/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
					if(m1 == 'm')
					{	
						if((x - x1) < 0)
							x1--;
						if((x - x1) > 0)
							x1++;
						if((y - y1) < 0)
							y1--;
						if((y - y1) > 0)
							y1++;
					}
					if(m2 == 'm')
					{	
						if((x - x2) < 0)
							x2--;
						if((x - x2) > 0)
							x2++;
						if((y - y2) < 0)
							y2--;
						if((y - y2) > 0)
							y2++;
					}
					if(m3 == 'm')
					{	
						if((x - x3) < 0)
							x3--;
						if((x - x3) > 0)
							x3++;
						if((y - y3) < 0)
							y3--;
						if((y - y3) > 0)
							y3++;
					}
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			}
		}
		else
		{
			t++;
			if(c == 'd')
				//verificarea daca mutarea este valida
				if((y + 1) < (M + 1))
				{
					k1 = 1;
					y++;
					c1 = '>';
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			if(c == 'a')
				//verificarea daca mutarea este valida
				if((y - 1) > 0)
				{
					k1 = 1;
					y--;
					c1 = '<';
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			if(c == 's')
				//verificarea daca mutarea este valida
				if((x + 1) < (N + 1))
				{
					k1 = 1;
					x++;
					c1 = 'v';
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
			if(c == 'w')
				//verificarea daca mutarea este valida
				if((x - 1) > 0)
				{
					k1 = 1;
					x--;
					c1 = '^';
					/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
					if((x == x1 && y == y1) || 
						(x == x2 && y == y2) || 
							(x == x3 && y == y3))
					{
							k = 1;
							k1 = 0;
							printf("GAME OVER\n");
					}
				}
		}
		/*daca omuletul nu a efectual nicio mutare valida, o sa se
			afiseze careul cu pozitia nemodificata, iar while-ul
			va continua sa ruleze*/
		if(k1 == 5)
			careu(N, M, x, y, 'v', x1, y1, x2, y2, x3, y3);
	}
	/*in cazul in care omuletul a efectuat o mutare valida, acest if va 
		afisa mutarea */ 
	if(k1 == 1)
		careu(N, M, x, y, c1, x1, y1, x2, y2, x3, y3);
	/*in cazul in care omuletul a interactionat cu un obstacol, acest
		if ne va garanta ca programul nu o sa ruleze si 
		al doilea while*/
	if(k1 != 0)
		/*"al doilea while" in care obiectul se misca pana cand acesta
			va ajunge in coltul din dreapta jos*/
		while(x < N || y < M) 
		{
			//citirea mutarilor
			scanf("%c", &c);
			//citirea caracterului 'enter'
			scanf("%c", &z);
			//oprirea in cazul introducerii caracterului 'q'
			if(c == 'q')
			{
				k = 2;
				break;
			}
			/*daca omuletul efectueaza a doua mutare, programul o sa intre 
			in acest if*/
			if(t == 1)
			{
				//resetarea t-ului
				t = 0;
				//verificarea caracterului introdus
				if(c == 'd')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if(y < M)
					{
						//mutarea obiectului
						y++;
						//retinerea orientarii
						c1 = '>';
						/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
						if(m1 == 'm')
						{	
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) || 
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '>', 
							x1, y1, x2, y2, x3, y3);
					}
					else 
					{
						/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/						
						if(m1 == 'm')
						{
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) || 
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, c1, 
							x1, y1, x2, y2, x3, y3);
					}
				}
				if(c == 's')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if(x < N)
					{
						x++;
						c1 = 'v';
						/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
						if(m1 == 'm')
						{	
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) || 
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, 'v',
							 x1, y1, x2, y2, x3, y3);
					}
					else 
					{
						/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
						if(m1 == 'm')
						{	
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) || 
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, c1,
							 x1, y1, x2, y2, x3, y3);
					}
				}
				if(c == 'w')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if((x-1) > 0)
					{
						x--;
						c1 = '^';
						/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
						if(m1 == 'm')
						{	
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) || 
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '^',
							x1, y1, x2, y2, x3, y3);
					}
					else 
					{
						/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
						if(m1 == 'm')
						{	
							if((x-x1) < 0)
								x1--;
							if((x-x1) > 0)
								x1++;
							if((y-y1) < 0)
								y1--;
							if((y-y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x-x2) < 0)
								x2--;
							if((x-x2) > 0)
								x2++;
							if((y-y2) < 0)
								y2--;
							if((y-y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x-x3) < 0)
								x3--;
							if((x-x3) > 0)
								x3++;
							if((y-y3) < 0)
								y3--;
							if((y-y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, c1, 
							x1, y1, x2, y2, x3, y3);
					}
				}
				if(c == 'a')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if((y - 1) > 0)
					{
						y--;
						c1 = '<';
						/*verificarea daca obiectele sunt
						mobile si mutarea acestora*/
						if(m1 == 'm')
						{	
							if((x - x1) < 0)
								x1--;
							if((x - x1) > 0)
								x1++;
							if((y - y1) < 0)
								y1--;
							if((y - y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x - x2) < 0)
								x2--;
							if((x - x2) > 0)
								x2++;
							if((y - y2) < 0)
								y2--;
							if((y - y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x - x3) < 0)
								x3--;
							if((x - x3) > 0)
								x3++;
							if((y - y3) < 0)
								y3--;
							if((y - y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '<',
							 x1, y1, x2, y2, x3, y3);
					}
					else 
					{
						/*chiar daca mutarea nu este valida,
						obstacolul tot trebuie 
						sa se deplaseze*/
						if(m1 == 'm')
						{	
							if((x - x1) < 0)
								x1--;
							if((x - x1) > 0)
								x1++;
							if((y - y1) < 0)
								y1--;
							if((y - y1) > 0)
								y1++;
						}
						if(m2 == 'm')
						{	
							if((x - x2) < 0)
								x2--;
							if((x - x2) > 0)
								x2++;
							if((y - y2) < 0)
								y2--;
							if((y - y2) > 0)
								y2++;
						}
						if(m3 == 'm')
						{	
							if((x - x3) < 0)
								x3--;
							if((x - x3) > 0)
								x3++;
							if((y - y3) < 0)
								y3--;
							if((y - y3) > 0)
								y3++;
						}
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, c1, 
							x1, y1, x2, y2, x3, y3);
					}
				}
			}
			else
			{
				t++;
				if(c == 'd')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if(y < M)
					{
						y++;
						c1 = '>';
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '>',
							 x1, y1, x2, y2, x3, y3);
					}
					else 
						careu(N, M, x, y, c1,
							 x1, y1, x2, y2, x3, y3);
				}
				if(c == 's')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if(x < N)
					{
						x++;
						c1 = 'v';
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, 'v',
							 x1, y1, x2, y2, x3, y3);
					}
					else 
						careu(N, M, x, y, c1, 
						x1, y1, x2, y2, x3, y3);
				}
				if(c == 'w')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if((x - 1) > 0)
					{
						x--;
						c1 = '^';
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '^',
							x1, y1, x2, y2, x3, y3);
					}
					else 
						careu(N, M, x, y, c1,
						 x1, y1, x2, y2, x3, y3);
				}
				if(c == 'a')
				{
					/* verificarea ca mutarea
						nu depaseste tabla*/
					if((y - 1) > 0)
					{
						y--;			
						c1 = '<';
						/* conditia de oprire in caz de 
						coliziune cu un obstacol*/
						if((x == x1 && y == y1) || 
							(x == x2 && y == y2) ||
							(x == x3 && y == y3))
						{
							k = 1;
							x = N;
							y = M;
							printf("GAME OVER\n");
						}
						else 
							careu(N, M, x, y, '<',
							 x1, y1, x2, y2, x3, y3);
					}
					else 
						careu(N, M, x, y, c1,
							 x1, y1, x2, y2, x3, y3);
				}
			}
		}
	/* acest if va afisa "game completed" in cazul in care omuletul ajunge 
		in coltul din dreapta jos*/
	if(k == 0)
		printf("GAME COMPLETED\n");
	return 0;
}
