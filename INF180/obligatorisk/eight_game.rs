use std::collections::{HashMap, HashSet, BinaryHeap};
use std::cmp::Ordering;

struct EightGame {
    start: [[u8; 3]; 3],
    goal_map: HashMap<u8, (usize, usize)>, 
    goal: [[u8; 3]; 3],
}

impl EightGame {
    fn new(start: [[u8; 3]; 3], goal: [[u8; 3]; 3]) -> EightGame {
        EightGame {
            start: start,
            goal_map: Self::precompute_goal(&goal),
            goal: goal,
        }
    }

    fn solve(&self) {
        let mut seen = BinaryHeap::<EightGameNode>::new();
        let mut searched = HashSet::<EightGameNode>::new();
        let empty = self.get_empty(&self.start);

        let start_node = EightGameNode::new(0, self.cal_h(self.start), self.start, None, empty);

        seen.push(start_node);
        while let Some(node) = seen.pop() {

            if node.board == self.goal {
                println!("Solution found!, printing path:\n");
                let mut path = vec![node.board];
                let mut current = node.clone();
                while let Some(parent) = current.last {
                    path.push(parent.board);
                    current = *parent;
                }
                for board in path.iter().rev() {
                    for row in board.iter() {
                        println!("{:?}", row);
                    }
                    println!();
                }
                println!("------------");
                println!("Moves: {}", path.len());
                println!();
                return;
            }
            if searched.contains(&node) {
                continue;
            } else {
                searched.insert(node.clone());
            }
            let cost = node.cost + 1;
            for &(dx, dy) in &[(0, 1), (0, -1), (1, 0), (-1, 0)] {
                let (x, y) = node.empty;
                let (nx, ny) = (x as isize + dx, y as isize + dy);
                if nx >= 0 && nx < 3 && ny >= 0 && ny < 3 {
                    let mut new_board = node.board.clone();
                    new_board[x][y] = new_board[nx as usize][ny as usize];
                    new_board[nx as usize][ny as usize] = 0;
                    let h = self.cal_h(new_board);
                    let new_empty = (nx as usize, ny as usize);
                    let new_node = EightGameNode::new(cost, h, new_board, 
                        Some(Box::new(node.clone())), new_empty);
                    if !searched.contains(&new_node) {
                        seen.push(new_node);
                    }
                }
            }
        }

    }

    fn precompute_goal(goal: &[[u8; 3]; 3]) -> HashMap<u8, (usize, usize)> {
        let mut goal_pos = HashMap::new();
        for i in 0..3 {
            for j in 0..3 {
                goal_pos.insert(goal[i][j], (i, j));
            }
        }
        goal_pos
    }

    fn get_empty(&self, board: &[[u8; 3]; 3]) -> (usize, usize) {
        for (i, row) in board.iter().enumerate() {
            for (j, &val) in row.iter().enumerate() {
                if  val == 0 {
                    return (i,j);
                }
            }
        }
        (0,0)
    }

    fn cal_h(&self, board: [[u8; 3]; 3]) -> u8 {
        let mut h: u8 = 0;
        for i in 0..3 {
            for j in 0..3 {
                let value = board[i][j];
                if value != 0 {
                    let &(x, y) = self.goal_map.get(&value).unwrap();
                    h += (x as i8 - i as i8).abs() as u8 + (y as i8 - j as i8).abs() as u8
                }
            }
        }
        h
    }
}

#[derive(Eq, PartialEq, Hash, Clone)]
struct EightGameNode {
    cost: u8,
    h: u8,
    board: [[u8; 3]; 3],
    last: Option<Box<EightGameNode>>,
    empty: (usize,usize),
}

impl EightGameNode {
    fn new(cost: u8, h: u8, board: [[u8; 3]; 3], past_node: Option<Box<EightGameNode>>, empty: (usize, usize)) -> EightGameNode {
        EightGameNode {
            cost,
            h,
            board,
            last: past_node,
            empty,
        }
    }
}

impl Ord for EightGameNode {
    fn cmp(&self, other: &Self) -> Ordering {
        (self.cost + self.h).cmp(&(other.cost + other.h)).reverse()
    }
}

impl PartialOrd for EightGameNode {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let board: [[u8; 3]; 3] = [[1,2,3],[4,0,6],[7,5,8]];
    let board2: [[u8; 3]; 3] = [[6,4,7],[8,5,0],[3,2,1]];
    let goal : [[u8; 3]; 3] = [[1,2,3],[4,5,6],[7,8,0]];
    let game = EightGame::new(board2, goal);
    game.solve();
}