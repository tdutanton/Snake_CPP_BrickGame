#include <cstdlib>
#include <iostream>

int main() {
  char choice;
  std::cout << "Games:" << std::endl;
  std::cout << "1. Tetris console" << std::endl;
  std::cout << "2. Snake console" << std::endl;
  std::cout << "3. Tetris desktop" << std::endl;
  std::cout << "4. Snake desktop" << std::endl;
  std::cout << "Q - quit" << std::endl;

  std::cout << "Make your choice: ";
  std::cin >> choice;

  switch (choice) {
    case '1':
      system("./tetris");
      break;
    case '2':
      system("./snake");
      break;
    case '3':
      system("gui/desktop/s21_tetris_desktop");
      break;
    case '4':
      system("gui/desktop/s21_snake_desktop");
      break;
    case 'q':
    case 'Q':
      std::cout << "Good bye!" << std::endl;
      break;
    default:
      std::cout << "Wrong choice. Try again!" << std::endl;
      break;
  }

  return 0;
}