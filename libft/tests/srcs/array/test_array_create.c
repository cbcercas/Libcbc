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

TestSuite(array_create, .disabled = DISABLE_ARRAY_TEST, .fini = teardown);

Test(array_create, Test_array_create_1) {
	array = array_create(1);
	cr_expect(array != NULL, "Array pointer NULL with array_create(1)");
	cr_expect(array != NULL, "Array data pointer NULL with array_create(1)");
	cr_expect(array->elem_size == 1, "Array_elem size error");
}

Test(array_create, Test_array_create_0) {
	array = array_create(0);
	cr_expect(array == NULL, "Array not NULL with array_create(0)");
}

Test(array_create, Test_array_create_cap_0) {
	array = array_create_cap(1, 0);
	cr_expect(array != NULL, "Array NULL with array_create_cap(1, 0)");
	cr_expect(array->array != NULL, "Array data pointer NULL with array_create_cap(1, 0)");
	cr_expect(array->capacity == ARRAY_MIN_SIZE, "Bad array capacity with array_create_cap(1, 0)");
	cr_expect(array->used == 0, "Bad array used with array_create_cap(1, 0)");
}

Test(array_create, Test_array_create_1_7) {
	array = array_create_cap(1, 7);
	cr_expect(array != NULL, "Array NULL with array_create_cap(1, 7)");
	cr_expect(array->array != NULL, "Array data pointer NULL with array_create_cap(1, 7)");
	cr_expect(array->capacity == 8, "Bad array capacity with array_create_cap(1, 7): cap = %zu", array->capacity);
	cr_expect(array->used == 0, "Bad array used with array_create_cap(1, 7)");
}
