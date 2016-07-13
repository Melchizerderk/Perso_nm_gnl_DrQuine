import sys

class formulae :

	def __init__(self):
		self.left = "" 
		self.right = ""

def main() :
	expression = formulae()
	string = sys.argv[1]
	expression.left, expression.right = string.split("=")
	print(expression.left, expression.right)
	for (i = 0; expression.left[i] != '\0'; i++)


if __name__ == '__main__' :
	main()
