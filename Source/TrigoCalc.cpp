/* 
 - Mode 0 degree, 1 radian. 
 - Pi(π) = 3.14159265358979323846264338327950288419716. 
 - Rad to deg = (x*180)/π. 
 - Deg to rad = (x*π)/180. 
 - "-static-libgcc -static-libstdc++" flag for PC no GCC. 
*/ 

#include <iostream> 
#include <cstdlib>
#include <iomanip>

using namespace std; 
 
char choice(); 
int changeMode(int& mode); 
void displayMode(); 
int precision(int& prec); 
void help(int mode, int prec); 
long double input(); 
void calculator(int mode, int prec); 
double fact(int d); 
void menu(int mode, int prec); 
 
int main() 
{ 
	int mode = 0, prec = 9; 
	bool finish = false; 
	char choice; 
	
	do 
	{ 
		system("cls"); 
		cout << endl; 
		
		menu(mode, prec); 
		cin >> choice; 
		choice = toupper(choice); 
	
		switch (choice)
		{
			case 'M' :	changeMode(mode); 
						break; 
						
			case 'P' :	precision(prec);
						system("pause"); 
						break; 
						
			case 'U' :	calculator(mode, prec); 
						system("pause"); 
						break; 
						
			case 'H' :	help(mode, prec); 
						system("pause"); 
						break; 
						
			case 'E' :	cout << "  Thank you for using the calculator!"<< endl; 
						system("pause"); 
						finish = true; 
						break; 
						
			default  :  cout << "  Invalid option, please choose again" << endl;
						system("pause");
						break; 
		} 
			
	} while (!finish); 
	
	return 0;
} 
 
int changeMode(int& mode) 
{
	
	if (mode == 0)
		mode = 1; 
	else 
		mode = 0; 
	
	return mode; 
} 

void displayMode(int mode) 
{
	if (mode == 0) 
		cout << "Degree";
	else 
		cout << "Radian";
} 

int precision(int& prec) 
{
	cout << "  Current precision = " << prec << " decimal numbers." << endl; 
	bool correct = false; 
	
	do 
	{ 
		cout << "  Enter new precision -> "; 
		prec = input(); 
		
		if (prec >= 0) 
			correct = true; 
		else 
			cout << "  Please enter a positive number. " << endl; 
		
	} while (!correct); 
	
	return prec; 
}
 
void help(int mode, int prec) 
{ 
	cout << endl << " Help: " << endl; 
	cout << " - This calculator will help to find the sine and cosine of entered angle \"x\"." << endl; 
	cout << " - Mode of entered number can be switched between Degree or Radian by choosing \"M\". (Current: "; displayMode(mode); cout << ")" << endl; 
	cout << " - The decimal numbers can be changed by choosing \"P\". (Current: " << prec << " decimal points)" << endl; 
	cout << " - Start using the calculator by choosing \"U\"." << endl; 
	cout << " - After finished using the calculator, exit by pressing \"E\""<< endl; 
	cout << " - Reopen the help menu by choosing \"H\"" << endl << endl;
	cout << " Pi = 3.14159265358979323846264338327950288419716."<< endl << endl; 
} 

long double input()
{
	long double num; 
	
	while (!(cin >> num))
	{
		cin.clear(); 
		cin.ignore(999, '\n'); 
		cout << "Invalid input, please enter numbers -> "; 
	} 
	
	return num; 
}

void calculator(int mode, int prec) 
{
	long double x, befResult, pi = 3.14159265358979323846264338327950288419716, sinResult = 0, cosResult = 1; 
	
	cout << "  Angle value in "; displayMode(mode); cout <<", x = "; 
	x = input(); 
	
	if (mode == 0) 
		x = (x*pi) / 180; 

	int denoNum = 1, seq = 0; 
	long double z = x;
	cout << endl << "  Sine progress: " << endl; 
	
	do 
	{ 
		seq++; 
		befResult = sinResult; 
		sinResult = sinResult + (z/fact(denoNum)); 
		
		cout << "  Sequence " << seq << " = " << setprecision(prec) << fixed << sinResult << endl; 
		
		denoNum = denoNum + 2; 
		z = z*x*(-x); 
	} while (sinResult - befResult != 0);
	
	denoNum = 2; 
	seq = 0; 
	z = x*-x; 
	cout << endl << "  Cosine progress: " << endl; 
	
	do 
	{ 
		seq++; 
		befResult = cosResult; 
		cosResult = cosResult + (z/fact(denoNum)); 
		
		cout << "  Sequence " << seq << " = " << setprecision(prec) << fixed << cosResult << endl; 
		
		denoNum = denoNum + 2; 
		z = z*x*(-x); 
	} while (cosResult - befResult != 0); 
		
	cout << endl << "  Sin " << x << " rad = " << setprecision(prec) << fixed << sinResult << endl << "  Cos " << x << " rad = " << setprecision(prec) << fixed << cosResult << endl << endl; 
}

double fact(int d)
{
	double num = 1;
	
	for (; d > 0; d--) 
	{
		num = num * d;
	}
	
	return num; 
}

void menu(int mode, int prec) 
{
	cout << "         \\\\-=-=-=-==-=-=-=-//" << endl; 
	cout << "         | Trigo Calculator |" << endl; 
	cout << "         //-=-=-=-==-=-=-=-\\\\" << endl << endl; 
	cout << "  /----------------------========--\\" << endl; 
	cout << "  |  Calculator mode :  | "; displayMode(mode); cout << " | |\n"; 
	cout << "  +----------------------========--+" << endl; 
	cout << "  |  Options:                      |" << endl; 
	cout << "  |  M - Switch mode               |" << endl; 
	cout << "  |  P - Set precision ("; if (prec <10) cout << prec << ")         |" << endl; else if (prec >= 10 && prec < 100) cout << prec << ")        |" << endl; else cout << prec << ")       |" << endl;
	cout << "  |  U - Use calculator            |" << endl; 
	cout << "  +--------------------------------+" << endl; 
	cout << "  |  H: Help                       |" << endl; 
	cout << "  |  E: Exit                       |" << endl; 
	cout << "  \\--------------------------------/" << endl << endl; 
	cout << "     Choice -> "; 
} 