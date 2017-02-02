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

TestSuite(string_insert, .disabled = DISABLE_STRING_TEST, .fini = teardown);

Test(string_insert, Test_string_insert_0) {
	if (string)
		teardown();
	char *test = "Hello ";
	char *test1 = "World ";
	cr_expect((string = string_dup(test)) != NULL, "string_dup fail!");
	cr_expect((string = string_insert_front(string, test1)) != NULL, "string_dup fail!");
	cr_expect(ft_strequ(string->s, "World Hello ") == 1, "string_insert fail!! s = %s", string->s);
}

Test(string_insert, Test_string_insert_1) {
	if (string)
		teardown();
	char *test = "Hello ";
	char *test1 = "World ";
	cr_expect((string = string_dup(test)) != NULL, "string_dup fail!");
	cr_expect((string = string_insert_back(string, test1)) != NULL, "string_dup fail!");
	cr_expect(ft_strequ(string->s, "Hello World ") == 1, "string_insert fail!! s = %s", string->s);
}

Test(string_insert, Test_string_insert_2) {
	if (string)
		teardown();
	char *test = "Hello";
	char *test1 = "1234";
	cr_expect((string = string_dup(test)) != NULL, "string_dup fail!");
	cr_expect((string = string_insert(string, test1, 3)) != NULL, "string_dup fail!");
	cr_expect(ft_strequ(string->s, "Hel1234lo") == 1, "string_insert fail!! s = %s", string->s);
}