// Where ever you see a capital Alphabet there is a word in output.txt 
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>
using namespace std;
string input[10];
char output[15][15];
void Insert(string text, int key)
{
	if (key == 0)
	{
		for (int i = 0, j = 0; i < text.size() && j < text.size(); i++, j++)
		{
			output[i][j] = text[i];
		}
	}
	if (key == 1)
	{
		int k = 0;
		for (int i = 14; k < text.size(); k++, i--)
		{
			output[i][0] = text[k];
		}
	}
	if (key == 2)
	{
		int k = 0;
		for (int i = 14 - text.size(); k < text.size(); k++, i++)
		{
			output[0][i] = text[k];
		}
	}
	if (key == 3)
	{
		int k = 0;
		for (int i = 0; k < text.size(); k++, i++)
		{
			output[i][14] = text[k];
		}
	}
	if (key == 4)
	{
		int k = 0;
		for (int i = 15 - text.size(); k < text.size(); k++, i++)
		{
			output[12][i] = text[k];
		}
	}
	if (key == 5)
	{
		int k = 0;
		for (int i = 14; k < text.size(); k++, i--)
		{
			output[14][i] = text[k];
		}
	}
	if (key == 6)
	{
		int k = 0;
		for (int i = 7; k < text.size(); k++, i++)
		{
			output[i][7] = text[k];
		}
	}
	if (key == 7)
	{
		int k = 0;
		for (int i = 14; k < text.size(); k++, i--)
		{
			output[6][i] = text[k];
		}
	}
	if (key == 9)
	{
		int k = 0;
		for (int i = 0; k < text.size(); k++, i++)
		{
			output[4][i] = text[k];
		}
	}
}



//First we will write 8 different function in order to search the word entered by the user. 

