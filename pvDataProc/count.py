import time

while True:
    # Contagem crescente
    for i in range(0, 10001):
        print(f"{i};{10000 - i}", flush=True)
        time.sleep(0.1)

    # Contagem decrescente
    for i in range(10000, -1, -1):
        print(f"{i};{10000 - i}", flush=True)
        time.sleep(0.1)
