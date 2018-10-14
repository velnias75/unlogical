/*
 * Copyright 2018 by Heiko Schäfer <heiko@rangun.de>
 *
 * This file is part of unlogical.
 *
 * unlogical is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * unlogical is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with unlogical.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "halfadder.h"

#include "andgate.h"
#include "xorgate.h"

using namespace Commons::Lab::unlogical::arith;

HalfAdder::RESULT HalfAdder::operator() () const {
    return HalfAdder::RESULT ( gate::XORGate ( m_a, m_b ) (), gate::ANDGate ( m_a, m_b ) () );
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
