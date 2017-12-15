#include "headers.h"

static void init(void) {
	logger_init(D_DEBUG3, "string test shrink", "dbg.log");
}

static void teardown(void) {
	logger_close();
	return;
}

TestSuite(string_replace, .disabled = DISABLE_STRING_TEST, .init = init, .fini = teardown);

Test(string_replace, Test_string_shrink_0) {
	t_string	*str;
	char *test = "Hello World!";
	char *test2 = "Un test qui marche!";
	char *backup;
	str = string_dup(test);
	cr_expect_str_eq(str->s, "Hello World!", "string_dup failed need to be \"Hello World!\" but is \"%s\"", str->s);
	backup = str->s;
	string_replace(str, test2);
	cr_expect_str_eq(str->s, "Un test qui marche!", "string_replace failed need to be \"Un test qui marche!\" but is \"%s\"", str->s);
	cr_assert_eq(str->len, 19, "str->len not updated!");
	cr_assert_eq(str->capacity, 24, "str->capacity Bad capacity == %zu!", str->capacity);
	string_del(&str);
}
