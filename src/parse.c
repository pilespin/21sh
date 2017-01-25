/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 20:33:16 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void		ft_parse_line(t_st *e, char *line)
{
	char	**tab_line;
	char	*line2;

	if (ft_strlen(line) <= 0)
		return ;
	ft_add_in_history(e, line);
	ft_replace_char(line, '\'', ' ');
	ft_replace_char(line, '"', ' ');
	while (ft_strchr(line, '`'))
		line = ft_parse_bquote(e, line);
	line2 = ft_strtrim(line);
	free(line);
	tab_line = ft_strsplit(line2, ';');
	free(line2);
	ft_parse_logic_operator(e, tab_line);
	ft_freetabchar(tab_line);
}
