#pragma once

int read_int(const char * request);

double read_double(const char * request);

/* Input non-empty string from standart input.
 * Does not include '\n' character in the end. */
char * read_string(const char * request);