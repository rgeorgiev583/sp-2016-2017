Example:  who | wc -l
ls | wc -l
grep argv[1] argv[2..] | wc -l
head -argv[1] argv[3..] | grep argv[2] | wc -l
grep argv[1..] | sort | uniq | wc -l
argv[1] | argv[2] | argv[3] ...
argv[1] argv[2] | argv[3] argv[4] | ...
