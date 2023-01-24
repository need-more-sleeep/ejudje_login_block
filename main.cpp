#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {

	
	uint64_t P, B, B_max, unix_time_curr, unix_time_error;
	unsigned int N;
	uint64_t unix_time_stop_ban = 0;
	bool ban = false;
	std::cin >> N >>P>> B >> B_max >> unix_time_curr;
	std::vector <uint64_t> error_logins;
	int pos_change_ban = 0;

	//O(n) добавл¤ем элты в вектор
	while (std::cin>> unix_time_error) {
		error_logins.emplace_back(unix_time_error);
	}

	// сложность сортировки  O(n*logn) //информаци¤ с сайта cpprefrerence
	std::sort(error_logins.begin(), error_logins.end());

	//снова проходимс¤ по вектору сложность - O(n)
	for (size_t i = 0; i < error_logins.size();i++)
	{
		if (unix_time_curr - 2 * B_max >= error_logins[i]) {
			pos_change_ban = i+1;
			continue;
		}
		//если меньше чем N попыток, но врем¤ дл¤ N попыток истекло
		if (error_logins[i] > (error_logins[pos_change_ban] + P)) {
			pos_change_ban++;
			continue;
		}
		//если больше чем N  попыток
		if (i == (pos_change_ban + N -1)) {
			pos_change_ban = i+1	;
			ban = true;
			unix_time_stop_ban = error_logins[i] + B;
			if (B * 2 <= B_max) {
				B *= 2;
			}
			else {
				B = B_max;
			}
			continue;
		}
	}
	if (unix_time_stop_ban >= unix_time_curr) {
		std::cout << unix_time_stop_ban;
	}
	else {
		std::cout << "ok" << std::endl;
	}

	//»тогова¤ сложность по времени O(n*log n) -тк сортируем  вектор
	//»тогова¤ сложность по пам¤ти O(n)

}