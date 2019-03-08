// Justin Allen Smith
// CSC 2144 - Spring 2019
// 8, March 2019

// This program asks a user to input a new password
// then verifies that it meets the required criteria
// if it does meet criteria, program displays a success message
// if it does not meet criteria, program displays a message
// identifying what is wrong with the criteria

// This program does not deal with special characters or spaces.
// A user could input something like: "J    j1" which would be valid.

#include <iostream>
#include <string>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	string password = "";
	string lengthError = "Password must be at least 6 characters long.\n";
	string alphaError = "Password must contain at least one letter.\n";
	string numericError = "Password must contain at least one numeric digit.\n";
	string uppercaseError = "Password must contain at least one uppercase letter.\n";
	string lowercaseError = "Password must contain at least one lowercase letter.\n";

	bool lengthError_b = false, alphaError_b = true,
		numericError_b = true, uppercaseError_b = true, lowercaseError_b = true;

	// User should enter a new password
	cout << "Create a new password: ";
	getline(cin, password);
	// is the password at least 6 characters
	if (password.length() < 6)
		lengthError_b = true;
		// if no -> update errors
	for (auto i = password.cbegin(); i!=password.cend(); ++i)
	{
		// does password contain characters
		if (alphaError_b && isalpha((int)*i) != 0)
			// if no -> update errors
			alphaError_b = false;
		// does password contain at least one digit
		if (numericError_b && isdigit((int)*i) != 0)
			// if no -> update errors
			numericError_b = false;
		// does password contain at least one uppercase letter
		if (uppercaseError_b && isupper((int)*i))
			// if it is upper -> set flag
			uppercaseError_b = false;
		// does password contain at least one lowercase letter
		if (lowercaseError_b && islower((int)*i))
			// if it is lower -> set flag
			lowercaseError_b = false;
	}

	cout << endl;

	// if there were any errors
	if (lengthError_b)
		cout << lengthError;
	if (alphaError_b)
		cout << alphaError;
	if (numericError_b)
		cout << numericError;
	if (uppercaseError_b)
		cout << uppercaseError;
	if (lowercaseError_b)
		cout << lowercaseError;
	// otherwise output success message
	if (!lengthError_b && !alphaError_b && !numericError_b
		&& !uppercaseError_b && !lowercaseError_b)
		cout << "Success! Password created successfully!" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
