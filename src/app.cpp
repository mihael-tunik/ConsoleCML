#include "parse.hpp"
#include "resources.hpp"
#include <process.h>
#include <iostream>
using namespace std;

int print_formula(Graph &mol)
{
	int counts[118] = { 0 }, size = mol.types.size();
    
	for (int i = 0; i < size; ++i)
	{
		int index = mol.types[i];
		if(index >= 0 && index < 118)
		    counts[index]++;
	}

	cout << "-f : molecule contains:" << endl;
	for (int i = 0; i < 118; ++i)
		if (counts[i] > 0)
			cout << p_table(i) << "[" << counts[i] << "]";
	cout << endl;
	return 0;
}

//12 до 4
vector <int> *buffer = NULL;

int oxidation_numbers(Graph &mol)
{
	int size = mol.edges.size();
	vector <int> o_nums(mol.nverts + 1);

	for (int j = 0; j < mol.nverts + 1; ++j)
		o_nums[j] = 0;

	for (int i = 0; i < size; ++i)
	{
		int id1, id2, t1, t2;

		id1 = mol.edges[i].id1;
		id2 = mol.edges[i].id2;//what id's are connected

		t1 = mol.types[id1];
		t2 = mol.types[id2];
	
		if ( n_table(t1) < n_table(t2) )
			o_nums[id2]--,	o_nums[id1]++;

		else if (n_table(t1) > n_table(t2) )
			o_nums[id2]++, o_nums[id1]--;
	}

	buffer = new vector <int>(100);
	buffer->resize(o_nums.size());

	if(buffer != NULL)
	{
      buffer->resize(o_nums.size());

	  for (int i = 0; i < (int)o_nums.size(); ++i)
		(*buffer)[i] = o_nums[i];
	}

	return 0;
}

int jmol(char *filename, int p_flag, char *path)
{
	if(!strncmp(path, "null", 4))
		path = "C://jml/jmol.jar";

	if (p_flag)
	{
		int ret;
		FILE *f = NULL;
		int n = buffer->size();
		
		fopen_s(&f, "script.spt", "w+");
    	
	    if (f == NULL)
			return (-1);

		char pattern_select[] = "select atomno=",  pattern_label[] = "label"; 

		char select_part[256] = { 0 }, label_part[256] = { 0 },
			id[12] = { 0 }, onum[12] = { 0 };

		for (int i = 0; i < (int)strlen(pattern_select); ++i)
			select_part[i] = pattern_select[i];
        
		for (int i = 0; i < (int)strlen(pattern_label); ++i)
			label_part[i] = pattern_label[i];

		for (int i = 0; i < n; ++i)
		{
			char script_line[536] = { 0 };
			int m = ((*buffer)[i] > 0) ? (*buffer)[i] : -(*buffer)[i];

			sprintf_s(id , 12, "%i"  , i + 1);//id
			sprintf_s(onum, 12, "%s%i", ((*buffer)[i] > 0) ? "+" : "-", m);

			strcat_s(script_line, 536, select_part);
			strcat_s(script_line, 536, id);
			strcat_s(script_line, 536, ";");
			strcat_s(script_line, 536, label_part);
			strcat_s(script_line, 536, " \"");
			strcat_s(script_line, 536, onum);
			strcat_s(script_line, 536, "\";");
		    
			cout << script_line << endl;
			fprintf(f, "%s\n", script_line);
		}
		fclose(f);
	
		ret = _spawnlp(P_WAIT, "java", "java", "-jar", path, filename , "-s", "script.spt");
		remove("script.spt");
		return ret;
	}
	else
		return _spawnlp(P_WAIT, "java", "java", "-jar", path, filename);
}






