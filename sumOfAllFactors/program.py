def sum_of_factors(x):
    sum=0
    for i in range(1,x+1):
        if(x%i==0):
            sum=sum+i
    return sum

def main():
    n=int(input("Enter a number:"))
    print("Sum of all factors will be "+str(sum_of_factors(n)))

main()
