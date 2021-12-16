#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1080
# define HIGHT 1080
# define TITLE "fdf"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif