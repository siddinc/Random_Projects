board = [" " for i in range(9)]

def print_board():
    for i in range(3):
        print("   |   |   ")
        for j in range(3):
            print(" {} ".format(board[3*i + j]), end = "|" if j<2 else "\n")
        print("   |   |   ")
        print("---+---+---" if i<2 else "")


def player_move(icon):
     if icon == "X":
          number = 1
     elif icon == "O":
          number = 2

     print("Your turn player {}".format(number))    

     choice = int(input("Enter your move (1-9): ").strip())
     if board[choice - 1] == " ":
          board[choice - 1] = icon
     else:
          print()
          print("That space is taken!")

def is_victory(icon):
     if (board[0] == icon and board[1] == icon and board[2] == icon) or \
        (board[3] == icon and board[4] == icon and board[5] == icon) or \
        (board[6] == icon and board[7] == icon and board[8] == icon) or \
        (board[0] == icon and board[3] == icon and board[6] == icon) or \
        (board[1] == icon and board[4] == icon and board[7] == icon) or \
        (board[2] == icon and board[5] == icon and board[8] == icon) or \
        (board[0] == icon and board[4] == icon and board[8] == icon) or \
        (board[2] == icon and board[4] == icon and board[6] == icon):
          return True
     else:
          return False

def is_draw():
     if " " not in board:
          return True
     else:
          return False
          
        
     
     
while True:
     print_board()
     player_move("X")
     print_board()
     if is_victory("X"):
          print("X wins! Congratulations!")
          break
     elif is_draw():
          print("Its a draw!")
          break
     
     player_move("O")
     if is_victory("O"):
          print_board()
          print("O wins! Congratulations!")
          break
     elif is_draw():
          print("Its a draw!")
          break
