#!/bin/bash

# Variables
headerPath="header"
srcPath="src"

hppExtension=".hpp"
cppExtension=".cpp"

# Ask the user for a file name
echo "Enter the file name you want to create:"

# Get the file name from the user
read fileName

# File variables
hppFile="${fileName}${hppExtension}"
cppFile="${fileName}${cppExtension}"

# Ask the user for the type of preprocessor guard (#pragma once or #ifndef FILE_HPP)
echo -e "Which type preprocessor guard do you choose?\nType p for #pragma once\nType i for #ifndef FILE_HPP"

# Get the answer from the user
read guardType

# Check the answer and add correct preprocessor guard type
if [ ${guardType} = "p" ]
then
	# Add content to hpp file ( pragma guard )
	hppContent="#pragma once\n\nclass ${fileName}\n{\npublic:\n\t// Constructors\n\
			\t${fileName}();\n\n\t// Destruktor\n\t~${fileName}();\n\nprivate:\n\
			\t// Variables\n\t\n};"
elif [ ${guardType} = "i" ]
then
	# Add content to hpp file ( ifndef guard )
	hppContent="#ifndef ${fileName^^}_HPP\n#define ${fileName^^}_HPP\n\
			\nclass ${fileName}\n{\npublic:\n\t// Constructors\n\t${fileName}();\n\n\
			\t// Destruktor\n\t~${fileName}();\n\nprivate:\n\t// Variables\n\t\n};\
			\n\n#endif"
else
	# Invalid choose
	echo "Invalid option selected! Script ended."
	exit
fi

# Add content to cpp file
cppContent="#include \"${hppFile}\"\n\n${fileName}::${fileName}()\n{\n\
			\t// Empty body\n}\n\n${fileName}::~${fileName}()\n{\n\t// Empty body\n}"

# Create files
echo -e ${hppContent} >> "${headerPath}/${hppFile}"
echo -e ${cppContent} >> "${srcPath}/${cppFile}"