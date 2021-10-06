def find_all(x):
    for i in range(1,x+1):
        if(x%i==0):
            print(i)

def main():
    num=int(input("Enter a Natural number:-> "))
    print("Factors of "+str(num)+" are: ","\t")
    find_all(num)

main()