// 748. Shortest Completing Word

// Given a string licensePlate and an array of strings words, find the shortest completing word in words.

// A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

// For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

// Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

 

// Example 1:

// Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
// Output: "steps"
// Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
// "step" contains 't' and 'p', but only contains 1 's'.
// "steps" contains 't', 'p', and both 's' characters.
// "stripe" is missing an 's'.
// "stepple" is missing an 's'.
// Since "steps" is the only word containing all the letters, that is the answer.
// Example 2:

// Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
// Output: "pest"
// Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.

var shortestCompletingWord = function(licensePlate, words) {
    let obj = {},maxLength=-1
    for(let i=0;i<licensePlate.length;i++){
        if((licensePlate[i].charCodeAt(0)>='a'.charCodeAt(0) && licensePlate[i].charCodeAt(0)<='z'.charCodeAt(0)) ||
        (licensePlate[i].charCodeAt(0)>='A'.charCodeAt(0) && licensePlate[i].charCodeAt(0)<='Z'.charCodeAt(0))
        
        ){
            let val = licensePlate[i].toLowerCase()
            obj[val] = (obj[val]||0) + 1
          
        }
    }
    let word = '',f=-1

    for(let i=0;i<words.length;i++){
        let z = words[i]
        let cp = {...obj}
        let exist = true
        //   console.log(cp)
        for(let j=0;j<z.length;j++){
                if(cp[z[j]]) cp[z[j]]--
        }
        // console.log(cp)
        for(let key in cp){
            if(cp[key]>0) exist = false
        }
        if(exist && (word.length>z.length || f==-1)){
            f=-2
            word = z
        }


    }
    return word

};

var shortestCompletingWord = function(licensePlate, words) {
    
    // Object to hold the shortest word that matches
    var match = {'found':false, 'word':''};
    
    // Char array to hold the upper case characters we want to match
    var licensePlateChars = licensePlate.toUpperCase().replace(/[^A-Z]/g, '').split('');
    
    words.forEach(function (word) {
        // if we already have a match make sure that the word we are checking is shorter
        if (!match.found || word.length < match.word.length) {
            var replaceWord = word.toUpperCase();
            
            // Loop over each character in the license plate and replace one at a time
            // the key here is that replace will only replace 1 S even if there are 2
            licensePlateChars.forEach(function (lChar) {
                replaceWord = replaceWord.replace(lChar, '');
            });
            
            // We know the word works if the length of the word minus 
            // the length of chars equals the length of the new word
            if (word.length - licensePlateChars.length === replaceWord.length) {
                match.found = true;
                match.word = word
            }
        }
    });
}