<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>G-Innovator - Smart Water Reservoir</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }

        header {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 15px 0;
        }

        .container {
            max-width: 800px;
            margin: 20px auto;
            overflow: hidden;
        }

        .box {
            float: left;
            width: calc(33.33% - 20px);
            margin: 10px;
            padding: 20px;
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            box-sizing: border-box;
        }

        h2 {
            color: #333;
        }

        .moisture-value {
            font-size: 24px;
            font-weight: bold;
            color: #4CAF50;
        }

        footer {
            text-align: center;
            padding: 10px 0;
            background-color: #333;
            color: #fff;
            position: fixed;
            width: 100%;
            bottom: 0;
        }
    </style>
</head>
<body>
    <header>
        <h1>G-Innovator - Smart Water Reservoir</h1>
        <img src="https://img.freepik.com/premium-vector/hydroelectric-power-station-river-water-renewable-energy-resource-electric-industrial-technology-factory-natural-environment-landscape-vector-illustration_345238-1519.jpg?w=2000" height="200px" width="400px">
    </header>

    <div class="container">
        <div class="box">
            <h2>Area 1</h2>
            <h5>Moisture level</h5>
            <div class="moisture-value">












<?php


$servername = "localhost";
$database = "esp32";
$username = "root";
$password = "";


$conn = mysqli_connect($servername, $username, $password, $database);





if ($conn) {
    // echo "Connected successfully";
}
else
{
    echo "something wrong";
}






if (isset($_POST["postData"])  ||  isset($_POST["postData2"])) {
    if(isset($_POST["postData"]) )
    {
        $receivedData = $_POST["postData"];
        $sqlInsert = "INSERT INTO moisture_table (area1) VALUES ('$receivedData')";
    }
  
    elseif(isset($_POST["postData2"]))
    {
        $receivedData = $_POST["postData2"];
        $sqlInsert = "INSERT INTO moisture_table (area2) VALUES ('$receivedData')";

    }
 

    
    if ($conn->query($sqlInsert) === TRUE) {
        echo "Data saved successfully.";
    } else {
        echo "Error: " . $sqlInsert . "<br>" . $conn->error;
    }


    $sqlCountRows = "SELECT COUNT(*) as rowCount FROM moisture_table";
    $resultCountRows = $conn->query($sqlCountRows);
    
    if ($resultCountRows->num_rows > 0) {
        $row = $resultCountRows->fetch_assoc();
        $rowCount = $row["rowCount"];
    
        // Delete the first row if the number of rows is more than 10
        if ($rowCount > 10) {
            $sqlDelete = "DELETE FROM moisture_table ORDER BY id ASC LIMIT 1";
            $conn->query($sqlDelete);
        }
    }


   
   
} 



else {
    $sqlRetrieve = "SELECT area1 FROM moisture_table ORDER BY id DESC LIMIT 1";
    $result = $conn->query($sqlRetrieve);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        $lastValue = $row["area1"];
        echo "" . $lastValue;
    } else {
        echo "No data available in area1.";
    }

   

    
    
}




?>



       












            
    </div>
        </div>




        <div class="box">
            <h2>Area 2</h2>
            <h5>Moisture level</h5>
            <div class="moisture-value">

<?php
            $sqlRetrieve = "SELECT area2 FROM moisture_table ORDER BY id DESC LIMIT 1";
             $result = $conn->query($sqlRetrieve);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        $lastValue = $row["area2"];
        echo "" . $lastValue;
    } else {
        echo "No data available in area1.";
    }


    // Close connection
    $conn->close();

?>
            </div>
        </div>

    </div>

    <footer>
        &copy; 2023 G-Innovator. All rights reserved.
    </footer>
</body>
</html>
