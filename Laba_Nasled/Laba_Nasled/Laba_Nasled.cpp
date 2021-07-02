#include <iostream>
#include <string>

using namespace std;

class Harbinger																			
{
	string h_name;
	string CatchPhrase;
	int h_age;

public:
	Harbinger(string name = "", int age = 0) : h_name(name), h_age(age)					// конструктор Harbinger	
	{

	}

	Harbinger(string name, int age, string CatchPhrase1)
	{
		h_name = name;
		h_age = age;
		CatchPhrase = CatchPhrase1;
	}

	void setName(string name) { h_name = name; }										// сеттеры Harbinger	

	void setAge(int age) { h_age = age; }

	void setCatchPhrase(string CatchPhrase1) { CatchPhrase = CatchPhrase1; }

	string getCatchPhrase() const { return CatchPhrase; }								// геттеры Harbinger	

	string getName() const { return h_name; }

	int getAge() const { return h_age; }
};

class Prophet : public Harbinger													     	// наследование Prophet-ом Harbinger-а с модификатором доступа public
{
	string ph_name;
	string ph_call;
	int ph_age;
	string* MagnumOpus;

public:
	Prophet(string name = "", int age = 0, string call = "") : ph_name(name), ph_age(age), ph_call(call)	// Prophet
	{
		MagnumOpus = new string[3];
	}

	void max()								                                               // поиск самой длинной строки в MagnumOpus для записи в ph_call
	{
		int g;
		for (size_t i = 0; i < 2; i++)
		{
			g = MagnumOpus[i].length();
			if (g <= MagnumOpus[i + 1].length())
			{
				ph_call = MagnumOpus[i + 1];
			}
		}
	}

	void setMagnumOpus(string Magnum[])											        	// сеттер MagnumOpus
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (Magnum[i].length() <= 25)												    // проверка длины вводимой строки
			{
				MagnumOpus[i] = Magnum[i];
			}
		}
		max();
	}

	const string* getMagnumOpus() { return MagnumOpus; }								    // геттер MagnumOpus
	

	void setpName(string name) { ph_name = name; }

	void setpAge(int age) { ph_age = age; }

	void setpCall(string call) { ph_call = call; } 

	string getpName() const { return ph_name; }

	int getpAge() const { return ph_age; }

	string getpCall() const { return ph_call; }
};

class DeusEx : public Prophet															// наследование DeusEx-ом Prophet-а с модификатором доступа public
{
	string gd_name;
	int gd_year;

public:
	DeusEx(string name = "Будда", int year = 1001) : gd_name(name), gd_year(year)		                 // конструктор по умолчанию
	{

	}

	void setgYear(int year) { gd_year = year; }															// сеттеры

	void setgName(string name) { gd_name = name; } 

	int getgYear() const { return gd_year; }															// геттеры

	string getgName() const { return gd_name; }

	void print()																		
	{
		cout << getName() << " в возрасте " << getAge() << " говорил, что " << getCatchPhrase() << endl;
		cout << "Первое пророчество: " << getMagnumOpus()[0] << endl;
		cout << "Второе пророчество: " << getMagnumOpus()[1] << endl;
		cout << "Главное пророчество: " << getpCall() << endl;
		cout << "Так говорил " << getpName() << " в возрасте " << getpAge() << endl;
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предракали " << getName() << " и " << getpName() << endl;
	}
};

class Believer : private DeusEx															// наследование Believer-ом DeusEx c модификатором private 
{
	string bv_name;
	int bv_age;

public:
	Believer(string name, int age)												      // конструктор
	{
		bv_name = name;
		bv_age = age;
	}

	void printBeliever(DeusEx deusex, Prophet prophet)										
	{
		cout << "Верующий " << getbName() << " молится " << deusex.getgName() << " именем " << prophet.getpName() << ". С " << deusex.getgYear() << " и по сей день." << endl;
	}

	void setbAge(int age)																// сеттеры Believer
	{ bv_age = age; }

	void setbName(string name) { bv_name = name; }

	int getbAge() const { return bv_age; }											   // геттеры Believer

	string getbName() const { return bv_name; }

};

int main()
{
	setlocale(LC_ALL, "RUS");

	Harbinger harbing("Илья", 19, " шишка ");								              // переменные классов
	Prophet prophe("Печаль", 5);
	DeusEx deus("Метакритик", 2029);
	Believer vas("Кто-то", 7);

	deus.setCatchPhrase(" не просил об этом");										      // замена данных через наследование 
	deus.setAge(30);
	deus.setName("Адам");
	deus.setpName("Дженсен");
	deus.setpAge(35);
	deus.setpCall("пуля");

	string Mass[3] = { "Square Enix", "закрыли", "DeusEx ов больше не будет" };                        
	deus.setMagnumOpus(Mass);													                        // заполнение OpusMagnum

	deus.print();																    
	vas.printBeliever(deus, prophe);											     	
}