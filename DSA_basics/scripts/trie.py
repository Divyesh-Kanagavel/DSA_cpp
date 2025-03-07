# used in autocomplete , autocorrect and in other areas involving IP addresses, numbers in phonebook etc

# each parent node contains children nodes which are hashmaps of characters
class TrieNode:
    def __init__(self):
        self.children = {}


class Trie:
    def __init__(self):
        self.root = TrieNode()
    # search for a word in our trie data structure
    # the time complexity of this function is O(k) where k is length of word
    # does not depend on the number of words stored in data structure, to search for character, hashmap is used with O(1) time complexity
    def search(self, word):
        current_node = self.root
        for char in word:
            if current_node.children.get(char):
                current_node = current_node.children[char]
            else:
                return None
        return current_node
    # insert a word into our trie data structure
    # time complexity : O(k+1) ~ O(k) where k is length of input word
    def insert(self, word, value):
        current_node = self.root
        for char in word:
            if current_node.children.get(char):
                current_node = current_node.children[char]
            else:
                newNode = TrieNode()
                current_node.children[char] = newNode
                current_node = newNode
        current_node.children['*'] = value # word delimiter with value added -> higher the value , the more the popular the word is. useful for better autocomplete

    def collectAllWords(self, current_node=None, word = "", words = {}):
        current_node = current_node or self.root
        for key, child_node in current_node.children.items():
            if key == '*':
                words[word] = child_node
            else:
                self.collectAllWords(child_node, word + key, words)
        return words
    # better autocomplete which sorts the words based on popularity through value and gives the top possibilities
    def autocomplete(self, prefix):
        current_node = self.search(prefix)
        if not current_node:
            return None
        else:
            words = self.collectAllWords(current_node)
            if len(words) < 3:
                return list(words.keys())
            else:
                return sorted(words.keys(), key=words.get, reverse=True)[:3]
    # traverse each node of the trie
    def traverse(self, current_node=None):
        current_node = current_node or self.root
        for key, child_node in current_node.children.items():
            print(key)
            if key != '*':
                self.traverse(child_node)
    
    def prefix(self, word, prefix_word = ""):
        current_node = self.root
        for char in word:
            if current_node.children.get(char):
                current_node = current_node.children[char]
                prefix_word += char
            else:
                return current_node, prefix_word
        return (current_node,prefix_word)

    def autocorrect(self, word):
        current_node,prefix_word = self.prefix(word)
        if not current_node:
            return None
        return " ,".join(prefix_word + word for word in list(self.collectAllWords(current_node).keys()))

        
# tests

trie = Trie()
trie.insert("apple",9)
trie.insert("app",5)
trie.insert("ape",1)
trie.insert("apps",4)
trie.insert("bat",9)
trie.insert("batter",4)
trie.insert("battle",4)
trie.insert("cat",8)
trie.insert("cattle",3)
trie.insert("batman",2)

a = trie.search("bat")
print(a.children.keys())


#print(trie.autocomplete("ap"))
    
print(trie.autocorrect("apak"))
    





