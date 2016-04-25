/*
  Challenger, a UCI chess playing engine derived from Stockfish
  
  Copyright (C) 2013-2017 grefen

  Challenger is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Challenger is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TIMEMAN_H_INCLUDED
#define TIMEMAN_H_INCLUDED

/// The TimeManager class computes the optimal time to think depending on the
/// maximum available time, the move game number and other parameters.

class TimeManager {
public:
  void init(const Search::LimitsType& limits, int currentPly, Color us);
  void pv_instability(float bestMoveChanges);
  int available_time() const { return optimumSearchTime + unstablePVExtraTime; }
  int maximum_time() const { return maximumSearchTime; }

private:
  int optimumSearchTime;
  int maximumSearchTime;
  int unstablePVExtraTime;
};

#endif // #ifndef TIMEMAN_H_INCLUDED
