//Include Statements
#include <iostream> //For text output
#include <fstream> //For file reading
#include <string> //For strings

using namespace std; //Namespace definition

//Button Classes
class button //Base button class
{
public:
	button() //Initializer; Needs to be here to properly compile or else it throws a fit and says that gui test in main is uninitialized :)
	{
		;
	}

	virtual void describe()
	{
		cout << "Button" << endl;
	}
};

class button90 : public button //90s Extended version of button
{
private:
	string description = "90s Button";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class button00 : public button //00s extended version of button
{
private:
	string description = "00s Button";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class button10 : public button //10s extended version of button
{
private:
	string description = "10s Button";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class button22 : public button //22s extended version of button
{
private:
	string description = "22s Button";
public:
	void describe()
	{
		cout << description << endl;
	}
};

//Textbox Classes
class textbox //Base textbox class
{
public:
	textbox() //Initializer; Needs to be here to properly compile or else it throws a fit and says that gui test in main is uninitialized :)
	{
		;
	}

	virtual void describe()
	{
		cout << "Textbox" << endl;
	}
};

class textbox90 : public textbox //90s extended version of textbox
{
private:
	string description = "90s Textbox";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class textbox00 : public textbox //00s extended version of textbox
{
private:
	string description = "00s Textbox";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class textbox10 : public textbox //10s extended version of textbox
{
private:
	string description = "10s Textbox";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class textbox22 : public textbox //22s extended version of textbox
{
private:
	string description = "22s Textbox";
public:
	void describe()
	{
		cout << description << endl;
	}
};

//Panel Classes
class panel //Base panel class
{
public:
	panel() //Initializer; Needs to be here to properly compile or else it throws a fit and says that gui test in main is uninitialized :)
	{
		;
	}

	virtual void describe()
	{
		cout << "Panel" << endl;
	}
};

class panel90 : public panel //90s extended version of panel
{
private:
	string description = "90s panel";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class panel00 : public panel //00s extended version of panel
{
private:
	string description = "00s panel";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class panel10 : public panel //10s extended version of panel
{
private:
	string description = "10s panel";
public:
	void describe()
	{
		cout << description << endl;
	}
};

class panel22 : public panel //22s extended version of panel
{
private:
	string description = "22s panel";
public:
	void describe()
	{
		cout << description << endl;
	}
};

//GUI Class
class gui
{
	//Create abstracted GUI parts
	button* guiButton;
	panel* guiPanel;
	textbox* guiTextbox;

public:
	gui()  //Initializer; Needs to be here to properly compile or else it throws a fit and says that gui test in main is uninitialized :)
	{
		guiButton = new button();
		guiPanel = new panel();
		guiTextbox = new textbox();
	}

	void createButton(button* x) //Create a button based on the one requested
	{
		guiButton = x;
	}

	void createPanel(panel* x) //Create a panel based on the one requested
	{
		guiPanel = x;
	}

	void createTextBox(textbox* x) //Create a textbox based on the one requested
	{
		guiTextbox = x;
	}

	void displayGUI() //Display the GUI
	{
		guiButton->describe();
		guiPanel->describe();
		guiTextbox->describe();
	}
};

//GUI Factory
class guiFactory
{
private:
	gui x; //Constructable GUI

public:
	gui create90s() //Create a 90s version GUI
	{
		//Create 90s button
		button* b = new button90;
		x.createButton(b);
		//delete b;

		//Create 90s panel
		panel* p = new panel90;
		x.createPanel(p);
		//delete p;

		//Create 90s textbox
		textbox* t = new textbox90;
		x.createTextBox(t);
		//delete t;

		return x; //Return the constructed GUI
	}

	gui create00s() //Create a 00s version GUI
	{
		//Create 00s button
		button* b = new button00;
		x.createButton(b);
		//delete b;

		//Create 90s panel
		panel* p = new panel00;
		x.createPanel(p);
		//delete p;

		//Create 90s textbox
		textbox* t = new textbox00;
		x.createTextBox(t);
		//delete t;

		return x; //Return the constructed GUI
	}

	gui create10s() //Create a 10s version GUI
	{
		//Create 10s button
		button* b = new button10;
		x.createButton(b);
		//delete b;

		//Create 10s panel
		panel* p = new panel10;
		x.createPanel(p);
		//delete p;

		//Create 10s textbox
		textbox* t = new textbox10;
		x.createTextBox(t);
		//delete t;

		return x; //Return the constructed GUI
	}

	gui create22s() //Create a 22s version GUI
	{
		//Create 22s button
		button* b = new button22;
		x.createButton(b);
		//delete b;

		//Create 22s panel
		panel* p = new panel22;
		x.createPanel(p);
		//delete p;

		//Create 22s textbox
		textbox* t = new textbox22;
		x.createTextBox(t);
		//delete t;

		return x; //Return the constructed GUI
	}
};

//GUI Tester Class
class testGUI
{
private:
	guiFactory guiMaker;
	static int iteration90; //Counter for how many times a 90s GUI has been tested
	static int iteration00; //Counter for how many times a 00s GUI has been tested
	static int iteration10; //Counter for how many times a 10s GUI has been tested
	static int iteration22; //Counter for how many times a 22s GUI has been tested

public:
	void testInterface(int version, gui x) //Build and test the interface
	{
		//Determine which version to test
		switch (version)
		{
		case 90:
			if (iteration90 < 2) //If it has not been tested twice already
			{
				x = guiMaker.create90s(); //Create GUI 90s
				x.displayGUI(); //display GUI 90s
				cout << endl; //formatting
			}
			else //If it's been tested twice already
			{
				cout << "WARNING: Number of test cases executed for version 90 already = 2. Skipping..." << endl << endl;
			}

			iteration90++; //Increase test counter
			break;
		case 00:
			if (iteration00 < 2) //If it has not been tested twice already
			{
				x = guiMaker.create00s(); //Create GUI 00s
				x.displayGUI(); //display GUI 90s
				cout << endl; //formatting
			}
			else //If it's been tested twice already
			{
				cout << "WARNING: Number of test cases executed for version 00 already = 2. Skipping..." << endl << endl;
			}

			iteration00++; //Increase test counter
			break;
		case 10:
			if (iteration10 < 2) //If it has not been tested twice already
			{
				x = guiMaker.create10s(); //Create GUI 10s
				x.displayGUI(); //display GUI 10s
				cout << endl; //formatting
			}
			else //If it's been tested twice already
			{
				cout << "WARNING: Number of test cases executed for version 10 already = 2. Skipping..." << endl << endl;
			}

			iteration10++; //Increase test counter
			break;
		case 22:
			if (iteration22 < 2) //If it has not been tested twice already
			{
				x = guiMaker.create22s(); //Create GUI 22s
				x.displayGUI(); //display GUI 22s
				cout << endl; //formatting
			}
			else //If it's been tested twice already
			{
				cout << "WARNING: Number of test cases executed for version 22 already = 2. Skipping..." << endl << endl;
			}

			iteration22++; //Increase test counter
			break;
		default: //If for some reason something in the file went wrong
			cout << "Invalid test case detected. Skipping..." << endl << endl;
		}
	}
};

//Static Class Variable initialization
int testGUI::iteration90 = 0;
int testGUI::iteration00 = 0;
int testGUI::iteration10 = 0;
int testGUI::iteration22 = 0;

int main()
{
	//Define variables
	ifstream testCase; //Get test cases
	string version; //String to hold version
	string year; //String to get year
	int i_year; //Int to get year
	gui test; //Create test GUI
	testGUI interface; //Create test interface

	testCase.open("testcase.txt"); //Open the test case file based on the name "testcase.txt"

	while (!testCase.eof()) //Read the entire file, and then break out
	{
		testCase >> version; //Get version
		year = version.substr(4,5); //Capture year of version
		i_year = stoi(year); //Convert year to integer for switch case
		interface.testInterface(i_year, test); //run testcase
	}

	testCase.close(); //Close the file

	//Exit the program gracefully
	system("pause");
	return 0;
}