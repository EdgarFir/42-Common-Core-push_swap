int calc_r_oper(t_opers *opers)
{
	int opers_count;

	opers_count = 0;
	if (opers[0].r && opers[1].r)
	{
		if (opers[0].r < opers[1].r)
			opers_count = opers[1].r;
		else
			opers_count = opers[0].r;
	}
	else if (opers[0].r)
		opers_count = opers[0].r;
	else if (opers[1].r)
		opers_count = opers[1].r;
	
}

int calc_rr_oper(t_opers *opers)
{
	int opers_count;

	opers_count = 0;
	if (opers[0].rr && opers[1].rr)
	{
		if (opers[0].r < opers[1].r)
			opers_count = opers[1].rr;
		else
			opers_count = opers[0].rr;
	}
	else if (opers[0].rr)
		opers_count = opers[0].rr;
	else if (opers[1].rr)
		opers_count = opers[1].rr;
		int calc_struct_opers(t_opers *opers)
		{
			int r_count;
			int rr_count;
			
			r_count = calc_r_oper(opers);
			rr_count = calc_rr_oper(opers);
			return (r_count + rr_count);
		}
}

void rotate_a_min(int *stack_a, int stack_a_size)
{
	int min_index;
	
	min_index = find_min_index(stack_a);
	if (min_index < stack_a_size / 2)
		rotate(stack_a, min_index);
	else
		reverse_rotate(stack_a, stack_a_size - min_index);
}