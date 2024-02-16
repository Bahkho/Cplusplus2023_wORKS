#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

// Custom exception for file-related errors
struct FileException : public std::runtime_error {
    explicit FileException(const std::string& message) : std::runtime_error(message) {}
};

bool isValidFileName(const std::string& fileName) {
    // A reasonable maximum path length based on common filesystem limitations
    const size_t maxPathSize = 4096;

    return fileName.size() <= maxPathSize && !fileName.empty() && fileName.back() != '.' &&
    // Regex to check if the file name contains any invalid characters
           fileName.find_first_of("/\\:*?\"<>|") == std::string::npos;
}

//REFERENCE FROM OPENAI
//https://chat.openai.com/c/3d718784-97fe-4059-b6dd-e26f2aba322

// Custom function to replace all occurrences of a substring in a string
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

int main() {
    try {
        //REFERENCE FROM W3SCHOOLS
        //https://www.w3schools.com/cpp/cpp_user_input.asp

        // Get the input file name from the user
        std::cout << "Enter the C++ source file name: ";
        std::string inputFileName;
        std::getline(std::cin, inputFileName);

        // Validate the input file name
        if (!isValidFileName(inputFileName)) {
            throw std::invalid_argument("Invalid file name. Please provide a valid file name.");
        }

        // Construct the absolute path
        std::string inputFilePath = fs::current_path().string() + "/" + inputFileName;

        // Output file name based on input file name
        std::string outputFileName = inputFileName + ".html";

        // Open the input file
        std::ifstream inputFile(inputFilePath);
        if (!inputFile.is_open()) {
            throw FileException("Error opening input file: " + inputFilePath);
        }

        // Read the content of the input file into a string
        std::stringstream buffer;
        buffer << "<PRE>\n"; // Add <PRE> tag at the beginning

        char ch;
        while (inputFile.get(ch)) {
            if (ch == '<') {
                buffer << "&lt;";
            } else if (ch == '>') {
                buffer << "&gt;";
            } else if (ch == '&') {
                buffer << "&amp;";
            } else if (ch == '"') {
                buffer << "&quot;";
            } else if (ch == '\'') {
                buffer << "&apos;";
            } else {
                buffer << ch;
            }
        }

        buffer << "\n</PRE>"; // Add </PRE> tag at the end

        // Close the input file
        inputFile.close();

        // Open the output file
        std::ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            throw FileException("Error opening output file: " + outputFileName);
        }

        // Write the modified content to the output file
        outputFile << buffer.str();

        // Close the output file
        outputFile.close();

        std::cout << "HTML file generated successfully: " << outputFileName << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const FileException& e) {
        std::cerr << "File error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
