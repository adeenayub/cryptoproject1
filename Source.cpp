
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <hash_map>
#include <time.h>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#define CHARSIZE 27

using namespace std;
using namespace stdext;

char charlist[] = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int charfreq[] = { 19, 7, 1, 2, 4, 10, 2, 2, 5, 6, 1, 1, 3, 2, 6, 6, 2, 1, 5, 5, 7, 2, 1, 2, 1, 2, 1 };
vector<string> plaintexts;
vector<string> ciphertext;
//vector<int> ciphertext;
//hash_map<char,int> unit_frequency_char_position_lists;
vector<hash_map<char,int>> unit_frequency_char_position_lists;
hash_map<char, int> key_chars;
hash_map<char, int> key;
hash_map<char, int> offset;
typedef pair<char, int> MAP_PAIR;
typedef pair<int, int> MAP_IPAIR;

//Generate character-frequency map and assign frequencies to each character
void Generatefrequencymap()
{
	
	for (int i = 0; i < CHARSIZE; i++)
	{
		key_chars[charlist[i]] = charfreq[i];
	}
}

void PopulatePlaintexts()
{
	plaintexts.push_back("dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu");
	plaintexts.push_back("rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma");
	plaintexts.push_back("trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine");
	plaintexts.push_back("dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines");
	plaintexts.push_back("mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba");
}
	
//Generate Character Map for characters with unit frequency
void Generatemapforunitfrequency()
{
	char charry[] = { 'b','j','k','q','x','z' };
	for (int l = 0; l < plaintexts.size(); l++)
	{
		for (int j = 0; j < 6 ; j++)
		{
			for (int i = 0; i < plaintexts[l].length(); i++)
			{
				if (plaintexts[l][i] == charry[j])
				{
					if (unit_frequency_char_position_lists[l].empty())
					{
						unit_frequency_char_position_lists[l] = {};
						//cout << "Unit 1 is "<< unit_frequency_char_position_lists[l]<<endl;
					}

					//iterator to see if an element is present or no
					/*hash_map<char,int>::iterator it = unit_frequency_char_position_lists[l].find(unit_frequency_char_position_lists[l][charry[j]]);
					int  b3;
					if (it != unit_frequency_char_position_lists[l].end())
					{
						//element found;
						b3 = it->second;
					} */
					if (unit_frequency_char_position_lists[l][charry[j]] == NULL)
					//if (getValue(unit_frequency_char_position_lists[l][charry[j]],&i))
					{
						unit_frequency_char_position_lists[l][charry[j]] = {};
						//cout << "Unit 2 is " << unit_frequency_char_position_lists[l][charry] << endl;
						//cout << "I am here Alhamdulillah";
					}
					//unit_frequency_char_position_lists[l].insert(MAP_PAIR(charry[j],i)); 
					unit_frequency_char_position_lists[l][charry[j]] = i;

					//unit_frequency_char_position_lists[l].push_back(i);
		
				} 
					
					
			}
		}
	}
}

//Generating the random key for ciphertext mapping
/*void GenerateKey()
{
	srand(time(NULL));
	for (int i = 0; i < CHARSIZE; i++)
	{
		for (int j = 1; j < key_chars[charlist[i]]; j++)
		{
			if (key[charlist[i]] == NULL)
			{
				key[charlist[i]] = {};
				key.insert(MAP_PAIR(charlist[i],rand()%106));
			}
		}
	}
} */


void PopulateCiphertext()
{
	string mycipher;
	cout << "Enter the ciphertext";
	getline(cin, mycipher);
	stringstream ss(mycipher);
	string i;
	while (ss >> i)
	{
		ciphertext.push_back(i);
		if (ss.peek() == ',')
		{
			ss.ignore();
		}
	}

	for (int j = 0; j < ciphertext.size(); j++)
	{
		cout << "The ciphertext is\n "<< ciphertext[j] << " ";
	} 

	/*
	//Made this function to read the ciphertext from a file. Because entering 500 characters is really tiring.
	string myline;
	ifstream myfile("cipher.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, myline))
		{
			//cout << myline << '\n';
			ciphertext.push_back(myline);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

*/
}
void DecryptCiphertext()

{
	vector<hash_map<char,int>> current_list;
	
	int right_plaintext_index = -1;
	for (int i = 0; i < unit_frequency_char_position_lists.size(); i++)
	{
		current_list.push_back(unit_frequency_char_position_lists[i]);
		//current_list.push_back(unit_frequency_char_position_lists);
		//cout<<"print unit frequency "<< unit_frequency_char_position_lists[i]<<endl;
		//cout << "print unit frequency's size " << unit_frequency_char_position_lists.size()<<endl;
		//current_list[i]= unit_frequency_char_position_lists[i];
		for (int j = 0; j < current_list.size(); j++)
		{
			
				//vector<int> arr;
			vector<string> arr;
			for (int k = 0; k < j; k++)
			{
				arr.push_back(ciphertext[k]);
			}
			
			if (arr.size() == 1)
			{
				//cout << "array size is "<< arr.size();
				right_plaintext_index = 1;
			}
			
			
		}

	}
	if (right_plaintext_index < 0)
	{
		cout << "Could not decode ciphertext";
	}
	else
	{
		cout << "My plaintext guess is:"<<endl << plaintexts[right_plaintext_index];
	}
}

int main()
{
	
	Generatefrequencymap();
	PopulatePlaintexts();
	Generatemapforunitfrequency();
	//GenerateKey(); //I guess we don't need this since its part of the encrypt function
	PopulateCiphertext();
	DecryptCiphertext();
	cout << "Alhamdulillah";
	system("pause");
	return 0;
}