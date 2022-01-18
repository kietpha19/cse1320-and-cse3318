#ifndef SPELL_H
#define	SPELL_H

/*
first_str - first string (vertical)
second_str - second string (horizontal)
print_table - can have value 1 or other.
	Value 1 indicates to print the distance matrix.
	Value 0 (or anything other than 1) indicates to NOT print the distance matrix. In this case
	the function is used only to compute the distance between 2 words.
*/
int edit_distance(char * first_str, char * second_str, int print_table);


/*
Parameters:
testname - string containing the name of the file with the paragraph to spell check, includes .txt e.g. "text1.txt" 
dictname - name of file with dictionary words. Includes .txt, e.g. "dsmall.txt"
printOn - If 1 it will print EXTRA debugging/tracing information (in addition to what it prints when 0):
			 dictionary as read from the file	
			 dictionary AFTER sorting in lexicographical order
			 for every word searched in the dictionary using BINARY SEARCH shows all the "probe" words and their indices indices
			 See sample run.
	      If 0 (or anything other than 1) does not print the above information, but still prints the number of probes.
		     See sample run.
*/
void spell_check(char * dictname, char * testname, int printOn);

#endif	/* SPELL_H */