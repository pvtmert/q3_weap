# Quake 3 engine weapon file 'decompiler'

as you know, cod sort of 'compiles' weapon files (probably for compressing to faster process in interpreter) and is single line file

this little console application takes filenames as program arguments and reads it then writes to new file with prefixed "fix_" on same folder as source file is with much readable content.

it simply translates

	var\val\var\val

to

	var:val
	var:val

format.

## Usage:

compilation:
	make CC[your_compiler_here]
	defaults to 'clang'

running:
	./weaponfix file_to_be_decompiled -file_to_be_recompiled file_to_be_decompiled -file_to_be_recompiled
	you can use anything as file but file will be placed next to its original one with prefix
	decompilation prefix default: fix_
	recompilation prefix default: comp_
	if you decomp c4_mp it will be fix_c4_mp when you recomp it (fix_c4_mp), name will be comp_fix_c4_mp
	- before your filename specifies it should be 'recompiled'

### notes:

* note: first variable is not a variable, just a header 'WEAPONFILE' so it skips that, else? You will get wrong combinations
* note: you may notice some variables has no value, you can assume they're null.
I tried on Cod2 and Cod4, MW2 has files in .ff (fast file) so i couldn't tried yet but since same engine (Q3) is under the hood, it should work on all Q3 games, Cod, Wolfenstein, Doom etc...

