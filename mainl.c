/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:18:09 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/14 18:00:48 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_CYAN "\033[36m"
#define COLOR_BOLD "\033[1m"

static int	g_tests;
static int	g_failures;

static void	check_int(const char *name, int actual, int expected)
{
	g_tests++;
	if (actual != expected)
	{
		g_failures++;
		printf(COLOR_RED COLOR_BOLD "FAIL" COLOR_RESET " %-32s" COLOR_CYAN
									" expected %d, got %d" COLOR_RESET "\n",
			   name,
			   expected,
			   actual);
	}
	else
		printf(COLOR_GREEN COLOR_BOLD "PASS" COLOR_RESET " %s\n", name);
}

static void	check_size(const char *name, size_t actual, size_t expected)
{
	g_tests++;
	if (actual != expected)
	{
		g_failures++;
		printf(COLOR_RED COLOR_BOLD "FAIL" COLOR_RESET " %-32s" COLOR_CYAN
									" expected %zu, got %zu" COLOR_RESET "\n",
			   name,
			   expected,
			   actual);
	}
	else
		printf(COLOR_GREEN COLOR_BOLD "PASS" COLOR_RESET " %s\n", name);
}

static void	check_text(const char *name, const char *actual, const char *expected)
{
	g_tests++;
	if (strcmp(actual, expected) != 0)
	{
		g_failures++;
		printf(COLOR_RED COLOR_BOLD
			   "FAIL" COLOR_RESET " %-32s" COLOR_CYAN " expected \"%s\", got "
													  "\"%s\"" COLOR_RESET "\n",
			   name,
			   expected,
			   actual);
	}
	else
		printf(COLOR_GREEN COLOR_BOLD "PASS" COLOR_RESET " %s\n", name);
}

static void	check_bytes(const char *name,
						const void *actual,
						const void *expected,
						size_t size)
{
	g_tests++;
	if (memcmp(actual, expected, size) != 0)
	{
		g_failures++;
		printf(COLOR_RED COLOR_BOLD "FAIL" COLOR_RESET " %s\n", name);
	}
	else
		printf(COLOR_GREEN COLOR_BOLD "PASS" COLOR_RESET " %s\n", name);
}

static void	check_pointer(const char *name, const void *actual, const void *expected)
{
	g_tests++;
	if (actual != expected)
	{
		g_failures++;
		printf(COLOR_RED COLOR_BOLD "FAIL" COLOR_RESET " %s: returned an "
													   "unexpected pointer\n",
			   name);
	}
	else
		printf(COLOR_GREEN COLOR_BOLD "PASS" COLOR_RESET " %s\n", name);
}

static void	test_character_functions(void)
{
	check_int("ft_isalpha: lowercase", ft_isalpha('z'), 1);
	check_int("ft_isalpha: uppercase", ft_isalpha('A'), 1);
	check_int("ft_isalpha: digit", ft_isalpha('4'), 0);
	check_int("ft_isalpha: boundary", ft_isalpha(127), 0);
	check_int("ft_isdigit: digit", ft_isdigit('0'), 1);
	check_int("ft_isdigit: non-digit", ft_isdigit('/'), 0);
	check_int("ft_isdigit: upper boundary", ft_isdigit(':'), 0);
	check_int("ft_isalnum: letter", ft_isalnum('m'), 1);
	check_int("ft_isalnum: digit", ft_isalnum('8'), 1);
	check_int("ft_isalnum: punctuation", ft_isalnum('!'), 0);
	check_int("ft_isascii: zero", ft_isascii(0), 1);
	check_int("ft_isascii: 127", ft_isascii(127), 1);
	check_int("ft_isascii: negative", ft_isascii(-1), 0);
	check_int("ft_isascii: 128", ft_isascii(128), 0);
	check_int("ft_isprint: space", ft_isprint(' '), 1);
	check_int("ft_isprint: tilde", ft_isprint('~'), 1);
	check_int("ft_isprint: control", ft_isprint('\n'), 0);
	check_int("ft_isprint: 127", ft_isprint(127), 0);
}

static void	test_case_conversion(void)
{
	check_int("ft_toupper: lowercase", ft_toupper('a'), 'A');
	check_int("ft_toupper: uppercase", ft_toupper('Z'), 'Z');
	check_int("ft_toupper: punctuation", ft_toupper('!'), '!');
	check_int("ft_toupper: negative", ft_toupper(-1), -1);
	check_int("ft_tolower: uppercase", ft_tolower('A'), 'a');
	check_int("ft_tolower: lowercase", ft_tolower('z'), 'z');
	check_int("ft_tolower: punctuation", ft_tolower('!'), '!');
	check_int("ft_tolower: out of ASCII", ft_tolower(128), 128);
}

