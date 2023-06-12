#include <cstring>
#include "User.h"
#include <iostream>

using namespace std;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* string) {
	this->name = new char[strlen(string)];
	strcpy(this->name, string);
	this->num_of_favourite_music = 0;
	this->music_list = new char *[5000];

	User::n_user ++;
}

// cctor
User::User(const User& other) {
	this->name = new char[strlen(other.getName())];
	strcpy(this->name, other.getName());

	this->num_of_favourite_music = other.getNumOfFavouriteMusic();

	this->music_list = new char*[5000];
	for (int i = 0; i < other.getNumOfFavouriteMusic(); i ++) {
		this->music_list[i] = new char[strlen(other.music_list[i])];

		strcpy(this->music_list[i], other.music_list[i]);
	}

	User::n_user ++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User()  {
	cout << "User " << this->name << " deleted" << endl;
	delete [] this->name;

	// delete dalemnya dlu
	for (int i = 0; i < this->getNumOfFavouriteMusic(); i ++) {
		delete[] this->music_list[i];
	}

	// delete luar
	delete[] music_list;

	User::n_user --;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* string) {
	this->num_of_favourite_music ++;
	this->music_list[this->num_of_favourite_music - 1] = new char[strlen(string)];
	strcpy(this->music_list[this->num_of_favourite_music - 1], string);
}

void User::deleteFavouriteMusic(char* string) {
	if (this->num_of_favourite_music > 0) {
		int deleted = -999;
		for (int i = 0; i < this->num_of_favourite_music; i ++) {
			if (strcmp(this->music_list[i], string) == 0) {
				deleted = i;
				break;
			}
		}

		if (deleted != -999) {
			this->num_of_favourite_music --;
			for (int j = deleted; j < this->num_of_favourite_music; j ++) {
				strcpy(this->music_list[j], this->music_list[j + 1]);
			}
		}
	}
}

void User::setName(char* string) {
	strcpy(this->name, string); // tai
}

char* User::getName() const {
	return this->name;
}

int User::getNumOfFavouriteMusic() const {
	return this->num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
	if (this->getNumOfFavouriteMusic() > 0) {
		for (int i = 0; i < this->num_of_favourite_music; i++) {
            cout << (i + 1) << ". " << this->music_list[i] << endl;
        }
	} else {
		cout << "No music in your favourite list" << endl;
	}
}

int User::getNumOfUser() {
	return User::n_user;
}

// #include "User.h"
// #include <iostream>
// #include <cstring>
// using namespace std;
// //
// int User::n_user = 0;
// User::User(char *n)
// {
//     this->name = new char[strlen(n)];
//     strcpy(this->name, n);
//     this->num_of_favourite_music = 0;
//     this->music_list = new char *[5000];
//     n_user++;
// }

// User::User(const User &other)
// {
//     this->name = new char[strlen(other.getName())];
//     strcpy(this->name, other.getName());
//     this->num_of_favourite_music = other.num_of_favourite_music;
//     this->music_list = new char *[5000];
//     for (int i = 0; i < other.num_of_favourite_music; i++)
//     {
//         this->music_list[i] = new char[strlen(other.music_list[i])];
//         strcpy(this->music_list[i], other.music_list[i]);
//     }
//     n_user++;
// }

// User::~User()
// {
//     cout << "User " << this->name << " deleted\n";
// }

// void User::addFavouriteMusic(char *musik)
// {
//     this->num_of_favourite_music++;
//     this->music_list[this->num_of_favourite_music - 1] = new char[strlen(musik)];
//     strcpy(this->music_list[this->num_of_favourite_music - 1], musik);
// }

// void User::deleteFavouriteMusic(char *musik)
// {
//     if (this->num_of_favourite_music > 0)
//     {
//         int deleted = -1;
//         for (int i = 0; i < this->num_of_favourite_music; i++)
//         {
//             if (strcmp(this->music_list[i], musik) == 0)
//             {
//                 deleted = i;
//                 break;
//             }
//         }
//         if (deleted != -1 and deleted < this->num_of_favourite_music)
//         {
//             this->num_of_favourite_music--;
//             for (int j = deleted; j < this->num_of_favourite_music; j++)
//             {
//                 strcpy(this->music_list[j], this->music_list[j + 1]);
//             }
//         }
//     }
// }

// void User::setName(char *name)
// {
//     strcpy(this->name, name);
// }

// char *User::getName() const
// {
//     return this->name;
// }

// int User::getNumOfFavouriteMusic() const
// {
//     return this->num_of_favourite_music;
// }

// void User::viewMusicList() const
// {
//     if (this->num_of_favourite_music > 0)
//     {
//         for (int i = 0; i < this->num_of_favourite_music; i++)
//         {
//             cout << (i + 1) << ". " << this->music_list[i] << endl;
//         }
//     }
//     else
//     {
//         cout << "No music in your favourite list" << endl;
//     }
// }

// int User::getNumOfUser()
// {
//     return User::n_user;
// }