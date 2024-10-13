#ifndef S21_SNAKE_MODEL
#define S21_SNAKE_MODEL

#include <ncurses.h>
#include <sys/time.h>

#include <cstdlib>
#include <ctime>
#include <deque>
#include <utility>

#define SPACEBAR 32
#define EMPTY_BLOCK 0
#define CURRENT_FIGURE_BLOCK 1
#define ATTACHED_BLOCK 2
#define ROWS 20
#define COLS 10
#define LEVEL_STEP 5
#define MAX_FIG_ROWS 4
#define MAX_FIG_COLS 4
#define START_SPEED 500
#define FULL_INFO s21::SnakeGame* full_info = s21::SnakeGame::update_full_info()

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action,
} UserAction_t;

typedef enum {
  START_STATE,
  SPAWN_STATE,
  MOVING_STATE,
  SHIFTING_STATE,
  GAME_OVER_STATE,
  PAUSE_STATE,
  TERMINATE_STATE,
} game_state;

typedef struct {
  int** field;
  int** next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct {
  int x, y;
} APPLE;

typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT,
} DIRECTION;

namespace s21 {

class SnakeGame {
#ifdef TEST
 public:
#endif
  APPLE apple_;
  std::deque<std::pair<int, int>> snake_body_;
  DIRECTION direction_;

 public:
  SnakeGame();
  ~SnakeGame() /* = default*/;

  GameInfo_t info;
  int current_action;
  bool holding_;
  game_state state;
  long long timer_;
  static SnakeGame* update_full_info();
  void clean_field();
  void fsm();
  void read_high_score();
  void update_high_score();
  long long update_time();
  void snake_step();
  void copy_only_apple();
  void place_snake_on_field();
  void set_level();
  void prepare_start_field();
  void start_actions();
  void spawn_apple();
  void get_direction();
  void pause_process();
  void set_speed();
  void check_eat(int x, int y);
  bool is_bad_move(int x, int y, int d_y);
};

}  // namespace s21

int** init_empty_area(int rows, int cols);
void copy_area(int** current, int** new_area, int rows, int cols);
GameInfo_t updateCurrentState(void);
void userInput(UserAction_t action, bool hold);

#endif