static void	test_strlen(void)
{
	check_size("ft_strlen: empty", ft_strlen(""), 0);
	check_size("ft_strlen: ordinary string", ft_strlen("libft"), 5);
	check_size("ft_strlen: spaces", ft_strlen("a b c"), 5);
}

static void	test_memset(void)
{
	char	buffer[8] = "abcdefg";
	char	zero_size[4] = "abc";

	check_pointer("ft_memset: return value", ft_memset(buffer, 'x', 3), buffer);
	check_text("ft_memset: changed prefix", buffer, "xxxdefg");
	ft_memset(zero_size, 'x', 0);
	check_text("ft_memset: zero length", zero_size, "abc");
}

static void	test_bzero(void)
{
	unsigned char	buffer[4] = {1, 2, 3, 4};
	unsigned char	expected[4] = {0, 0, 3, 4};
	unsigned char	unchanged[3] = {1, 2, 3};

	ft_bzero(buffer, 2);
	check_bytes("ft_bzero: zero prefix", buffer, expected, sizeof(buffer));
	ft_bzero(unchanged, 0);
	check_bytes("ft_bzero: zero length",
				unchanged,
				(unsigned char[]){1, 2, 3},
				sizeof(unchanged));
}

static void	test_memcpy(void)
{
	char	buffer[8] = "xxxxxxx";
	char	unchanged[4] = "abc";

	check_pointer(
		"ft_memcpy: return value", ft_memcpy(buffer, "hello", 6), buffer);
	check_text("ft_memcpy: copied string", buffer, "hello");
	ft_memcpy(unchanged, "xyz", 0);
	check_text("ft_memcpy: zero length", unchanged, "abc");
}

static void	test_memmove(void)
{
	char	right[7] = "abcdef";
	char	left[7] = "abcdef";

	check_pointer(
		"ft_memmove: return value", ft_memmove(right + 2, right, 4), right + 2);
	check_text("ft_memmove: overlapping right", right, "ababcd");
	ft_memmove(left, left + 2, 4);
	check_text("ft_memmove: overlapping left", left, "cdefef");
	ft_memmove(left, left, sizeof(left));
	check_text("ft_memmove: same pointer", left, "cdefef");
}

static void	test_strlcpy(void)
{
	char	buffer[8];
	char	one_byte[1] = {'x'};
	char	zero_size[4] = "abc";

	check_size("ft_strlcpy: zero size", ft_strlcpy(zero_size, "hello", 0), 5);
	check_text("ft_strlcpy: zero size unchanged", zero_size, "abc");
	check_size("ft_strlcpy: size one", ft_strlcpy(one_byte, "hello", 1), 5);
	check_bytes("ft_strlcpy: size one terminator",
				one_byte,
				(unsigned char[]){'\0'},
				sizeof(one_byte));
	check_size("ft_strlcpy: truncated", ft_strlcpy(buffer, "hello", 4), 5);
	check_text("ft_strlcpy: truncated content", buffer, "hel");
	check_size("ft_strlcpy: exact fit", ft_strlcpy(buffer, "hello", 6), 5);
	check_text("ft_strlcpy: exact fit content", buffer, "hello");
}

static void	test_string_search(void)
{
	const char	*text;

	text = "banana";
	check_pointer("ft_strchr: first match", ft_strchr(text, 'a'), text + 1);
	check_pointer("ft_strchr: missing", ft_strchr(text, 'x'), NULL);
	check_pointer("ft_strchr: terminator", ft_strchr(text, '\0'), text + 6);
	check_pointer("ft_strrchr: last match", ft_strrchr(text, 'a'), text + 5);
	check_pointer("ft_strrchr: missing", ft_strrchr(text, 'x'), NULL);
	check_pointer("ft_strrchr: terminator", ft_strrchr(text, '\0'), text + 6);
}

static void	test_strncmp(void)
{
	check_int("ft_strncmp: equal", ft_strncmp("abc", "abc", 3), 0);
	check_int("ft_strncmp: zero length", ft_strncmp("a", "b", 0), 0);
	check_int("ft_strncmp: difference", ft_strncmp("abc", "abd", 3), -1);
	check_int(
		"ft_strncmp: difference after limit", ft_strncmp("abc", "abd", 2), 0);
	check_int("ft_strncmp: shorter string", ft_strncmp("ab", "abc", 3), -'c');
	check_int("ft_strncmp: unsigned bytes", ft_strncmp("\200", "\177", 1), 1);
}

