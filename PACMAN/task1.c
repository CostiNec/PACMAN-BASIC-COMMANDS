#include <stdio.h>

int main()
{
	int N, m = 0, i;
	char C;
	scanf("%d %c", &N, &C);
	while(m < N-1)
	{
		for(i = 0; i < m; i++)
		printf("  ");
		for(i = m; i < N-1; i++)
		printf("%c ", C);
		printf("%c", C);
		printf("\n");
		m++;
	} 
	for(i = 0; i < m; i++)
		printf("  ");
	for(i = m; i < N; i++)
		printf("%c", C);
	printf("\n");
	return 0;
}
