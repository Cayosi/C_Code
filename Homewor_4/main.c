#include <stdio.h>
void triangle(int a,int b,int c){
    if (a + b > c && a + c > b && b + c > a     ) {
        if(a == b || b == c || a == c){
            if (a == b && b == c && a == c) {
                printf("Equilateral triangle!");
        } else{
                printf("Isosceles triangle!");
            }

        } else{
            printf("Ordinary triangle!");
        }
    } else{
        printf("Not a triangle!");
    }
}

int main()
{
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b-5;
	}
	printf("%d\n", a);
	return 0;
}