<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sum Min and Max</title>
</head>
<body>
    <!-- Main container for the application -->
    <div id="main">
        <!-- Container for input fields -->
        <div id="input_fields">
        </div>
        <!-- Container for utility buttons -->
        <div id="util_buttons">
            <!-- Button to add input fields -->
            <button onclick="addInput()">Додади</button><br/>
            <!-- Button to calculate average, maximum, and minimum values -->
            <button onclick="calculate()">Пресметај</button>
        </div>
        <!-- Container to display calculated data -->
        <div id="data">
            <!-- Display average value -->
            <div>Просек: <span id="avg"></span></div>
            <!-- Display maximum value -->
            <div>Максимум: <span id="max"></span></div>
            <!-- Display minimum value -->
            <div>Минимум: <span id="min"></span></div>
        </div>
    </div>
    
    <!-- JavaScript script for dynamic functionality -->
    <script>
        // Function executed when the window is loaded
        window.onload = function() {
            // Initial call to addInput function to create an input field
            addInput();
        }

        // Function to add a new input field
        function addInput() {
            // Create a new div for the input field
            let inputField = document.createElement("div");
            inputField.classList.add("input_field");

            // Create an input element for numeric values
            let input = document.createElement("input");
            input.classList.add("input_number");
            input.type = "number";
            inputField.appendChild(input);

            // Create a button to delete the corresponding input field
            let button = document.createElement("button");
            button.innerHTML = "Избриши";
            button.addEventListener("click", function handle(event) { deleteInput(button); });
            inputField.appendChild(button);

            // Append the input field to the container
            document.getElementById("input_fields").appendChild(inputField);
        }

        // Function to delete an input field
        function deleteInput(button) {
            button.parentNode.remove();
        }

        // Function to calculate and display average, maximum, and minimum values
        function calculate() {
            // Get all input elements with the class "input_number"
            let inputs = document.getElementsByClassName("input_number");

            // Initialize variables for average, maximum, and minimum values
            let avg = 0;
            max = Number.MIN_VALUE;
            min = Number.MAX_VALUE;

            // Iterate through input elements to calculate average, maximum, and minimum
            for(let i = 0; i < inputs.length; i++) {
                let val = parseInt(inputs[i].value);
                avg += val;
                if(val > max) max = val;
                if(val < min) min = val;
            }

            // Display calculated values in the corresponding HTML elements
            document.getElementById("avg").innerHTML = avg / inputs.length;
            document.getElementById("max").innerHTML = max;
            document.getElementById("min").innerHTML = min;
        }
    </script>
</body>
</html>
