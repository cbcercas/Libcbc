#include "headers.h"

static t_array *array;

static void teardown(void) {
	if (array)
	{
		ft_bzero(array->array, array->capacity * array->elem_size);
		ft_bzero(array, sizeof(*array));
		free(array->array);
		free(array);
		array = NULL;
	}
}

TestSuite(array_simple_usage, .disabled = DISABLE_ARRAY_TEST, .fini = teardown);

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
		cr_expect(*(int *)array_get_at(array, count) == a[count], "Array %d != %d with array_push(array, %d)",((int*)array->array)[count], a[count], a[count]);
	//teardown();
}

Test(array_simple_usage, Test_array_get_first_last) {
	int a[4] = {0, 1, 2, 3};
	int count;

	array = array_create(sizeof(int));
	count = -1;
	cr_expect(array_get_first(array) == NULL, "array_get_first when array have 0 element failed");
	cr_expect(array_get_last(array) == NULL, "array_get_last when array have 0 element failed");
	while (++count < 4)
		array_push(array, a + count);
	cr_expect(*(int *)array_get_first(array) == a[0], "array_get_first failed");
	cr_expect(*(int *)array_get_last(array) == a[3], "array_get_last failed");
	//teardown();
}

Test(array_simple_usage, Test_array_auto_growth) {
	int a[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int count;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 11)
		array_push(array, a + count);
	count = -1;
	cr_expect(array->used == 11, "Array->used incorect: %zu", array->used);
	while (++count < 11)
		cr_expect(*(int *)array_get_at(array, count) == a[count], "%d Array %d != %d with array_push(array, %d)", count, ((int*)array->array)[count], a[count], a[count]);
	//teardown();
}

Test(array_simple_usage, Test_simple_array_swap) {
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int count;
	int count2;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 10)
		array_push(array, a + count);
	cr_expect(array_swap(array, 0, array->capacity) == false, "can swap array->capacity");
	cr_expect(array_swap(array, 0, array->capacity + 4) == false, "can swap array->capacity + 4");
	cr_expect(array_swap(array, array->capacity, 0) == false, "can swap array->capacity");
	cr_expect(array_swap(array, array->capacity + 4, 0) == false, "can swap array->capacity + 4");
	cr_expect(array_swap(array, 0, 7) == true, "Error when swappping!");
	cr_expect(array_swap(array, 1, 6) == true, "Error when swappping!");
	cr_expect(array_swap(array, 2, 5) == true, "Error when swappping!");
	cr_expect(array_swap(array, 3, 4) == true, "Error when swappping!");
	count = 9;
	count2 = 0;
	while (--count != 0)
	{
		cr_expect(((int*)array->array)[count - 1] == a[count2], "Array[%d]-> %d != %d", count - 1, ((int*)array->array)[count - 1], a[count2]);
		count2++;
	}
	cr_expect(((int*)array->array)[8] == a[8], "Array[%d]-> %d != %d", 8, ((int*)array->array)[8], a[8]);
	//teardown();
}

Test(array_simple_usage, Test_simple_array_pop) {
	int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int count;
	int poped;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 8)
		array_push(array, a + count);
	array_pop(array, &poped);
	cr_expect(poped == 7, "pop failed failed %d", poped);
	cr_expect(array->used == 7, "array->used not decreased after poping: %zu", array->used);
	array_pop(array, &poped);
	cr_expect(poped == 6, "pop failed failed %d", poped);
	cr_expect(array->used == 6, "array->used not decreased after poping: %zu", array->used);
 	//teardown();
}

Test(array_simple_usage, Test_array_copy_array) {
	int		a[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int		count;
	t_array *dest;
	array = array_create(sizeof(int));
	dest = array_create(sizeof(int));
	count = -1;
	while (++count < 11)
		array_push(array, a + count);
	count = -1;
	cr_expect(array_copy(dest, array) != NULL, "Error in array_copy return");
	while (++count < 11)
		cr_expect(*(int *)array_get_at(dest, count) == a[count], "%d Array %d != %d with array_push(array, %d)", count, *(int*)array_get_at(dest, count), a[count], a[count]);
	//teardown();
}

Test(array_simple_usage, Test_simple_array_insert) {
	int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int count;

	array = array_create(sizeof(int));
	count = -1;
	while (++count < 8)
		array_push(array, a + count);
	cr_expect(array->capacity == 8, "Bad array capacity");
	cr_expect(array_insert(array, 5, a + 8) != NULL, "array insert failed");
	cr_expect(array->capacity == 12, "Bad array capacity after array_insert");
	cr_expect(*(int *)array_get_at(array, 5) == a[8], "Bad inserted value");
	cr_expect(*(int *)array_get_at(array, 6) == a[5], "Bad vaule after the inserted element");
	cr_expect(array_insert(array, 5, NULL) == NULL, "array insert failed");
}

Test(array_simple_usage, Test_array_shrink)
{
	int		a[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int		count;

	array = array_create_cap(sizeof(int), 11);
	cr_expect(array->capacity == 12, "Error when creating array with capacity 12, array->capacity = %zu", array->capacity);
	count = -1;
	while (++count < 3)
		array_push(array, a + count);
	cr_expect(array_shrink(array) != NULL, "Error on array_shrink return");
	cr_expect(array->capacity == 4, "Error capacity not shrinked array->capacity = %zu", array->capacity);
	count = -1;
	while (++count < 3)
		cr_expect(*(int *)array_get_at(array, count) == a[count], "New array value %d =! old array %d", *(int *)array_get_at(array, count), a[count]);
	//teardown();
}
