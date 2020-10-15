
//Encrypts an input file and writes the encrypted contents to an output file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



 int main()
 {

	 using std::cout; 
	 using std::endl;

	 // When the program begins, the statement "Encryption Level 1" should be displayed.
	 cout << "Encryption Level 1 \n\n\n";

	 //	When the program opens the input file, the statement "Opening input file...." should be displayed.
	 cout << "Opening Input File....\n\n\n";

	 ifstream inputFile;
	 inputFile.open("October20.txt");          // Open the file to be encrypted.
	 
	 
	 
	
	 // When the program begins reading through the input file encrypting the contents, the statement "Encrypting...." should be displayed.
	 cout << "Encrypting....\n\n\n";

	 ofstream encryptedFile;
	 encryptedFile.open("EncryptedOct20.txt");		// Opens the output file for editing


	 string line;				// Will hold a line from the inputFile
	 int ascii;					// Will store the ascii value for each character in each line
	 char newChar;				// Will store the encrypted character for the new string
	 string newString = "";		// Will hold the encoded line from the inputFile
	 int i;						// Used for increment in for loop

	 if (inputFile.is_open())
	 {
		 while (getline(inputFile, line))
		 {
			 for (i = 0; i < line.length(); i++)
			 {
				 // Get the original character's ASCII code
				 ascii = line[i];

		

			  // Spaces, digits, special characters, and punctuation are not encrypted and are written to the output file as is and in the correct sequence.
			  //	32 to 47 is special characters
			  //	Examples:  Space (32) and period (46)
			  //	48 to 57 is digits
			  //	58 to 64 is more special characters
			  //	91 to 96 is more special characters
			  			
				 if (31 < ascii && ascii < 65)
				 {
					 newChar = ascii;		//Spaces, digits, special characters - leave as-is.
				 }
				 else if (90 < ascii && ascii < 97)
				 {
					 newChar = ascii;		//Spaces, digits, special characters - leave as-is.
				 }

				 
			 // Every letter is encrypted by moving 3 letters forward.  (A = D, z = c, etc...)
			 //		Special Cases to handle:
			 //		x to a, y to b, z to c		(if ascii 120, 121, 122 ...)						
			 //		X to A, Y to B, Z to C		(if ascii 88, 89, 90 ...)

				 else if (ascii == 120)		// x to a
				 {
					 newChar = 97;
				 }

				 else if (ascii == 121)		// y to b
				 {
					 newChar = 98;
				 }

				 else if (ascii == 122)		// z to c
				 {
					 newChar = 99;
				 }


				 else if (ascii == 88)		// X to A
				 {
					 newChar = 65;
				 }

				 else if (ascii == 89)		// Y to B
				 {
					 newChar = 66;
				 }

				 else if (ascii == 90)		// Z to C
				 {
					 newChar = 67;
				 }



				 // Every uppercase letter in the input file is uppercase in the output file
				 //		65 to 90 is uppercase


				 // Every lowercase letter in the input file is lowercase in the output file
				 //		97 to 122 is lowercase

				 // Get the new replacement character if not digit, special char, space, or XYZ/xyz.
				 else if (64 < ascii && ascii < 88)
				 {
					 newChar = ascii + 3;
				 }

				 else if (96 < ascii && ascii < 120)
				 {
					 newChar = ascii + 3;
				 }

				 
				 
				 else 
				 {

				 }

				 // Add the character to the end of the new string
				 newString += newChar;
			 }


		 encryptedFile << newString << '\n';		// Write the new string to encrypted file.

		 newString = "";		// Reset newString to empty for next line to be read

		 }
		 encryptedFile.close();
		 inputFile.close();			// Close the file streams.
	 }

	 else cout << "Unable to open file";


	 // When the program closes the input and output files, the statement "Encryption complete." should be displayed.
	 cout << "Encryption Complete.\n\n\n";


	 cout << "End of Program.\n\n\n\n";


	 system("pause");
	 return 0;
 }

