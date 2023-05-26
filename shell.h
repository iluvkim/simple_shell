#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_COMMAND_LENGTH 1000
#ifndef LISTS_H_
#define LISTS_H_


/**
 * struct listtoken_s - singly linked list
 * @token: pointer
 * @token_length: integer
 * @next: points to the next node
 */
typedef struct listtoken_s
{
	char *token;
	int token_length;
	struct listtoken_s *next;
} listtoken_t;


/**
 * struct builtin_command - Short description
 * @name: First member
 * @function: Second member
 */
struct builtin_command
{
	char *name;
	int (*function)(char **a);
};

size_t _tokennum(char *istr, char *delim);
char **s_delim(char *istr, char *delim);
int d_count(size_t n);
int _printsenv(__attribute((unused)) char **a);
int p_error(char **arvs, char **a, size_t n);
int exitbuilt(char **a);
void ffree(char **a, char *istr);
void wfree(char **path_var, char **a);
char *_getenv(const char *name);
ssize_t _getLine(char **istr,size_t *nummallocalloc, int status);
int isbuilt(char **a);
int _handler(char **a);
size_t listslen(const listtoken_t *head);
void freeslist(listtoken_t **head);
int main(__attribute((unused)) int ac,__attribute((unused)) char **arvs,__attribute((unused)) char **envp);
size_t p_element(const listtoken_t *head);
void inter_mode(void);
int forks_thread(char *s, char **a);
int print_node(void);
void c_envar(char **dir, unsigned int envar_length, const char *name, const char *value);
int _envset(char *dir, unsigned int envar_length, const char *name, int o);
int _envariable(char *dir, unsigned int envar_length, unsigned int q);
int _setenv(const char *name, const char *value, int o);
void sigint_(int si);
void stringrevs(char *str);
char *_convertstring(size_t n);
char *malloc_char(char **string, size_t size_of_malloc, char *mms);
char **malloc_array(char **array, size_t size_of_malloc, char *mms);
int c_array(char **dest, char **source);
int envname_(const char *name);
int _block(void);
listtoken_t *_nodetoken(listtoken_t **head, char *token);
int _unsetenv(const char *name);
int _validpath(char *filename);
void filepath_(char **_path, char **a, char *filename, int y);
char *_alai(char *filename);
int _cndd(int argc, char *argv[]);
void execute_command(const char *cmd);
#endif
