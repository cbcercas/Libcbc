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

TestSuite(string_create, .disabled = DISABLE_STRING_TEST, .fini = teardown);

Test(string_create, Test_string_create_0) {
	string = string_create();
	cr_expect(string != NULL, "String pointer NULL with string_create(1)");
	cr_expect(string != NULL, "String data pointer NULL with string_create(1)");
	cr_expect(string->capacity == STRING_MIN_SIZE, "Bad string capacity with string_create_cap(1, 0)");
	cr_expect(string->len == 0, "Bad string len with string_create_cap(1, 0)");
}

Test(string_create, Test_string_create_cap_0) {
	string = string_create_cap(0);
	cr_expect(string != NULL, "String NULL with string_create_cap(0)");
	cr_expect(string->s != NULL, "String data pointer NULL with string_create_cap(1, 0)");
	cr_expect(string->capacity == STRING_MIN_SIZE, "Bad string capacity with string_create_cap(1, 0)");
	cr_expect(string->len == 0, "Bad string len with string_create_cap(1, 0)");
}

Test(string_create, Test_string_create_9) {
	string = string_create_cap(9);
	cr_expect(string != NULL, "String NULL with string_create_cap(1, 7)");
	cr_expect(string->s != NULL, "String data pointer NULL with string_create_cap(1, 7)");
	cr_expect(string->capacity == STRING_MIN_SIZE * 2, "Bad string capacity with string_create_cap(1, 7): cap = %zu", string->capacity);
	cr_expect(string->len == 0, "Bad string len with string_create_cap(1, 7)");
}
