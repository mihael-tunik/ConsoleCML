#include <iostream>
#include <cstring>

#include "getopt.h"
#include "parse.hpp"

int cmd_interface(int argc, char **argv)
{
	Graph mol;
    int rez = 0, f_flag = 0, p_flag = 0, v_flag = 0;
    char *path = NULL, *infile = NULL;

    switch(argc){
        case 1:

			printf("The input is empty! \n");
            return -1;

        case 2:

            if (!strcmp(argv[1], "help"))
                printf("HELP: use options -f for showing formula, -p for showing oxidation number, -v for visualizing model.");
            else
                printf("Wrong input...\n");

            return -1;

        default:

           infile  = argv[1];
           path    = argv[argc-1];

	        while ((rez = getopt (argc - 1, &(argv[1]), ": f : p : v :")) != -1)
                switch (rez)
                {
                  case 'f':
                    f_flag = 1;
                    break;

				  case 'p':
                    p_flag = 1;
                    break;
                  
				  case 'v':
                    v_flag = 1;
                    break;

                  case '?':
                    printf("Error...\n");
					return -1;
                }
    }

	if(-1 == parse( infile, mol ))
	{
		printf("Parsing failed!\n");
		return -1;
	}

	if (f_flag)
		print_formula(mol);

	if (p_flag)
		oxidation_numbers(mol);

   	if (v_flag)
	   jmol(infile, p_flag, path);
	
	cout << "ConsoleCML 1.0" << endl;

	return 0;
}

//#include <process.h>
int main(int argc, char **argv){
    return cmd_interface(argc, argv);
}


