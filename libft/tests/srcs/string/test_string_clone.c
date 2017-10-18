#include "headers.h"

static t_string *string1;
static t_string *string2;

static void teardown(void) {
	if (string1)
	{
		free(string1->s);
		free(string1);
		string1 = NULL;
	}
	if (string2)
	{
		free(string2->s);
		free(string2);
		string2 = NULL;
	}
}

TestSuite(string_clone, .disabled = DISABLE_STRING_TEST, .fini = teardown);

Test(string_clone, Test_string_clone_0) {
	if (string1 || string2)
		teardown();
	char *test = "Hello World dup";
	string1 = string_dup(test);
	string2 = string_clone(string1);
	cr_expect(string1->s != NULL, "String->s is NULL after string_dup()");
	cr_expect(ft_strequ(string2->s, test) == 1, "String2->s not a copy of string1->s --%s--%s--", string1->s, string2->s);
	cr_expect(string1->len == 15, "string2->len is not the same as string1->len");
	cr_expect(string1->capacity == STRING_MIN_SIZE * 2, "String1->capacity not good");
	cr_expect(string2->capacity == STRING_MIN_SIZE * 2, "String2->capacity not good");
}

Test(string_clone, Test_string_clone_1) {
	if (string1 || string2)
		teardown();
	string2 = string_clone(NULL);
	cr_expect(string1 == NULL, "String->s is NULL after string_dup()");
}
