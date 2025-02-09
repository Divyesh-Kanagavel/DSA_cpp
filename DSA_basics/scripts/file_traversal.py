# the objective is to list all the files inside a directory and its subdirectories
import os
dir = '/Users/divyeshkanagavel/Desktop/Books'

def list_files(dir):
    for file in os.listdir(dir):
        if os.path.isfile(dir + '/' + file):
            print(file)
        if os.path.isdir(dir + '/' + file):
            if file!='.' and file!='..':
                list_files(dir + '/' + file)

list_files(dir)

        
    