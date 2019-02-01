#include <iostream>

using namespace std;
enum choise { CREATE = 1, ERASE, ERASEALL, LIST, EXPORT, ANIMTE, ANIMTELIST, ERAESEANIM };
int enterChois();
void create(vector<shape *>&);
void list(const vector<shape *>&);
void erase(vector<shape *>&);
void createFile(vector<shape *>&,fstream &);
void animate(vector<shape *>&);
void animlist(vector<shape *>&);
void eraseanim(vector<shape *>&);
int main()
{
	int choice;
		fstream pic("pic.svg", ios::out);
		if (!pic) {
			cout << "file could not be open !!!";
			exit ( EXIT_FAILURE );
		}
		vector<shape *>eraseVector;
		vector<shape *>shape;
	return 0;
}
