#include "headers.h"

static t_array *array;

static void teardown(void) {
	if (array)
	{
		free(array->array);
		free(array);
		array = NULL;
	}
}

Test(array_simple_usage, Test_simple_array) {
	int a[4] = {0, 1, 2, 3};
	int count;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 4)
		array_push(array, a + count);
	cr_expect(array->used == 4, "Array->used incorect");
	count = -1;
	while (++count < 4)
		cr_expect(((int*)array->array)[count] == a[count], "Array %d != %d with array_push(array, %d)",((int*)array->array)[count], a[count], a[count]);
	teardown();
}

Test(array_simple_usage, Test_array_auto_growth) {
	int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int count;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 8)
		array_push(array, a + count);
	count = -1;
	cr_expect(array->used == 8, "Array->used incorect");
	while (++count < 8)
		cr_expect(((int*)array->array)[count] == a[count], "%d Array %d != %d with array_push(array, %d)", count, ((int*)array->array)[count], a[count], a[count]);
	teardown();
}