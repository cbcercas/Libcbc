#include "headers.h"
#include <array/array.h>
//#include <libft.h>
static t_array *array;

static void teardown(void) {
	if (array)
	{
		free(array->array);
		free(array);
		array = NULL;
	}
}


Test(array_create, Test_array_create_1) {
	array = array_create(1);
	cr_expect(array != NULL, "Array pointer NULL with array_create(1)");
	cr_expect(array != NULL, "Array data pointer NULL with array_create(1)");
	cr_expect(array->elem_size == 1, "Array_elem size error");
	teardown();
}

Test(array_create, Test_array_create_0) {
	array = array_create(0);
	cr_expect(array == NULL, "Array not NULL with array_create(0)");
	teardown();
}

Test(array_create, Test_array_create_cap_0) {
	array = array_create_cap(1, 0);
	cr_expect(array != NULL, "Array NULL with array_create_cap(1, 0)");
	cr_expect(array->array != NULL, "Array data pointer NULL with array_create_cap(1, 0)");
	cr_expect(array->capacity == ARRAY_MIN_SIZE, "Bad array capacity with array_create_cap(1, 0)");
	cr_expect(array->used == 0, "Bad array used with array_create_cap(1, 0)");
	teardown();
}

Test(array_create, Test_array_create_1_7) {
	array = array_create_cap(1, 7);
	cr_expect(array != NULL, "Array NULL with array_create_cap(1, 7)");
	cr_expect(array->array != NULL, "Array data pointer NULL with array_create_cap(1, 7)");
	cr_expect(array->capacity == 8, "Bad array capacity with array_create_cap(1, 7): cap = %zu", array->capacity);
	cr_expect(array->used == 0, "Bad array used with array_create_cap(1, 7)");
	teardown();
}

Test(array_push, Test_simple_array) {
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

Test(array_push, Test_array_auto_growth) {
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