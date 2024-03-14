# HTB Cyber Apocalypse 2024

## Stop Drop and Roll

>  Author: ir0nstone


## Solution

Connecting to the server prompts you this

```
===== THE FRAY: THE VIDEO GAME =====
Welcome!
This video game is very simple
You are a competitor in The Fray, running the GAUNTLET
I will give you one of three scenarios: GORGE, PHREAK or FIRE
You have to tell me if I need to STOP, DROP or ROLL
If I tell you there's a GORGE, you send back STOP
If I tell you there's a PHREAK, you send back DROP
If I tell you there's a FIRE, you send back ROLL
Sometimes, I will send back more than one! Like this: 
GORGE, FIRE, PHREAK
In this case, you need to send back STOP-ROLL-DROP!
Are you ready? (y/n) 
```

So I just need to create a script that reads what they send me and answers the correct instructions back
<br/>[`solve.py`](solve.py)

After running the script for a minute I got the flag