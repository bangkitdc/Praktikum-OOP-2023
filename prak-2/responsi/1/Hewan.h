#include <iostream>

using namespace std;

class Hewan {
	protected:
		string name;
	public:
		Hewan(string namaHewan) {
			this->name = namaHewan;
		}
		~Hewan() {
			cout << "Hewan mati " << this->name << endl;
		}
		virtual void print() {
			cout << "Hewan ini namanya " << this->name << endl;
		}
};

class Kucing : public Hewan {
	public:
		Kucing(string namaHewan) : Hewan(namaHewan) {}
		virtual ~Kucing() {
			cout << "Kucing mati " << this->name << endl;
		}
};

class Anjing : public Hewan {
	public:
		Anjing(string namaHewan) : Hewan(namaHewan) {}
		~Anjing() {
			cout << "Anjing mati " << this->name << endl;
		}
		virtual void print() {
			cout << "Anjing ini namanya " << this->name << endl;
		}
};

class KucingAnggora : public Kucing {
	protected:
		string owner;
	public:
		KucingAnggora(string namaHewan, string newOwner) : Kucing(namaHewan) {
			this->owner = newOwner;
		}
		~KucingAnggora() {
			cout << "Kucing anggora mati " << this->name << endl;
		}
		void print() {
			cout << "Kucing anggora ini namanya " << name << ". Pemiliknya adalah " << owner << endl;
		}
};

class AnjingBulldog : public Anjing {
	protected:
		string owner;
	public:
		AnjingBulldog(string namaHewan, string newOwner) : Anjing(namaHewan) {
			this->owner = newOwner;
		}
		~AnjingBulldog() {
			cout << "Anjing bulldog mati " << this->name << endl;
		}
		void print() {
			cout << "Anjing bulldog ini namanya " << name << ". Pemiliknya adalah " << owner << endl;
		}
};