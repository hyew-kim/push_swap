/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:01 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:09:03 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*library*/
# include "./libft/libft.h"

/*struct*/
typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

/*prototype*/
void				check_input(int argc, char *argv[], t_stack *stack);
void				check_arr(char *arr, t_stack *stack);
void				print_error(t_stack *stack);
t_node				*create_node(int content);
int					empty(t_node *head);
t_node				*back(t_node *head);
void				push_front(t_node *head, int content);
void				push_back(t_node *head, int content);
void				pop_front(t_node *head);
void				pop_back(t_node *head);
int					find_value(t_node *head, int value);
int					size(t_node *head);
void				set_stack(t_stack *stack, int num);
void				free_stack(t_stack *stack);
void				set_sort(t_stack *stack);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
void				indexing(t_node *head, int **arr);
void				sort(t_stack *stack);
int					issorted(t_node *head, int flag);
void				sort_few_elements(t_stack *stack, int len);
void				sort_three(t_stack *stack);
void				sort_four(t_stack *stack, int len);
void				sort_five(t_stack *stack, int len);
int					is_done_a(t_stack *stack, int len);
int					is_done_b(t_stack *stack, int len);
int					is_possible_pb(t_node *head, int pivot);
int					is_possible_pa(t_node *head, int pivot);
int					get_pivot(t_node *head, int length);
void				a_to_b(t_stack *stack, int len);
void				b_to_a(t_stack *stack, int len);
int					get_value_min(t_node *head);
int					get_value_max(t_node *head);
int					get_index_min(t_node *head);
int					get_index_max(t_node *head);
int					check_case(t_node *head);
#endif
