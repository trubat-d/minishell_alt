#ifndef PARSER_H
# define PARSER_H

# include "includers.h"

enum	e_type
{
	IO,
	PIPE,
	WORD,
};

struct s_lexical
{
	enum e_type			type;
	int					size;
	char				*content;
	struct s_lexical	*next;
};

int			get_type(t_lexical **type, char *str, int *i);
int			create_lexical(t_lexical **lexical, enum e_type type, int size, char *content);
int			lex_add_front(t_lexical **root, enum e_type type, int size);
int			lex_add_back(t_lexical **root, enum e_type type, int size, char*content);
int			get_lexical(t_lexical **lst_head, char *str);

void		in_dquote(int *i, char c);
void		in_squote(int *i, char c);
int			ft_rmv_char(char **buffadr, int i);
void		is_in_squote(int *i, char c);
void		is_in_dquote(int *i, char c);

#endif