cmake_minimum_required(VERSION 3.5)
project (Mathamatical)
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
add_executable(Mathamatical 
	main.cpp
	Calculate.cpp
	CSVReader.cpp
)
