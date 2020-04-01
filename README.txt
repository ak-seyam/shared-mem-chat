# Chat between shared data

send_message()   |-> ------ | receiving() 

waiting_for_done |          |

                 | ----- <- | done

waiting receiving|	   | wait_to_avoid_stalling_second

		 | ----- <- | send_messege()
 
