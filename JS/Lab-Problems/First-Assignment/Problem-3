<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <script>
        function findLongestWord() {
            let strings = [];
            for(let i=0; i<3; i++) {
                strings[i] = prompt("Please enter string " + (i+1));
            }
        
            let longestWord = "";
            for(let i=0; i<strings.length; i++) {
                let words = strings[i].split(" ");
                for(let j=0; j<words.length; j++) {
                    if(words[j].length > longestWord.length) {
                        longestWord = words[j];
                    }
                }
            }
        
            alert("The longest word is: " + longestWord);
        }
        
        findLongestWord();
        </script>
</body>
</html>
