#include "ArtistUser.h"
#include <iostream>
#include <cstring>

using namespace std;

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* username) : User(username) {
	num_of_music_uploaded = 0;
	uploaded_music_list = new char*[255];
	num_of_artist ++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& other) : User(other.getName()) {
	this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[5000];
    for (int i = 0; i < other.num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    this->num_of_music_uploaded = other.num_of_music_uploaded;
    this->uploaded_music_list = new char *[5000];
    for (int i = 0; i < other.num_of_music_uploaded; i++)
    {
        this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    cout << "Artist user " << name << " deleted" << endl;

	for (int i = 0; i < num_of_music_uploaded; i++) {
        delete[] uploaded_music_list[i];
    }
    delete[] uploaded_music_list;

    num_of_artist--;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* music) {
	num_of_music_uploaded ++;
	this->uploaded_music_list[this->num_of_music_uploaded - 1] = new char[strlen(music)];
	strcpy(this->uploaded_music_list[this->num_of_music_uploaded - 1], music);
}

void ArtistUser::deleteUploadedMusic(char* string) {
	if (this->num_of_music_uploaded > 0) {
		int deleted = -999;
		for (int i = 0; i < this->num_of_music_uploaded; i ++) {
			if (strcmp(this->music_list[i], string) == 0) {
				deleted = i;
				break;
			}
		}

		if (deleted != -999) {
			this->num_of_music_uploaded --;
			for (int j = deleted; j < this->num_of_music_uploaded; j ++) {
				strcpy(this->music_list[j], this->music_list[j + 1]);
			}
		}
	}
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {
	if (getNumOfMusicUploaded() != 0) {
		for (int i = 0; i < getNumOfMusicUploaded(); i ++) {
			cout << i + 1 << ". " << uploaded_music_list[i] << endl;
		}
	} else {
		cout << "No music uploaded" << endl;
	}
}

int ArtistUser::getNumOfMusicUploaded() const {
    return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}

// #include "ArtistUser.h"
// #include <iostream>
// #include <cstring>
// using namespace std;

// int ArtistUser::num_of_artist = 0;
// ArtistUser::ArtistUser(char *n) : User(n)
// {
//     this->num_of_music_uploaded = 0;
//     this->uploaded_music_list = new char *[255];
//     num_of_artist++;
// }

// ArtistUser::ArtistUser(const ArtistUser &other) : User(other.getName())
// {
//     this->num_of_favourite_music = other.num_of_favourite_music;
//     this->music_list = new char *[5000];
//     for (int i = 0; i < other.num_of_favourite_music; i++)
//     {
//         this->music_list[i] = new char[strlen(other.music_list[i])];
//         strcpy(this->music_list[i], other.music_list[i]);
//     }
//     this->num_of_music_uploaded = other.num_of_music_uploaded;
//     this->uploaded_music_list = new char *[5000];
//     for (int i = 0; i < other.num_of_music_uploaded; i++)
//     {
//         this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i])];
//         strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
//     }
//     num_of_artist++;
// }

// ArtistUser::~ArtistUser()
// {
//     cout << "Artist user " << this->name << " deleted\n";
// }

// void ArtistUser::uploadMusic(char *musik)
// {
//     this->num_of_music_uploaded++;
//     this->uploaded_music_list[this->num_of_music_uploaded - 1] = new char[strlen(musik)];
//     strcpy(this->uploaded_music_list[this->num_of_music_uploaded - 1], musik);
// }

// void ArtistUser::deleteUploadedMusic(char *musik)
// {
//     if (this->num_of_music_uploaded > 0)
//     {
//         int deleted = -1;
//         for (int i = 0; i < this->num_of_music_uploaded; i++)
//         {
//             if (strcmp(this->uploaded_music_list[i], musik) == 0)
//             {
//                 deleted = i;
//                 break;
//             }
//         }
//         if (deleted != -1 and deleted < this->num_of_music_uploaded)
//         {
//             this->num_of_music_uploaded--;
//             for (int j = deleted; j < this->num_of_music_uploaded; j++)
//             {
//                 strcpy(this->uploaded_music_list[j], this->uploaded_music_list[j + 1]);
//             }
//         }
//     }
// }

// void ArtistUser::viewUploadedMusicList() const
// {
//     if (this->num_of_music_uploaded > 0)
//     {
//         for (int i = 0; i < this->num_of_music_uploaded; i++)
//         {
//             cout << (i + 1) << ". " << this->uploaded_music_list[i] << endl;
//         }
//     }
//     else
//     {
//         cout << "No music uploaded" << endl;
//     }
// }

// int ArtistUser::getNumOfMusicUploaded() const
// {
//     return this->num_of_music_uploaded;
// }

// int ArtistUser::getNumOfArtist()
// {
//     return ArtistUser::num_of_artist;
// }