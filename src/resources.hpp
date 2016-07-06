
#define TABLE_SIZE  118

extern char *periodic_table[TABLE_SIZE] = {       "H", "He", "Li", "Be", "B" , "C" , "N" , "O" , "F" , "Ne",
		                                         "Na", "Mg", "Al", "Si", "P" , "S" , "Cl", "Ar", "K" , "Ca",
		                                         "Sc", "Ti", "V" , "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
		                                         "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y" , "Zr",
		                                         "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
		                                         "Sb", "Te", "I" , "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
		                                         "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
		                                         "Lu", "Hf", "Ta", "W" , "Re", "Os", "Ir", "Pt", "Au", "Hg",
		                                         "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
		                                         "Pa", "U" , "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
		                                         "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
		                                         "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og" };

extern double negativity_pauling[TABLE_SIZE] = { 2.20, 4.50, 0.98, 1.57, 2.04, 2.55, 3.04, 3.44, 3.98, 4.40,
                                                 0.93, 1.31, 1.61, 1.90, 2.19, 2.58, 3.16, 4.30, 0.82, 1.00,
                                                 1.36, 1.54, 1.63, 1.66, 1.55, 1.83, 1.88, 1.91, 1.90, 1.65,
                                                 1.81, 2.01, 2.18, 2.55, 2.96, 3.00, 0.82, 0.95, 1.22, 1.33,
                                                 1.60, 2.16, 1.90, 2.20, 2.28, 2.20, 1.93, 1.69, 1.78, 1.96,
                                                 2.05, 2.10, 2.66, 2.60, 0.79, 0.89, 1.10, 1.12, 1.13, 1.14,
                                                 1.13, 1.17, 1.20, 1.20, 1.10, 1.22, 1.23, 1.24, 1.25, 1.10,
                                                 1.27, 1.30, 1.50, 2.36, 1.90, 2.20, 2.20, 2.28, 2.54, 2.00,
                                                 1.62, 2.33, 2.02, 2.00, 2.20, 2.20, 0.70, 0.90, 1.10, 1.30,
                                                 1.50, 1.38, 1.36, 1.28, 1.30, 1.30, 1.30, 1.30, 1.30, 1.30,
					 	                         1.30, 1.30, 1.30, 1.30, 1.30,-1.00,-1.00,-1.00,-1.00,-1.00,//undefined
					   		                    -1.00,-1.00,-1.00,-1.00,-1.00,-1.00,-1.00,-1.00 };

char *p_table(int index)
{
	if (index < TABLE_SIZE )
	     return periodic_table[index];
	return 0;
}

double n_table(int index)
{
	if (index < TABLE_SIZE)
		return negativity_pauling[index];
	return 0;
}
