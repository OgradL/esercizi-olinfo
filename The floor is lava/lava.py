
import sys
import os
import time
import random
import math


currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))



H, W = list(map(int, input().strip().split()))


class cell:
    def __init__(self, cella, x, y):
        self.x = x
        self.y = y
        self.cell = cella
        self.distance = W * H

    def calculate(self, board, distance):

        self.distance = distance
        
        

        
        
board = [['.'] * W] * H

for i in range(H):
    board[i] = [char for char in input().strip().replace(" ", "")]

    for j in range(len(board[i])):
        board[i][j] = cell(board[i][j], j, i)
    

board[0][0].calculate(board, 0)



