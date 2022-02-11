#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#define BUFFER_SIZE 1000

char	*get_next_line(int fd);

int		next_line_check(const char *line);
int		ft_strlen(const char *str);
char	*make_line(const char *buf, int *i);
char	*ft_strjoin(char *s1, char *s2);
int		fd_read(int	fd, char *buf, int *i);

#endif