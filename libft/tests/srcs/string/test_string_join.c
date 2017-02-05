#include "headers.h"

static void teardown(void) {
	return;
}

TestSuite(string_join, .disabled = DISABLE_STRING_TEST, .fini = teardown);

Test(string_join, Test_string_join_0) {
	t_string	*str1;
	t_string	*str2;
	t_string	*str3;
	char *test = "Hello World";

	str1 = string_dup(test);
	str2 = string_clone(str1);
	cr_expect((str3 = string_join(str1, str2)) != NULL, "string_join fail!");
	cr_expect(ft_strequ(str3->s, "Hello WorldHello World") == 1, "string_join fail!! s = %s", str3->s);
	cr_expect(str3->capacity == 24, "string->capacity not good : %zu", str3->capacity);
	cr_expect(str3->len == 22, "string->len not good : %zu", str3->len);
}