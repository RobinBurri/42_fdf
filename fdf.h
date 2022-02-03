#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HIGHT 1000
# define TITLE "fdf"
# define ESC_CODE 53

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define INT_MAX 2147483647



//ERROR MESSAGES
# define FDF_INIT_ERR "Fdf initialization error"
# define MAP_INIT_ERR "Map initialization error"
# define OPEN_ERR "Open map_file error"
# define MAP_ERR "Map parsing error"
# define USR_ERR "Usage: ./fdf map_file"
# define IMG_INT_ERR "img initialization error"
# define CONVERT_ARRAY_ERR "Error at converting stack to array"
# define ERR_CAMERA_INIT "Error at camera init"

typedef struct			s_camera
{
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	struct s_point		*next;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					z_min;
	int					z_max;
	int					z_range;
	t_camera			*camera;
}						t_map;


int		key_hook(int keycode, t_mlx *data);
t_mlx	*fdf_init(void);
t_map	*map_init(void);
t_camera	*camera_init(t_map *map);
t_point		project(t_point p, t_map *map);
int		read_map(int fd, t_point **pts_stack, t_map *map);
void	draw_line(t_mlx *fdf, t_point s, t_point f);
void	my_pixel_put(t_mlx *fdf, int x, int y, int color);
//UTILS
void	send_err(char *s);
t_point	*pop_pts(t_point **pts_stack);
void	push_pts(t_point **pts_stack, t_point *new_pts);
void	ft_print_stack(t_point *stack);
void	ft_free_stack(t_point *stack);
void	stack_to_coords_array(t_point **pts_stack, t_map *map);
void	draw(t_map *map, t_mlx *fdf);
void	ft_free_map(t_map *map);


#endif