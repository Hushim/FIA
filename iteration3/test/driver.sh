#!/bin/bash

echo "Hello, $USER !"
echo "This is MIA regression test"
source script/comparison.sh
source script/bad-input.sh
source script/filter.sh
source script/filter-chain.sh
source script/batch.sh

