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

#ifndef FULLADDER_H
#define FULLADDER_H

namespace Commons {

namespace Lab {

namespace unlogical {

namespace arith {
    
class FullAdder {
public:
    typedef struct _result {
        _result(bool r, bool c) : result(r), carry(c) {}
        
        const bool result;
        const bool carry;
    } RESULT;
    
    FullAdder(bool a, bool b, bool c) : m_a(a), m_b(b), m_c(c) {}
    
    RESULT operator()() const;
    
private:
    const bool m_a;
    const bool m_b;
    const bool m_c;
};

}

}

}

}

#endif /* FULLADDER_H */
