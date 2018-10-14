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

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include "carryrippleadder.h"

namespace Commons {

namespace Lab {

namespace unlogical {

namespace arith {

template<class T, int N>
class Subtractor {
public:
    typedef T number_type;
    
    Subtractor(const number_type& a, const number_type& b) : m_a(a), m_b(b) {}
    
    number_type operator()() const {
        return CarryRippleAdder<T, N>(m_a, CarryRippleAdder<T, N>(~m_b, 1)())();
    }
    
private:
    const number_type m_a;
    const number_type m_b;
};

}

}

}

}

#endif /* SUBTRACTOR_H */

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
