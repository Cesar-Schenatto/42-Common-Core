#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number_of_values>"
    exit 1
fi

ARG=$(seq 1 $1 | shuf | tr '\n' ' ')  # Generate shuffled numbers from 1 to x
echo "Testing with: $ARG"

./push_swap $ARG | ./checker_linux $ARG  # Run push_swap and check output

MOVES=$(./push_swap $ARG | wc -l)  # Count moves
echo "Moves: $MOVES"
