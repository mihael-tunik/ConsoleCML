#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <vector>
#include <map>


using namespace std;
using namespace boost;
using namespace boost::property_tree;


class edge
{

    public:
	
	int id1;
	int id2;

	edge(int _id1, int _id2)
	{
		id1 = _id1;
		id2 = _id2;
	}

};

typedef struct _graph
{
	int                  nverts;      // atoms in molecule
	map    <string, int> ids   ;      // string CML atom identifier <-> simple integer identifier for single atom
	map    <int   , int> types ;      // id - type
	vector <edge>        edges ;      // vector of edges

}Graph;

int    parse(char *infile, Graph &molecule_struct);
int    print_formula(Graph &mol);
int    oxidation_numbers(Graph &mol);
int    jmol(char * filename, int p_flag, char *path);
char * p_table(int index);

