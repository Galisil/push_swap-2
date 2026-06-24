#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long int		valeur;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*start;
	int				size;
	struct s_node	*end;
}					t_stack;

typedef struct data_ve
{
	char			*strategy;
	float			disorder;
	int				bench;
}					data_verif;

t_node				*ft_new_node(int val);
void				ft_create_stack(char **argv, t_stack *stack, int size);
void				ft_stack_clear(t_stack *stack);
void				init_structs(t_stack *a, t_stack *b, data_verif *verif);
void				ft_data_clear(data_verif *verif);

void				ft_add_front(t_stack *stack, t_node *node);
void				ft_add_back(t_stack *stack, t_node *node);
t_node				*ft_remove_front(t_stack *stack);
t_node				*ft_remove_last(t_stack *stack);

void				ft_ra(t_stack *a);
void				ft_rb(t_stack *b);
void				ft_rr(t_stack *a, t_stack *b);
void				ft_rra(t_stack *a);
void				ft_rrb(t_stack *b);
void				ft_rrr(t_stack *a, t_stack *b);
void				ft_pa(t_stack *a, t_stack *b);
void				ft_pb(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

long int			ft_atoi(char *str);
int					is_digit(char *stack);
int					is_duplicata(char **stack, int argc);
int					ft_strcmp(const char *s1, const char *s2);

void				put_error(void);

float				compute_disorder(t_stack *a);
void				compute_index(t_stack *a, int size);
void				push_to_b(t_stack *a, t_stack *b, int nb_chunks);
//void				compute_pos(t_stack *a, int index);

void				algo_simple(t_stack *a, t_stack *b);
int					find_min_pos(t_stack *a);

void				algo_medium(t_stack *a, t_stack *b);

void				algo_complex(t_stack *a, t_stack *b);

void				algo_adaptive(t_stack *a, t_stack *b);

void				ft_validation(int argc, char **argv, data_verif *verif,
						t_stack *a);
void				ft_extract_flag(char **argv, data_verif *verif);

int					main(int argc, char **argv);

#endif