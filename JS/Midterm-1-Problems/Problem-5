<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Random Strings</title>

    <style>
        /* Style for the main container */
        #main {
            width: 1000px;
        }

        /* Style for the individual string elements */
        .string {
            display: inline-block;
            margin: 5px;
            cursor: pointer;
        }
    </style>
</head>
<body>
    
    <!-- Main container for the application -->
    <div id="main">
        <!-- Container for displaying random strings -->
        <div id="strings"></div>
        <hr />
        <!-- Container for displaying selected strings -->
        <div id="selected"></div>
        <hr />
        <!-- Button to trigger the check function -->
        <button onclick="check()">Check</button>
    </div>
    
    <script>
        // Constant string containing uppercase English letters
        const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // Function executed when the window is loaded
        window.onload = function() {
            // Get the container for random strings
            let strings = document.getElementById("strings");

            // Generate 50 random strings and add them to the container
            for(let i = 0; i < 50; i++) {
                let str = "";
                let len = getRandomInt(3, 10);

                // Construct a random string of a random length
                for(let j = 0; j < len; j++) {
                    let num = Math.floor(Math.random() * 26);
                    str += letters[num];
                }

                // Create a div element for the string and add styles
                let element = document.createElement("div");
                element.classList.add("string");
                element.innerHTML = str;
                element.style.backgroundColor = getRandomColor();

                // Add a click event listener to move the string to the selected container
                element.addEventListener("click", function handle(event) { addToSelected(element); });
                strings.appendChild(element);
            }
        }

        // Function to check the selected strings
        function check() {
            // Get an array of selected string elements
            let elements = document.getElementById("selected").getElementsByClassName("string");

            // Check if at least two strings are selected
            if(elements.length <= 1) {
                alert("Error! Please select at least 2 strings!");
                return;
            }

            // Calculate total points based on the selected strings
            let total = elements[0].innerHTML.length;
            for(let i = 1; i < elements.length; i++) {
                let current = elements[i].innerHTML;
                let prev = elements[i - 1].innerHTML;

                // Check if each consecutive string starts with the last letter of the previous string
                if(current[0] != prev[prev.length - 1]) {
                    alert("Error! Each consecutive word should start with the last letter of the previous word!");
                    return;
                }

                total += current.length;
            }

            // Display a success message with the total points
            alert("Success! You earned " + total + " points!");
        }

        // Function to add a string to the selected container
        function addToSelected(element) {
            // Clone the element and add a click event listener to remove it from the selected container
            let copy = element.cloneNode(true);
            copy.addEventListener("click", function handle(event) { removeFromSelected(copy); })
            // Append the cloned element to the selected container and remove it from the original container
            document.getElementById("selected").appendChild(copy);
            element.remove();
        }

        // Function to remove a string from the selected container
        function removeFromSelected(element) {
            // Clone the element and add a click event listener to add it back to the original container
            let copy = element.cloneNode(true);
            copy.addEventListener("click", function handle(event) { addToSelected(copy); })
            // Append the cloned element to the original container and remove it from the selected container
            document.getElementById("strings").appendChild(copy);
            element.remove();
        }

        // Function to get a random integer between min and max (inclusive)
        function getRandomInt(min, max) {
            return Math.floor(Math.random() * ((max + 1) - min) + min);
        }

        // Function to generate a random color in hexadecimal format
        function getRandomColor() {
            const hex = '0123456789ABCDEF';
            var color = '#';
            for(let i = 0; i < 6; i++) {
                color += hex[Math.floor(Math.random() * 16)];
            }
            return color;
        }
    </script>
</body>
</html>