//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// take the word string to be searched and searches it horizontally from left to right in the grid
//	and writes the starting and ending indices in the "output.txt" file.
//-------------------------------------------------------------------------------------------------------------
int HorizontalLeft_to_right(ofstream& output, string word, int row, int col, char Arr[][100])
{
	int a = 0;
	int t = 0;

	for (int i = 0; i <= row; i++)
	{
		int j = 0;
		while (j <= col)
		{
			t = j;

			while (Arr[i][t] == word[a] && word[a] != '\0')
			{
				t++;
				a++;
				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << i << " , " << (j - 1) + word.size() << "}" << endl;
					return 0;

				}

			}
			a = 0;
			j++;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------------------------------------
// Desc : take the word string to be searched and searches it horizontally from right to left in the grid
//		and writes the starting and ending indices in the "output.txt" file.
//-------------------------------------------------------------------------------------------------------------
int HorizontalRight_to_Left(ofstream& output, string word, int row, int  col, char Arr[][100])
{
	int a = 0;
	int	t = 0;

	for (int i = 0; i <= row; i++)
	{
		int j = col - 1;
		while (j >= 0)
		{
			t = j;
			while (Arr[i][t] == word[a] && word[a] != '\0')
			{
				t--;
				a++;
				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << i << " ," << j - word.size() + 1 << "}" << endl;
					return 0;
				}
			}
			a = 0;
			j--;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// takes the word string to be searched and searches it vertically from Top to bottom in the entire grid
// and writes the starting and ending indices in the "output.txt" file.
//-------------------------------------------------------------------------------------------------------------
int VerticalTop_to_bottom(ofstream& output, string word, int row, int col, char Arr[][100])
{
	int a = 0;
	int	t = 0;
	for (int j = 0; j <= col; j++)
	{
		int i = 0;
		while (i <= row)
		{
			t = i;
			while (Arr[t][j] == word[a] && word[a] != '\0')
			{
				t++;
				a++;
				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << i + word.size() - 1 << " ," << j << "}" << endl;
					return 0;
				}
			}
			a = 0;
			i++;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// takes the word string to be searched and searches it vertically from bottom to top in the entire grid
// and writes the starting and ending indices in the "output.txt" file.
//-------------------------------------------------------------------------------------------------------------

int VerticalBottom_to_Top(ofstream& output, string word, int row, int  col, char Arr[][100])
{
	int a = 0;
	int t = 0;

	for (int j = 0; j < col - 1; j++)
	{
		int i = row - 1;
		while (i >= 0)
		{
			t = i;
			while (Arr[t][j] == word[a] && word[a] != '\0')
			{
				t--;
				a++;
				if (word[a] == '\0')
				{
					output << "{" << i << " ," << j << "} ";
					output << "{" << i - word.size() + 1 << " ," << j << "}" << endl;
					return 0;
				}
			}
			a = 0;
			i--;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------------------------------------
//Description of the function : 
// Takes the word and searches it in a diagonal from TopLeft to bottom right in the entire grid 
// and writes the indices in the "output.txt" file
//-------------------------------------------------------------------------------------------------------------
int Diagonally_TopLeft_to_BottomRight(ofstream& output, string word, int col, int  row, char Arr[][100])
{
	int a = 0;
	int last_r = 0;
	int last_c = 0;
	for (int i = 0; i <= row; i++)
	{
		int j = 0;
		while (j < col - 1)
		{
			last_r = i;
			last_c = j;
			while (Arr[last_r][last_c] == word[a] && word[a] != '\0')
			{
				last_r++;
				last_c++;
				a++;
				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << last_r - 1 << " ," << last_c - 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
			j++;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// Takes the word and searches it in a diagonal from Bottom right to Top Left in the entire grid 
// and writes the indices in the "output.txt" file
//-------------------------------------------------------------------------------------------------------------
int Diagonally_Bottomright_to_TopLeft(ofstream& output, string word, int col, int  row, char Arr[][100])

{
	int a = 0;
	int last_r = 0;
	int last_c = 0;
	for (int i = row - 1; i > 0; i--)
	{
		int j = col - 1;
		while (j > 0)
		{
			last_r = i;
			last_c = j;
			while (Arr[last_r][last_c] == word[a] && word[a] != '\0')
			{
				last_r--;
				last_c--;
				a++;
				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << last_r + 1 << " ," << last_c + 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
			j--;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// Takes the word and searches it in a diagonal from top right to bottom left in the entire grid and also finds 
// the indices of the first and the last alphabet of the word and writes it in the "output.txt" file
//-------------------------------------------------------------------------------------------------------------
int Diagonally_TopRight_to_BottomLeft(ofstream& output, string word, int col, int  row, char Arr[][100])
{

	int a = 0;
	int last_r = 0;
	int last_c = 0;
	for (int i = 0; i <= row; i++)
	{
		int j = col - 1;
		while (j > 0)
		{
			last_r = i;
			last_c = j;
			while (Arr[last_r][last_c] == word[a] && word[a] != '\0')
			{

				last_r++;
				last_c--;
				a++;

				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "} ";
					output << "{" << last_r - 1 << " ," << last_c + 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
			j--;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// Takes the word and searches it in a diagonal from bottom left to top right in the entire grid and also finds 
// the indices of the first and the last alphabet of the word and writes it in the "output.txt" file
//-------------------------------------------------------------------------------------------------------------
int Diagonally_BottomLeft_to_TopRight(ofstream& output, string word, int col, int  row, char Arr[][100])
{
	int a = 0;
	int last_r = 0;
	int last_c = 0;
	for (int i = row - 1; i > 0; i--)
	{
		int j = 0;
		while (j < col - 1)
		{
			last_r = i;
			last_c = j;
			while (Arr[last_r][last_c] == word[a] && word[a] != '\0')
			{

				last_r--;
				last_c++;
				a++;

				if (word[a] == '\0')
				{

					output << "{" << i << " ," << j << "}";
					output << "{" << last_r + 1 << " , " << last_c - 1 << "} " << endl;
					return 0;
				}
			}
			a = 0;
			j++;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------------------------------------
// Description of the function : 
// Calls all the searching condition functions to search in all 8 conditions and stores their returning 
// values to find if the word exists in the grid or not. 
//-------------------------------------------------------------------------------------------------------------

void Word_Find(ofstream& output, char Grid[][100], string wordsearch, int rows, int cols)
{

	int Left_to_Right = 0;		//from horizontal left to right
	int	Right_to_Left = 0;		//from horizontal right to left
	int Top_to_Bottom = 0;		//from vertical top to bottom
	int Bottom_to_Top = 0;		//from vertical bottom to top
	int Diagonal_BR_to_TL = 0;  //Diagonal bottom right to top left
	int Diagonal_TL_to_BR = 0;		//Diagonal top left to bottom right
	int Diagonal_BL_to_TR = 0;		//Diagonal bottom left to top right
	int Diagonal_TR_to_BL = 0;		//Diagonal top right to bottom left

	// Now we will pass these variables to each function in order to find the word.
	Left_to_Right = HorizontalLeft_to_right(output, wordsearch, rows, cols, Grid);
	Right_to_Left = HorizontalRight_to_Left(output, wordsearch, rows, cols, Grid);
	Top_to_Bottom = VerticalTop_to_bottom(output, wordsearch, rows, cols, Grid);
	Bottom_to_Top = VerticalBottom_to_Top(output, wordsearch, rows, cols, Grid);

	Diagonal_BR_to_TL = Diagonally_Bottomright_to_TopLeft(output, wordsearch, cols, rows, Grid); //Diagonal bottom Right to top left
	Diagonal_TL_to_BR = Diagonally_TopLeft_to_BottomRight(output, wordsearch, cols, rows, Grid);  //Diagonal top left to bottom right
	Diagonal_BL_to_TR = Diagonally_BottomLeft_to_TopRight(output, wordsearch, cols, rows, Grid);  //Diagonal bottom left to top right
	Diagonal_TR_to_BL = Diagonally_TopRight_to_BottomLeft(output, wordsearch, cols, rows, Grid);  //Diagonal top right to bottom left

	// If the word doesnot exist in the given grid then we will use the following conditions
	// and will display "NOT FOUND" in the output.txt file.
	//if the above condition fulfills and returns -1 it means that the word was not in the
	//grid,if the word would have been in the grid its starting and ending index 
	//would have been printed

	if (Left_to_Right == -1 && Right_to_Left == -1 && Top_to_Bottom == -1 && Bottom_to_Top == -1
		&& Diagonal_BR_to_TL == -1 && Diagonal_TL_to_BR == -1 && Diagonal_BL_to_TR == -1 && Diagonal_TR_to_BL == -1)
	{
		output << "NOT FOUND" << endl;
	}


}

//---------------------------------------------------------------------------------------------
// Description of the function :
// This function takes a pointer char array and the size and then converts it into a string 
// finally return the string
//----------------------------------------------------------------------------------------------
string convertToString(char* ch, int size)
{
	string s = "";
	for (int i = 0; i < size; i++)
	{
		s = s + ch[i];
	}
	return s;
}

//----------------------------------------------------------------------------------------------------------------
// Description of the function :
// This function will read the data entered in the input text file,ask the user to enter to enter the number of
// test cases he/she wants to test and then he/she will enters the words to search them in the grid.In the end 
// function will create the output.txt file and then show the output of the indices of the first and the 
// last alphabet of the word.
//----------------------------------------------------------------------------------------------------------------

void ReadData(ifstream& read, ofstream& write, int ROWS, int COLS)
{
	int n = 0;
	char grid[100][100];		//creating a grid in which we will read data from input file.
	string wordsearch;

	read >> ROWS;
	read >> COLS;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			read >> grid[i][j];
	}

	//Displaying no of rows and coloumns separated by a space
	cout << ROWS << " " << COLS << endl;

	//asking from the user on console for the number of words he wants to find and then user
	//also has to write the number of alphabets in that word
	//after that user have to write the word which he wants to find in th grid. 
	cout << "Enter the number of Test cases : ";
	cin >> n;	//variable for the number of test cases
	int s = 0;	//holds the size of alphabets in a single word
	char* arr = new char[50];
	for (int i = 1; i <= n; i++)
	{
		//Asking user for the lenght of each word.
		cout << "Enter the size of your " << i << " word : ";
		cin >> s;
		cout << "Enter the word \n";
		for (int i = 0; i < s; i++)
		{
			cin >> arr[i];
		}
		wordsearch = convertToString(arr, s);
		Word_Find(write, grid, wordsearch, ROWS, COLS);
	}
	delete[] arr;
}

void CreateGrid(ifstream& in, ofstream &Output)
{

	fstream file;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			output[i][j] = '0';
		}
	}
	//getline(file, input);
	string temp;
	int i = 0;
	while (getline(in, input[i++])) {}

	for (int i = 0; i < 10; i++)
	{
		Insert(input[i], i);
	}

	srand(time(0));
	random_device rd;
	uniform_int_distribution<int> dist('a', 'z'); /* create disribution */

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (output[i][j] == '0')
			{
				output[i][j] = dist(rd);
			}
		}

	}
	
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			Output << output[i][j] << " ";
		}
		Output << endl;
	}


	/*for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	*/
}

int main()
{
	//CREATING MENU 
	cout << "//****************|| MENUE ||***************//" << endl;
	cout << "||                                                                                                        ||" << endl;
	cout << "|| 1. Create Grid(c).                                                                                     ||" << endl;
	cout << "|| 2. Search Words From Grid(S).                                                                          ||" << endl;
	cout << "|| 3. Quit(Q).                                                                                            ||" << endl;
	cout << "||                                                                                                        ||" << endl;
	cout << "//************************************//" << endl;

	// ASKING THE USER TO ENTER THE INPUT
	cout << " Enter the options : " << endl;
	char a;
	cin >> a;
	//APPLYING THE CONDITION THAT IF USER ENTERED WRONG INPUT THEN PRINT INVALID INPUT
	if (a != 'C' && a != 'c' && a != 'S' && a != 's' && a != 'Q' && a != 'q') {

		cout << " Invalid Option!!" << endl;
	}

	while (a != 'Q' && a != 'q') 
	{
		//IF USER ENTER OPTION C THEN CREATION OF GRID SHOULD BE FORMED
		if (a == 'c' || a == 'C') 
		{

			//ASKING THE USER TO ENTER THE NAME OF FILE WHER INPUT IS STORED
			string Input;
			cout << "Enter the name of the file from which you want data\n";
			cin >> Input;
			ifstream in((Input), ios::in);
			string Output;
			//ASKING THE USER TO NAME THE OUTPUT GRID
			cout << "Enter the name of the file you want to put Data in\n";
			cin >> Output;
			ofstream file1(Output);
			//CALLING FUNCTION WHCH WAS CREATED FOR THE FORMATION OF GRID

			if (!file1.is_open())
			{
				cout << "Wrong file name\n";
			}
			else
			{
				CreateGrid(in, file1);
			}
			

		}

		if (a == 'S' || a == 's') 
		{
			int ROWS = 0;
			int COLS = 0;
			string INPUT;
			cout << "Enter the name of the file you want data from\n";
			// ASKING THE USER TO ENTER THE NAME OF FILE WHER INPUT IS STORED
			cin >> INPUT;
			ifstream file2(INPUT);
			string OUTPUT;
			cout << "Enter the name of the file You want to store data\n";
			//ASKING THE USER TO NAME THE OUTPUT GRID
			cin >> OUTPUT;
			ofstream file3(OUTPUT);

			if (!file2.is_open())
			{
				cout << "File not opening";
			}
			else
			{
				ReadData(file2, file3, ROWS, COLS);
			}

		}

		//DECLAIRING THAT OPERATION IS ENDED AFTER PERFORMING EACH OPTION FROM THE MENU
		cout << endl;
		cout << "***************|| OPERATION DONE ||*****************" << endl << endl;
		//ASKING USER THE OPTION UNTIL USER ENTER Q IN ORDER TO TERMINATE THE FUNCTION
		cout << " Enter Your Option : ";
		cin >> a;

	
	}


	

	

	/* {
		//APPLYING THE CONDITION FOR TERMINAL OF LOOP UNTIL USER ENTER OR PRESS Q
		while (a != 'Q' && a != 'q') {
			//IF USER ENTER OPTION C THEN CREATION OF GRID SHOULD BE FORMED
			if (a == 'c' || a == 'C') {
				//ASKING THE USER TO ENTER THE NAME OF FILE WHER INPUT IS STORED
				cout << " Enter the name of file where input is stored : ";
				string k;
				cin >> k;
				//ASKING THE USER TO ENTER THE NUMBER OF WORDS
				cout << " Enter the numbers of words stored in file :  ";
				int n = 0;
				cin >> n;
				//ASKING THE USER TO ENTER THE NUMBER OF ROWS
				cout << " Enter the number of rows : ";
				int r = 0;
				cin >> r;
				//ASKING THE USER TO ENTER THE NUMBER OF COLUMNS
				cout << " Enter the number of coloumns : ";
				int c = 0;
				cin >> c;
				//ASKING THE USER TO NAME THE OUTPUT GRID
				cout << " Enter the name of output grid : ";
				string o;
				cin >> o;
				//DECLARING FUNCTION WHCH WAS CREATED FOR THE FORMATION OF GRID
				Create_Grid(r, c, n, k, o);
			}
			// IF USER ENTER S THEN WORD SEARCH SHOULD BE PERFORMED
			if (a == 'S' || a == 's') {
				//ASKING THE USER TO ENTER THE NAME OF FILE WHERE GRID ID STORED
				cout << " Enter the name of file : ";
				string File;
				cin >> File;
				//CRAETING THE INPUT FILE TO READ THE WORDS FROM THE GRID
				ifstream input(File);
				//READING THE DATA FROM THE GRID
				char A[18][19];
				for (int i = 0; i < 18; i++) {
					for (int j = 0; j < 19; j++) {
						input >> A[i][j];
					}
				}

				//ASKING THE USER TO ENTER THE NAME OF FILE WHERE WORDS ARE STORED TO BE SEARCHED
				cout << " Enter the name of file where words are stored : ";
				string words;
				cin >> words;
				//ASKING THE USER TO ENTER THE NUMBER OF ROWS
				cout << " Enter the number of rows : ";
				int rows = 0;
				cin >> rows;
				//ASKING THE USER TO ENTER THE NUMBER OF COLUMNS
				cout << " Enter the number of coloumns : ";
				int coloumns;
				cin >> coloumns;
				//CREATING THE STRING TO COLLECT THE WORDS FROM THE FILE
				string n[20];

				ifstream file(words);
				//CRAETING THE LOOP TO INTAKE THE WORDS FROM THE FILE
				for (int i = 0; i < 20; i++) {

					getline(file, n[i]);
				}

				//ASKING THE USER TO ENTER THE NAME OF FILE WHERE OUTPUT SHOULD BE STORED
				cout << " Enter the file name where input should be stored : ";
				string t;
				cin >> t;
				//PRINTING THE DESIRE INDEXES
				cout << " Indexes are as follows : " << endl;

				//CRAETING THE LOOP CONSIDERING ALL THE WORDS IN THE FILE
				for (int we = 0; we < 20; we++) {

					n[we];
					//CREATING THE CHAR TYPE VARIABLE TO STORE THE FIRST ALPHABET OF THE WORD
					char c;
					string k;
					k = n[we];

					//STORING THE FIRST ALPHABET
					c = n[we][0];
					//CREATING LOOP TO TRANSFER THE INDEXES OF FIRST LETTER OF THE WORD IN FUNCTIONS
					for (int i = 0; i < rows; i++) {

						for (int j = 0; j < coloumns; j++) {

							if (A[i][j] == c) {
								//CALLING ALL THE CONDITION INORDER TO SEARCH THE WORD
								Left_Right(i, j, k, A, t);
								Right_Left(i, j, k, A, t);
								TOP_BOTTOM(i, j, k, A, t);
								Bottom_Top(i, j, k, A, t);
								TOP_BOTTOM_Diagonal(i, j, k, A, t);
								Bottom_Top_Diagonal(i, j, k, A, t);
								TOP_BOTTOM_Diagonal_Left(i, j, k, A, t);
								Bottom_Top_Diagonal_Left(i, j, k, A, t);

							}

						}
					}

				}


			}
			//DECLAIRING THAT OPERATIPON IS ENDED AFTER PERFORMING EACH OPTION FROM THE MENUE
			cout << endl;
			cout << "***************|| OPERATION DONE ||*****************" << endl << endl;
			//ASKING USER THE OPRION UNTIL USER ENTER Q INORDER TO TERMINATE THE FUNCTION
			cout << " Enter Your Option : ";
			cin >> a;
		}
	}

	
	system("pause");
	return 0;
	*/

}