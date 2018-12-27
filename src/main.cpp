#include <iostream>

#include <t9spelling.hpp>

int main (int argc, char** argv) {
	std::cout
		<< "  _______ ___     _____            _ _ _             " 				<< std::endl
		<< " |__   __/ _ \\   / ____|          | | (_)            " 			<< std::endl
		<< "    | | | (_) | | (___  _ __   ___| | |_ _ __   __ _ " 				<< std::endl
		<< "    | |  \\__, |  \\___ \\| '_ \\ / _ \\ | | | '_ \\ / _` |" 	<< std::endl
		<< "    | |    / /   ____) | |_) |  __/ | | | | | | (_| |" 				<< std::endl
		<< "    |_|   /_/   |_____/| .__/ \\___|_|_|_|_| |_|\\__, |" 			<< std::endl
		<< "                       | |                      __/ |" 				<< std::endl
		<< "                       |_|                     |___/ " 				<< std::endl
		<< std::endl;

	if (argc < 2) {
		std::cout
			<< "No input string." << std::endl
			<< "  Example: t9-spelling \"hello\"" << std::endl
			<< std::endl;

		return 0;
	}

	try {
		auto result = t9spelling::getDigitsSequenceForString<char>(std::string(argv[1]));
		std::cout
			<< "Input string is \"" << argv[1] << "\"" << std::endl
			<< "Result T9 sequence: "
			<< result << std::endl;
	} catch (const t9spelling::exception& exception) {
		std::cout
			<< "Oh no! We catch exception: " << std::endl
			<< "  \"" << exception.what() << "\"." << std::endl
			<< "Input string is \"" << argv[1] << "\"" << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
