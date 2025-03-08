<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <script>
        function checkNumber(){
            let inputNumber = prompt("Enter a 4 digit number: ");

            if(inputNumber.length!==4 || isNaN(inputNumber)){
                alert("The number isn't a 4 digit number!");
            }
            else{
                let number = parseInt(inputNumber);
                let reverseNumber = parseInt(inputNumber.split("").reverse().join(""));

                let isPalindrome = number === reverseNumber;

                let sumOfDigits = parseInt(inputNumber[0]) + parseInt(inputNumber[1]) + parseInt(inputNumber[2]) + parseInt(inputNumber[4]);

                let isDevisible = number % sumOfDigits ===0
                
                alert("The number " + number + " is a palindrome: " + isPalindrome + " and is devisable by the sum of the nums: " + isDevisible);
            }
        }
        checkNumber();
    </script>
</body>
</html>
