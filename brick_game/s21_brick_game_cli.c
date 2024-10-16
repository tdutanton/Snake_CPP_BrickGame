#include <unistd.h>

#include "../gui/cli/s21_frontend.h"

void main_game_cycle(void);
UserAction_t user_push(wchar_t key);
void set_init_screen(void);

int main(void) {
  set_init_screen();
  main_game_cycle();
  endwin();
  return 0;
}

/**
 * Main game function. The heart and brain of the program
 */
void main_game_cycle(void) {
  UserAction_t push;
  while ((push = user_push(getch())) != Terminate) {
    print_current_game_state(updateCurrentState());
    userInput(push, false);
  }
}

UserAction_t user_push(wchar_t key) {
  UserAction_t push;
  switch (key) {
    case KEY_ENTER:
    case '\n':
      push = Start;
      break;
    case 'P':
    case 'p':
      push = Pause;
      break;
    case 'Q':
    case 'q':
      push = Terminate;
      break;
    case KEY_LEFT:
      push = Left;
      break;
    case KEY_RIGHT:
      push = Right;
      break;
    case KEY_DOWN:
      push = Down;
      break;
    case KEY_UP:
      push = Up;
      break;
    case KEY_F0:
    case SPACEBAR:
      push = Action;
  }
  return push;
}

void set_init_screen(void) {
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  srand(time(NULL));
  curs_set(0);
  timeout(5);
}