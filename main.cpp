//
// Simulator for UIC 1.0, a very simple computer language.
// UIC 1.0 has 10 memory locations, an accumulator, and only
// supports integers, basic I/O, and arithmetic operations.
//
// Initial version written by
//   Prof. Hummel, U. of Illinois Chicago, Fall 2020
//   Project 01: solution
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // isspace

using namespace std;

string nextToken(istream& infile);  // defined in "token.cpp"


//
// readMemory
//
// Given an operand such as "M0", returns the contents of that
// memory location.  If the operand is not a memory location, 
// it is assumed to be an integer literal in which case that 
// value is converted to an integer and returned.
//
int readMemory(string operand, int M0, int M1, int M2, int M3,
   int M4, int M5, int M6, int M7, int M8, int M9)
{
   if (operand == "M0")
      return M0;
   else if (operand == "M1")
      return M1;
   else if (operand == "M2")
      return M2;
   else if (operand == "M3")
      return M3;
   else if (operand == "M4")
      return M4;
   else if (operand == "M5")
      return M5;
   else if (operand == "M6")
      return M6;
   else if (operand == "M7")
      return M7;
   else if (operand == "M8")
      return M8;
   else if (operand == "M9")
      return M9;
   else  // assume it's an integer literal, convert and return:
   {
      return stoi(operand);
   }
}

//
// writeMemory
//
//
// Given an operand such as "M0" and a new value, stores that value 
// into the appropriate memory location (overwriting the current value).
//
void writeMemory(string operand, int value, int& M0, int& M1, int& M2, int& M3,
   int& M4, int& M5, int& M6, int& M7, int& M8, int& M9)
{
   if (operand == "M0")
      M0 = value;
   else if (operand == "M1")
      M1 = value;
   else if (operand == "M2")
      M2 = value;
   else if (operand == "M3")
      M3 = value;
   else if (operand == "M4")
      M4 = value;
   else if (operand == "M5")
      M5 = value;
   else if (operand == "M6")
      M6 = value;
   else if (operand == "M7")
      M7 = value;
   else if (operand == "M8")
      M8 = value;
   else if (operand == "M9")
      M9 = value;
   else
   {
      cout << "**Error in writeMemory: unexpected operand '" << operand << "'" << endl;
      return;
   }
}


//
// main:
//
int main()
{
   string filename;
   cout << "Filename> ";
   cin >> filename;

   //
   // open the program file:
   //
   ifstream infile(filename);

   if (!infile.good())
   {
      cout << "**Error: unable to open input file '" << filename << "'." << endl;
      return 0;
   }

   //
   // read the contents of the file and execute each instruction 
   // one by one:
   //
   string instruction, operand;

   int ACC, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9;  // our memory:

   instruction = nextToken(infile);

   while (instruction != "")
   {
      if (instruction == "in_i")
      {
         cin >> ACC;
      }
      else if (instruction == "out_i")
      {
         cout << ACC;
      }
      else if (instruction == "out_s")
      {
         operand = nextToken(infile);
         cout << operand;
      }
      else if (instruction == "add_i")
      {
         operand = nextToken(infile);

         ACC = ACC + readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "sub_i")
      {
         operand = nextToken(infile);

         ACC = ACC - readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "mult_i")
      {
         operand = nextToken(infile);

         ACC = ACC * readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "div_i")
      {
         operand = nextToken(infile);

         ACC = ACC / readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "mod_i")
      {
         operand = nextToken(infile);

         ACC = ACC % readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "load_i")
      {
         operand = nextToken(infile);

         ACC = readMemory(operand, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "store_i")
      {
         operand = nextToken(infile);

         writeMemory(operand, ACC, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9);
      }
      else if (instruction == "clear")
      {
         M0 = 0;  // clear memory to 0:
         M1 = 0;
         M2 = 0;
         M3 = 0;
         M4 = 0;
         M5 = 0;
         M6 = 0;
         M7 = 0;
         M8 = 0;
         M9 = 0;
      }
      else if (instruction == "end")
      {
         break;
      }
      else
      {
         cout << "**Error: unknown instruction '" << instruction << "'." << endl;
      }

      instruction = nextToken(infile);
   }

   //
   // done
   //
   return 0;
}


//
// nextToken
//
// Returns the next token in the input stream; returns the empty
// string "" if there is no more input (i.e. end of stream).
// Comments (i.e. REM ...) are discarded by this function, and 
// never returned.
//
string nextToken(istream& stream)
{
   char  c;
   string token = "";

   while (token == "")
   {
      // skip initial whitespace:
      stream.get(c);
      while (!stream.eof() && isspace(c))
      {
         stream.get(c);
      }

      // did we reach end of file?  If so, there's no token:
      if (stream.eof())
      {
         return "";
      }

      if (c == '"')  // a string literal, loop until end of string:
      {
         stream.get(c);
         while (!stream.eof() && c != '"')
         {
            if (c == '\\')  // escape char?  Then read next done
            {
               stream.get(c);

               if (c == 'n')
                  c = '\n';
               else if (c == 't')
                  c = '\t';
               else if (c == 'f')
                  c = '\f';
               else if (c == 'r')
                  c = '\r';
               else
                  token += '\\';  // not sure what it is, so leave alone:
            }

            token += c;
            stream.get(c);
         }
      }
      else  // we have a word or numeric literal:
      {
         token += c;  // append that first char

         // now append remaining chars up until next whitespace:
         stream.get(c);
         while (!stream.eof() && !isspace(c))
         {
            token += c;
            stream.get(c);
         }
      }

      //
      // was the token REM?  If so, this denotes a comment, so discard 
      // rest of line and try again:
      //
      if (token == "REM")
      {
         //
         // we want to discard the rest of the line, except when
         // REM already comes at the end of the line (in which case
         // we do nothing):
         //
         if (c == '\n' || c == '\r')  // REM @ end of line, do nothing
         {
            // nothing
         }
         else
         {
            getline(stream, token);  // discard rest of line:
         }

         token = "";  // try again:
      }
   }//while

   //
   // done, we have a token to return:
   //
   return token;
}
