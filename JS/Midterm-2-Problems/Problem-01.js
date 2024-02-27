<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Problem-01</title>
</head>
<body>
    <div class="main">
        <input type="text" id="input"><button id="button">Постави</button>
    </div>
    <br>
    <div class="container"></div>
    <script>
        let input = document.querySelector('#input');
        let button = document.querySelector('#button');

        const create = () => {
            let podeli = input.value.split(",");
            let container = document.querySelector('.container');

            let color = podeli[0];
            let width = podeli[1] + "px";
            let height = podeli[2] + "px";
            let name = podeli[3];

            let newName = " ";
            name.split('').forEach(function(char, index) {
                if(index % 2 === 0) {
                    newName += char.toLowerCase();
                } else {
                    newName += char.toUpperCase();
                }
            });

            let newDiv = document.createElement('div');
            newDiv.style.backgroundColor = color;
            newDiv.style.width = width;
            newDiv.style.height = height;
            newDiv.textContent = newName;
            newDiv.style.textAlign = 'center';
            newDiv.setAttribute('className', 'destroy');
            container.append(newDiv);

            newDiv.addEventListener('click', function() {
                container.removeChild(newDiv);
            });
        }
        button.addEventListener("click", create);
    </script>
</body>
</html>
