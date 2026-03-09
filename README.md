# file-organizer-cpp
Program that automatically organizes files into folders based on their extension.

Features
- Detects file types
- Creates folders automatically
- Moves files into categorized folders

- ## How to Use

1. Compile the program using a C++ compiler.

Example with g++:

g++ main.cpp -o organizer

2. Run the program.

Linux / Mac:
./organizer

Windows:
organizer.exe

3. When the program starts, enter the path of the folder you want to organize.

Example:

Ingrese la ruta de la carpeta:
C:\Users\USER\Downloads

4. The program will automatically:

- Detect file types
- Create folders if they do not exist
- Move files into categorized folders

Example result:

Downloads/
│
├── Imagenes
├── Videos
├── Documentos
├── Comprimidos
└── Otros
