#include<iostream>
#include<fstream>
#include<unistd.h>

int main()
{	
	std::string name ;
	std::string data = "";
	std::cout << "Enter the file name:\n";
	std::cin >> name;
	
	int flag = 0;
	std::ifstream file;

	//opening the file
	file.open(name);
	
	if(file){
		// file is open
		//std::cout << "The file is open\n";
		//Read the file
		while(file >> data){
			//std::cout << data << std::endl;
			if(flag == 1){
				if(data == "{}"){
					std::cout << "ANALYSIS:\nIf statement is empty\n";
				}else{
					std::cout << "ANALYSIS:\nNot an empty if statement\n";
				}
				flag = 0;
			}
			if(data == "if(1)")
				flag = 1;
		}
	}else{
		// file is not open
		std::cout << "The file is not openable\n";
	}

	//closing the file
	file.close();

	return 0;
}
