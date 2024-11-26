1. **Problem Scenarios**:
    
    - **Party Invitation Problem**: Solving constraints for whom to invite to a party based on individual preferences.
    - **Room Allocation Problem**: Assigning rooms to university courses based on specific requirements.
2. **Core Concepts**:
    
    - **CSP**: Problems involving assigning values to variables under constraints.
    - **Variables, Domains, and Constraints**: Variables have domains of possible values, and constraints restrict value combinations.
3. **Problem Representation**:
    
    - Formulating problems with constraints either as logical predicates (intensional) or explicit combinations (extensional).
    - Using schemas and tuples for formal representation.
4. **Algorithms and Techniques**:
    
    - **Generate-and-Test**: Testing all possible value assignments, suitable for small-scale problems.
    - **Partial Assignments**: Incrementally building solutions while pruning inconsistent assignments.
    - **Search Techniques**: Depth-first search to explore the solution space.
    - **Domain Reduction**: Using techniques like arc-consistency to eliminate invalid values and reduce the search space.
5. **Graph Representation**:
    
    - Constraint networks represent variables and their relationships.
    - Algorithms for achieving domain and arc consistency.
6. **Advanced Methods**:
    
    - **Domain Splitting**: Dividing variable domains into subsets to simplify problem-solving.
    - **Optimization Techniques**: Reducing computational complexity and focusing on feasible solutions.
7. **Examples and Practice**:
    
    - Worked examples demonstrate applying domain reduction and search methods to solve CSPs.
    - Emphasis on formulating conditions, partial assignments, and consistency checks.
