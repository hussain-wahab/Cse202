//Hussain Alabdrabalnabi
// Hw2

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Code
{
   public:
   Code();
   Code(vector<string> codewords);
   string encode(vector<char> message);
   string decode(vector<string> message);

   private:
   vector<string> codewords;
   vector<char> alpha;
   vector<char> alphacode();
   vector<string> morsecode();
   string encode(char x);
   char decode(string c);
   vector<string> code;

};

int main ()
{
   cout << "Enter a 0 to input a message in English, or enter a 1 to input a message in morse code." << endl;
   int userinput;
   cin >> userinput;


   cout << "Enter your message." << endl;
   cin.clear();
   cin.ignore(10000,'\n');

   if(userinput == 0)
    {
	string filename;
	cout << "Input File for Message with .txt Extension : ";
	cin >> filename; 
	ifstream ifs(filename.c_str());
	if(!ifs.is_open())
	{
		cout << "The file Can't be opened. " << filename << endl;
		return 1;
	}
	string code;
	vector<char> codes;
	Code encoder;
	while(ifs >> code)
	{
for ( int i =0 ; i < code.size() ; i ++ )
{
		codes.push_back(code[i]);
		if(code[i] == '.')
		{
			cout << "The encoded Message is =  " << encoder.encode(codes) << endl;
			//clear the vector for next message
			codes.clear();
		}
}
	}
   }
   /*{
       vector<char> usermessage;
       char x;

       cin.get(x);
       while(x != 'x')
       {
           usermessage.push_back(x);
           cin.get(x);
       }

       Code alphamessage;
       cout << "The encoded message is: " << alphamessage.encode(usermessage) << endl;
   }*/
   else if(userinput == 1)
   {
	string filename;
	cout << "Input File for Message with .txt Extension : ";
	cin >> filename; 
	ifstream ifs(filename.c_str());
	if(!ifs.is_open())
	{
		cout << "The file Can't be opened. " << filename << endl;
		return 1;
	}
	string code;
	vector<string> codes;
	Code decoder;
	while(ifs >> code)
	{
		codes.push_back(code);
		if(code == "x")
		{
			cout << "The Decoded Message is =  " << decoder.decode(codes) << endl;
			//clear the vector for next message
			codes.clear();
		}
	}
   }

}

Code::Code()
{

	alpha = alphacode();

	codewords = morsecode();
}

Code::Code(vector<string> codewords)
{
   this-> code = codewords;
}

vector<string>Code::morsecode()
{

   // This function returns a vector containing the morse code

	vector<string> temp(28);
	temp[0] =".-";
	temp[1] ="-...";
	temp[2] ="-.-.";
	temp[3] ="-..";
	temp[4] =".";
	temp[5] ="..-.";
	temp[6] ="--.";
	temp[7] ="....";
	temp[8] ="..";
	temp[9] =".---";
	temp[10] ="-.-";
	temp[11] =".-..";
	temp[12] ="--";
	temp[13] ="-.";
	temp[14] ="---";
	temp[15] =".--.";
	temp[16] ="--.--";
	temp[17] =".-.";
	temp[18] ="...";
	temp[19] ="-";
	temp[20] ="..-";
	temp[21] ="...-";
	temp[22] =".--";
	temp[23] ="-..-";
	temp[24] ="-.--";
	temp[25] ="--..";
	temp[26] =".......";
	temp[27] ="x";
	return temp;
}

vector<char>Code::alphacode()
{
// This returns a vector containing the alphabet a-z and " "

	vector<char> temp;

	for (char c='a'; c<='z'; c++)

	temp.push_back(c);

	temp.push_back(' ');

	temp.push_back('.');

	return temp;

}

string Code::decode(vector< string> message)
{
   string alphaword;
   char alphaletter;

   for (int i = 0; i < message.size(); i++)
   {
       alphaletter = decode(message[i]);
       alphaword = alphaword + alphaletter;
   }

   return alphaword;
}

char Code::decode(string c)
{
   for (int j = 0; j < codewords.size(); j++)
   {
       if (c == codewords[j])
       {
           return alpha[j];
       }
   }

   cout << "No letter found in decode function for: " << c << endl;
}

string Code::encode(vector<char> message)
{
   string morseletter;
   string morseword;

   for (int i = 0; i < message.size(); i++)
   {
       morseletter = this->encode(message[i]);
       morseword = morseword + morseletter + " ";

   }

   return morseword;
}

string Code::encode(char x)
{
   for (int i = 0; i < codewords.size(); i++)
   {
       if (x == alpha[i])
       {
           return codewords[i];
       }
   }

   cout << "No letter found in the encode function for: " << x << endl;
   return "";
}

