#ifndef NUMGRID_H_INCLUDED
#define NUMGRID_H_INCLUDED

#ifndef NUMGRID_API
#  ifdef _WIN32
#    if defined(NUMGRID_BUILD_SHARED) /* build dll */
#      define NUMGRID_API __declspec(dllexport)
#    elif !defined(NUMGRID_BUILD_STATIC) /* use dll */
#      define NUMGRID_API __declspec(dllimport)
#    else /* static library */
#      define NUMGRID_API
#    endif
#  else
#    if __GNUC__ >= 4
#      define NUMGRID_API __attribute__((visibility("default")))
#    else
#      define NUMGRID_API
#    endif
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct context_s;
typedef struct context_s context_t;

/* get version */
NUMGRID_API char *get_version();

/* create a new context */
NUMGRID_API context_t *new_context();

/* destroy the context and deallocates all data */
NUMGRID_API void free_context(context_t *context);

/* generate grid and hold it in memory for the lifetime of the context */
NUMGRID_API int generate_grid(context_t *context,
                              const double radial_precision,
                              const int    min_num_angular_points,
                              const int    max_num_angular_points,
                              const int    num_centers,
                              const double center_coordinates[],
                              const int    center_elements[],
                              const int    num_outer_centers,
                              const double outer_center_coordinates[],
                              const int    outer_center_elements[],
                              const int    num_shells,
                              const int    shell_centers[],
                              const int    shell_l_quantum_numbers[],
                              const int    shell_num_primitives[],
                              const double primitive_exponents[]);

/* get number of grid points */
NUMGRID_API int get_num_points(const context_t *context);

/* get the pointer to the memory which holds the grid */
NUMGRID_API double *get_grid(const context_t *context);

#ifdef __cplusplus
}
#endif

#endif /* NUMGRID_H_INCLUDED */
