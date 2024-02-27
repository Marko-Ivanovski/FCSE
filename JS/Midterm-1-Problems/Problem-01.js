<!DOCTYPE html>
<html lang="en">
<head>
    <!-- Meta tags for character set and viewport settings -->
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Online Shop</title>

    <!-- Styles for the HTML elements -->
    <style>
        /* Style for the main container */
        #main {
            width: 800px;
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

        /* Style for h2 elements */
        h2 {
            margin: 5px 0;
        }

        /* Style for tables and their cells */
        table, th, td {
            text-align: center;
            border: 1px solid black;
            border-collapse: collapse;
        }

        /* Flex container for the tables */
        #tables {
            display: flex;
            gap: 10px;
            justify-content: space-between;
        }

        /* Style for individual table containers */
        #unused, #used {
            flex: 1;
        }

        /* Style for table elements */
        #unused-table, #used-table {
            width: 100%;
        }

        /* Style for common padding in various elements */
        .form_field, .form_dropdown, #active-items, h2 {
            padding: 5px;
        }

        /* Style for the state display and form button */
        #form_state {
            text-align: center;
        }

        .form_button {
            padding: 10px;
        }

        /* Style for the form button's width */
        .form_button button {
            width: 50px;
        }
    </style>
</head>
<body>

    <!-- Main container for the online shop -->
    <div id="main">
        <!-- Heading for the online shop -->
        <div class="center"><h1>Online classes</h1></div>

        <!-- Form for adding items to the shop -->
        <div class="form">
            <!-- Form fields for item information -->
            <div class="form_field">
                <label for="form_name">Name and Surname</label>
                <input type="text" id="form_name" name="form_name" />
            </div>
            <div class="form_field">
                <label for="form_item">Item</label>
                <input type="text" id="form_item" name="form_item" />
            </div>
            <div class="form_field">
                <label for="form_code">Item Code</label>
                <input type="text" id="form_code" name="form_code" />
            </div>
            <div class="form_field">
                <label for="form_desc">Item description</label>
                <input type="text" id="form_desc" name="form_desc" />
            </div>
            <div class="form_field">
                <label for="form_price">Price</label>
                <input type="number" id="form_price" name="form_price" />
            </div>
            <div class="form_dropdown">
                <label for="form_state">Used</label>
                <select id="form_state" name="form_state">
                    <option value="used">used</option>
                    <option value="unused">unused</option>
                </select>
            </div>

            <!-- Button to add an item to the shop -->
            <div class="form_button">
                <button onclick="addUser()">Add</button>
            </div>
        </div>

        <!-- Display for the number of active items -->
        <div id="active-items">Active items: <span id="item-count">0</span></div>

        <!-- Tables for displaying unused and used items -->
        <div id="tables">
            <div id="unused">
                <h2>Unused Items</h2>
                <table id="unused-table">
                    <tr>
                        <th>Name</th>
                        <th>Item</th>
                        <th>Price</th>
                        <th>Code</th>
                        <th>Number</th>
                        <th>Actions</th>
                    </tr>
                </table>
            </div>
            <div id="used">
                <h2>Used Items</h2>
                <table id="used-table">
                    <tr>
                        <th>Name</th>
                        <th>Item</th>
                        <th>Price</th>
                        <th>Code</th>
                        <th>Number</th>
                        <th>Actions</th>
                    </tr>
                </table>
            </div>
        </div>
    </div>

    <!-- JavaScript script for dynamic functionality -->
    <script>
        // Variables for tracking active items and tables
        var activeItems = 0;
        var unusedTable = document.getElementById('unused-table');
        var usedTable = document.getElementById('used-table');

        // Arrays to store used and unused item codes
        var usedItems = new Array();
        var unusedItems = new Array();

        // Function to be executed on window load
        window.onload = function() {
            setAvailableActiveCount();
        }

        // Function to add a new item to the shop
        function addUser() {
            // Retrieve form input values
            let name = document.getElementById('form_name').value;
            let item = document.getElementById('form_item').value;
            let code = document.getElementById('form_code').value;
            let description = document.getElementById('form_desc').value;
            let price = document.getElementById('form_price').value;
            let state = document.getElementById('form_state').value;

            // Validate form inputs
            if(name === "" || item === "" || code === "" || description === "" || price === "" || state === "") {
                alert("Error! Please fill in all fields.");
                return;
            }

            // Check for duplicate item codes
            if(state === "used" && usedItems.includes(code)) {
                alert("Error! This item already exists!");
                return;
            } else if(state === "unused" && unusedItems.includes(code)) {
                alert("Error! This item already exists!");
                return;
            }

            // Validate price input
            if(price <= 0) {
                alert("Error! Price must be greater than 0.");
                return;
            }

            // Create a new table row and populate it with item information
            var row = document.createElement("tr");
            var user = "<td>" + name + "</td>" +
                    "<td>" + item + "</td>" +
                    "<td>" + Math.floor(price * 1.1) + "</td>" +
                    "<td>" + code + "</td>" +
                    "<td>" + filterNumber(code) + "</td>" +
                    "<td><button onclick=\"sellItem(this)\">Sold</button></td>";

            row.innerHTML = user;
            activeItems++;

            // Add the new row to the appropriate table and update item arrays
            if(state === "used") {
                usedTable.appendChild(row);
                usedItems.push(code);
            } else if(state === "unused") {
                unusedTable.appendChild(row);
                unusedItems.push(code);
            }

            // Update the count of active items
            setAvailableActiveCount();
        }

        // Function to update the display of active item count
        function setAvailableActiveCount() {
            document.getElementById('item-count').innerHTML = activeItems;
        }

        // Function to mark an item as sold
        function sellItem(button) {
            let row = button.parentNode.parentNode;
            row.style.backgroundColor = "yellow";
            button.remove();
            activeItems--;
            setAvailableActiveCount();
        }

        // Function to filter out non-numeric characters from a string
        function filterNumber(str) {
            let result = "";
            for(let i = 0; i < str.length; i++) {
                if((str[i] >= "0" && str[i] <= "9") || str[i] == "!") continue;
                result += str[i];
            }
            return result;
        }
    </script>
</body>
</html>
