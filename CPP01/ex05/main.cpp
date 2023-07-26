#include "Harl.hpp"

int main() {
    Harl harl;

    int arr[5] = {1, 5, 3, 2, 4};
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            harl.complain(DEBUG);
            if (arr[i] > arr[j]) {
                harl.complain(INFO);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    harl.complain(DEBUG);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] && arr[3] < arr[4])
        harl.complain(GOOD);
    else
        harl.complain(ERROR);

    int new_num = 6;
    std::cout << "New number: " << new_num << std::endl;
    harl.complain(WARNING);
    arr[2] = new_num;

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] && arr[3] < arr[4])
        harl.complain(GOOD);
    else
        harl.complain(ERROR);

    return 0;
}
