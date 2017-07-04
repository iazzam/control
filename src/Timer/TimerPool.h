/*!
 * @author Deep Dhillon
 * @date 2017-06-23
 * @brief This class provides Timers and TimerPool to execute functions at different times
 */

#ifndef CONTROL_TIMERPOOL_H
#define CONTROL_TIMERPOOL_H

#include <Arduino.h>

class TimerPool {
public:
    /*! Timer struct used by TimerPool */
    struct Timer {
    private:
        const unsigned long interrupt_time; /*!< interrupt time for each timer */
        void (*func)(); /*!< function to be executed when interrupt is called */

    public:
        /*!
         * Single constructor creates a Timer using interrupt time and function to be used
         * @param interrupt_time time after which the function must be called
         * @param func function to be called
         */
        Timer(const unsigned long interrupt_time, void (*func)());

        /*!
         * Gives access to the time of the timer
         * @return returns time interrupt
         */
        unsigned long getTime();

        /*!
         * Executes the function that has been assigned
         */
        void execute();
    };

    /*!
     * Single constructor creates a timer pool based on number of pools provided
     * @param num_timers number of pools to be created
     */
    TimerPool(int num_timers);

    /*!
     * Destructor deletes all the Timer Objects
     */
    ~TimerPool();

    /*!
     * Adds timer to the Timer Pool
     * @param t a Timer object to be added
     */
    void addTimer(Timer *t);

    /*!
    * Updates each timer based on the timer interrupt for each timer
    */
    void handleTimers();

private:
    Timer **timers;
    int counter;
    const int num_timers;
    unsigned long *current_micros;
};

#endif //CONTROL_TIMERPOOL_H
