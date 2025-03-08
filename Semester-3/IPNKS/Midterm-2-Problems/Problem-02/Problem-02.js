<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Problem-02</title>
</head>
<body>
    <div id="numbers">

    </div>
    <div>
        <input id="input" type="text"><button id="button">Провери</button>
    </div>
    <div>
        <p>Преостанато време <span id="seconds">60</span> секунди.</p>
    </div>
    <script>
        let NUMBERS = [];

        const generateNums = () => {
            let num1 = generateRandomNumber(1);
            let num2 = generateRandomNumber(1);
            let num3 = generateRandomNumber(2);
            let num4 = generateRandomNumber(2);
            let num5 = generateRandomNumber(3);
            let num6 = generateRandomNumber(3);

            NUMBERS.push(num1, num2, num3, num4, num5, num6);

            let display = document.querySelector('#numbers');
            display.textContent = num1 + ' ' + num2 + ' ' + num3 + ' ' + num4 + ' ' + num5 + ' ' + num6;
        }

        // ZAPISI //
        const generateRandomNumber = (num) => {
            const min = Math.pow(10, num - 1);
            const max = Math.pow(10, num) - 1;

            return Math.floor(Math.random() * (max - min + 1)) + min;
        }
        // ZAPISI //

        console.log(NUMBERS);

        // ZAPISI //
        const timer = () => {
            let countDown = 60;
            let interval = setInterval(function() {
                countDown--;
                if(countDown > 0) {
                    document.querySelector('#seconds').textContent = countDown.toString();
                } else {
                    document.querySelector('#seconds').textContent = '0';
                    document.querySelector('#input').disabled = true;
                    document.querySelector('#button').disabled = true;
                    clearInterval(interval);
                }
            }, 1000);
        }
        // ZAPISI //

        // ZAPISI //
        const check = () => {
            let input = document.querySelector('#input').value;
            let result = eval(input);
            if (result === num6) {
                input.textContent = "ПОГОДОК";
                input.disabled = true;
                document.querySelector('#button').disabled = true;
            }
        }
        // ZAPISI //

        document.addEventListener('DOMContentLoaded', generateNums);
        document.addEventListener('DOMContentLoaded', timer);
        button.addEventListener("click", check);
    </script>
</body>
</html>