static void	test_memory_search_and_compare(void)
{
	const unsigned char	data[] = {0, 127, 128, 255};
	const unsigned char	first[] = {1, 2, 3};
	const unsigned char	second[] = {1, 2, 4};

	check_pointer("ft_memchr: high byte", ft_memchr(data, 255, 4), data + 3);
	check_pointer("ft_memchr: missing", ft_memchr(data, 42, 4), NULL);
	check_pointer("ft_memchr: zero length", ft_memchr(data, 0, 0), NULL);
	check_int("ft_memcmp: equal", ft_memcmp(first, first, 3), 0);
	check_int("ft_memcmp: zero length", ft_memcmp(first, second, 0), 0);
	check_int("ft_memcmp: first difference", ft_memcmp(first, second, 3), -1);
	check_int("ft_memcmp: unsigned bytes", ft_memcmp(data + 2, data + 1, 1), 1);
}

static void	test_strnstr(void)
{
	const char	*text;

	text = "libft functions";
	check_pointer("ft_strnstr: found", ft_strnstr(text, "fun", 15), text + 6);
	check_pointer("ft_strnstr: found at limit", ft_strnstr(text, "lib", 3), text);
	check_pointer(
		"ft_strnstr: match exceeds limit", ft_strnstr(text, "libft", 4), NULL);
	check_pointer("ft_strnstr: missing", ft_strnstr(text, "xyz", 15), NULL);
	check_pointer("ft_strnstr: empty needle", ft_strnstr(text, "", 0), text);
}

static void	test_atoi(void)
{
	check_int("ft_atoi: positive", ft_atoi("12345"), 12345);
	check_int("ft_atoi: negative", ft_atoi("-42"), -42);
	check_int("ft_atoi: leading whitespace", ft_atoi(" \t\n+17"), 17);
	check_int("ft_atoi: no digits", ft_atoi("word"), 0);
	check_int("ft_atoi: trailing characters", ft_atoi("29abc"), 29);
	check_int("ft_atoi: sign without digits", ft_atoi("-"), 0);
	check_int("ft_atoi: second sign stops parse", ft_atoi("+-5"), 0);
}

static void	test_calloc(void)
{
	unsigned char	*buffer;

	buffer = ft_calloc(4, sizeof(*buffer));
	check_int("ft_calloc: allocation", buffer != NULL, 1);
	if (buffer != NULL)
	{
		check_bytes("ft_calloc: zero initialized",
					buffer,
					(unsigned char[]){0, 0, 0, 0},
					4);
		free(buffer);
	}
	check_pointer(
		"ft_calloc: multiplication overflow", ft_calloc((size_t)-1, 2), NULL);
}

static void	test_strdup(void)
{
	char	*copy;

	copy = ft_strdup("libft");
	check_int("ft_strdup: allocation", copy != NULL, 1);
	if (copy != NULL)
	{
		check_text("ft_strdup: copied string", copy, "libft");
		free(copy);
	}
	copy = ft_strdup("");
	check_int("ft_strdup: empty allocation", copy != NULL, 1);
	if (copy != NULL)
	{
		check_text("ft_strdup: empty string", copy, "");
		free(copy);
	}
}

static void	test_strlcat(void)
{
	char	buffer[8] = "Hi";
	char	truncated[5] = "ab";
	char	too_small[5] = "abcd";
	char	zero_size[4] = "abc";

	check_size("ft_strlcat: append", ft_strlcat(buffer, "!", sizeof(buffer)), 3);
	check_text("ft_strlcat: appended content", buffer, "Hi!");
	check_size("ft_strlcat: truncated",
			   ft_strlcat(truncated, "cdef", sizeof(truncated)),
			   6);
	check_text("ft_strlcat: truncated content", truncated, "abcd");
	check_size("ft_strlcat: destination longer than size",
			   ft_strlcat(too_small, "xy", 2),
			   4);
	check_text("ft_strlcat: small size unchanged", too_small, "abcd");
	check_size("ft_strlcat: zero size", ft_strlcat(zero_size, "xy", 0), 2);
	check_text("ft_strlcat: zero size unchanged", zero_size, "abc");
}

int			main(void)
{
	test_character_functions();
	test_case_conversion();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_string_search();
	test_strncmp();
	test_memory_search_and_compare();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_strlcat();
	if (g_failures == 0)
		printf("\n" COLOR_GREEN COLOR_BOLD "All %d tests passed!" COLOR_RESET
			   "\n",
			   g_tests);
	else
		printf("\n" COLOR_RED COLOR_BOLD "%d of %d tests failed." COLOR_RESET
			   "\n",
			   g_failures,
			   g_tests);
	return (g_failures != 0);
}
