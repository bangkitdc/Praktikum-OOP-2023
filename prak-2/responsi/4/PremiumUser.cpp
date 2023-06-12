#include "PremiumUser.h"
#include <iostream>
#include <cstring>

using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char* name) : User(name) {
	num_of_music_downloaded = 0;
	active = true;
}
// cctor
PremiumUser::PremiumUser(const PremiumUser &other) : User(other.name)
{
    this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[5000];
    for (int i = 0; i < other.num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    this->num_of_music_downloaded = other.num_of_music_downloaded;
    this->active = other.active;
}
// implementasikan jika diperlukan, 
// jika tidak diperlukan, hapus cctor
// jika perlu diimplementasikan, print "Premium User Copied<endl>"

// dtor; implementasikan jika diperlukan
PremiumUser::~PremiumUser() {}
// jika tidak diperlukan, hapus dtor
// jika diperlukan
// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
// Contoh:
// Premium user A deleted

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh: 
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char* music) {
	if (active) {
		num_of_music_downloaded ++;

		cout << "Music Downloaded: " << music << endl;
	} else {
		cout << "Activate premium account to download music" << endl;
	}
}

void PremiumUser::inactivatePremium() {
	active = false;
}

void PremiumUser::activatePremium() {
	active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
	return num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const {
	return active;
}

// #include "PremiumUser.h"
// #include <iostream>
// #include <cstring>
// using namespace std;
// //
// PremiumUser::PremiumUser(char *n) : User(n)
// {
//     this->num_of_music_downloaded = 0;
//     this->active = true;
// }

// PremiumUser::PremiumUser(const PremiumUser &other) : User(other.name)
// {
//     this->num_of_favourite_music = other.num_of_favourite_music;
//     this->music_list = new char *[5000];
//     for (int i = 0; i < other.num_of_favourite_music; i++)
//     {
//         this->music_list[i] = new char[strlen(other.music_list[i])];
//         strcpy(this->music_list[i], other.music_list[i]);
//     }
//     this->num_of_music_downloaded = other.num_of_music_downloaded;
//     this->active = other.active;
// }

// PremiumUser::~PremiumUser()
// {
// }

// void PremiumUser::downloadMusic(char *musik)
// {
//     if (this->active)
//     {
//         this->num_of_music_downloaded++;
//         cout << "Music Downloaded: " << musik << endl;
//     }
//     else
//     {
//         cout << "Activate premium account to download music" << endl;
//     }
// }

// void PremiumUser::inactivatePremium()
// {
//     this->active = false;
// }

// void PremiumUser::activatePremium()
// {
//     this->active = true;
// }

// int PremiumUser::getNumOfMusicDownloaded() const
// {
//     return this->num_of_music_downloaded;
// }

// bool PremiumUser::getPremiumStatus() const
// {
//     return this->active;
// }