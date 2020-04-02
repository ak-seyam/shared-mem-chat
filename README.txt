Chat between shared data
Issues to be solved:
You can't send twice from a single participate

How the protocol works:

send_message()    |-> ------ | receiving() 
waiting_for_done  |          |
                  | ----- <- | done
waiting receiving |	     | wait_to_avoid_stalling_second
		  | ----- <- | send_messege()
 
