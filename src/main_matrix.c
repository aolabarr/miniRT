#include "../inc/minirt.h"

float *create_matrix(float a1,float a2,float a3,float a4,
    float a5,float a6,float a7,float a8,
    float a9,float a10,float a11,float a12,
    float a13,float a14,float a15,float a16);
void print_matrix(float *mat);
void print_matrix_4f(float *mat);
void print_vector(float *vec);

int main(int argc, char **argv)
{
    
    float *mat, *mat2, *mat3, *mat4;
    float vector[4] = {1, 1, 2, 0};
    float *vec;

    if (argc != 17)
        return (printf("introducir 17 numeros\n"), 1);

    mat = create_matrix(ft_atoif(argv[1]),ft_atoif(argv[2]),ft_atoif(argv[3]),ft_atoif(argv[4]),
                        ft_atoif(argv[5]),ft_atoif(argv[6]),ft_atoif(argv[7]),ft_atoif(argv[8]),
                        ft_atoif(argv[9]),ft_atoif(argv[10]),ft_atoif(argv[11]),ft_atoif(argv[12]),
                        ft_atoif(argv[13]),ft_atoif(argv[14]),ft_atoif(argv[15]),ft_atoif(argv[16]));
    print_matrix(mat);
    mat2 = multiply_matrix(mat, mat);
    print_matrix(mat2);
    mat3 = identity_matrix();
    print_matrix(mat3);
    mat4 = transpose_matrix(mat2);
    print_matrix(mat4);
    vec = multiply_matrix_vector(mat3, vector);
    print_vector(vec);
    mat3 = invert_matrix(mat);
    print_matrix_4f(mat3);
    mat4 = invert_matrix(mat3);
    print_matrix_4f(mat4);
    return(0);
}
