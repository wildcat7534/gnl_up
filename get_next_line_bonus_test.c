#include "get_next_line_bonus.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void	test_get_next_line(void)
{
	char	*line;
	int		fd;

	fd = open("single_line.txt", O_RDONLY);
	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is a single line.\n");
	free(line);
	close(fd);
	// ... Add more test cases for different scenarios ...
	fd = open("multiple_lines.txt", O_RDONLY);
	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is the first line.\n");
	free(line);
/*	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is the second line.\n");
	free(line);
	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is the third line.\n");
	free(line);*/
	close(fd);
	fd = open("empty_file.txt", O_RDONLY);
	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is an empty file.\n");
	close(fd);
	fd = open("single_line_no_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	CU_ASSERT_STRING_EQUAL(line, "This is a single line without a newline.");
	free(line);
	close(fd);
}

int	main(void)
{
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("get_next_line_suite", 0, 0);
	CU_add_test(suite, "test_get_next_line", test_get_next_line);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}