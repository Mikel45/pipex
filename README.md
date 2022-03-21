# pipex
Pipex realization on C.
Alternative for:
```bash
< file1 cmd1 | cmd2 > file2
```

## Running
Clone this repository:

```bash
git clone https://github.com/Mikel45/pipex.git
```

Run the app:
Mandatory:
```bash
cd pipex
make
./pipex infile cmd1 cmd2 outfile
```

Bonus:

```bash
cd pipex
make bonus
./pipex infile cmd1 cmd2 ... cmd(n) outfile
```

here_doc
Alternative for:
```bash
cmd << LIMITER | cmd1 >> file
```
Run:
```bash
cd pipex
make bonus
./pipex here_doc LIMITER cmd cmd1 file
```

