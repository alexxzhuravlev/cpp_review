// Ebook_my.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main()
{
	std::vector<int> user_to_page_;
	std::vector<int> page_to_user_count_;
	int users_count_;

	user_to_page_ = std::vector<int>(100'001);
	std::fill(user_to_page_.begin(), user_to_page_.end(), -1);
	page_to_user_count_ = std::vector<int>(1001);
	users_count_ = 0;

	int n;
	std::cin >> n;

	std::string query;
	int user;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> query;

		if (query == "READ")
		{
			int page;
			std::cin >> user >> page;

			int& current_page = user_to_page_[user];

			if (current_page == -1)
			{
				++page_to_user_count_[page];
				++users_count_;
			}
			else
			{
				--page_to_user_count_[current_page];
				++page_to_user_count_[page];
			}

			current_page = page;
		}

		if (query == "CHEER")
		{
			std::cin >> user;
			const int page = user_to_page_.at(user);
			if (page == -1)
				std::cout << 0 << '\n';
			else
			{
				if (users_count_ == 1)
				{
					std::cout << 1 << '\n';
				}
				else
				{
					double answer = 0;
					for (int i = 0; i < page; ++i)
					{
						answer += page_to_user_count_.at(i);
					}

					std::cout << answer / (users_count_ - 1) << '\n';
				}
			}
		}
	}
}

