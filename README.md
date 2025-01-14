README
En Español
Descripción
Este repositorio contiene varios programas en C que implementan funcionalidades básicas para la gestión de tareas, edición de texto, gestión de inventarios, simulación bancaria, un servidor HTTP, un compresor de archivos, un analizador léxico y el juego de la vida de Conway. Los programas incluyen persistencia de datos mediante el uso de archivos de texto, lo que permite almacenar la información entre ejecuciones.

Programas
Servidor HTTP Simple
Un servidor HTTP básico que responde con páginas HTML estáticas. Puedes configurarlo para servir archivos HTML.

Compresor de Archivos
Un compresor de archivos utilizando el algoritmo de Huffman para comprimir y descomprimir archivos.

Analizador Léxico
Un programa que analiza un código fuente (como en C o Python) y reconoce tokens, identificadores, operadores, etc.

Juego de la Vida de Conway
Implementación del famoso autómata celular que simula el crecimiento y extinción de células en una cuadrícula.

Gestor de Tareas (To-Do List)
Permite crear, actualizar y eliminar tareas. Las tareas se almacenan en un archivo de texto llamado tasks.txt.

Mini Editor de Texto
Permite abrir, modificar y guardar archivos de texto. Puedes editar el contenido de un archivo y guardarlo de nuevo.

Sistema de Gestión de Inventario
Permite gestionar productos, sus precios y cantidades en un inventario. La información se guarda en un archivo de texto llamado inventory.txt.

Simulador de Banco
Permite crear cuentas bancarias, realizar depósitos y consultar saldos. Los datos de las cuentas se almacenan en un archivo de texto llamado bank_accounts.txt.

Requisitos
Un compilador de C (como GCC o Clang).
Sistema operativo basado en UNIX (Linux o macOS) o el uso de herramientas como MinGW, Cygwin o WSL en Windows.
Instrucciones
Compilar los programas:

Para compilar cada programa, usa el siguiente comando (suponiendo que el archivo de código fuente se llame programa.c):

bash
Copiar código
gcc -o programa programa.c
Ejecutar el programa:

Una vez compilado, ejecuta el programa con:

bash
Copiar código
./programa
Archivos de salida:

Los programas generarán archivos de texto como tasks.txt, inventory.txt o bank_accounts.txt, que contienen la información almacenada entre ejecuciones.

In English
Description
This repository contains several C programs that implement basic functionalities for task management, text editing, inventory management, banking simulation, a simple HTTP server, file compression, lexical analysis, and Conway's Game of Life. The programs include data persistence using text files, allowing information to be stored between executions.

Programs
Simple HTTP Server
A basic HTTP server that responds with static HTML pages. You can configure it to serve HTML files.

File Compressor
A file compressor using the Huffman algorithm to compress and decompress files.

Lexical Analyzer
A program that analyzes source code (such as in C or Python) and recognizes tokens, identifiers, operators, etc.

Conway's Game of Life
An implementation of the famous cellular automaton that simulates the growth and extinction of "cells" in a grid.

Task Manager (To-Do List)
Allows you to create, update, and delete tasks. The tasks are stored in a text file called tasks.txt.

Mini Text Editor
Allows you to open, modify, and save text files. You can edit the content of a file and save it back.

Inventory Management System
Allows you to manage products, their prices, and quantities in an inventory. The data is stored in a text file called inventory.txt.

Bank Simulator
Allows you to create bank accounts, make deposits, and check balances. Account data is stored in a text file called bank_accounts.txt.

Requirements
A C compiler (such as GCC or Clang).
A Unix-based operating system (Linux or macOS), or tools like MinGW, Cygwin, or WSL on Windows.
Instructions
Compile the programs:

To compile each program, use the following command (assuming the source file is called program.c):

bash
Copiar código
gcc -o program program.c
Run the program:

Once compiled, run the program with:

bash
Copiar código
./program
Output files:

The programs will generate text files like tasks.txt, inventory.txt, or bank_accounts.txt, which store the information between executions.
