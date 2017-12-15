#include "headers.h"

static void teardown(void) {
	return;
}

TestSuite(logger, .disabled = DISABLE_LOGGER_TEST, .fini = teardown);

// Test(logger, Test_logger_0) {
// 	int fd;

// 	fd = logger_init(1, PROGNAME, "test.log");
// 	cr_expect(fd > 2, "Logger: error file descriptor number, fd = %d", fd);
// 	fd = logger_close();
// 	cr_expect(fd == 0, "error when closing fd fd = %d", fd);
// }

// Test(logger, Test_logger_1) {
// 	int fd;

// 	fd = logger_init(1, PROGNAME, "test.log");
// 	cr_expect(fd > 2, "Logger: error file descriptor number, fd = %d", fd);
// 	close(fd);
// 	fd = logger_close();
// 	cr_expect(fd == -1, "error when closing fd, fd = %d", fd);
// }

Test(logger, Test_logger_2) {
	int fd;
	int i = 0;
	fd = logger_init(5, PROGNAME, "test.log");
	while (i < 50)
	{
		log_fatal("test de log %s", "fatal");
		log_error("test de log %s", "error");
		log_warn("test de log %s", "warning");
		log_info("test de log %s", "info");
		log_dbg1("test de log %s %d", "debug", 1);
		log_dbg2("test de log %s %d", "debug", 2);
		log_dbg3("test de log %s %d", "debug", 3);
		i++;
	}
	fd = logger_close();
}
