// Crack05.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>


int main()
{
	printf("CrackMe 05 \n");
	HKEY hKey;
	DWORD res;
	DWORD TYPE;
	LSTATUS Crt;
	Crt = RegCreateKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\CRACK05", 0, NULL, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, NULL, &hKey, &res);
	if ( Crt != ERROR_SUCCESS) return 0;

	if (res == REG_CREATED_NEW_KEY)
	{
		/*CTime t;
		t = t.GetCurrentTime();
		time_t	t_t = t.GetTime();*/

		SYSTEMTIME st;

		GetSystemTime(&st);
		

		RegSetValueEx(hKey, (LPWSTR)"", 0, REG_DWORD, (CONST BYTE*) & st, 16);
		printf("The system time is: %02d:%02d\n", st.wHour, st.wMinute);
		printf("Base time have saved! \n");
	}
	else
	{
		
		SYSTEMTIME streg, st;
		GetSystemTime(&st);
		res = 16;
		RegQueryValueEx(hKey, L"", 0, &TYPE, (LPBYTE)& streg, &res);

		FILETIME  tm1, tm2;
		__int64 t1, t2, qu;

		SystemTimeToFileTime(&streg, &tm1);
		SystemTimeToFileTime(&st, &tm2);
		t1 = (((__int64)tm1.dwHighDateTime) << 32) | tm1.dwLowDateTime;
		t2 = (((__int64)tm2.dwHighDateTime) << 32) | tm2.dwLowDateTime;

		qu = (t2 - t1) / 10000000 / 60 ;

		if (qu < 1)
		{
			printf("Working... \n\n");
			printf("The register time is: %02d:%02d:%02d\n", streg.wHour, streg.wMinute, streg.wSecond);
			printf("The system time is: %02d:%02d:%02d\n", st.wHour, st.wMinute, st.wSecond);
		}
		else
		{
			printf("Abort! \x7 \n\n");
		}
	}
	RegCloseKey(hKey);
	std::system( "pause");
	return 0;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
