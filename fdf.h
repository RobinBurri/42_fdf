#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1080
# define HIGHT 1080
# define TITLE "fdf"

//ERROR MESSAGES
# define FDF_INIT_ERR "Fdf initialization error"
# define OPEN_ERR "MAP_FILE ERROR"


typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		key_hook(int keycode, t_mlx img);
t_mlx	*fdf_init(void);
void	send_err(char *s);
#endif