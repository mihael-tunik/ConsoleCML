#include "parse.hpp"

int get_code(const char *str)
{
	for (int i = 0; i < 118; ++i)
		if (!strncmp(str, p_table(i), strlen(p_table(i)) ))
			return i;
	return -1;
}

int parse(char *infile, Graph &molecule_struct)
{
	ptree tree;

	try{
		read_xml(infile, tree);
	}
	catch (...)
	{
		printf("Exception! Reading XML failed...");
		return -1;
	}

	
	BOOST_FOREACH(ptree::value_type const& v, tree.get_child("molecule"))
	{
		if (v.first == "atomArray") {
			
			ptree subtree = (ptree)v.second;
			int id = 0;

			BOOST_FOREACH(boost::property_tree::ptree::value_type &vs, subtree)
			{
				if (vs.first == "atom") {	

					ptree empty;
					const ptree & attributes = vs.second.get_child("<xmlattr>", empty);
					string get;

					BOOST_FOREACH(const ptree::value_type &vss, attributes)
					{
						if (!strncmp(vss.first.data(), "id", 2))
						{
							get = (vss.second.data());
							molecule_struct.ids.insert( pair<string, int>(get, id));
							molecule_struct.nverts = id;
						}
						else if (!strncmp(vss.first.data(), "elementType", 11))
						{
							int code;
							get = (vss.second.data());

							if (  -1 == (code = get_code(get.c_str()))  )
								return -1;

							molecule_struct.types.insert(pair <int, int>(id, code));
							++id;
						}
					}
				}
			}
		}
		else if (v.first == "bondArray")
		{
			ptree subtree = (ptree)v.second;

			BOOST_FOREACH(boost::property_tree::ptree::value_type &vs, subtree)
			{
				if (vs.first == "bond")
				{
					ptree empty;
					const ptree & attributes = vs.second.get_child("<xmlattr>", empty);

					BOOST_FOREACH(const ptree::value_type &vss, attributes)
					{
						if (!strncmp(vss.first.data(), "atomRefs", 8))
						{
							int id1, id2;
							string get = (vss.second.data());
							const char *s = get.c_str();
							char *token = strtok((char *)s, (const char *)" ");

							string arg1, arg2;

							arg1 = token;
				    		token = strtok(NULL, (const char *)" ");
			     			arg2 = token;
						
							//map
							if ( molecule_struct.ids.find(arg1) != molecule_struct.ids.end() )
						        id1 = molecule_struct.ids[arg1];

							if (molecule_struct.ids.find(arg2) != molecule_struct.ids.end())
						    	id2 = molecule_struct.ids[arg2];

							molecule_struct.edges.push_back(edge(id1, id2));
						}
					}
				}
			}
		}
	}

	return 0;
}
