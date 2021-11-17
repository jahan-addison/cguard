# crownguard

> A relational database in modern C++

You can monitor the progress on [the project kanban boards](https://github.com/jahan-addison/crownguard/projects).

## Details

The query language of choice is currently scheme + schemeQL. I plan to build a virtual machine and bytecode engine quite similar to SQLite, such that querying the relational model is "free" from storage itself.

## Research

I am particularly interested in investigating alternatives to SQL for the relational model, which in general I find unintuitive while modern breakthrough research exists.

Relevant papers on relational models:

 * https://www.dcs.warwick.ac.uk/~hugh/TTM/DBE-Chapter11.pdf
 * https://www.seas.upenn.edu/~zives/03f/cis550/codd.pdf
 * https://www.dcs.warwick.ac.uk/~hugh/TTM/reference_material.html

Database architecture:
 * https://www.sqlite.org/arch.html
 * https://www.sqlite.org/opcode.html

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
