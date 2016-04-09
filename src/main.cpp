#include <iostream>
#include <string>

#include "bitboard.h"
#include "evaluate.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "ucioption.h"

int main(int argc, char* argv[]) {

  std::cout << engine_info() << std::endl;

  UCI::init(Options);
  Bitboards::init();
  Position::init();
  Bitbases::init_kpk();
  Search::init();
  Eval::init();
  Threads.init();
  TT.set_size(Options["Hash"]);

  //test_bitboard();
  //test_position();

  std::string args;

  for (int i = 1; i < argc; ++i)
      args += std::string(argv[i]) + " ";

  UCI::loop(args);

  Threads.exit();
}