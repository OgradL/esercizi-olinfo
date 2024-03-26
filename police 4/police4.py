#Scrivi qui il tuo codice
#!/usr/bin/env python3
import sys
sys.stdin = open("input.txt")
N, R, T, L = map(int, input().strip().split())
X = list(map(int, input().strip().split()))
X.sort()

log_indent = 0



def log(*text, **kwargs):
    pass


def emulate(semaphores_list, semaphores_time, pos=0, clock=0, skip=R):
    global log_indent
    log_indent += 4
    for sem in semaphores_list:
        clock += sem - pos
        pos += sem - pos
        is_sem_red = int(clock / semaphores_time) % 2
        if not is_sem_red:
            semaphores_list = semaphores_list[1:]
            continue
        else:
            if skip:
                wait = emulate(semaphores_list[1:], T, pos, (int(clock/T) + 1)*T, skip)

                ignore = emulate(semaphores_list[1:], T, pos, clock, skip-1)
                clock = min(wait, ignore)
                break
            else:
                clock = (int(clock/T) + 1)*T
                continue
    log_indent -= 4
    return clock


if R >= N:
    print(L)
else:
    print(emulate(X, T) + (L-X[-1]))
    