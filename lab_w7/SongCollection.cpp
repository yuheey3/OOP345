// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Nov.7.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<cstring>
#include"SongCollection.h"

namespace sdds {
	Song::Song() {
		artist = "";
		title = "";
		album = "";
		m_price = 0.0;
		year = 0;
		length = 0;
	}
	SongCollection::SongCollection(const char* filename) {
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			return;
		}
		while (file && !file.eof())
		{
			Song song = Song(file);
			m_song.push_back(song);
		}
	}
	Song::Song(std::istream& filename) {
		std::string line;
		getline(filename, line, '\n');

		title = line.substr(0, 25);
		title = title.substr(title.find_first_not_of(' '), (title.find_last_not_of(' ') - title.find_first_not_of(' ')) + 1);
		line.erase(0, 25);

		artist = line.substr(0, 25);
		artist = artist.substr(artist.find_first_not_of(' '), (artist.find_last_not_of(' ') - artist.find_first_not_of(' ')) + 1);
		line.erase(0, 25);

		album = line.substr(0, 25);
		album = album.substr(album.find_first_not_of(' '), (album.find_last_not_of(' ') - album.find_first_not_of(' ')) + 1);
		line.erase(0, 25);

		std::string temp = "";
		temp = line.substr(0, 5);

		temp = temp.substr(title.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

		year = std::atoi(temp.c_str());

		line.erase(0, 5);


		std::string temp2 = "";
		temp2 = line.substr(0, 5);
		temp2 = temp2.substr(temp2.find_first_not_of(' '), (temp2.find_last_not_of(' ') - temp2.find_first_not_of(' ')) + 1);
		length = std::atoi(temp2.c_str());
		line.erase(0, 5);


		std::string temp3 = "";
		temp3 = line.substr(0, 5);
		temp3 = temp3.substr(temp3.find_first_not_of(' '), (temp3.find_last_not_of(' ') - temp3.find_first_not_of(' ')) + 1);
		m_price = std::stod(temp3.c_str());

	}



	void SongCollection::SongCollection::display(std::ostream& out) const {
		std::for_each(m_song.begin(), m_song.end(), [&](const Song song) {
			out << song;
		});
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.title << " | " << std::setw(15) << std::left << theSong.artist << " | "
			<< std::setw(20) << std::left << theSong.album << " | ";
		if (theSong.year != 0) {
			out << std::setw(6) << std::right << theSong.year;
		}
		else {
			out << std::setw(6) << "";
		}
		int min = theSong.length / 60;
		int sec = theSong.length % 60;

		out << " | " << min << ":";
		out << std::setw(2) << std::setfill('0') << sec << " | " << std::setfill(' ') << theSong.m_price << " |" << std::endl;
		out.precision(2);
		out.setf(std::ios::fixed);
		return out;
	}


}