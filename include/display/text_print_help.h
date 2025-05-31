#ifndef _PRINT_H_
#define _PRINT_H_
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

void text_print_head1_blank1(const char **str[], int columns_num);
void text_print_head1_blank0(const char **str[], int columns_num);
void text_print_head0_blank1(const char **str[], int columns_num);
void text_print_head0_blank0(const char **str[], int columns_num);
#endif