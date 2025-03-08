<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <style>
        label {
            display: block;
            font-size: 18px;
            font-family: 'Courier New', Courier, monospace;
            margin-left: 5px;
        }
        /* Styles for radio buttons */
        #ne, #da {
            width: 20px;
            height: 20px;
        }
        /* Styles for the button */
        #button {
            width: 120px;
            font-size: 18px;
            font-family: 'Courier New', Courier, monospace;
            text-align: center;
        }
        /* Styles for input and select elements */
        input, select {
            -webkit-border-radius: 20px;
            -moz-border-radius: 20px;
            border-radius: 20px;
            border: 1px solid #2d9fd9;
            color: #a0d18c;
            width: 250px;
            height: 30px;
            padding-left: 10px;
        }
        /* Styles for list items */
        li {
            list-style-type: disc;
        }
        /* Styles for specific labels */
        label:nth-child(5), label:nth-child(3) {
            display: inline;
        }
        /* Styles for new card elements */
        .newCard {
            padding: 28px;
            display: inline-block;
            height: 200px;
            text-align: center;
            margin: 10px;
        }
    </style>
</head>
<body>
     <!-- Main heading -->
     <h1>Осигурување возила</h1>
     <!-- Input fields for user information -->
     <div><label>Име</label><input type="text" id="name"></div>
     <div><label>Презиме</label><input type="text" id="lname"></div>
     <div><label>Регистарска таблица</label><input type="text" id="reg"></div>
     <div><label>Години на старост</label><input type="text" id="age"></div>
     <!-- Radio buttons for a traffic accident -->
     <div>
         <label>Сообраќајна незгода</label>
         <input type="radio" id="da" name="answer"><label for="da">Да</label>
         <input type="radio" id="ne"  name="answer"><label for="ne">Не</label>
     </div>
     <!-- Button to generate a bill -->
     <div><button onclick="Generate()" id="button">Генерирај сметка</button></div>
     <!-- Section to display generated bills -->
     <h2>Сметки</h2>
     <p>Вкупно сметки за плаќање: <span id="counter">0</span></p>
     <section id="Cards"></section>

      <!-- JavaScript script for dynamic functionality -->
    <script>
        // Variable to keep track of the number of generated bills
        let global = 0;

        // Function to generate a bill
        function Generate() {
            // Retrieving values from input fields
            let name = document.getElementById("name").value;
            let lname = document.getElementById("lname").value;
            let reg = document.getElementById("reg").value;
            let age = document.getElementById("age").value;
            let answerY = document.getElementById("da");
            let answerN = document.getElementById("ne");

            // Validation to check if all fields are filled
            if (!name || !lname || !reg || !age || !answerY || !answerN) {
                alert("Please fill in all the forms");
                return;
            }

            // Variable to store the fine amount for the bill
            let fineTicket = 3000;

            // Checking the registration plate format
            if (!regChecker(reg)) {
                alert("Please enter the number plate in this format AB-1234-CD");
                return;
            }

            // Checking for a golden plate
            if (GoldenPlate(reg)) {
                fineTicket += 1000;
            }

            // Checking if there was a traffic accident
            if (answerY.checked == true) {
                fineTicket += 500;
                Accident = "Има";
            } else {
                Accident = "Нема";
            }

            // Creating a new card element
            let Cards = document.getElementById("Cards");
            let createCard = document.createElement("div");

            // Applying styles based on the age of the vehicle
            if (age >= 30) {
                createCard.style.background = "red";
                createCard.style.border = "2px solid black";
            } else {
                createCard.style.background = "lightgreen";
                createCard.style.border = "2px solid black";
            }

            // Adding content to the card
            createCard.innerHTML = "<p>" + name + " " + lname + "</p>" +
                "<p>" + reg + "</p>" +
                "<p>Сообраќајки: " + Accident + "</p>" +
                "<p>Старост на возило: " + age + "</p>" +
                "<p>За плаќење: " + fineTicket + "</p>" +
                "<button onclick='Pay(this)'>Плати</button>  <button onclick='Delete(this)'>Избриши</button>";

            // Appending the card to the section
            Cards.append(createCard);
            createCard.setAttribute("class", "newCard");

            // Updating the counter and resetting the input fields
            let counter = document.getElementById("counter");
            global++;
            counter.innerHTML = global;
            name = " ";
            lname = " ";
            reg = " ";
            age = " ";
            answerY = " ";
            answerN = " ";
        }

        // Function to check the registration plate format
        function regChecker(reg) {
            let splitter = reg.split("-");
            let fLetter = splitter[0];
            let lLetter = splitter[2];
            let nums = splitter[1];
            if (isNaN(fLetter) && !isNaN(parseInt(nums)) && isNaN(lLetter)) {
                if (fLetter.length == 2 && nums.length == 4 && lLetter.length == 2) {
                    return true;
                }
            }
            return false;
        }

        // Function to check for a golden plate
        function GoldenPlate(reg) {
            let splitter = reg.split("-");
            let nums = splitter[1];
            if (parseInt(splitter[1]) % 1111 == 0) {
                return true;
            }
            return false;
        }

        // Function to mark a bill as paid
        function Pay(btn) {
            btn.disabled = true;
            btn.nextElementSibling.disabled = true;
        }

        // Function to delete a bill
        function Delete(btn) {
            let deleteCard = btn.parentNode;
            deleteCard.remove();
            global--;
            let counter = document.getElementById("counter");
            counter.innerHTML = global;
        }
    </script>
</body>
</html>
