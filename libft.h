#ifndef _LIBFT_H
# define _LIBFT_H

# define BUFF_SIZE 1
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

float compute_disorder(int *stack);
int	ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *list);
t_list  *ft_lstnew(void const *content, size_t content_size);
void	  ft_lstadd_front(t_list **lst, t_list *new);
void	  ft_lstadd_back(t_list **lst, t_list *new);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memalloc(size_t size);

#endif
