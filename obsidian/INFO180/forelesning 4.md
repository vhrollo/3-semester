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




### **Variants of Local Search**

1. **Standard Local Search**:
    
    - Explore neighbors of the current solution.
    - Stop when a satisfying solution or stopping criterion is reached.
2. **Simple Variants**:
    
    - **Random Selection**: Pick neighbors or variables randomly.
		- repeat thing until too many is tried
    - **Random Walk**: Randomly explore neighbors until a solution is found.
		- chooses a random neighbor and walks until its pleased
1. **Greedy Search** (Iterative Improvement):
    
    - Iteratively improves the solution by selecting changes that most improve the objective function.
    - Variants:
        - Consider all neighbors and pick the best (most improving step).
        - Modify only variables that cause the largest errors (two-stage choice).
        - Use a **tabu list** to avoid revisiting recently explored solutions.
4. **Simulated Annealing**:
    
    - Combines random exploration with gradual convergence to an optimal solution.
    - **Steps**:
        - Start with a high probability of accepting worse solutions.
        - Gradually reduce this probability (temperature) over iterations.
        - Helps escape local optima early in the process.
    - Probability formula: $p = e^{\frac{\Delta f}{T}}$​ Where $\Delta f$ is the change in the objective function, and T is the temperature.
5. **Beam Search**:
    
    - Maintain a population of k solutions (beams).
    - At each step, explore neighbors of all current solutions and select the k best.
    - Stochastic variant: Select solutions probabilistically based on their fitness.