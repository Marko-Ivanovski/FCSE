<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Flight Registration</title>
    <style>
        label {
            display: block;
            font-size: 18px;
            font-family: 'Courier New', Courier, monospace;
            margin-left: 5px;
        }
        /* Styles for the button */
        #button {
            width: 75px;
            font-size: 18px;
            font-family: 'Courier New', Courier, monospace;
            text-align: center;
        }
        /* Margin bottom for div elements */
        div {
            margin-bottom: 10px;
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
        /* Styles for the list of flight registrations */
        #Cards {
            width: 400px;
            height: 100px;
        }
        /* Styles for list items */
        li {
            list-style-type: disc;
        }
    </style>
</head>
<body>
    <h1>Регистрирај лет</h1>
    <!-- Input fields for flight registration -->
    <div><label>Име & Презиме</label><input type="text" id="name"></div>
    <div><label>Ознака на летало</label><input type="text" id="mark"></div>
    <div><label>Координати на лет</label><input type="text" id="coord"></div>
    <div><label>Радиус на лет</label><input type="text" id="rad"></div>
    <div><label>Висина на лет</label><input type="text" id="heigth"></div>
    <div>
        <label>Тип на летало</label>
        <!-- Dropdown for selecting the type of aircraft -->
        <select id="type">
            <option value="Едрилица">Едрилица</option>
            <option value="Дрон">Дрон</option>
        </select>
    </div>
    <!-- Button to initiate the flight registration -->
    <div><button onclick="login()" id="button">Најави</button></div>
    <!-- Section for displaying registered flights -->
    <h2>Регистрирани летович</h2>
    <p>Вкупно најавени летови: <span id="counter">0</span></p>
    <ul id="Cards"></ul>
    <!-- JavaScript script for dynamic functionality -->
    <script>
        // Variable to keep track of the number of registered flights
        let global = 0;

        // Function to register a flight
        function login() {
            // Retrieving values from input fields
            let name = document.getElementById("name").value;
            let mark = document.getElementById("mark").value;
            let coord = document.getElementById("coord").value;
            let rad = document.getElementById("rad").value;
            let height = document.getElementById("heigth").value;
            let type = document.getElementById("type").value;
            let parsedRad = parseInt(rad);
            let parsedHeight = parseInt(height);

            // Validation to check if all fields are filled
            if (!name || !mark || !coord || !rad || !height || !type) {
                alert("Please fill in all the required fields");
                return;
            }

            // Checking the format of the aircraft mark
            if (!MarkChecker(mark)) {
                alert("Invalid format. It should be Z3-UNR-____ (4 digits)");
                return;
            }

            // Checking if the aircraft mark has repeating digits
            if ((parsedRad > 500 && parsedHeight > 150)) {
                if (!SameDigit(mark)) {
                    alert("Exceeds the maximum requirements");
                    return;
                }
            }

            // Creating a new list item for the registered flight
            let Cards = document.getElementById("Cards");
            let createCard = document.createElement("li");

            // Applying styles based on the type of aircraft
            if (type === "Едрилица") {
                createCard.style.border = "2px solid black";
            } else if (type === "Дрон") {
                if (parsedHeight === parsedRad) {
                    createCard.style.border = "2px solid black";
                }
            }

            // Adding content to the list item
            createCard.innerHTML = "<p>" + name + "," + mark + "</p>" +
                                   "<p>Радиус: " + rad + "," + " Висина: " + height + "</p>" +
                                   "<p>" + type + "</p>" +
                                   "<button onclick='Confirm(this)'>Confirm</button>  <button onclick='Cancel(this)'>Cancel</button>";

            // Appending the list item to the list
            Cards.append(createCard);

            // Updating the counter and resetting the input fields
            let counter = document.getElementById("counter");
            global++;
            counter.innerHTML = global;

            name.value = "";
            mark.value = "";
            coord.value = "";
            rad.value = "";
            height.value = "";
            type.value = "";
        }

        // Function to check the format of the aircraft mark
        function MarkChecker(mark) {
            // Z3-UNR-1234
            if (mark.slice(0, 7) == "Z3-UNR-" && !isNaN(parseInt(mark.slice(7, 11)))) {
                return true;
            }
            return false;
        }

        // Function to check if the aircraft mark has repeating digits
        function SameDigit(mark) {
            if (parseInt(mark.slice(7, 11)) % 1111 == 0) {
                return true;
            }
            return false;
        }

        // Function to cancel a registered flight
        function Cancel(btn) {
            let del = btn.parentNode;
            del.remove();
            let counter = document.getElementById("counter");
            global--;
            counter.innerHTML = global;
        }

        // Function to confirm a registered flight
        function Confirm(btn) {
            let bg = btn.parentNode;
            bg.style.background = "lightgreen";
        }
    </script>
</body>
</html>
