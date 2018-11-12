Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  us/call  us/call  name    
 53.60      5.81     5.81                             game::get_features(int)
  9.73      6.87     1.06 299087356     0.00     0.00  game::get2(int, int)
  8.07      7.74     0.88 297707671     0.00     0.00  game::get3(int, int)
  6.41      8.44     0.70 296795098     0.00     0.00  game::get4(int, int)
  4.43      8.92     0.48  5906100     0.08     0.23  game::getRunDownUtil(int, int, int, int)
  4.24      9.38     0.46  5906100     0.08     0.19  game::getRunSWUtil(int, int, int, int)
  3.23      9.73     0.35  5906100     0.06     0.23  game::getRunSEUtil(int, int, int, int)
  2.31      9.98     0.25                             allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool)
  1.66     10.16     0.18  2335342     0.08     0.12  game::getDirection(int, int, int, int)
  0.92     10.26     0.10 19724911     0.01     0.01  void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&)
  0.83     10.35     0.09 16961828     0.01     0.01  void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag)
  0.65     10.42     0.07                             game::eval(int)
  0.55     10.48     0.06                             AI::maxValue(game, double, double, int)
  0.51     10.53     0.06  3160475     0.02     0.02  game::get1(int, int)
  0.46     10.58     0.05  3632329     0.01     0.01  void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&)
  0.46     10.63     0.05  1968700     0.03     0.62  game::getRunSW(int)
  0.37     10.67     0.04  1968700     0.02     2.05  game::getRun(int)
  0.37     10.71     0.04                             void std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > >::_M_realloc_insert<std::pair<std::vector<moves, std::allocator<moves> >, double> >(__gnu_cxx::__normal_iterator<std::pair<std::vector<moves, std::allocator<moves> >, double>*, std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > > >, std::pair<std::vector<moves, std::allocator<moves> >, double>&&)
  0.37     10.75     0.04                             void std::vector<int, std::allocator<int> >::emplace_back<int>(int&&)
  0.28     10.78     0.03  2303872     0.01     0.13  game::moveRing(int, int, int, int)
  0.18     10.80     0.02  1968700     0.01     0.72  game::getRunSE(int)
  0.18     10.82     0.02    47400     0.42     2.12  game::validMoves(int)
  0.09     10.83     0.01   202038     0.05     0.10  game::getValid5(int, int)
  0.09     10.84     0.01                             AI::minValue(game, double, double, int)
  0.00     10.84     0.00  3392602     0.00     0.00  game::get0(int, int)
  0.00     10.84     0.00  2447899     0.00     0.00  game::terminal()
  0.00     10.84     0.00  2441815     0.00     0.00  game::performMove(moves, int)
  0.00     10.84     0.00  2303872     0.00     0.01  game::flip(int, int, int, int, int)
  0.00     10.84     0.00  1968700     0.00     0.69  game::getRunDown(int)
  0.00     10.84     0.00  1756114     0.00     0.00  game::get5(int, int)
  0.00     10.84     0.00   202038     0.00     0.04  game::getValid0(int, int)
  0.00     10.84     0.00   202038     0.00     0.08  game::getValid1(int, int)
  0.00     10.84     0.00   202038     0.00     0.04  game::getValid2(int, int)
  0.00     10.84     0.00   202038     0.00     0.05  game::getValid3(int, int)
  0.00     10.84     0.00   202038     0.00     0.06  game::getValid4(int, int)
  0.00     10.84     0.00    31417     0.00     0.13  game::removeRun(int, int, int, int)
  0.00     10.84     0.00    21623     0.00     0.09  game::validRemoveRing(int)
  0.00     10.84     0.00      141     0.00     0.00  void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&)
  0.00     10.84     0.00      118     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...) [clone .constprop.194]
  0.00     10.84     0.00      114     0.00     0.00  void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00     10.84     0.00       33     0.00     0.00  convert_to_vector(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
  0.00     10.84     0.00       28     0.00     0.00  game::insertRing(int, int, int)
  0.00     10.84     0.00       15     0.00     0.00  void std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > >::_M_realloc_insert<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >(__gnu_cxx::__normal_iterator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >*, std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > > >, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&&)
  0.00     10.84     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN4game10insertRingEiii
  0.00     10.84     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN4game10validMovesEi
  0.00     10.84     0.00        1     0.00     0.00  _GLOBAL__sub_I_direct
  0.00     10.84     0.00        1     0.00     0.00  _GLOBAL__sub_I_nom

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2018 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.09% of 10.84 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     54.3    5.81    0.07                 game::get_features(int) [1]
                0.07    0.00 13991508/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
-----------------------------------------------
                                                 <spontaneous>
[2]     43.1    0.25    4.42                 allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
                0.04    3.99 1968700/1968700     game::getRun(int) [3]
                0.02    0.22 1825005/2303872     game::moveRing(int, int, int, int) [13]
                0.02    0.08   47400/47400       game::validMoves(int) [16]
                0.03    0.00 1943346/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.02 1825005/2303872     game::flip(int, int, int, int, int) [25]
                0.00    0.00   21623/31417       game::removeRun(int, int, int, int) [32]
                0.00    0.00   21623/21623       game::validRemoveRing(int) [33]
                0.00    0.00 1969012/2447899     game::terminal() [44]
                0.00    0.00 1943346/2441815     game::performMove(moves, int) [45]
                0.00    0.00      14/28          game::insertRing(int, int, int) [51]
-----------------------------------------------
                0.04    3.99 1968700/1968700     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[3]     37.2    0.04    3.99 1968700         game::getRun(int) [3]
                0.02    1.39 1968700/1968700     game::getRunSE(int) [4]
                0.00    1.35 1968700/1968700     game::getRunDown(int) [6]
                0.05    1.16 1968700/1968700     game::getRunSW(int) [8]
                0.02    0.00 3937400/16961828     void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
-----------------------------------------------
                0.02    1.39 1968700/1968700     game::getRun(int) [3]
[4]     13.0    0.02    1.39 1968700         game::getRunSE(int) [4]
                0.35    1.02 5906100/5906100     game::getRunSEUtil(int, int, int, int) [5]
                0.02    0.00 3937400/16961828     void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
-----------------------------------------------
                0.35    1.02 5906100/5906100     game::getRunSE(int) [4]
[5]     12.6    0.35    1.02 5906100         game::getRunSEUtil(int, int, int, int) [5]
                1.02    0.00 288888950/299087356     game::get2(int, int) [10]
                0.00    0.00   33738/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00   11246/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
-----------------------------------------------
                0.00    1.35 1968700/1968700     game::getRun(int) [3]
[6]     12.5    0.00    1.35 1968700         game::getRunDown(int) [6]
                0.48    0.85 5906100/5906100     game::getRunDownUtil(int, int, int, int) [7]
                0.02    0.00 3937400/16961828     void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
-----------------------------------------------
                0.48    0.85 5906100/5906100     game::getRunDown(int) [6]
[7]     12.3    0.48    0.85 5906100         game::getRunDownUtil(int, int, int, int) [7]
                0.85    0.00 289262864/297707671     game::get3(int, int) [11]
                0.00    0.00    7635/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00    2545/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
-----------------------------------------------
                0.05    1.16 1968700/1968700     game::getRun(int) [3]
[8]     11.2    0.05    1.16 1968700         game::getRunSW(int) [8]
                0.46    0.68 5906100/5906100     game::getRunSWUtil(int, int, int, int) [9]
                0.02    0.00 3937400/16961828     void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
-----------------------------------------------
                0.46    0.68 5906100/5906100     game::getRunSW(int) [8]
[9]     10.5    0.46    0.68 5906100         game::getRunSWUtil(int, int, int, int) [9]
                0.68    0.00 290615976/296795098     game::get4(int, int) [12]
                0.00    0.00   23496/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00    7832/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
-----------------------------------------------
                0.00    0.00   68456/299087356     game::removeRun(int, int, int, int) [32]
                0.00    0.00  543704/299087356     game::getValid2(int, int) [31]
                0.00    0.00  703519/299087356     game::flip(int, int, int, int, int) [25]
                0.03    0.00 8882727/299087356     game::getDirection(int, int, int, int) [14]
                1.02    0.00 288888950/299087356     game::getRunSEUtil(int, int, int, int) [5]
[10]     9.7    1.06    0.00 299087356         game::get2(int, int) [10]
-----------------------------------------------
                0.00    0.00   19832/297707671     game::removeRun(int, int, int, int) [32]
                0.00    0.00  476050/297707671     game::getValid3(int, int) [29]
                0.00    0.00  899504/297707671     game::flip(int, int, int, int, int) [25]
                0.02    0.00 7049421/297707671     game::getDirection(int, int, int, int) [14]
                0.85    0.00 289262864/297707671     game::getRunDownUtil(int, int, int, int) [7]
[11]     8.1    0.88    0.00 297707671         game::get3(int, int) [11]
-----------------------------------------------
                0.00    0.00   37392/296795098     game::removeRun(int, int, int, int) [32]
                0.00    0.00  612798/296795098     game::getValid4(int, int) [28]
                0.00    0.00 1246715/296795098     game::flip(int, int, int, int, int) [25]
                0.01    0.00 4282217/296795098     game::getDirection(int, int, int, int) [14]
                0.68    0.00 290615976/296795098     game::getRunSWUtil(int, int, int, int) [9]
[12]     6.4    0.70    0.00 296795098         game::get4(int, int) [12]
-----------------------------------------------
                0.00    0.00     943/2303872     AI::makeDecision(game) [34]
                0.00    0.01   46508/2303872     AI::minValue(game, double, double, int) [26]
                0.01    0.05  431416/2303872     AI::maxValue(game, double, double, int) [15]
                0.02    0.22 1825005/2303872     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[13]     2.8    0.03    0.27 2303872         game::moveRing(int, int, int, int) [13]
                0.18    0.09 2303920/2335342     game::getDirection(int, int, int, int) [14]
-----------------------------------------------
                0.00    0.00   31422/2335342     game::removeRun(int, int, int, int) [32]
                0.18    0.09 2303920/2335342     game::moveRing(int, int, int, int) [13]
[14]     2.5    0.18    0.10 2335342         game::getDirection(int, int, int, int) [14]
                0.03    0.00 1932729/3160475     game::get1(int, int) [20]
                0.03    0.00 8882727/299087356     game::get2(int, int) [10]
                0.02    0.00 7049421/297707671     game::get3(int, int) [11]
                0.01    0.00 4282217/296795098     game::get4(int, int) [12]
                0.00    0.00 2335342/3392602     game::get0(int, int) [43]
-----------------------------------------------
                                                 <spontaneous>
[15]     1.1    0.06    0.06                 AI::maxValue(game, double, double, int) [15]
                0.01    0.05  431416/2303872     game::moveRing(int, int, int, int) [13]
                0.00    0.00  431416/2303872     game::flip(int, int, int, int, int) [25]
                0.00    0.00    2240/31417       game::removeRun(int, int, int, int) [32]
                0.00    0.00  435900/2441815     game::performMove(moves, int) [45]
                0.00    0.00   46519/2447899     game::terminal() [44]
                0.00    0.00       4/28          game::insertRing(int, int, int) [51]
-----------------------------------------------
                0.02    0.08   47400/47400       allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[16]     0.9    0.02    0.08   47400         game::validMoves(int) [16]
                0.01    0.01  202038/202038      game::getValid5(int, int) [24]
                0.00    0.02  202038/202038      game::getValid1(int, int) [27]
                0.00    0.01  202038/202038      game::getValid4(int, int) [28]
                0.00    0.01  202038/202038      game::getValid3(int, int) [29]
                0.00    0.01  202038/202038      game::getValid0(int, int) [30]
                0.00    0.01  202038/202038      game::getValid2(int, int) [31]
                0.01    0.00 1212228/16961828     void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
                0.00    0.00      14/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00      14/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
-----------------------------------------------
                0.00    0.00      14/19724911     game::validMoves(int) [16]
                0.00    0.00      97/19724911     convertToMyMove(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [35]
                0.00    0.00    7635/19724911     game::getRunDownUtil(int, int, int, int) [7]
                0.00    0.00   23496/19724911     game::getRunSWUtil(int, int, int, int) [9]
                0.00    0.00   33738/19724911     game::getRunSEUtil(int, int, int, int) [5]
                0.00    0.00  193408/19724911     game::validRemoveRing(int) [33]
                0.00    0.00  640605/19724911     game::getValid2(int, int) [31]
                0.00    0.00  721695/19724911     game::getValid1(int, int) [27]
                0.00    0.00  904392/19724911     game::getValid3(int, int) [29]
                0.00    0.00  926799/19724911     game::getValid0(int, int) [30]
                0.01    0.00 1138566/19724911     game::getValid4(int, int) [28]
                0.01    0.00 1142958/19724911     game::getValid5(int, int) [24]
                0.07    0.00 13991508/19724911     game::get_features(int) [1]
[17]     0.9    0.10    0.00 19724911         void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
-----------------------------------------------
                0.01    0.00 1212228/16961828     game::validMoves(int) [16]
                0.02    0.00 3937400/16961828     game::getRunSW(int) [8]
                0.02    0.00 3937400/16961828     game::getRunDown(int) [6]
                0.02    0.00 3937400/16961828     game::getRunSE(int) [4]
                0.02    0.00 3937400/16961828     game::getRun(int) [3]
[18]     0.8    0.09    0.00 16961828         void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag) [18]
-----------------------------------------------
                                                 <spontaneous>
[19]     0.6    0.07    0.00                 game::eval(int) [19]
-----------------------------------------------
                0.00    0.00       4/3160475     game::removeRun(int, int, int, int) [32]
                0.01    0.00  553114/3160475     game::getValid1(int, int) [27]
                0.01    0.00  674628/3160475     game::flip(int, int, int, int, int) [25]
                0.03    0.00 1932729/3160475     game::getDirection(int, int, int, int) [14]
[20]     0.5    0.06    0.00 3160475         game::get1(int, int) [20]
-----------------------------------------------
                0.00    0.00      14/3632329     game::validMoves(int) [16]
                0.00    0.00      35/3632329     convertToMyMove(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [35]
                0.00    0.00    2545/3632329     game::getRunDownUtil(int, int, int, int) [7]
                0.00    0.00    7832/3632329     game::getRunSWUtil(int, int, int, int) [9]
                0.00    0.00   11246/3632329     game::getRunSEUtil(int, int, int, int) [5]
                0.00    0.00   75185/3632329     game::validRemoveRing(int) [33]
                0.00    0.00  190420/3632329     game::getValid2(int, int) [31]
                0.00    0.00  219201/3632329     game::getValid1(int, int) [27]
                0.00    0.00  250220/3632329     game::getValid3(int, int) [29]
                0.00    0.00  270837/3632329     game::getValid0(int, int) [30]
                0.00    0.00  329333/3632329     game::getValid4(int, int) [28]
                0.00    0.00  332115/3632329     game::getValid5(int, int) [24]
                0.03    0.00 1943346/3632329     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[21]     0.5    0.05    0.00 3632329         void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
-----------------------------------------------
                                                 <spontaneous>
[22]     0.4    0.04    0.00                 void std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > >::_M_realloc_insert<std::pair<std::vector<moves, std::allocator<moves> >, double> >(__gnu_cxx::__normal_iterator<std::pair<std::vector<moves, std::allocator<moves> >, double>*, std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > > >, std::pair<std::vector<moves, std::allocator<moves> >, double>&&) [22]
-----------------------------------------------
                                                 <spontaneous>
[23]     0.4    0.04    0.00                 void std::vector<int, std::allocator<int> >::emplace_back<int>(int&&) [23]
-----------------------------------------------
                0.01    0.01  202038/202038      game::validMoves(int) [16]
[24]     0.2    0.01    0.01  202038         game::getValid5(int, int) [24]
                0.01    0.00 1142958/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  332115/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  643823/1756114     game::get5(int, int) [46]
-----------------------------------------------
                0.00    0.00     943/2303872     AI::makeDecision(game) [34]
                0.00    0.00   46508/2303872     AI::minValue(game, double, double, int) [26]
                0.00    0.00  431416/2303872     AI::maxValue(game, double, double, int) [15]
                0.00    0.02 1825005/2303872     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[25]     0.2    0.00    0.02 2303872         game::flip(int, int, int, int, int) [25]
                0.01    0.00  674628/3160475     game::get1(int, int) [20]
                0.00    0.00 1246715/296795098     game::get4(int, int) [12]
                0.00    0.00  899504/297707671     game::get3(int, int) [11]
                0.00    0.00  703519/299087356     game::get2(int, int) [10]
                0.00    0.00 1112291/1756114     game::get5(int, int) [46]
                0.00    0.00  402612/3392602     game::get0(int, int) [43]
-----------------------------------------------
                                                 <spontaneous>
[26]     0.2    0.01    0.01                 AI::minValue(game, double, double, int) [26]
                0.00    0.01   46508/2303872     game::moveRing(int, int, int, int) [13]
                0.00    0.00    7450/31417       game::removeRun(int, int, int, int) [32]
                0.00    0.00   46508/2303872     game::flip(int, int, int, int, int) [25]
                0.00    0.00  432368/2447899     game::terminal() [44]
                0.00    0.00   61413/2441815     game::performMove(moves, int) [45]
                0.00    0.00       5/28          game::insertRing(int, int, int) [51]
-----------------------------------------------
                0.00    0.02  202038/202038      game::validMoves(int) [16]
[27]     0.2    0.00    0.02  202038         game::getValid1(int, int) [27]
                0.01    0.00  553114/3160475     game::get1(int, int) [20]
                0.00    0.00  721695/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  219201/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
-----------------------------------------------
                0.00    0.01  202038/202038      game::validMoves(int) [16]
[28]     0.1    0.00    0.01  202038         game::getValid4(int, int) [28]
                0.01    0.00 1138566/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  329333/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  612798/296795098     game::get4(int, int) [12]
-----------------------------------------------
                0.00    0.01  202038/202038      game::validMoves(int) [16]
[29]     0.1    0.00    0.01  202038         game::getValid3(int, int) [29]
                0.00    0.00  904392/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  250220/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  476050/297707671     game::get3(int, int) [11]
                0.00    0.00   82981/3392602     game::get0(int, int) [43]
-----------------------------------------------
                0.00    0.01  202038/202038      game::validMoves(int) [16]
[30]     0.1    0.00    0.01  202038         game::getValid0(int, int) [30]
                0.00    0.00  926799/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  270837/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  571663/3392602     game::get0(int, int) [43]
-----------------------------------------------
                0.00    0.01  202038/202038      game::validMoves(int) [16]
[31]     0.1    0.00    0.01  202038         game::getValid2(int, int) [31]
                0.00    0.00  640605/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00  190420/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  543704/299087356     game::get2(int, int) [10]
-----------------------------------------------
                0.00    0.00     104/31417       AI::makeDecision(game) [34]
                0.00    0.00    2240/31417       AI::maxValue(game, double, double, int) [15]
                0.00    0.00    7450/31417       AI::minValue(game, double, double, int) [26]
                0.00    0.00   21623/31417       allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[32]     0.0    0.00    0.00   31417         game::removeRun(int, int, int, int) [32]
                0.00    0.00   31422/2335342     game::getDirection(int, int, int, int) [14]
                0.00    0.00   68456/299087356     game::get2(int, int) [10]
                0.00    0.00   37392/296795098     game::get4(int, int) [12]
                0.00    0.00   19832/297707671     game::get3(int, int) [11]
                0.00    0.00       4/3160475     game::get1(int, int) [20]
                0.00    0.00       4/3392602     game::get0(int, int) [43]
-----------------------------------------------
                0.00    0.00   21623/21623       allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[33]     0.0    0.00    0.00   21623         game::validRemoveRing(int) [33]
                0.00    0.00   75185/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00  193408/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
-----------------------------------------------
                                                 <spontaneous>
[34]     0.0    0.00    0.00                 AI::makeDecision(game) [34]
                0.00    0.00     943/2303872     game::moveRing(int, int, int, int) [13]
                0.00    0.00     104/31417       game::removeRun(int, int, int, int) [32]
                0.00    0.00     943/2303872     game::flip(int, int, int, int, int) [25]
                0.00    0.00    1156/2441815     game::performMove(moves, int) [45]
                0.00    0.00       5/28          game::insertRing(int, int, int) [51]
-----------------------------------------------
                                                 <spontaneous>
[35]     0.0    0.00    0.00                 convertToMyMove(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [35]
                0.00    0.00      97/19724911     void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [17]
                0.00    0.00      35/3632329     void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&) [21]
                0.00    0.00     114/114         void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [49]
-----------------------------------------------
                0.00    0.00       4/3392602     game::removeRun(int, int, int, int) [32]
                0.00    0.00   82981/3392602     game::getValid3(int, int) [29]
                0.00    0.00  402612/3392602     game::flip(int, int, int, int, int) [25]
                0.00    0.00  571663/3392602     game::getValid0(int, int) [30]
                0.00    0.00 2335342/3392602     game::getDirection(int, int, int, int) [14]
[43]     0.0    0.00    0.00 3392602         game::get0(int, int) [43]
-----------------------------------------------
                0.00    0.00   46519/2447899     AI::maxValue(game, double, double, int) [15]
                0.00    0.00  432368/2447899     AI::minValue(game, double, double, int) [26]
                0.00    0.00 1969012/2447899     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[44]     0.0    0.00    0.00 2447899         game::terminal() [44]
-----------------------------------------------
                0.00    0.00    1156/2441815     AI::makeDecision(game) [34]
                0.00    0.00   61413/2441815     AI::minValue(game, double, double, int) [26]
                0.00    0.00  435900/2441815     AI::maxValue(game, double, double, int) [15]
                0.00    0.00 1943346/2441815     allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[45]     0.0    0.00    0.00 2441815         game::performMove(moves, int) [45]
-----------------------------------------------
                0.00    0.00  643823/1756114     game::getValid5(int, int) [24]
                0.00    0.00 1112291/1756114     game::flip(int, int, int, int, int) [25]
[46]     0.0    0.00    0.00 1756114         game::get5(int, int) [46]
-----------------------------------------------
                0.00    0.00     141/141         convert_to_vector(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [50]
[47]     0.0    0.00    0.00     141         void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&) [47]
-----------------------------------------------
                0.00    0.00     118/118         convertTo[abi:cxx11](std::vector<moves, std::allocator<moves> >) [62]
[48]     0.0    0.00    0.00     118         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...) [clone .constprop.194] [48]
-----------------------------------------------
                0.00    0.00     114/114         convertToMyMove(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [35]
[49]     0.0    0.00    0.00     114         void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [49]
-----------------------------------------------
                0.00    0.00      33/33          init_diagonal() [61]
[50]     0.0    0.00    0.00      33         convert_to_vector(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [50]
                0.00    0.00     141/141         void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&) [47]
-----------------------------------------------
                0.00    0.00       4/28          AI::maxValue(game, double, double, int) [15]
                0.00    0.00       5/28          AI::minValue(game, double, double, int) [26]
                0.00    0.00       5/28          AI::makeDecision(game) [34]
                0.00    0.00      14/28          allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [2]
[51]     0.0    0.00    0.00      28         game::insertRing(int, int, int) [51]
-----------------------------------------------
                0.00    0.00      15/15          init_diagonal() [61]
[52]     0.0    0.00    0.00      15         void std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > >::_M_realloc_insert<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >(__gnu_cxx::__normal_iterator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >*, std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > > >, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&&) [52]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [108]
[53]     0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN4game10insertRingEiii [53]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [108]
[54]     0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN4game10validMovesEi [54]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [108]
[55]     0.0    0.00    0.00       1         _GLOBAL__sub_I_direct [55]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [108]
[56]     0.0    0.00    0.00       1         _GLOBAL__sub_I_nom [56]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2018 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

  [53] _GLOBAL__sub_I__ZN4game10insertRingEiii [7] game::getRunDownUtil(int, int, int, int) [27] game::getValid1(int, int)
  [54] _GLOBAL__sub_I__ZN4game10validMovesEi [33] game::validRemoveRing(int) [31] game::getValid2(int, int)
  [55] _GLOBAL__sub_I_direct  [19] game::eval(int)        [29] game::getValid3(int, int)
  [56] _GLOBAL__sub_I_nom     [25] game::flip(int, int, int, int, int) [28] game::getValid4(int, int)
  [50] convert_to_vector(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [43] game::get0(int, int) [24] game::getValid5(int, int)
   [2] allvalidmoves::getAllMoves(int, game, std::vector<moves, std::allocator<moves> >, bool) [20] game::get1(int, int) [32] game::removeRun(int, int, int, int)
  [15] AI::maxValue(game, double, double, int) [10] game::get2(int, int) [48] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...) [clone .constprop.194]
  [26] AI::minValue(game, double, double, int) [11] game::get3(int, int) [18] void std::vector<moves, std::allocator<moves> >::_M_range_insert<__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > > >(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, __gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, std::forward_iterator_tag)
   [6] game::getRunDown(int)  [12] game::get4(int, int)   [21] void std::vector<moves, std::allocator<moves> >::_M_realloc_insert<moves const&>(__gnu_cxx::__normal_iterator<moves*, std::vector<moves, std::allocator<moves> > >, moves const&)
  [51] game::insertRing(int, int, int) [46] game::get5(int, int) [49] void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  [16] game::validMoves(int)   [3] game::getRun(int)      [52] void std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > >::_M_realloc_insert<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >(__gnu_cxx::__normal_iterator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >*, std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > > >, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&&)
  [45] game::performMove(moves, int) [4] game::getRunSE(int) [22] void std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > >::_M_realloc_insert<std::pair<std::vector<moves, std::allocator<moves> >, double> >(__gnu_cxx::__normal_iterator<std::pair<std::vector<moves, std::allocator<moves> >, double>*, std::vector<std::pair<std::vector<moves, std::allocator<moves> >, double>, std::allocator<std::pair<std::vector<moves, std::allocator<moves> >, double> > > >, std::pair<std::vector<moves, std::allocator<moves> >, double>&&)
  [14] game::getDirection(int, int, int, int) [8] game::getRunSW(int) [47] void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&)
   [5] game::getRunSEUtil(int, int, int, int) [13] game::moveRing(int, int, int, int) [23] void std::vector<int, std::allocator<int> >::emplace_back<int>(int&&)
   [9] game::getRunSWUtil(int, int, int, int) [44] game::terminal() [17] void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&)
   [1] game::get_features(int) [30] game::getValid0(int, int)
