#include "headers.h"

static void init(void) {
	logger_init(D_DEBUG3, "string test shrink", "dbg.log");
}

static void teardown(void) {
	logger_close();
	return;
}

TestSuite(string_shrink, .disabled = DISABLE_STRING_TEST, .init = init, .fini = teardown);

Test(string_shrink, Test_string_shrink_0) {
	t_string	*str;
	char *test = "Hello World, I'm remove function!";

	str = string_dup(test);
	ft_bzero(str->s + 11, str->len - 11);
	str->len = 11;
	string_shrink(str);
	cr_expect_eq(str->capacity, 16, "string->capacity need tobe 16 but is %zu", str->capacity);
	string_del(&str);
}