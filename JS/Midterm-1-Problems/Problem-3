<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Cards/title>

    <style>
        /* Style for the main container */
        #main {
            width: 1500px;
        }

        /* Center-align text */
        .center {
            text-align: center;
        }

        /* Style for bold text */
        span {
            font-weight: bold;
        }

        /* Style for labels in forms */
        label {
            display: inline-block;
            width: 200px;
        }

        /* Style for input and select elements in forms */
        input, select {
            width: 250px;
        }

        /* Common padding for various form elements */
        .form_field, .form_dropdown, #available-teachers, h2 {
            padding: 10px;
        }

        /* Center-align text in the form_role section */
        #form_role {
            text-align: center;
        }

        /* Padding for form buttons */
        .form_button {
            padding: 10px;
        }

        /* Style for the width of the select element */
        .form_button button {
            width: 50px;
        }

        /* Center-align text in the select element */
        select {
            text-align: center;
        }

        /* Display for cards */
        #cards {
            display: flex;
            padding: 10px;
            gap: 10px;
            flex-wrap: wrap;
        }

        /* Style for individual cards */
        .card {
            display: block;
            text-align: center;
        }

        /* Style for description in the card */
        .desc {
            font-weight: normal;
            padding-top: 5px;
            line-height: 2;
            margin-bottom: 12px;
        }
    </style>
</head>
<body>
    <div id="main">
        <!-- Heading for user cards -->
        <div class="center"><h1>User Cards</h1></div>

        <!-- Form for adding user cards -->
        <div class="form">
            <!-- Form fields for user card information -->
            <div class="form_field">
                <label for="form_user">Username</label>
                <input type="text" id="form_user" name="form_user" />
            </div>
            <div class="form_field">
                <label for="form_id">Id</label>
                <input type="text" id="form_id" name="form_id" />
            </div>
            <div class="form_field">
                <label for="form_width">Width</label>
                <input type="number" id="form_width" name="form_width" />px
            </div>
            <div class="form_field">
                <label for="form_height">Height</label>
                <input type="number" id="form_height" name="form_height" />px
            </div>
            <div class="form_dropdown">
                <label for="form_color">Color</label>
                <select id="form_color" name="form_color">
                    <option value="red">red</option>
                    <option value="yellow">yellow</option>
                    <option value="green">green</option>
                    <option value="blue">blue</option>
                </select>
            </div>

            <!-- Button to add a user card -->
            <div class="form_button">
                <button onclick="addColor()">Add</button>
            </div>
        </div>

        <!-- Display for the total sold amount -->
        <div id="total">Вкупно продадени: <span id="sold">0</span></div>

        <!-- Container for displaying user cards -->
        <div id="cards">

        </div>
    </div>

    <script>
        // Variables for tracking total sold amount, card display, and card array
        var totalSold = 0;
        var cardsParent = document.getElementById('cards');
        var cardsArray = new Array();

        // Function to add a new user card
        function addColor() {
            // Retrieve form input values
            let username = document.getElementById('form_user').value;
            let id = document.getElementById('form_id').value;
            let width = document.getElementById('form_width').value;
            let height = document.getElementById('form_height').value;
            let color = document.getElementById('form_color').value;

            // Validate form inputs
            if(username === "" || id === "" || width === "" || height === "" || color === "") {
                alert("Error! Please fill in all fields.");
                return;
            }

            // Validate ID format
            if(!isIdValid(id)) {
                alert("Error! Please enter a valid ID.");
                return;
            }

            // Calculate total sum based on width and height
            let totalSum = width * height * 0.5;

            // HTML element for the card
            let element = "<div class='desc'>Id: " + id +
                "<br/>Width: " + width +
                "<br/>Height: " + height +
                "<br/>Color: " + color +
                "<br/>Total sum: " + totalSum +
                "</div><button onclick=\"sell(" + totalSum + ", this)\">Sell</button";

            // Update an existing card if the ID already exists
            if(cardsArray.includes(id)) {
                let cardById = document.getElementById(id);
                cardById.innerHTML = element;
                cardById.style.backgroundColor = color;
                cardById.style.width = width + "px";
                cardById.style.height = height + "px";

                return;
            }

            // Create a new card and update its styles
            cardsArray.push(id);
            let card = document.createElement('div');
            card.id = id;
            card.classList.add('card');
            card.innerHTML = element;
            card.style.backgroundColor = color;
            card.style.width = width + "px";
            card.style.height = height + "px";

            // Append the card to the cards container
            cardsParent.append(card);
        }

        // Function to update the display of the total sold amount
        function setTotalSold() {
            document.getElementById('sold').innerHTML = totalSold;
        }

        // Function to check if an ID is valid
        function isIdValid(str) {
            for(let i = 0; i < str.length; i++) {
                if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
                    return false;
                }
            }
            return true;
        }

        // Function to sell a card and update the total sold amount
        function sell(sum, button) {
            totalSold += sum;
            let idx = cardsArray.indexOf(button.parentNode.id);
            if(idx != -1) {
                cardsArray.splice(idx, 1);
            }
            button.parentNode.remove();
            setTotalSold();
        }
    </script>
</body>
</html>
