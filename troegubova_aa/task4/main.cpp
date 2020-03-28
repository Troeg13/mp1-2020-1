#include <clocale>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <locale>
#include <fstream>
#include "Songbook.h"
#include <Windows.h>

std::vector<std::string> SetSongData(int i, std::string _data, std::vector<std::string> _Data)
{
	std::string data;
	std::cout << _data;
	if (i != 0)
		std::getline(std::cin, data);
	else
	{
		std::getline(std::cin, data);
		std::getline(std::cin, data);
	}
	_Data.push_back(data);
	return _Data;
}

Songbook SetSong(std::vector<std::string> _data_song, Songbook _songbook)//�������� �����
{
	std::vector<std::string> Data;
	std::cout << "������� ������ � �����, ������� ������ ��������:" << std::endl;

	for (int i = 0; i < 6; i++)
		Data = SetSongData(i, _data_song[i], Data);
	_songbook.SetSong(Data);
	return _songbook;
}

Songbook ChangeDataSong(std::vector<std::string> _data_song, Songbook _songbook)//�������� ������ � �����
{
	std::string change_song, data;
	std::vector<std::string> Data;
	std::cout << "������� �������� �����, ������ ������� ������ ��������: ";
	std::getline(std::cin, change_song);
	std::getline(std::cin, change_song);
	std::cout << "������� ������ � �����, ������� ������ ��������:" << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << _data_song[i];
		std::getline(std::cin, data);
		Data.push_back(data);
	}
	_songbook.ChangeDataSong(change_song, Data);
	return _songbook;
}

void GetSong(Songbook songbook)//����� ����� �� �������� � �����������
{
	std::string _name_song, _singer;
	std::cout << "�������� �����:";
	std::getline(std::cin, _name_song);
	std::getline(std::cin, _name_song);
	std::cout << "��� �����������:";
	std::getline(std::cin, _singer);
	Song get_song = songbook.GetSong(_name_song, _singer);
	get_song.WriteCon1();
	get_song.WriteCon2();
}

void GetSongs(Songbook songbook, int human)// ������ ��� ����� ��������� �����, �����������, �����������
{
	std::string _name;
	std::cout << "�������� ���:";
	std::getline(std::cin, _name);
	std::getline(std::cin, _name);
	Songbook get_songbook = songbook.GetSongsData(_name, human);
	get_songbook.WriteCon();
}

void GetCountSong(Songbook songbook)//������ ���������� �����
{
	std::cout << "������� ���-�� ����� � ���������: " << songbook.GetCountSong() << std::endl;
}

Songbook DeleteSong(Songbook songbook)
{
	std::string delete_song;
	std::cout << "������� �������� �����, ������� ������ �������: ";
	std::getline(std::cin, delete_song);
	std::getline(std::cin, delete_song);
	songbook.DeleteSong(delete_song);
	return songbook;
}
void SaveInFile(Songbook songbook)
{
	songbook.SaveInFile();
	std::cout << "�������� ������� � ����" << std::endl;
}

Songbook ReadFile(Songbook songbook)
{
	songbook.ReadFile();
	return songbook;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Songbook songbook1;
	int i, item;

	std::vector<std::string> data_song
		= { "�������� �����:", "����� ����:", "����������:", "�����������:", "�������� �������, � ������� ������ �����:", "���� ������� �����:" };
	Songbook(*Act_1[2])(std::vector<std::string> _data_song, Songbook _songbook) = { SetSong, ChangeDataSong };
	void(*Act_2[3])(Songbook songbook) = { GetSong, GetCountSong, SaveInFile };
	Songbook(*Act_3[2])(Songbook _songbook) = { DeleteSong, ReadFile };

	while (true)
	{
		system("cls");
		std::cout << "1) �������� �����\n2) �������� ������ ��������� �����\n3) ������ ��� ����� ��������� �����\n4) ������ ��� ����� ��������� �����������\n5) ������ ��� ����� ��������� �����������\n6) ����� ����� �� �������� � �����������\n7) ������ ������� ����� �����\n8) ��������� �������� � ����\n9) ������� �����\n10) ������� �������� �� �����\n";
		std::cin >> item;
		if ((item == 1) || (item == 2))
		{
			songbook1 = Act_1[item - 1](data_song, songbook1);
		}
		else
		{
			if ((item > 2) && (item < 6))
			{
				GetSongs(songbook1, item - 2);
			}
			else
			{
				if ((item > 5) && (item < 9))
					Act_2[item - 6](songbook1);
				else
				{
					if ((item == 9) || (item == 10))
						songbook1 = Act_3[item - 9](songbook1);
				}
			}
		}
		std::cout << "���������� ������ ���������?\n1)��\n2)���\n";
		std::cin >> i;
		if (i != 1)break;
	}
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	system("pause");
}
