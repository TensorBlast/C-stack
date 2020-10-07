#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


main()
{
	stack * stck = create_stack(sizeof(int));

	for (int i=0; i<=10; i++)
		push(stck, &i);

	int j=0;
	pop(stck, &j);

	printf("%d\n", j);
}
