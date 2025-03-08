def TOH(n, src, temp, dest):
    if n == 1:
        print(f"Move disk 1 from {src} to {dest}")
    else:
        TOH(n - 1, src, dest, temp) 
        print(f"Move disk {n} from {src} to {dest}")
        TOH(n - 1, temp, src, dest)

n = int(input("Enter the number of disks: "))
print(f"The sequence of moves for {n} disks:")
TOH(n, 'A', 'B', 'C')
