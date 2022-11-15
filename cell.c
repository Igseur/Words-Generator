#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"

p_cell createCell(char flechie, char type)
{
    p_cell p_res;

    p_res = (p_cell) malloc(sizeof(t_cell));

    p_res->flechie = flechie;
		p_res->type = type;
    p_res->next = NULL;

    return p_res;
}