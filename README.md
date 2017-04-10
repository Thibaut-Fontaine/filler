# Filler

Algorithm explication :

- Calculate the closest point of the p2 from the p1 (us player)
- Calculate all the next moves the p2 can do
- Calculate if our next move will block a probable move of the p2
- If not, go on the closest point of the p2
- If yes, go on the position who will block the most possible moves of the p2

Make, then Run the program as following : 
make && ./resources/filler_vm -f ./resources/maps/map01 -p1 ./resources/players/carli.filler -p2 ./tfontain.filler
