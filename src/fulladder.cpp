/*
 * Copyright 2018 by Heiko Schäfer <heiko@rangun.de>
 *
 * This file is part of unlogical.
 *
 * DiskFit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * DiskFit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with DiskFit.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fulladder.h"

#include "halfadder.h"
#include "orgate.h"

using namespace Commons::Lab::unlogical::arith;

FullAdder::RESULT FullAdder::operator()() const {
    
    HalfAdder  har1(m_a, m_b);
    HalfAdder  har2(har1().result, m_c);
    gate::ORGate ol(har2().carry, har1().carry);
    
    return FullAdder::RESULT(har2().result, ol());
}
