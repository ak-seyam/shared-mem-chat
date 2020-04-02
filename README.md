# Chat between shared data
# Hotfix1: change sending receiving paradigm
send_message()   |-> ------ | receiving() 
waiting_for_done |          |
                 | ----- <- | done
waiting receiving|	   | wait_to_avoid_stalling_second
		 | ----- <- | send_messege()
 
