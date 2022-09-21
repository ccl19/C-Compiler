#include <iostream>
#include "ast.hpp"
#include <fstream>

// int main(int argc, char* argv[]){
// 	int destination;
// 	Context program;
// 	const Node *ast = parseAST();
// 	//std::cout << "HERE" << std::endl;

// 	ast -> Compile(std::cout, program, destination);

// 	std::cout << std::endl;
// }


extern FILE *yyin;

int main(int argc, char *argv[]){
	std::ostream &dst(std::cout);
	std::string input_file = argv[2];
	std::cout << "INPUT:" << input_file << std::endl;
	std::string output_file = argv[4];
	std::cout << "OUTPUT:" << output_file << std::endl;
	std::ofstream output(output_file);

	if (input_file != "")
	{
		FILE *fh;
		if ((fh = fopen(input_file.c_str(), "r")))
		{
			yyin = fh;
		}
		else
		{
			std::cerr << "Error: input file \"" << input_file << "\" could not be opened." << std::endl;
			return 1;
		}
	}

	int destination = 0;
	Context program;
	const Node *ast = parseAST();
	ast -> Compile(output, program, destination);

}
