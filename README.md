*This project has been created as part of the 42 curriculum by zgeorges.*

---

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. Given a stack of
integers passed as command-line arguments, the program outputs the shortest possible
sequence of operations that sorts them in ascending order using exactly two stacks,
A and B.

The allowed operations are:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap the top two elements of stack A / B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top of B onto A / top of A onto B |
| `ra` / `rb` | Rotate stack A / B upward (top goes to bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack A / B (bottom goes to top) |
| `rrr` | `rra` and `rrb` simultaneously |

Performance targets for full score:
- 100 numbers sorted in **under 700 operations**
- 500 numbers sorted in **under 5500 operations**

The algorithm used is a greedy insertion sort inspired by the community-named
**Turkish algorithm**: all nodes are pushed blindly to B, the remaining 3 in A are
sorted with `sort_3`, then each B node is inserted back into A at its cheapest cost,
using simultaneous rotations (`rr`/`rrr`) when both stacks rotate in the same direction
to minimise total operation count.

---

## Instructions

### Compilation

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

### Usage

```bash
./push_swap 3 1 2 5 4
./push_swap "3 1 2 5 4"
./push_swap 3 "1 2" 5 4
```

All three forms are equivalent — arguments are flattened before parsing.

The program prints each operation on its own line to stdout. If the input is already
sorted, nothing is printed.

### Error cases

The program prints `Error` to stderr and exits with code 1 if:
- Any argument is not a valid integer
- Any argument is outside the `int` range (−2 147 483 648 to 2 147 483 647)
- There are duplicate values

### Benchmarking

```bash
# Count operations for 100 random numbers
ARG=$(python3 -c 'import random; l=list(range(1,101)); random.shuffle(l); print(*l)')
./push_swap $ARG | wc -l

# Count operations for 500 random numbers
ARG=$(python3 -c 'import random; l=list(range(1,501)); random.shuffle(l); print(*l)')
./push_swap $ARG | wc -l
```

---

## Resources

### References

- [push_swap — medium tutorial by Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — overview of common approaches
- [Turkish algorithm video (YouTube)](https://www.youtube.com/watch?v=OaG81sDEpVk) — the community tutorial that popularised the greedy cost-based insertion approach used here
- [Visualiser by o-reo](https://github.com/o-reo/push_swap_visualizer) — renders the operation sequence graphically, useful for debugging

### AI usage

Claude (Anthropic) was used as a development assistant throughout this project via
Claude Code. Specific contributions:

- **Architecture and design decisions** — data structure layout, file/function split,
  algorithm choice and cost formula
- **Implementation** — all functions in `stack_init_utils.c`, `node_data.c`, `algo.c`,
  and the `push_swap` body in `main.c` were written with AI assistance
- **Bug fixing** — identified and fixed the compound-operation output bug (`ss`/`rr`/`rrr`
  were calling component functions and printing triple output), the `exit_msg` char-literal
  bug, and `push_instructions.c` misleading-indentation bug
- **Norminette compliance** — all files were reviewed and corrected to pass the 42
  Norminette checker
- **Code review** — header file audit, function signature mismatches, missing declarations

---

## Tracing

End-to-end data flow from `main` through every call site.

```
main                        (main.c)
 │   Validates argc, builds the flat token array, creates the
 │   stack, checks if already sorted, then dispatches.
 │
 ├── flatten_input           (main_utils.c)
 │    │   Merges all argv strings into one flat NULL-terminated
 │    │   array of tokens, handling "a b c", a b c, and "a b" c uniformly.
 │    │
 │    └── count_tokens       (main_utils.c)
 │         └── ft_split      (parsing.c)
 │              └── wrd_count, get_word    (parsing_utils.c)
 │
 ├── create_stack            (parsing.c)
 │    │   Iterates the flat array, validates each token, checks for
 │    │   duplicates, builds the doubly linked list, then frees flat.
 │    │
 │    ├── is_int             (stack_init_utils.c)
 │    │     Checks the string is a valid signed integer within INT range.
 │    ├── ft_atoi            (stack_init_utils.c)
 │    ├── has_duplicates     (stack_init_utils.c)
 │    ├── new_node           (stack_init_utils.c)
 │    ├── append_node        (stack_init_utils.c)
 │    └── exit_msg           (parsing.c)
 │         └── free_stack    (stack_utils.c)
 │         └── free_flat     (parsing.c)
 │
 ├── is_sorted               (stack_utils.c)
 │
 └── cases                   (main.c)
      │   Routes to the appropriate sort based on stack length.
      │
      ├── sa                 (swap_instructions.c)   ← len == 2
      │
      ├── sort_3             (main.c)                ← len == 3
      │    │   Moves the largest element to the bottom with at most
      │    │   one rotation, then fixes the top two with at most one sa.
      │    └── ra, rra       (rotate_instructions.c / reverse_rotate_instructions.c)
      │    └── sa            (swap_instructions.c)
      │
      └── push_swap          (main.c)                ← len > 3
           │
           ├── pb            (push_instructions.c)   ← blind dump: repeat until 3 remain in A
           │
           ├── sort_3        (main.c)
           │
           ├── [loop] init_node_data   (node_data.c) ← refreshes metadata every B→A iteration
           │    │   Recomputes positions, targets, and costs so the
           │    │   cheapest node reflects the current stack state.
           │    │
           │    ├── set_positions      (node_data.c)
           │    │     Writes 0, 1, 2… into each node's pos field top-to-bottom.
           │    │
           │    ├── set_targets        (node_data.c)
           │    │     For each B node, finds the A node with the smallest
           │    │     value strictly greater than the B node's value.
           │    │     Wraps to the minimum of A if no greater value exists.
           │    │     └── get_smallest (stack_utils.c)
           │    │
           │    └── set_costs          (node_data.c)
           │         │   Computes cost for every B node and marks the
           │         │   one with the lowest total_cost as is_cheapest.
           │         │
           │         └── calc_cost     (node_data.c)
           │               For one B node: cost_self = min(pos, len_b − pos),
           │               cost_target = min(target.pos, len_a − target.pos).
           │               total_cost = max(both) if same direction, sum if opposite.
           │               └── stack_len (stack_utils.c)
           │
           ├── [loop] move_the_damn_node  (algo.c)   ← moves cheapest B node into A
           │    │   Finds the is_cheapest node, chooses simultaneous or
           │    │   individual rotations, then pushes to A.
           │    │
           │    ├── rr_looped          (algo.c)
           │    │     Issues rr while both cheapest and its target still
           │    │     need forward rotation, advancing both simultaneously.
           │    │     └── rr           (rotate_instructions.c)
           │    │          └── rotate_stack (rotate_instructions.c)
           │    │
           │    ├── rrr_looped         (algo.c)
           │    │     Same as rr_looped but for reverse rotation.
           │    │     └── rrr          (reverse_rotate_instructions.c)
           │    │          └── rev_rotate_stack (reverse_rotate_instructions.c)
           │    │
           │    ├── finish_loop        (algo.c)
           │    │     Rotates one stack individually until the target
           │    │     node reaches the top, picking ra/rb or rra/rrb
           │    │     based on whichever direction is shorter.
           │    │     └── ra / rra / rb / rrb
           │    │
           │    └── pa                 (push_instructions.c)
           │
           └── final alignment
                │   Rotates A until the minimum value is at the top.
                │
                ├── set_positions      (node_data.c)
                ├── get_smallest       (stack_utils.c)
                └── ra or rra
```
