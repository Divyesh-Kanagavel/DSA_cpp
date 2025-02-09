class Printer:
    def __init__(self):
        self.queue = []
    
    def queue_print_job(self, document):
        self.queue.append(document)
    
    def run(self):
        while self.queue:
            self.print_job(self.queue.pop(0))
    
    def print_job(self, document):
        print(document)

printer = Printer()
printer.queue_print_job("First Document") 
printer.queue_print_job("Second Document") 
printer.queue_print_job("Third Document")

printer.run()
