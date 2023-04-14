#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <fstream>

class	Sed {
	private :
		std::string		s1;
		std::string 	s2;
		std::ifstream	infile;
		std::ofstream	outfile;
	public :
		Sed(char **argv);
		~Sed();
		void	change(void);
};

#endif
