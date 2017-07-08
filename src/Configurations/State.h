/*!
 * @author Deep Dhillon
 * @date 2017-06-06
 * @brief This class is the snapshot of various components' values at a given time
 */

#ifndef CONTROL_SNAPSHOT_H
#define CONTROL_SNAPSHOT_H

class State{
    public:
        bool board_on = false; /*!< status of board */

        // components state
        bool ballValve = 0; /*!< ball valve value*/
        int speed = 0; /*!< speed percentage of the pod */
        bool emergency = false; /*!< emergency flag*/
        bool brake = true; /*!< brake flag to determine if the pod braked*/
        bool run_autonomous = false; /*!< autonomous flag to determine when to run autonomous*/
        bool run_manual = false; /*!< manual flag to determine when to allow manual controls*/
        bool run_script = true; /*!< script flag to determine when to run a script*/


        // lev snapshots
        int lev_state = 0;
};

#endif
