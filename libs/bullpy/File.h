/**
 * @file File.h
 * @brief Simple file reading and writing library
 * @author neos300
 * @version 1.0
 * @date 2012-06-21
 */
#pragma once
//Simple file library.
#include <fstream>
#include <string>
#include <sstream>
//#include <windows.h>
typedef unsigned char BYTE;
/**
 * @brief Class for reading from files
 */
class inFile
{
    public:
        
	
	inFile();
	/**
	 * @brief Opens a file for reading
	 *
	 * @param filename
	 */
        void OpenFile(std::string filename);
	/**
	 * @brief Reads a block of bytes
	 *
	 * @param size The size of the block
	 *
	 * @return Pointer to the block
	 */
        char* ReadBlock(int size);
	/**
	 * @brief Reads a string from the file
	 *
	 * @return 
	 */
        std::string ReadString();
	/**
	 * @brief Reads a floating point number from the file.
	 *
	 * @return 
	 */
        float ReadFloat();
	/**
	 * @brief Reads a 32 bit interger from the file.
	 *
	 * @return 
	 */
        int ReadInt();
	/**
	 * @brief Reads a byte from the file
	 *
	 * @return 
	 */
        BYTE ReadByte();
	/**
	 * @brief Closes the file
	 */
        void Close();
    protected:
    private:
        std::ifstream* f;
};


/**
 * @brief A class for writing to files
 */
class outFile
{
    public:
        outFile();
	/**
	 * @brief Opens a file for writing
	 *
	 * @param filename
	 */
        void OpenFile(std::string filename);
	/**
	 * @brief Writes a block of bytes
	 *
	 * @param data Pointer to data block
	 */
        void WriteBlock(char* data);
	/**
	 * @brief Writes a string to a file, prefixed by it's length
	 *
	 * @param str
	 */
        void WriteString(std::string str);
	/**
	 * @brief Writes a floating point number to a file
	 *
	 * @param ff
	 */
        void WriteFloat(float ff);
	/**
	 * @brief Writes a 32 bit interger
	 *
	 * @param ff
	 */
        void WriteInt(int ff);
	/**
	 * @brief Writes a byte
	 *
	 * @param ff
	 */
        void WriteByte(BYTE ff);
	/**
	 * @brief Closes the file
	 */
        void Close();
    protected:
    private:
        std::ofstream* f;
};

