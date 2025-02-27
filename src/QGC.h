/*=====================================================================

 QGroundControl Open Source Ground Control Station

 (c) 2009 - 2011 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

 This file is part of the QGROUNDCONTROL project

 QGROUNDCONTROL is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 QGROUNDCONTROL is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

 ======================================================================*/

#ifndef QGC_H
#define QGC_H

#include "configuration.h"
#include <QDateTime>
#include <QColor>
#include <QThread>

#include <QGCMAVLink.h>

#define define2string_p(x) #x
#define define2string(x) define2string_p(x)

#if defined(_MSC_VER) && (_MSC_VER<1800)
        #include <limits>

        template<typename T>
        inline bool isnan(T value){
            return value != value;
        }

        template<typename T>
        inline bool isinf(T value){
            return (value == std::numeric_limits<T>::infinity() || (-1*value) == std::numeric_limits<T>::infinity()) && std::numeric_limits<T>::has_infinity;
        }
#else
    #include <cmath>

    #if defined(Q_OS_MACX) || defined(Q_OS_WIN)
        #ifndef isnan
            #define isnan(x) std::isnan(x)
        #endif
        #ifndef isinf
            #define isinf(x) std::isinf(x)
        #endif
    #endif
#endif

namespace QGC
{

const static int defaultComponentId = MAV_COMP_ID_PRIMARY; // The main component ID is 1 for autopilot/and GCS (0 means all components)

const QColor colorCyan(55, 154, 195);
const QColor colorRed(154, 20, 20);
const QColor colorGreen(20, 200, 20);
const QColor colorYellow(255, 255, 0);
const QColor colorOrange(255, 140, 0);
const QColor colorMagenta(255, 0, 55);
const QColor colorDarkWhite(240, 240, 240);
const QColor colorDarkYellow(180, 180, 0);
const QColor colorBackground("#050508");
const QColor colorBlack(0, 0, 0);

/** @brief Get the current ground time in microseconds */
quint64 groundTimeUsecs();
/** @brief Get the current ground time in milliseconds */
quint64 groundTimeMilliseconds();
/** @brief Get the current ground time in seconds */
qreal groundTimeSeconds();
/** @brief Returns the angle limited to -pi - pi */
float limitAngleToPMPIf(float angle);
/** @brief Returns the angle limited to -pi - pi */
double limitAngleToPMPId(double angle);
int applicationVersion();

const static int MAX_FLIGHT_TIME = 60 * 60 * 24 * 21;

class SLEEP : public QThread
{
public:
    /**
     * @brief Set a thread to sleep for seconds
     * @param s time in seconds to sleep
     **/
    static void sleep(unsigned long s) {
        QThread::sleep(s);
    }
    /**
     * @brief Set a thread to sleep for milliseconds
     * @param ms time in milliseconds to sleep
     **/
    static void msleep(unsigned long ms) {
        QThread::msleep(ms);
    }
    /**
     * @brief Set a thread to sleep for microseconds
     * @param us time in microseconds to sleep
     **/
    static void usleep(unsigned long us) {
        QThread::usleep(us);
    }
};

}

#define QGC_EVENTLOOP_DEBUG 0

#endif // QGC_H
