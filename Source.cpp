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
		while  ((choice = enterChois()) != 9)
	{
		switch (choice)
		{
		case CREATE:
			create(shape);
			break;
		case ERASE:
			erase(shape);
			break;
		case ERASEALL:
			shape = eraseVector;
			break;
		case LIST:
			list(shape);
			break;
		case EXPORT:
			createFile(shape, pic);
			break;
		case ANIMTE:
			animate(shape);
			break;
		case ANIMTELIST:
			animlist(shape);
			break;
		case ERAESEANIM:
			eraseanim(shape);
			break;
		default:
			cout << "the number that you enter wrong plz try again" << endl;
		}
	}
	for (int i = 0; i < shape.size(); i++)
		delete shape[i];
	pic.close();
	return 0;
	return 0;
}
