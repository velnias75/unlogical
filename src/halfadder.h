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

#ifndef HALFADDER_H
#define HALFADDER_H

class HalfAdder {
public:
    typedef struct _result {
        _result(bool r, bool c) : result(r), carry(c) {}
        
        const bool result;
        const bool carry;
    } RESULT;
    
    HalfAdder(bool a, bool b) : m_a(a), m_b(b) {}
    
    RESULT operator()() const;
    
private:
    const bool m_a;
    const bool m_b;
};

#endif /* HALFADDER_H */
