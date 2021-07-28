# fcrownguard

> A relational database in modern C++

You can monitor the progress of the project on [the automated kanban board](https://github.com/jahan-addison/fcrownguard/projects/1?add_cards_query=is%3Aopen).

## Research

I plan to support at least 2 engine types (probably kv and B+ tree). In addition, I am particularly interested in investigating alternatives to SQL, which in general I find unintuitive while modern breakthrough research exists.

Relevant papers on relational models:

 * https://www.dcs.warwick.ac.uk/~hugh/TTM/DBE-Chapter11.pdf
 * https://www.seas.upenn.edu/~zives/03f/cis550/codd.pdf
 * https://www.dcs.warwick.ac.uk/~hugh/TTM/reference_material.html

I have sound [knowledge](https://github.com/jahan-addison/SDL-dart) of [computational lingustics](https://github.com/jahan-addison/ttre) and want to personally explore the nature of a formal system closed under relational algebra.

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

## Services

If the repository is activated with Travis-CI, then unit tests will be built and executed on each commit.
The same is true if the repository is activated with Appveyor.

If the repository is activated with Coveralls/Codecov, then deployment to Travis will also calculate code coverage and
upload this to Coveralls.io and/or Codecov.io


## Tests