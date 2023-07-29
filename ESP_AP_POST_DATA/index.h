static const char Main_Page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <title>Contoh Form</title>
</head>
<body>
  <h2>Contoh Form</h2>

  <form action="/form" method="post">
    <label for="inputField">Input:</label>
    <input type="text" id="inputField" name="inputField" required><br><br>
    <input type="submit" value="Kirim">
  </form>

</body>
</html>


)=====";
