print("Type 'help' in the command line to briefly understand the game")
command=""
while True:
        command=input(">").lower()
        if command =="start":
            print("Bus started, ready to go ------> |----------|")
            print("                                 |          |  ")
            print("                                 |----------|             ")
            print("                                  o o    o o     ")
        elif command=="stop":
            print("Bus stopped,  |----------|")
            print("              |          |  ")
            print("              |----------|             ")
            print("               o o    o o     ")
        elif command=="help":
            print("start=to start the Bus,\nstop=to stop the Bus,\nquit=to quit the game.")
        elif command=="quit":
            print("Thanks for playing,We hope you return back here soon.")
            break
        else:

                print("Sorry,i didn't understand ...\nPLEASE TRY AGAIN.")