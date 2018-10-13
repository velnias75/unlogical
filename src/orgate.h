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

#ifndef ORLATTICE_H
#define ORLATTICE_H

namespace Commons {

namespace Lab {

namespace unlogical {

namespace gate {
    
class ORGate {
public:
    ORGate(bool a, bool b) : m_a(a), m_b(b) {}
    
    inline bool operator()() const {
        return m_a | m_b;
    }
    
private:
    const bool m_a;
    const bool m_b;
};

}

}

}

}

#endif /* ORLATTICE_H */
