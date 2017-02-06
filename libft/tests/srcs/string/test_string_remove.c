#include "headers.h"

static void init(void) {
	logger_init(D_DEBUG3, "string test", "dbg.log");
}

static void teardown(void) {
	logger_close();
	return;
}

TestSuite(string_remove, .disabled = DISABLE_STRING_TEST, .init = init, .fini = teardown);

Test(string_remove, Test_string_remove_0) {
	t_string	*str;
	size_t		rem;
	char *test = "Hello World, I'm remove function!";

	str = string_dup(test);
	cr_expect_eq(rem = string_remove(str, str->len + 2, 5), 0, "return needed is 0 but your function return %zu", rem);
	rem = string_remove(str, 5, 6);
	cr_expect_eq(rem, 6, "return needed is 5 but your function return %zu", rem);
	cr_expect_eq(str->len, 27, "str->len needed to be 28 after remove, but you have %zu", str->len);
	cr_expect_eq(rem = string_remove(str, 20, 10), 7, "return needed is 9 but your function return %zu", rem);
	string_del(&str);
}