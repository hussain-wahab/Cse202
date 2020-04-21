// Hussain Alabdrabalnabi
// Lab-04

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


class Code
	{

	public:

		Code(); 

		string decode(vector< string> message);
	private:

		vector<string> codewords;

		vector<char> alpha; 

		vector<char> alphacode(); 

		vector<string> morsecode(); 

		char decode(string c);
	};

	Code::Code()
	{
	alpha = alphacode();
	codewords = morsecode();
	}

	vector<string> Code::morsecode()
	{ 

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

	vector<char> Code::alphacode()
	{

	vector<char> temp;
	for (char c='A'; c<='Z'; c++)
	temp.push_back(c);
	temp.push_back(' ');
	temp.push_back('.');
	return temp;
	}

	char Code::decode(string c)
	{
	for(int i = 0; i < codewords.size(); i++)
	{
	if(codewords[i] == c)
	return alpha[i];
	}

	return ' '; 
	}

	string Code::decode(vector< string> message)
	{
	string str = "";

	for(int i = 0; i < message.size(); i++)
	{

		str += decode(message[i]); 
	}
	return str;
	}

	int main()
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

			codes.clear();
			}
		}
	}
