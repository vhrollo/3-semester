*ubruklig fag god damn*
Simulert herding (Simulated annealing)
- Hvert steg vurder å ta et nytt med en sannsynlighet som synket for hver gang man gjør det
- Slik at man evt kan unngå lokale minima eller maksima
- The tempreture is the randomness which slowly gets lower

Beam search
- Always maintain 'k' solution as each iteration. For each individual, find best k.
- This is basically just trying multiple times, and hoping one of them is better

Stochastic beam search
- basically beam search with simulated annealing, where the "temperature" of doing random choices lower throughout the search

Genetisk
- gitt en array med variabler
- Velg ut de beste i par
- gjør et tilfeldig bytt
- og deretter muter de tilfeldig for å skape nye unike 