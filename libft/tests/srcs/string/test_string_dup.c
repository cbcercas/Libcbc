#include "headers.h"

static t_string *string;

static void teardown(void) {
	if (string)
	{
		free(string->s);
		free(string);
		string = NULL;
	}
}

TestSuite(string_dup, .disabled = DISABLE_STRING_TEST, .fini = teardown);

Test(string_dup, Test_string_dup_0) {
	if (string)
		teardown();
	char *test = "Hello World dup";
	string = string_dup(test);
	cr_expect(string->s != NULL, "String->s is NULL after string_dup()");
	cr_expect(ft_strequ(string->s, test) == 1, "String->s not a copy of char *test after string_dup()");
	cr_expect(string->len == 15, "string->len need to be 15");
	cr_expect(string->capacity == STRING_MIN_SIZE * 2, "String->capacity not good");
}

Test(string_dup, Test_string_dup_1) {
	if (string)
		teardown();
	char *test = NULL;
	string = string_dup(test);
	cr_expect(string != NULL, "String is NULL after string_dup(NULL)");
	cr_expect(string->s != NULL, "string->s need to be !NULL when string_dup(NULL)");
	cr_expect(string->len == 0, "string->len need to be 0");
	cr_expect(string->capacity == STRING_MIN_SIZE, "string->capacity need to be STRING_MIN_SIZE not %zu", string->capacity);
}

Test(string_dup, Test_string_ndup_0) {
	if (string)
		teardown();
	char *test = "Hello World dup";
	string = string_ndup(test, 11);
	cr_expect(string->s != NULL, "String->s is NULL after string_dup()");
	cr_expect(ft_strequ(string->s, "Hello World") == 1, "String->s not a copy of char *test after string_dup()");
	cr_expect(string->len == 11, "string->len need to be 11 not %zu", string->len);
	cr_expect(string->capacity == STRING_MIN_SIZE * 2, "String->capacity not good");
}

Test(string_dup, Test_string_ndup_1) {
	if (string)
		teardown();
	char *test = "Hello World dup";
	string = string_ndup(test, 11);
	cr_expect(string->s != NULL, "String->s is NULL after string_dup()");
	cr_expect(ft_strequ(string->s, "Hello World") == 1, "String->s not a copy of char *test after string_dup()");
	cr_expect(string->len == 11, "string->len need to be 11 not %zu", string->len);
	cr_expect(string->capacity == STRING_MIN_SIZE * 2, "String->capacity not good");
}

Test(string_dup, Test_string_ndup_2) {
	if (string)
		teardown();
	char *test = NULL;
	string = string_ndup(test, 11);
	cr_expect(string != NULL, "String is NULL after string_dup(NULL)");
	cr_expect(string->s != NULL, "string->s need to be !NULL when string_dup(NULL)");
	cr_expect(string->len == 0, "string->len need to be 0");
	cr_expect(string->capacity == STRING_MIN_SIZE * 2, "string->capacity need to be STRING_MIN_SIZE not %zu", string->capacity);

}

Test(string_dup, Test_string_ndup_3) {
	if (string)
		teardown();
	char *test = "Hello World dup";
	string = string_ndup(test, 50);
	cr_expect(string->s != NULL, "String->s is NULL after string_ndup()");
	cr_expect(ft_strequ(string->s, test) == 1, "String->s not a copy of char *test after string_ndup()");
	cr_expect(string->len == 15, "string->len need to be 15 not %zu", string->len);
	cr_expect(string->capacity == STRING_MIN_SIZE * 7, "String->capacity not good");
}
