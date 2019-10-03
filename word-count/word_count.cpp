#include "word_count.h"

namespace word_count {

	std::map<std::string, int> words(std::string text) {
		std::map<std::string, int> dict;
		std::string buff = "";
		for (int i = 0; i <= text.length(); i++) {
			if (std::isalpha(text[i]) || std::isdigit(text[i]) || (text[i] == '\'' && text[i-1] == 'n'))
				buff += std::tolower(text[i]);

			else if (buff == "")
				continue;

			else {
				std::map<std::string, int>::iterator it;
				it = dict.find(buff);
				if (it == dict.end())
					dict[buff] = 1;
				else
					dict[buff]++;

				buff = "";
			}
		}
		return dict;
	}
}  // namespace word_count
