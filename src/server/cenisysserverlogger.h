/*
 * CenisysServerLogger
 * Copyright (C) 2016 iTX Technologies
 *
 * This file is part of Cenisys.
 *
 * Cenisys is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cenisys is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cenisys.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CENISYS_CENISYSSERVERLOGGER_H
#define CENISYS_CENISYSSERVERLOGGER_H

#include <list>
#include <mutex>
#include "server/serverlogger.h"

namespace cenisys
{

class CenisysServerLogger : public ServerLogger
{
public:
    //!
    //! \brief Allocate a logger.
    //!
    CenisysServerLogger();
    //!
    //!\brief Free a logger.
    //!
    ~CenisysServerLogger();

    //!
    //! \brief Write the line to server console.
    //! \param content The content to write.
    //!
    void log(const std::string &content);

    //!
    //! \brief Register a backend of console logger.
    //! \param backend The function to call.
    //! \return A handle to unregister the backend.
    //!
    RegisteredLoggerBackend registerBackend(LoggerBackend backend);

    //!
    //! \brief Remove the backend from the registered list.
    //! \param backend The handle returned by registerBackend.
    //!
    void unregisterBackend(RegisteredLoggerBackend handle);

private:
    BackendList _backends;
    std::mutex _backendListLock;
};

} // namespace cenisys

#endif // CENISYS_CENISYSSERVERLOGGER_H