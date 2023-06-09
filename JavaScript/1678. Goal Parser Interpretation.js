/*
1678. Goal Parser Interpretation

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.



Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"


Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.

*/

//Brute Force 

/**
 * @param {string} command
 * @return {string}
 */
var interpret = function(command) {
    
    let result = ""
    for(let i = 0; i < command.length; i++)
    {
        if(command[i] == "G")
        result += "G"
        else if(command[i] == "(" && command[i+1] == ")")
        result += "o"
        else if(command[i] == "(" && command[i+1] == "a")
        result += "al"
    }

    return result;

};

//Using a map
/**
 * @param {string} command
 * @return {string}
 */
var interpret = function(command) {
    
    const commandKey = new Map();

    commandKey.set("G", "G");
    commandKey.set("()" , "o");
    commandKey.set("(al)", "al");

    let temp = "";
    let result = "";
    command.split("").forEach(letter =>{
        temp += letter;
        if(commandKey.has(temp))
        {
            result += commandKey.get(temp);
            temp= "";
        }

    })

    return result;

};