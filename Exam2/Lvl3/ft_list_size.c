/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:27:13 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 16:29:34 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}