#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include "vector.h"

std::string vec_to_str(vector<char> vec)
{
	std::ostringstream os;
	std::string str;
	for (int i = 0; i < vec.length(); i++)
	{
		os << vec[i];
	}
	str = os.str();
	return str;
}

vector<std::string> sent_seperate(std::ifstream& fin)
{
	vector<char> sentence;
	vector<std::string> sentences;
	char c;
	while ((c = fin.get()) != EOF)
	{
		if (c == ' ' && sentence.length() == 0)
		{
			continue;
		}
		sentence.push_back(c);
		if (c == '.' || c == '?' || c == '!')
		{
			sentences.push_back(vec_to_str(sentence));
			sentence.clear();
		}
	}
	return sentences;
}

vector<std::string> word_seperate(std::string text)
{
	std::istringstream is(text);
	vector<char> word;
	vector<std::string> words;
	char c;
	while ((c = is.get()) != EOF)
	{
		if (c == ' ' || c == '.' || c == '?' || c == '!' || c == ',' || c == ':' || c == ';' || c == '\'' || c == '\"' || c == '\n' || c == '\0')
		{
			if (word.length() != 0)
			{
				words.push_back(vec_to_str(word));
				word.clear();
			}
			continue;
		}
		word.push_back(c);
	}
	return words;
}

bool checker(vector<std::string> words, std::string word)
{
	bool eqflag;
	for (int i = 0; i < words.length(); i++)
	{
		eqflag = true;
		if (word.length() == words[i].length())
		{
			for (int j = 0; j < word.length(); j++)
			{
				if (word[j] != words[i][j])
				{
					eqflag = false;
					break;
				}
			}
			if (eqflag)
			{
				return eqflag;
			}
		}
	}
	return false;
}

vector<std::string> text_process(std::ifstream& fin, std::string word)
{
	vector<std::string> sentences = sent_seperate(fin);
	vector<std::string> good_sentences;
	for (int i = 0; i < sentences.length(); i++)
	{
		if (checker(word_seperate(sentences[i]), word))
		{
			good_sentences.push_back(sentences[i]);
		}
	}
	return good_sentences;
}