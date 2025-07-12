# Write a program which takes a pathname, and retums the shortest equivalent pathname. Assume
# individual directories and files have names that use only alphanumeric characters

def shortest_equivalent_path(path_name):
    if not path_name:
        raise IndexError("Empty string is not a valid path")
    
    path_list = []
    if path_name[0] == '/':
        path_list.append('/')
    
    # we need to take out the /../ and replace with previous directory.
    # exception is when the path begins with .. or ../.. and so on
    for token in (token for token in path_name.split('/') if token not in ['.','']):
        if token == '..':
            if not path_list or path_list[-1] == '..':
                path_list.append(token)
            else:
                if path_list[-1] == '/':
                    raise ValueError("not a valid path")
                path_list.pop()
        else:
            path_list.append(token)
    
    ret_path = '/'.join(path_list)
    return ret_path[ret_path.startswith('//'):] # avoid paths starting with //

if __name__ == "__main__":
    path = "/home/divy/../hary"
    print(shortest_equivalent_path(path))


    
    